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

int main()
{
	double roznica;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(5);
	clock_t start, koniec;

	int wiersz = 1;
	std::fstream plik;
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
	int rozmiaryTablic[5] = {1000000,500000, 100000, 50000, 10000 };
	double wstepnePosortowanie[8] = { -1, 1, 0.25, 0.5 , 0.75, 0.95, 0.99, 0.997};

	//int rozmiar = 0;
	//int posortowanie = 0;
	int **tablica = new int *[wiersz];
	for (int rozmiar = 0; rozmiar < 1; rozmiar++)
	{
		std::cout << "Kolejny rozmiar ********* \n";
		for (int posortowanie = 0; posortowanie < 5; ++posortowanie)
		{
			std::cout << "Kolejny stopien posortowania\n";
			for (int i = 0; i < wiersz; ++i)
			{
				std::cout << "Kolejna tablica\n";
				tablica[i] = new int[rozmiaryTablic[rozmiar]];
				for (int j = 0; j < rozmiaryTablic[rozmiar] - 1; ++j)
					tablica[i][j] = rand();

			}
			//std::cout << posortowanie << " \n";






			if (wstepnePosortowanie[posortowanie] == -1.0)
			{
				for (int i = 0; i < wiersz; ++i) 
				{
					sortujOdwrotnie(tablica[i], 0, rozmiaryTablic[rozmiar] - 1); // wstêpne odwrotne sortowanie
					//std::cout << i;
				}
			}
			else if ((wstepnePosortowanie[posortowanie] != 1) && (wstepnePosortowanie[posortowanie] > 0))
				for (int i = 0; i < wiersz; ++i)
				{
					quickSort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, wstepnePosortowanie[posortowanie]); //wstêpne sortowanie
					//std::cout << i;
				}



			for (int i = 0; i < wiersz; ++i)
			{
				//int *tablica_pomocnicza = new int[rozmiaryTablic[rozmiar]];
				//start = clock();
				auto start = std::chrono::system_clock::now();
				//Tu wpisujemy sortowanie
				//quickSort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, 1); //czwarty parametr to stopieñ posortowania w % (0-1)
				//mergeSort(tablica[i],tablica_pomocnicza, 0, rozmiaryTablic[rozmiar] - 1);
				if (IntroSort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, 2 * (log(rozmiar) / log(2))))
				{
					auto end = std::chrono::system_clock::now();
					std::chrono::duration<double> elapsed_seconds = end - start;
				}
				//2*(log(rozmiar)/log(2))
				//koniec = clock();
				//roznica = (koniec - start) / (double)CLOCKS_PER_SEC;
				
				


				//delete[] tablica_pomocnicza;
				//tablica_pomocnicza = NULL;

				if (czyPosortowanaRosnaco(tablica, wiersz, rozmiar))
				{
					plik.open("plik.txt", std::ios::out | std::ios::app);
					if (plik.good() == true)
					{
						
						plik << i << " " << rozmiaryTablic[rozmiar] << " " << wstepnePosortowanie[posortowanie] << " ";
						plik << " " << elapsed_seconds.count() << std::endl;
						plik.close();
					}
				}
				else
				{
					plik.open("plik.txt", std::ios::out | std::ios::app);
					if (plik.good() == true)
					{
						plik << "\nTablica nieposortowana" << "\n";
						plik.close();
					}
				}
				
			}




			for (int i = 0; i < wiersz; ++i)
			{
				delete[] tablica[i]; //zwolnienie pamiêci
			}
			/*delete[] tablica;
			tablica = NULL;*/
			//std::cout << << " \n";
		}
	}

	delete[] tablica;
	tablica = NULL;

	system("pause");
	return 0;


}


