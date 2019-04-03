#pragma once

/*	Funkcja dzielaca tablice na partycje. *
 *	Zwraca indeks pivota.				  *
 *	Argumenty:							  *
 *		tab[] - tablica					  *
 *		left - lewy indeks tablicy        *
 *		right - prawy indeks tablicy	  */
template <typename T>
int podzielnaPartycje(T tab[], int left, int right)
{
	int i, j, pivotIndex;
	T pivot, temp;

	pivotIndex = (left + right) / 2;
	pivot = tab[pivotIndex];
	tab[pivotIndex] = tab[right]; // zamiana pivota z ostatnim elementem 

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

	// podzial na partycje zakonczony
	// wymieniamy pivota z elementem j - tym
	tab[right] = tab[j];
	tab[j] = pivot;
	return j; //zwracamy aktualny indeks pivota
}


/*	Procedura sortowania szybkiego.							 *
 *	Argumenty funkcji:										 *
 *		tab[] - tablica										 *
 *		left - lewy indeks tablicy							 *
 *		right - prawy indeks tablicy						 *
 *		ilePosortowane - parametr okreslajacy czesc tablicy  *
 *						 wstepnie posortowanej, wartosc		 *
 *						 z zakresu 0-1						 */
template <typename T>
void quickSort(T tab[], int left, int right, double ilePosortowane)
{
	int pivotIndex = podzielnaPartycje(tab, left, T (right*ilePosortowane));

	if (left < pivotIndex - 1)
		quickSort(tab, left, pivotIndex - 1, 1);
	if (pivotIndex + 1 < right)
		quickSort(tab, pivotIndex + 1, T (right*ilePosortowane), 1);

}