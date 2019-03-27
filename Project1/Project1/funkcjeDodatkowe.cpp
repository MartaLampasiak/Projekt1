#include "funkcjeDodatkowe.hpp"
#include <iostream>


//Funkcja sprawdzajaca posortowanie
bool czyPosortowanaRosnaco(int tab[], int rozmiar)
{
	for (int i = 0; i < rozmiar - 1; ++i)
	{
		if (tab[i] > tab[i + 1])
			return 0;
	}
	return 1;
}