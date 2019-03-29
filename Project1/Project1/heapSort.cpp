//#include "heapSort.hpp"

//void przywrocKopiec(int tab[], int k, int rozmiar)
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
//
//void heapSort(int tab[], int rozmiar)
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