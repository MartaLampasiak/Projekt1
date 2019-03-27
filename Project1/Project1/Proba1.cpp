#include <iostream>
#include <cstdlib>
#include <ctime>

#include "funkcjeDodatkowe.hpp"
#include "bubbleSort.hpp"
#include "insertionSort.hpp"
#include "quickSort.hpp"
#include "mergeSort.hpp"
#include "heapSort.hpp"


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
	int *tablica_pomocnicza = new int[rozmiar]; //do merge
	

	for (int i = 0; i < rozmiar; ++i)
	{
		tablica[i] = rand();
		//std::cout << tablica[i] << " ";
	}

	start = clock();
	//bubbleSort(tablica, rozmiar);
	//insertionSort(tablica, rozmiar);
	quickSort(tablica, 0, rozmiar-1);

	//mergeSort(tablica,tablica_pomocnicza, 0, rozmiar - 1);
	//heapSort(tablica, rozmiar);

	koniec = clock();
	roznica = (koniec - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania: " << roznica << "\n";

	std::cout << "Posortowana" << "\n";
	for (int i = 0; i < rozmiar; ++i)
	{
		//std::cout << tablica[i] << " ";
	}
		

	if (czyPosortowanaRosnaco)
		std::cout << "\nPoprawnie posortowana rosnaco" << "\n";

	delete[] tablica;
	system("pause");
	return 0;
}


