#pragma once


template <typename T>
void przywrocMaxKopiec(T tab[], int parentIndex, int rozmiar)
{
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

template <typename T>
void heapSort(T tab[], int rozmiar)
{	// firstNode - pierwszy wezel, ktory nie jest lisciem (gdzie leaf to ostatni element tablicy)
	for (int firstNode = (rozmiar / 2 - 1); firstNode >= 0; firstNode--)
		przywrocMaxKopiec(tab, firstNode, rozmiar);
	for (int leaf = rozmiar - 1; leaf >= 0; leaf--)
	{
		T temp = tab[0];
		tab[0] = tab[leaf];
		tab[leaf] = temp;
		przywrocMaxKopiec(tab, 0, leaf);
	}
}






template <typename T>
void przywrocMaxKopiecintro(T tab[], int parentIndex, int rozmiar)
{
	int largest = parentIndex;
	int leftChild = 2 * parentIndex + 1;
	int rightChild = 2 * parentIndex + 2;

	if ((leftChild < rozmiar) && (tab[leftChild] > tab[largest]))
		largest = leftChild;

	if ((rightChild < rozmiar) && (tab[rightChild] > tab[largest]))
		largest = rightChild;

	if (largest != parentIndex)
	{
		T temp = tab[parentIndex];
		tab[parentIndex] = tab[largest];
		tab[largest] = temp;
		przywrocMaxKopiecintro(tab, largest, rozmiar);
	}
}

template <typename T>
void heapSortintro(T tab[],int left, int rozmiar)
{	// firstNode - pierwszy wezel, ktory nie jest lisciem (gdzie leaf to ostatni element tablicy)
	for (int firstNode = (rozmiar / 2 - 1); firstNode >= left; firstNode--)
		przywrocMaxKopiecintro(tab, firstNode, rozmiar);
	for (int leaf = rozmiar - 1; leaf >= left; leaf--)
	{
		T temp = tab[left];
		tab[left] = tab[leaf];
		tab[leaf] = temp;
		przywrocMaxKopiecintro(tab, left, leaf);
	}
}