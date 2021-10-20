/*
    Keszitette: Horvath Akos Zsigmond
    Neptunkod: R3SZY2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct auto_
{
    char rendszam[30];
    char tipus[30];
    int ar;
}auto_t;

void write_car_to_file(auto_t* _auto, FILE* fptr);
auto_t get_car_from_file(FILE* fptr, int index);

void write_car_to_file(auto_t* _auto, FILE* fptr)
{
    fwrite(_auto, sizeof(auto_t), 1, fptr);
}

auto_t get_car_from_file(FILE* fptr, int index)
{
    int n = 0;
    auto_t auto_;
    while(fread(&auto_, sizeof(auto_t), 1, fptr))
    {
        if (index == n)
        {
            return auto_;
        }
        n++;
    }
}

int main()
{
    FILE* fptr;
    fptr = fopen("cars.binary", "wb");

    auto_t a = {"ABC-123", "Skoda Fabia", 300000};
    auto_t b = {"DEF-456", "Opel Calibra", 200000};
    auto_t c = {"GHI-789", "Honda Accord", 100000};
    auto_t autok[3];
    autok[0] = a;
    autok[1] = b;
    autok[2] = c;

    for (int i = 0; i < 3; i++)
    {
        write_car_to_file(&autok[i], fptr);
    }
    
    fclose(fptr);
    
    fopen("cars.binary", "rb");
    auto_t auto1 = get_car_from_file(fptr, 2);
    printf("Rendszam: %s\nTipus: %s\nAr: %d\n", auto1.rendszam, auto1.tipus, auto1.ar);
    fclose(fptr);
}
