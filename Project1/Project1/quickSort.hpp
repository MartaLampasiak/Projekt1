#pragma once

//// left - indeks pierwszego elementu, right - indeks ostatniego elementu
//int podzielnaPartycje(int tab[], int left, int right);
////void quickSort(int tab[], int left, int right);
//void quickSort(int tab[], int left, int right, double ilePosortowane);


template <typename T>
int podzielnaPartycje(T tab[], int left, int right)
{
	int i, j, p;
	T pivot, temp;

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

	//wszystko posortowane - wymieniamy pivota z elementem j - tym
	tab[right] = tab[j];
	tab[j] = pivot;
	return j;
}


template <typename T>
void quickSort(T tab[], int left, int right, double ilePosortowane)
{
	int pivotIndex = podzielnaPartycje(tab, left, right*ilePosortowane);

	if (left < pivotIndex - 1)
		quickSort(tab, left, pivotIndex - 1, 1.0);
	if (pivotIndex + 1 < right)
		quickSort(tab, pivotIndex + 1, right*ilePosortowane, 1.0);

}