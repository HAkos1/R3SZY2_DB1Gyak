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

float calc_average_price(FILE* fptr);
int count_red_cards(FILE* fptr);
auto_t get_most_expensive_car(FILE* fptr);

int main()
{
	FILE* fptr = fopen("cars.binary", "rb");
	
	printf("Atlag ar: %f\n", calc_average_price(fptr));
	printf("Piros autok szama: %d\n", count_red_cards(fptr));
	
	auto_t most_expensive = get_most_expensive_car(fptr);
	printf("Legdragabb auto rendszama: %s, tipusa: %s, ara: %d\n",
			most_expensive.rendszam, most_expensive.tipus, most_expensive.ar); 
	
	return 0;
}

float calc_average_price(FILE* fptr)
{
	fseek(fptr, 0, SEEK_SET);
	float avg_price = 0;
	int n = 0;
	int sum = 0;
	
	auto_t auto_;
    while(fread(&auto_, sizeof(auto_t), 1, fptr))
    {
		sum+=auto_.ar;
		printf("%d\n",auto_.ar);
		n++;
    }
	
	avg_price = sum/n;
	return avg_price;
}

int count_red_cards(FILE* fptr)
{
	fseek(fptr, 0, SEEK_SET);
	int n = 0;

	auto_t auto_;
    while(fread(&auto_, sizeof(auto_t), 1, fptr))
    {
		if(strcmp(auto_.tipus, "piros")==0)
			n++;
    }
    
    return n;
}

auto_t get_most_expensive_car(FILE* fptr)
{
	fseek(fptr, 0, SEEK_SET);
	auto_t most_expensive_car;
	most_expensive_car.ar = 0;
	
	auto_t auto_;
    while(fread(&auto_, sizeof(auto_t), 1, fptr))
    {
		if(auto_.ar > most_expensive_car.ar)
		{
			most_expensive_car = auto_;
		}
    }
    
    return most_expensive_car;
}
