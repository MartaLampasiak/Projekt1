#pragma once

#include "quickSort.hpp"
#include "heapSort.hpp"
#include "insertionSort.hpp"


/*	Procedura sortowania introspektywnego.		*
 *	Argumenty funkcji:							*
 *		tab[] - tablica							*
 *		left - lewy indeks tablicy			    *
 *		right - rozmiar tablicy				    *
 *		MaxRekurencji - przyjeta glebokosc		*
						wywolan rekurencyjnych  */
				
template <typename T>
void IntroSort(T tab[], int left, int right, int MaxRekurencji)
{
	if (left < right)
	{
		if (MaxRekurencji == 0)
		{
			heapSortintro(tab,left, right);	
		}
			int pivotIndex = podzielnaPartycje(tab, left, right-1);
			IntroSort(tab, left, pivotIndex, MaxRekurencji - 1);
			IntroSort(tab, pivotIndex + 1, right, MaxRekurencji - 1);	
	}
}

/*	Przeciazenie procedury IntroSort			*
 *  w celu podania glebokosci rekurencji		*
 *	Argumenty funkcji:							*
 *		tab[] - tablica							*
 *		right - rozmiar tablicy				    */

template <typename T>
void IntroSort(T tab[], int right)
{
	int MaxRekurencji = (2 * floor(log2(right))); //wartosc maksymalnej glebokosci rekurencji
	IntroSort(tab, 0, right, MaxRekurencji);
}

