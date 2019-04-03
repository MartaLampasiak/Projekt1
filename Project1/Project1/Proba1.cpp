#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

#include "funkcjeDodatkowe.hpp"
#include "bubbleSort.hpp"
#include "insertionSort.hpp"
#include "quickSort.hpp"
#include "mergeSort.hpp"
#include "heapSort.hpp"
#include "IntroSort.hpp"
#include "tester.hpp"


int main()
{
	// warunki do testow
	int wiersz = 100;
	int rozmiaryTablic[5] = {10000, 50000, 100000, 500000, 1000000 };
	double wstepnePosortowanie[8] = { -1, 1, 0.25, 0.5 , 0.75, 0.95, 0.99, 0.997 };

	std::fstream plik;

	int **tablica = new int *[wiersz];
	for (int rozmiar = 0; rozmiar < 5; rozmiar++)
	{
		std::cout << "Tablica " << rozmiaryTablic[rozmiar] << "\n";
		for (int posortowanie = 0; posortowanie < 8; ++posortowanie)
		{
			std::cout << posortowanie+1 << ". Sortowanie dla warunku " << wstepnePosortowanie[posortowanie] << "\n";


			// utworzenie i wype³nienie tablicy
			for (int i = 0; i < wiersz; ++i)
			{
				tablica[i] = new int[rozmiaryTablic[rozmiar]];
				for (int j = 0; j < rozmiaryTablic[rozmiar] - 1; ++j)
					tablica[i][j] = rand();
			}


			//warunek wstêpnego sortowania odwrotnego
			if (wstepnePosortowanie[posortowanie] == -1.0)
			{
				for (int i = 0; i < wiersz - 1; ++i)
				{
					sortujOdwrotnie(tablica[i], 0, rozmiaryTablic[rozmiar] - 1); // wstêpne odwrotne sortowanie
				}
			}


			//warunek wstêpnego sortowania z parametrem
			else if ((wstepnePosortowanie[posortowanie] != 1) && (wstepnePosortowanie[posortowanie] > 0))
			{
				for (int i = 0; i < wiersz - 1; ++i)
				{
					quickSort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, wstepnePosortowanie[posortowanie]); //wstêpne sortowanie
				}
			}
			

			//w³asciwe sortowanie
			for (int i = 0; i < wiersz; ++i)
			{
				//tablica pomocnicza potrzebna do mergeSort'a
				//int *tablica_pomocnicza = new int[rozmiaryTablic[rozmiar]];

				auto start = std::chrono::system_clock::now();

				//Tu wpisujemy dany algorytm sortowania
				quickSort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, 1); //ostatni parametr to czesc tablicy, ktora ma byc posortowana (wartosc od 0-1)
				//mergeSort(tablica[i],tablica_pomocnicza, 0, rozmiaryTablic[rozmiar] - 1);
				//IntroSort(tablica[i], rozmiaryTablic[rozmiar]);
				
				auto end = std::chrono::system_clock::now();


				//sprawdzenie poprawnoœci posortowania i zapis do pliku
				if (czyPosortowanaRosnacoJedna(tablica[i], rozmiaryTablic[rozmiar]) == 1)
				{
					std::chrono::duration<double> elapsed_seconds = end - start;
					plik.open("plik.txt", std::ios::out | std::ios::app);
					if (plik.good() == true)
					{
						plik << i << " " << rozmiaryTablic[rozmiar] << " " << wstepnePosortowanie[posortowanie] << " ";
						plik << elapsed_seconds.count() << std::endl;
						plik.close();
					}
				}

				//jeœli Ÿle posortowane
				else if (czyPosortowanaRosnacoJedna(tablica[i], rozmiaryTablic[rozmiar]) == 0)
				{
					plik.open("plik.txt", std::ios::out | std::ios::app);
					if (plik.good() == true)
					{
						plik << "\nTablica nieposortowana" << "\n";
						plik.close();
					}
				}


				//zwolnienie pamieci dla tablicy pomocniczej w przypadku wywolania mergeSort'a
				//delete[] tablica_pomocnicza;
				//tablica_pomocnicza = NULL;
			}



			for (int i = 0; i < wiersz - 1; ++i)
			{
				delete[] tablica[i]; //zwolnienie pamiêci
			}

		}
	}

	delete[] tablica;
	tablica = NULL;

	system("pause");
	return 0;


}