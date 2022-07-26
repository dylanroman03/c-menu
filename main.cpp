#include <stdio.h>
#include <vector>
#include <string.h>
#define MAX 20

using namespace std;

struct S
{
	char a[20];
};

vector<S> verduras;
vector<vector<float>> calendario;

void showTable()
{
	for (std::size_t i = 0; i < verduras.size(); i++)
	{
		printf("%s\n", verduras[i].a);

		for (std::size_t e = 0; e < calendario[i].size(); e++)
		{
			printf("%d) %0.2lf\n", e + 1, calendario[i][e]);
		}
	}
}

void oneDay() {
	int e;
	printf("Ingrese el dia de interes\n");
	scanf("%d", &e);

	for (std::size_t i = 0; i < verduras.size(); i++)
	{
		printf("%s\n", verduras[i].a);
		printf("%d) %0.2lf\n", e, calendario[i][e - 1]);
	}
}

void percentage(){
	vector<float> percentages;

	for (int i = 0; i < MAX; i++)
	{
		float daySum = 0;
		float porcentage = 0;

		for (std::size_t e = 0; e < calendario.size(); e++)
		{
			daySum = daySum + calendario[e][i];
		}

		porcentage = daySum / calendario.size();
		percentages.push_back(porcentage);

		printf("Dia %d) %0.2lf kilogramos\n", i, porcentage);
	}
	
}

void price() {
	float price;

	printf("Ingrese el precio para cada hortalizas\t");	
	scanf("%f", &price);

	for (std::size_t i = 0; i < verduras.size(); i++)
	{
		float total = 0;
		float totalPrice = 0;

		for (std::size_t e = 0; e < calendario[i].size(); e++)
		{
			total = total + calendario[i][e];
		}

		totalPrice = total * price;

		printf("%s: %0.2lfBS\n", verduras[i].a, totalPrice);
	}
}

int main()
{
	int option;

	while (option != 6)
	{
		printf("Seleccione una opcion\n1)Agregar Verdura\t2)Mostar Tabla\t3)Consumo en un dia especifico\t4)Porcentaje\t5)Total en BS\t6)Salir\n");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			{
				char verdura[20];
				struct S element;

				printf("Nombre de la verdura:\t");
				scanf("%s", &verdura);

				stpcpy(element.a, verdura);
				verduras.push_back(element);
				vector<float> dias;

				for (int i = 0; i < MAX; i++)
				{
					float kilogramos;
					printf("ingrese kilogramos del dia %d:\t", i + 1);
					scanf("%f", &kilogramos);
					dias.push_back(kilogramos);
				}

				calendario.push_back(dias);

				break;
			}
		case 2:
			showTable();
			break;

		case 3:
			oneDay();
			break;

		case 4:
			percentage();
			break;

		case 5:
			price();
			break;

		case 6:
			printf("Adios.....");
			break;

		default:
			printf("Ingrese una opcion valida\n");
			break;
		}
	}

	return 0;
}
