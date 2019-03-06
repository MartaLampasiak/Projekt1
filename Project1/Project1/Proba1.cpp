#include <iostream>
#include <cstdlib>
#include <time.h>

void bubbleSort(int tab[], int n);
void insertionSort(int tab[], int n);

int main()
{
	const int rozmiar = 10;
	int tablica[rozmiar];


	for (int i = 0; i < rozmiar; ++i)
	{
		tablica[i] = rand();
		std::cout << tablica[i] << " ";
	}


	//bubbleSort(tablica, rozmiar);
	insertionSort(tablica, rozmiar);

	std::cout << "posortowana: ";
	for (int i = 0; i < rozmiar; ++i)
	{
		std::cout << tablica[i] << " ";
	}

	
	system("pause");
}

void bubbleSort(int tab[], int n)
{
	int temp;
	bool z = 0;
	do
	{
		z = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				z = 1;
			}
		}
	} while (z);
}

void insertionSort(int tab[], int n)
{
	int wstawiany;
	int j;
	for (int i = 1; i < n; ++i)
	{
		wstawiany = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > wstawiany)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = wstawiany;
	}
}