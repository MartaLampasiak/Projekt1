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


	//wype³nianie tablicy
	for (int i = 0; i < wiersz; ++i)
	{
		tablica[i] = new int[rozmiar];
		for (int j = 0; j < rozmiar; ++j)
			tablica[i][j] = rand();
		
	}


	//wyswietlanie tablicy
	for (int i = 0; i < wiersz; ++i)
	{
		for (int j = 0; j < rozmiar; ++j)
		{
			//std::cout << tablica[i][j] << " ";
		}
		//std::cout << "\n";
	}

	
start = clock();

	for (int i = 0; i < wiersz; i++)
	{	
		
		//bubbleSort(tablica[i], rozmiar);
		//insertionSort(tablica[i], rozmiar);
		//mergeSort(tablica[i],tablica_pomocnicza, 0, rozmiar - 1);
		//heapSort(tablica[i], rozmiar);
		//quickSort(tablica[i], 0, rozmiar - 1, 1);
		//IntroSort(tablica[i], 0,rozmiar - 1, 2*(log(rozmiar)/log(2)));
		//sortujOdwrotnie(tablica[i], 0, rozmiar - 1, 1);
	}

	
	/*for (int i = 0; i < wiersz; ++i)
	{
	for (int j = 0; j < rozmiar; ++j)
		quickSort(tablica[i], 0, rozmiar - 1, 1);
	}*/
	
	koniec = clock();
	roznica = (koniec - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Czas wykonania: " << roznica << "\n";


	//wyswietlanie tablicy posortowanej
	std::cout << "Posortowana" << "\n";
	for (int i = 0; i < wiersz; ++i)
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
	for (int i = 0; i < wiersz; ++i)
		delete [] tablica[i];
	delete[] tablica;
	tablica = NULL;

	system("pause");
	return 0;
}


