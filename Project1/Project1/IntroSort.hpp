#pragma once

//void IntroSort(int tab[], int left, int right, double MaxRekurencji);

#include "quickSort.hpp"
#include "heapSort.hpp"
#include "insertionSort.hpp"
#include <math.h>

template <typename T>
void IntroSort(T tab[], int left, int right, double MaxRekurencji)
{
	if (left < right)
	{
		if (MaxRekurencji == 0)
		{
			heapSort(tab, right + 1);
			return;
		}
		int pivotIndex = podzielnaPartycje(tab, left, right);
		IntroSort(tab, left, pivotIndex - 1, MaxRekurencji - 1);
		IntroSort(tab, pivotIndex + 1, right, MaxRekurencji - 1);
	}
}