#include <iostream>
#include <cstdlib>
#include <time.h>

#include "insertionSort.hpp"
#include "bubbleSort.hpp"
#include "mergeSort.hpp"
#include "quickSort.hpp"


int main()
{
	int rozmiar;

	std::cout << "Podaj rozmiar tablicy: " << "\n";
	std::cin >>  rozmiar;

	int *tablica = new int[rozmiar];



	for (int i = 0; i < rozmiar; ++i)
	{
		tablica[i] = rand();
		std::cout << tablica[i] << " ";
	}


	//bubbleSort(tablica, rozmiar);
	//insertionSort(tablica, rozmiar);
	quickSort(tablica, 0, rozmiar - 1);

	std::cout << "posortowana: " << "\n";
	for (int i = 0; i < rozmiar; ++i)
	{
		std::cout << tablica[i] << " ";
	}

	delete[] tablica;
	system("pause");
}


