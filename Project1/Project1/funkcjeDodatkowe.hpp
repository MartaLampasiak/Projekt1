#pragma once

//bool czyPosortowanaRosnaco(int **tab, int wiersz, int rozmiar);
//bool czyPosortowanaMalejaco(int **tab, int wiersz, int rozmiar);
//int podzielnaPartycjeOdwrotne(int tab[], int left, int right);
//void SortujOdwrotnie(int tab[], int left, int right, double ilePosortowane);
#include <iostream>


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

//Sortowanie odwrotne quicksortem
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

	//wszystko posortowane - wymieniamy pivota z elementem j-tym
	tab[right] = tab[j];
	tab[j] = pivot;
	return j;
}

template <typename T>
void sortujOdwrotnie(T tab[], int left, int right)
{
	int pivotIndex = podzielnaPartycjeOdwrotne(tab, left, right);

	if (left < pivotIndex - 1)
		sortujOdwrotnie(tab, left, pivotIndex - 1);
	if (pivotIndex + 1 < right)
		sortujOdwrotnie(tab, pivotIndex + 1, right);
}
