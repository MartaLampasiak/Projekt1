#include "IntroSort.hpp"
#include "quickSort.hpp"
#include "heapSort.hpp"
#include "insertionSort.hpp"
#include <math.h>

void IntroSort(int tab[], int rozmiar, double MaxRekurencji)
{
	int i = podzielnaPartycje(tab, 0, rozmiar - 1);
	/*if (MaxRekurencji <= 0)
	{
		heapSort(tab, rozmiar);
		return;
	}
	i = podzielnaPartycje(tab, 0, rozmiar - 1);

	if (i > 9)
		IntroSort(tab, i, MaxRekurencji - 1);
	if(rozmiar-i-1 > 9)
		IntroSort(tab+i+1, rozmiar-1-i, MaxRekurencji - 1);*/

	if (rozmiar <= 1)
		return;
	else if (MaxRekurencji = 0)
			heapSort(tab, rozmiar);
	else
	{
		IntroSort(tab, i, MaxRekurencji - 1);
		IntroSort(tab, rozmiar - i - 1, MaxRekurencji - 1);
	}

}

void Hybrid_Introsort(int tab[], int rozmiar)
{
	IntroSort(tab, rozmiar, (int(2 * log(double(rozmiar)))));
	insertionSort(tab, rozmiar);

}