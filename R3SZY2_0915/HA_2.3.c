/*
    Keszitette: Horvath Akos Zsigmond
    Neptunkod: R3SZY2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int copy_file_content(FILE* fptr);
char* get_file_name(FILE* fptr);

char* get_file_name(FILE* fptr)
{
    int fdpr;
    char fdpr_path[200];
    char* filename = malloc(200);

    fdpr = fileno(fptr);
    sprintf(fdpr_path, "/proc/self/fd/%d", fdpr);
    int n = readlink(fdpr_path, filename, 200);
    if (n < 0)
        return NULL;
    else
    {
        filename[n] = '\0';
        return filename;
    }
}   

int copy_file_content(FILE* fptr)
{
    FILE* fptr2;
    char c;
    char* buffer;
    char* filename;

    fseek(fptr, 0, SEEK_END);
    int length = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    buffer = malloc(length);
    fread(buffer, 1, length, fptr);

    if((filename = get_file_name(fptr)) == NULL)
    {
        perror("Error while getting the filename!\n");
        return -1;
    }
    fclose(fptr);

    fptr2 = fopen(filename, "w");
    fprintf(fptr2, "%s", buffer);
    fclose(fptr2);

    return 0;
}

int main()
{
    FILE* fptr;

    fptr = fopen("to_be_copied.txt", "r");
    if(copy_file_content(fptr) < 0)
    {
        perror("Error while copying the file!\n");
        return -1;
    }
    else 
        return 0;
}