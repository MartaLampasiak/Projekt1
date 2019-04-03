#pragma once
#include <iostream>

/*	Procedura sprawdzajaca posortowanie rosnace		*
 *	tablicy dwuwymiarowej. Wykorzystywana do testow.*/
template <typename T>
bool czyPosortowanaRosnaco(T **tab, int wiersz, int rozmiar)
{
	for (int i = 0; i < wiersz - 1; ++i)
	{
		for (int j = 0; j < rozmiar - 1; ++j)
		{
			if (tab[i][j] > tab[i][j + 1])
				return 0;
		}
	}
	return 1;
}

/*	Procedura sprawdzajaca posortowanie rosnace		*
 *	tablicy jednowymiarowej.						*/
template <typename T>
bool czyPosortowanaRosnacoJedna(T tab[], int rozmiar)
{
		for (int j = 0; j < rozmiar - 1; ++j)
		{
			if (tab[j] > tab[j + 1])
			{
				std::cout << "NIEPOSORTOWANE!\n";
				return 0;
			}
				
		}
	
	return 1;
}


/*	Procedura sprawdzajaca posortowanie malejace		*
 *	tablicy dwuwymiarowej. Wykorzystywana do testow		*
 *  procedury sortujacej tablice odwrotnie.				*/
template <typename T>
bool czyPosortowanaMalejaco(T **tab, int wiersz, int rozmiar)
{
	for (int i = 0; i < wiersz - 1; ++i)
	{
		for (int j = 0; j < rozmiar - 1; ++j)
		{
			if (tab[i][j] < tab[i][j + 1])
				return 0;
		}
	}
	return 1;
}

/*	Funkcja dzielaca tablice na partycje     *
 *	odwrotne (z lewej strony pivota elementy *
 *  wieksze od niego. Zwraca indeks pivota.  *
 *	Argumenty:							     *
 *		tab[] - tablica					     *
 *		left - lewy indeks tablicy           *
 *		right - prawy indeks tablicy	     */
template <typename T>
int podzielnaPartycjeOdwrotne(T tab[], int left, int right)
{
	int i, j, p;
	T pivot, temp;

	p = (left + right) / 2;
	pivot = tab[p];
	tab[p] = tab[right];

	for (j = i = left; i < right; ++i)
	{
		if (tab[i] > pivot)
		{
			temp = tab[j];
			tab[j] = tab[i];
			tab[i] = temp;
			j++;
		}
	}

	tab[right] = tab[j];
	tab[j] = pivot;
	return j;
}

/*	Procedura odwrotnego sortowania szybkiego.				 *
 *	Argumenty funkcji:										 *
 *		tab[] - tablica										 *
 *		left - lewy indeks tablicy							 *
 *		right - prawy indeks tablicy						 */
template <typename T>
void sortujOdwrotnie(T tab[], int left, int right)
{
	int pivotIndex = podzielnaPartycjeOdwrotne(tab, left, right);

	if (left < pivotIndex - 1)
		sortujOdwrotnie(tab, left, pivotIndex - 1);
	if (pivotIndex + 1 < right)
		sortujOdwrotnie(tab, pivotIndex + 1, right);
}
