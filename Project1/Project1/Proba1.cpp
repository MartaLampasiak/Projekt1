#include <iostream>
#include <cstdlib>
#include <ctime>

#include "funkcjeDodatkowe.hpp"
#include "bubbleSort.hpp"
#include "insertionSort.hpp"
#include "quickSort.hpp"
#include "mergeSort.hpp"
#include "heapSort.hpp"
#include "IntroSort.hpp"

int main()
{
	double roznica;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(5);
	clock_t start, koniec;

	int wiersz = 100;
	int rozmiar;

	std::cout << "Podaj rozmiar tablicy: " << "\n";
	std::cin >>  rozmiar;
	
	int **tablica = new int *[wiersz];
	int *tablica_pomocnicza = new int[rozmiar]; //do merge


	for (int i = 0; i < wiersz - 1; ++i)
	{
		tablica[i] = new int[rozmiar];
		for (int j = 0; j <rozmiar; ++j)
			tablica[i][j] = rand();
		
	}

	for (int i = 0; i < wiersz - 1; ++i)
	{
		for (int j = 0; j < rozmiar; ++j)
		{
			//std::cout << tablica[i][j] << " ";
		}
		//std::cout << "\n";
	}

	start = clock();

	for (int i = 0; i < wiersz - 1; ++i)
	{	
		//bubbleSort(tablica[i], rozmiar);
		//insertionSort(tablica[i], rozmiar);
		//mergeSort(tablica[i],tablica_pomocnicza, 0, rozmiar - 1);
		//heapSort(tablica[i], rozmiar);
		//quickSort(tablica[i], 0, rozmiar-1, 0.25);
		//quickSort(tablica[i], 0, rozmiar - 1, 1);
		//IntroSort(tablica[i], 0,rozmiar-1, 2*(log(rozmiar)/log(2)));
		sortujOdwrotnie(tablica[i], 0, rozmiar - 1, 1);
	}
	
	koniec = clock();
	roznica = (koniec - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania: " << roznica << "\n";

	std::cout << "Posortowana" << "\n";
	for (int i = 0; i < wiersz - 1; ++i)
	{
		for (int j = 0; j < rozmiar; ++j)
		{
			std::cout << tablica[i][j] << " ";
		}
		std::cout << "\n";
	}
		
	//EXOR 1 i 1 = 0, 0 i 0 = 0, reszta 1
	if (czyPosortowanaRosnaco(tablica,wiersz, rozmiar) ^ czyPosortowanaMalejaco(tablica, wiersz, rozmiar))
		std::cout << "\nPoprawnie posortowana" << "\n";
	else
		std::cout << "\nTablica nieposortowana" << "\n";



// zniszczenie tablicy
	for (int i = 0; i < wiersz - 1; ++i)
		delete [] tablica[i];
	delete[] tablica;
	tablica = NULL;

	system("pause");
	return 0;
}


