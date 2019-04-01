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
//#include "tester1x1.hpp"

int main()
{

	//	int rozmiar;
	//
	//	std::cout << "Podaj rozmiar tablicy: " << "\n";
	//	std::cin >> rozmiar;
	//
	//	int **tablica = new int *[wiersz];
	//	int *tablica_pomocnicza = new int[rozmiar]; //do merge
	//
	//
	//	//wype³nianie tablicy
	//	for (int i = 0; i < wiersz; ++i)
	//	{
	//		tablica[i] = new int[rozmiar];
	//		for (int j = 0; j < rozmiar; ++j)
	//			tablica[i][j] = rand();
	//
	//	}
	//
	//
	//	//wyswietlanie tablicy
	//	for (int i = 0; i < wiersz; ++i)
	//	{
	//		for (int j = 0; j < rozmiar; ++j)
	//		{
	//			//std::cout << tablica[i][j] << " ";
	//		}
	//		//std::cout << "\n";
	//	}
	//
	//
	//	start = clock();
	//
	//	for (int i = 0; i < wiersz; i++)
	//	{
	//
	//		//bubbleSort(tablica[i], rozmiar);
	//		//insertionSort(tablica[i], rozmiar);
	//		//mergeSort(tablica[i],tablica_pomocnicza, 0, rozmiar - 1);
	//		//heapSort(tablica[i], rozmiar);
	//		//quickSort(tablica[i], 0, rozmiar - 1, 1);
	//		IntroSort(tablica[i], 0,rozmiar - 1, 2*(log(rozmiar)/log(2)));
	//		//sortujOdwrotnie(tablica[i], 0, rozmiar - 1, 1);
	//	}
	//
	//
	//	/*for (int i = 0; i < wiersz; ++i)
	//	{
	//	for (int j = 0; j < rozmiar; ++j)
	//		quickSort(tablica[i], 0, rozmiar - 1, 1);
	//	}*/
	//
	//	koniec = clock();
	//	roznica = (koniec - start) / (double)CLOCKS_PER_SEC;
	//	std::cout << "Czas wykonania: " << roznica << "\n";
	//
	//
	//	//wyswietlanie tablicy posortowanej
	//	std::cout << "Posortowana" << "\n";
	//	for (int i = 0; i < wiersz; ++i)
	//	{
	//		for (int j = 0; j < rozmiar; ++j)
	//		{
	//			//std::cout << tablica[i][j] << " ";
	//		}
	//		//std::cout << "\n";
	//	}
	//
	//	//XOR 
	//	if (czyPosortowanaRosnaco(tablica, wiersz, rozmiar) || czyPosortowanaMalejaco(tablica, wiersz, rozmiar))
	//		std::cout << "\nPoprawnie posortowana" << "\n";
	//	else
	//		std::cout << "\nTablica nieposortowana" << "\n";
	//
	//
	//
	//	// zniszczenie tablicy
	//	for (int i = 0; i < wiersz; ++i)
	//		delete[] tablica[i];
	//	delete[] tablica;
	//	tablica = NULL;
	//
	//	system("pause");
	//	return 0;
	//}

	//***********************************************************************************************
	int wiersz = 100;
	int rozmiaryTablic[5] = {10000, 50000, 100000, 500000, 1000000 };
	double wstepnePosortowanie[8] = { -1, 1, 0.25, 0.5 , 0.75, 0.95, 0.99, 0.997 };
	std::fstream plik;
	//int rozmiar = 0;
	//int posortowanie = 0;
	int **tablica = new int *[wiersz];
	for (int rozmiar = 0; rozmiar < 5; rozmiar++)
	{
		std::cout << "Kolejny rozmiar ********* \n";
		for (int posortowanie = 0; posortowanie < 8; ++posortowanie)
		{
			std::cout << "Kolejny stopien posortowania\n";
			// utworzenie i wype³nienie 
			for (int i = 0; i < wiersz; ++i)
			{
				std::cout << "Kolejna tablica\n";
				tablica[i] = new int[rozmiaryTablic[rozmiar]];
				for (int j = 0; j < rozmiaryTablic[rozmiar] - 1; ++j)
					tablica[i][j] = rand();
			}
			//std::cout << posortowanie << " \n";

			//warunek wstêpnego sortowania odwrotnego
			if (wstepnePosortowanie[posortowanie] == -1.0)
			{
				for (int i = 0; i < wiersz - 1; ++i)
				{
					sortujOdwrotnie(tablica[i], 0, rozmiaryTablic[rozmiar] - 1); // wstêpne odwrotne sortowanie
					//std::cout << i;
				}
			}

			//warunek wstêpnego sortowania z parametrem
			else if ((wstepnePosortowanie[posortowanie] != 1) && (wstepnePosortowanie[posortowanie] > 0))
			{
				for (int i = 0; i < wiersz - 1; ++i)
				{
					quickSort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, wstepnePosortowanie[posortowanie]); //wstêpne sortowanie
					//std::cout << i;
				}
			}
			
			//w³asciwe sortowanie
			for (int i = 0; i < wiersz; ++i)
			{
				int *tablica_pomocnicza = new int[rozmiaryTablic[rozmiar]];
				auto start = std::chrono::system_clock::now();

				//Tu wpisujemy sortowanie
				//quickSort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, 1); //czwarty parametr to stopieñ posortowania w % (0-1)
				mergeSort(tablica[i],tablica_pomocnicza, 0, rozmiaryTablic[rozmiar] - 1);
				//IntroSort(tablica[i], rozmiaryTablic[rozmiar], (2 * log2(rozmiar)));
				//IntroSort(tablica[i],  rozmiaryTablic[rozmiar]);
				//IntroSort(tablica[i], rozmiaryTablic[rozmiar]);
				//introsort(tablica[i],0, rozmiaryTablic[rozmiar]);
				//heapSort(tablica[i], rozmiaryTablic[rozmiar]);
				auto end = std::chrono::system_clock::now();

				//sprawdzenie poprawnoœci posortowania
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

				delete[] tablica_pomocnicza;
				tablica_pomocnicza = NULL;
			}



			for (int i = 0; i < wiersz - 1; ++i)
			{
				delete[] tablica[i]; //zwolnienie pamiêci
			}
			//delete[] tablica;
			//tablica = NULL;
			//std::cout << << " \n";
		}
	}

	delete[] tablica;
	tablica = NULL;

	system("pause");
	return 0;


}