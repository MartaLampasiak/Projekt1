#pragma once

/*	Procedura przywracajaca kopiec.		  *
 *	Argumenty:							  *
 *		tab[] - tablica					  *
 *		parentIndex - indeks rodzica      *
 *		rozmiar - rozmiar tablicy		  */
template <typename T>
void przywrocMaxKopiec(T tab[], int parentIndex, int rozmiar)
{	
	// zapis elementow drzewa za pomoca indeksow tablicy
	int largest = parentIndex;
	int leftChild = 2 * parentIndex + 1;
	int rightChild = 2 * parentIndex + 2;

	if ((leftChild < rozmiar) && (tab[leftChild] > tab[largest]))
		largest = leftChild;

	if ((rightChild < rozmiar) && (tab[rightChild] > tab[largest]))
		largest = rightChild;

	if (largest!= parentIndex)	
	{
		T temp = tab[parentIndex];
		tab[parentIndex] = tab[largest];
		tab[largest] = temp;
		przywrocMaxKopiec(tab, largest, rozmiar);
	}
}

/*	Procedura sortowania przez kopcowanie.					 *
 *	Argumenty funkcji:										 *
 *		tab[] - tablica										 *
 *		rozmiar - rozmiar tablicy						 	 */
template <typename T>
void heapSort(T tab[], int rozmiar)
{	// firstNode - pierwszy wezel, ktory nie jest lisciem (gdzie leaf to ostatni element tablicy)
	for (int firstNode = (rozmiar / 2 - 1); firstNode >= 0; firstNode--)
		przywrocMaxKopiec(tab, firstNode, rozmiar);

	for (int leaf = rozmiar - 1; leaf >= 0; leaf--)
	{
		// wymiana korzenia drzewa z ostatnim elementem tablicy - lisciem
		T temp = tab[0];
		tab[0] = tab[leaf];
		tab[leaf] = temp;
		przywrocMaxKopiec(tab, 0, leaf);
	}
}

/*	Procedura sortowania przez kopcowanie, potrzebna do		 *
 *  sortowania introspektywnego								 *
 *	Argumenty funkcji:										 *
 *		tab[] - tablica										 *
 *		left - pierwszy element tablicy						 *
 *		rozmiar - rozmiar tablicy						 	 */
template <typename T>
void heapSortintro(T tab[],int left, int rozmiar)
{	
	for (int firstNode = (rozmiar / 2 - 1); firstNode >= left; firstNode--)
		przywrocMaxKopiec(tab, firstNode, rozmiar);

	for (int leaf = rozmiar - 1; leaf >= left; leaf--)
	{
		T temp = tab[left];
		tab[left] = tab[leaf];
		tab[leaf] = temp;
		przywrocMaxKopiec(tab, left, leaf);
	}
}