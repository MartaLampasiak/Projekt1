//#include "funkcjeDodatkowe.hpp"
//#include <iostream>
//
//
//
//bool czyPosortowanaRosnaco(int **tab, int wiersz, int rozmiar)
//{
//	for (int i = 0; i < wiersz - 1; ++i)
//	{
//		for (int j = 0; j < rozmiar - 1; ++j)
//		{
//			if (tab[i][j] > tab[i][j + 1])
//				return 0;
//		}
//	}
//	return 1;
//}
//
//bool czyPosortowanaMalejaco(int **tab, int wiersz, int rozmiar)
//{
//	for (int i = 0; i < wiersz - 1; ++i)
//	{
//		for (int j = 0; j < rozmiar - 1; ++j)
//		{
//			if (tab[i][j] < tab[i][j + 1])
//				return 0;
//		}
//	}
//	return 1;
//}


//Posortowanie tablicy odwrotnie
//od najwiêkszego do najmniejszego - wykorzystanie quicksorta


//int podzielnaPartycjeOdwrotne(int tab[], int left, int right)
//{
//	int i, j, p, pivot, temp;
//
//	p = (left + right) / 2;
//	pivot = tab[p];
//	tab[p] = tab[right];
//
//	for (j = i = left; i < right; ++i)
//	{
//		if (tab[i] > pivot)
//		{
//			temp = tab[j];
//			tab[j] = tab[i];
//			tab[i] = temp;
//			j++;
//		}
//	}
//
//	//wszystko posortowane - wymieniamy pivota z elementem j-tym
//	tab[right] = tab[j];
//	tab[j] = pivot;
//	return j;
//}
//
//
//
//void SortujOdwrotnie(int tab[], int left, int right, double ilePosortowane)
//{
//	int j = podzielnaPartycjeOdwrotne(tab, left, right*ilePosortowane);
//
//	if (left < j - 1)
//		SortujOdwrotnie(tab, left, j - 1, 1);
//	if (j + 1 < right)
//		SortujOdwrotnie(tab, j + 1, right*ilePosortowane, 1);
//
//}