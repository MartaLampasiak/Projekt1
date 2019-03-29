#pragma once

//void insertionSort(int tab[], int n);

template <typename T>
void insertionSort(T tab[], int n)
{
	T wstawiany;
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
