#include "quickSort.hpp"

void quickSort(int tab[], int left, int right)
{
	int i, j, p, pivot, temp;

	p = (left + right) / 2;
	pivot = tab[p];
	tab[p] = tab[right];

	for (j = i = left; i < right; ++i)
	{
		if (tab[i] < pivot)
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

	if (left < j - 1)
		quickSort(tab, left, j - 1);
	if (j + 1 < right)
		quickSort(tab, j + 1, right);

}