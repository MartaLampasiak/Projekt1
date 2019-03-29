#pragma once

//void przywrocKopiec(int tab[], int k, int rozmiar);
//void heapSort(int tab[], int rozmiar);

//template <typename T>
//void przywrocKopiec(T tab[], int k, int rozmiar)
//{
//	int i, j;
//	i = tab[k - 1];
//	while (k <= rozmiar / 2)
//	{
//		j = 2 * k;
//		if ((j < rozmiar) && tab[j - 1] < tab[j])
//			j++;
//		if (i >= tab[j - 1])
//			break;
//		tab[k - 1] = tab[j - 1];
//		k = j;
//	}
//	tab[k - 1] = i;
//}
//
//template <typename T>
//void heapSort(T tab[], int rozmiar)
//{
//	int k, zamiana;
//	for (int k = rozmiar / 2; k > 0; --k)
//		przywrocKopiec(tab, k, rozmiar);
//	do {
//		zamiana = tab[0];
//		tab[0] = tab[rozmiar - 1];
//		tab[rozmiar - 1] = zamiana;
//		rozmiar--;
//		przywrocKopiec(tab, 1, rozmiar);
//	} while (rozmiar > 1);
//
//}

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


