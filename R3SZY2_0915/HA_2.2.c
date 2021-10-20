/*
    Keszitette: Horvath Akos Zsigmond
    Neptunkod: R3SZY2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void read_filename(char* filename);
void write_input_text_to_file(FILE* fptr);
void rewrite_file_touppercase(char*);

void read_filename(char* filename)
{
    printf("Filename:\n");
    scanf("%s", filename);
}

void write_input_text_to_file(FILE* fptr)
{
    char c;
    while ((c=getchar()) != '#')
    {
        fprintf(fptr, "%c", c);
    }
    
}

void rewrite_file_touppercase(char* filename)
{
    FILE* fptr;
    char c;
    char* buffer;

    fptr = fopen(filename, "r");

    fseek(fptr, 0, SEEK_END);
    int length = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    buffer = malloc(length);
    fread(buffer, 1, length, fptr);
    fclose(fptr);

    for(int i = 0; i<length; i++)
    {
        char upperc;
        upperc = toupper(buffer[i]);
        buffer[i] = upperc;
    }

    fptr = fopen(filename, "w");
    fprintf(fptr, "%s", buffer);
    fclose(fptr);
}

int main()
{
    char filename[50];
    FILE* fptr;

    read_filename(filename);

    fptr = fopen(filename, "w");
    write_input_text_to_file(fptr);
    fclose(fptr);

    rewrite_file_touppercase(filename);

    return 0;
}