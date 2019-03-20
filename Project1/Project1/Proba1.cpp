#include <iostream>
#include <cstdlib>
//#include <time.h>
#include <ctime>

#include "insertionSort.hpp"
#include "bubbleSort.hpp"
#include "mergeSort.hpp"
#include "quickSort.hpp"


int main()
{
	double roznica;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(5);
	clock_t start, koniec;

	int rozmiar;

	std::cout << "Podaj rozmiar tablicy: " << "\n";
	std::cin >>  rozmiar;

	int *tablica = new int[rozmiar];



	for (int i = 0; i < rozmiar; ++i)
	{
		tablica[i] = rand();
		//std::cout << tablica[i] << " ";
	}

	start = clock();
	//bubbleSort(tablica, rozmiar);
	//insertionSort(tablica, rozmiar);
	//quickSort(tablica, 0, rozmiar - 1);
	

	koniec = clock();
	roznica = (koniec - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania: " << roznica << "\n";

	std::cout << "posortowana: " << "\n";
	for (int i = 0; i < rozmiar; ++i)
	{
		std::cout << tablica[i] << " ";
	}

	delete[] tablica;
	system("pause");
	return 0;
}


