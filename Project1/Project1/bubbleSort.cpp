#include "bubbleSort.hpp"


void bubbleSort(int tab[], int n)
{
	int temp;
	bool z = 0;
	do
	{
		z = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				z = 1;
			}
		}
	} while (z);
}
