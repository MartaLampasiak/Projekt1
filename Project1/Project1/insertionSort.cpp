#include "insertionSort.hpp"

void insertionSort(int tab[], int n)
{
	int wstawiany;
	int j;
	for (int i = 1; i < n; ++i)
	{
		wstawiany = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > wstawiany)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = wstawiany;
	}
}