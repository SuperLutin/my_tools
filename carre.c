#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print(const int tab[], int taille, int ordre)
{
	static int nb_sol = 1;

	printf("sol %i :\n", nb_sol);

	for (int i = 0; i < taille; ++i)
	{
		printf("%i", tab[i]);
	}
	printf("\n");

	for (int i = 0; i < taille; ++i)
	{
		printf("%i ", tab[i]);

		if (((i + 1) % ordre) == 0)
			printf("\n");
	}
	printf("\n");

	++nb_sol;
}

bool is_colonne(const int tab[], int ordre, int majik)
{

	for (int i = 0; i < ordre; ++i)
	{
		int offset = 0;
		int cal = 0;
		for (int j = 0; j < ordre; ++j)
		{
			cal += tab[offset];
			offset += ordre;
		}
		if (cal != majik)
			return false;
	}

	return true;
}

bool is_ligne(const int tab[], int ordre, int majik)
{
	int offset = ordre;

	for (int i = 1; i < ordre; ++i)
	{
		int cal = 0;
		for (int j = 0; j < ordre; ++j)
		{
			cal += tab[offset];
			++offset;
		}
		if (cal != majik)
			return false;
	}

	return true;
}

bool is_diag(const int tab[], int ordre, int majik)
{
	int offset = 0;
	int cal = 0;

	for (int i = 0; i < ordre; ++i)
	{
		cal += tab[offset];
		offset += ordre + 1;
	}
	if (cal != majik)
		return false;

	offset = ordre - 1;
	cal = 0;

	for (int i = 0; i < ordre; ++i)
	{
		cal += tab[offset];
		offset += ordre - 1;
	}
	if (cal != majik)
		return false;

	return true;
}


bool is_magique(const int tab[], int ordre)
{
	int majik = 0;

	for (int i = 0; i < ordre; ++i)
	{
		majik += tab[i];
	}

	if (is_ligne(tab, ordre, majik) &&
		is_colonne(tab, ordre, majik) &&
		is_diag(tab, ordre, majik))
			return true;

	return false;
}


void gen_carre(int tab[], int taille, int ordre, int pos)
{
	static int nb_car = 1;

	if (pos == taille)
	{
		if (is_magique(tab, ordre))
		{
			print(tab, taille, ordre);
		}
		// else
		// {
		//	printf("Carré n %i pas magique.\n", nb_car);
		//}

		++nb_car;
		return;
	}

	for (int i = pos; i < taille; ++i)
	{
		int tmp = tab[pos];
		tab[pos] = tab[i];
		tab[i] = tmp;

		gen_carre(tab, taille, ordre, pos + 1);

		tmp = tab[pos];
		tab[pos] = tab[i];
		tab[i] = tmp;
	}
}

void gen_carres(int ordre)
{
	int taille = ordre * ordre;
	int tab[taille];

	// init
	for (int j = 0; j < taille; ++j)
	{
		tab[j] = j + 1;
	}

	gen_carre(tab, taille, ordre, 0);
}



int main(int N, char* T[])
{
	int ordre = 0;

	if (N < 2)
	{
		printf("Argument: ordre du carré.\n");
		return 1;
	}

	ordre = atoi(T[1]);

	if (ordre <= 0)
	{
		printf("Golmon vas !\n");
		return 2;
	}

	gen_carres(ordre);

	/*
	int tab[9];
	tab[0] = 2;
	tab[1] = 7;
	tab[2] = 6;
	tab[3] = 9;
	tab[4] = 5;
	tab[5] = 1;
	tab[6] = 4;
	tab[7] = 3;
	tab[8] = 8;

	is_magique(tab, 3);
	*/

	return 0;
}
