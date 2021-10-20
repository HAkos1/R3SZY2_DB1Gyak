/*
    Keszitette: Horvath Akos Zsigmond
    Neptunkod: R3SZY2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct szemely
{
	char azonosito[20];
	char nev[30];
}szemely_t;


int write_new_record(FILE* fptr, szemely_t szemely);
int remove_record(const char* filename, szemely_t szemely);
int modify_record(const char* filename, szemely_t old_szemely, szemely_t new_szemely);
void print_all_records(const char* filename);

int main()
{
	const char* filename = "szemelyek.bin"; 

	szemely_t szemelyek[3];
	strcpy(szemelyek[0].azonosito, "ABC-123-456");
	strcpy(szemelyek[0].nev, "Kovacs Bela");
	strcpy(szemelyek[1].azonosito, "DEF-456-789");
	strcpy(szemelyek[1].nev, "Nagy Ferenc");
	strcpy(szemelyek[2].azonosito, "GHI-654-321");
	strcpy(szemelyek[2].nev, "Kiss István");
	
	FILE* fptr = NULL;
	
	fptr = fopen(filename, "wb");
	
	if(fptr == NULL)
	{
		perror("Hiba a fajl megynitasakor!\n");
	}
	
	for(int i = 0; i < 3; i++)
	{
		if(write_new_record(fptr, szemelyek[i]) != 0)
		{
			perror("Hiba rekord irasakor!\n");
			return 1;
		}
	}	 
	
	fclose(fptr);
	
	print_all_records(filename);
	
	remove_record(filename, szemelyek[1]);	
	print_all_records(filename);
	
	szemely_t new_szemely;
	strcpy(new_szemely.azonosito, "XYZ-111-222");
	strcpy(new_szemely.nev, "Kovacs Bela");
	modify_record(filename, szemelyek[0], new_szemely);
	
	print_all_records(filename);
}

int write_new_record(FILE* fptr, szemely_t szemely)
{
	if(fwrite(&szemely, sizeof(szemely_t), 1, fptr) == 0)
		return 1;
	
	return 0;
}

int remove_record(const char* filename, szemely_t szemely)
{
	FILE* fptr = NULL;
	
	fptr = fopen(filename, "rb");
	
	if(fptr == NULL)
	{
		perror("Hiba a fajl megynitasakor!\n");
	}
	
	FILE* tmp_fptr = NULL;
	szemely_t szemely1;
	int found = 0;
	
	tmp_fptr = fopen("temp.bin", "wb+");
	
	if(tmp_fptr == NULL)
	{
		perror("Hiba temp fajl megnyitasakor!\n");
		return 1;
	}
	
    while(fread(&szemely1, sizeof(szemely_t), 1, fptr))
    {
		if(strcmp(szemely1.azonosito, szemely.azonosito) == 0 &&
		strcmp(szemely1.nev, szemely.nev) == 0)
		{
			printf("%s azonsitoju szemely kitorolve!\n", szemely.azonosito);
			found = 1;
		}
		else
			fwrite(&szemely1, sizeof(szemely_t), 1, tmp_fptr);
    }
    
    if(!found)
			printf("Nem talalhato a %s azonositoju szemely!\n", szemely.azonosito);

	fclose(tmp_fptr);
	fclose(fptr);
	remove(filename);
	rename("temp.bin", filename);
	
	return 0;
}

int modify_record(const char* filename, szemely_t old_szemely, szemely_t new_szemely)
{
	FILE* fptr = NULL;
	
	fptr = fopen(filename, "rb");
	
	if(fptr == NULL)
	{
		perror("Hiba a fajl megynitasakor!\n");
	}
	
	FILE* tmp_fptr = NULL;
	szemely_t szemely1;
	int found = 0;
	
	tmp_fptr = fopen("temp.bin", "wb+");
	
	if(tmp_fptr == NULL)
	{
		perror("Hiba temp fajl megnyitasakor!\n");
		return 1;
	}
	
    while(fread(&szemely1, sizeof(szemely_t), 1, fptr))
    {
		if(strcmp(szemely1.azonosito, old_szemely.azonosito) == 0 &&
		strcmp(szemely1.nev, old_szemely.nev) == 0)
		{
			fwrite(&new_szemely, sizeof(szemely_t), 1, tmp_fptr);
			printf("%s azonsitoju szemely modositva!\n", szemely1.azonosito);
			found = 1;
		}
		else
			fwrite(&szemely1, sizeof(szemely_t), 1, tmp_fptr);
		
		if(!found)
			printf("Nem talalhato a %s azonositoju szemely!\n", szemely1.azonosito);
    }

	fclose(tmp_fptr);
	fclose(fptr);
	remove(filename);
	rename("temp.bin", filename);
	
	return 0;
}

void print_all_records(const char* filename)
{
	FILE* fptr = NULL;
	
	fptr = fopen(filename, "rb");
	fseek(fptr, 0, SEEK_SET);
	
	if(fptr == NULL)
	{
		perror("Hiba a fajl megynitasakor!\n");
	}
	
	szemely_t szemely;
	
	printf("Jelenlegi szemelyek a fajlban:\n");
	
	while(fread(&szemely, sizeof(szemely_t), 1, fptr))
	{
		printf("Nev: %s Azonosito: %s\n", szemely.nev, szemely.azonosito);
	}

	fclose(fptr);
}
