#pragma once

//void IntroSort(int tab[], int left, int right, double MaxRekurencji);

#include "quickSort.hpp"
#include "heapSort.hpp"
#include "insertionSort.hpp"



////test z insert
//template <typename T>
//void IntroSort(T tab[], int left, int right, double MaxRekurencji)
//{
//	if ((right - left) < 16)
//	{
//		insertionSort(tab, right);
//	}
//	else if (MaxRekurencji == 0)
//	{
//		heapSort(tab, right);
//		return;
//	}
//
//	else 
//	{
//		int pivotIndex = podzielnaPartycje(tab, left, right - 1);
//		IntroSort(tab, left, pivotIndex, MaxRekurencji - 1);
//		IntroSort(tab, pivotIndex + 1, right, MaxRekurencji - 1);
//	}
//
//}


//Moj intro
template <typename T>
void IntroSort(T tab[], int left, int right, int MaxRekurencji)
{
	if (left < right)
	{
		if (MaxRekurencji == 0)
		{
			heapSortintro(tab,left, right);
			//return;
		}

		
			int pivotIndex = podzielnaPartycje(tab, left, right-1);
			IntroSort(tab, left, pivotIndex, MaxRekurencji - 1);
			IntroSort(tab, pivotIndex + 1, right, MaxRekurencji - 1);
		
	}
}

template <typename T>
void IntroSort(T tab[], int right)
{
	int MaxRekurencji = (2 * floor(log2(right)));
	IntroSort(tab, 0, right, MaxRekurencji);
}


//void IntroSort(int tab[], int rozmiar, double MaxRekurencji)
//{
//	if (MaxRekurencji == 0)
//	{
//		heapSort(tab, rozmiar);
//		return;
//	}		
//	
//int pivotIndex = podzielnaPartycje(tab, 0, rozmiar - 1);
//	/*if (MaxRekurencji > 0)
//	{*/
//		
//		if(pivotIndex > 0)
//		IntroSort(tab, pivotIndex, MaxRekurencji - 1);
//		if(rozmiar-1-pivotIndex > 0)
//		IntroSort(tab + pivotIndex + 1,rozmiar - 1 - pivotIndex, MaxRekurencji - 1);
//	}
//	
//
//










//#include "IntroSort.hpp"
//#include "quickSort.hpp"
//#include "heapSort.hpp"
//#include "insertionSort.hpp"
//#include <math.h>
//
//
//void IntroSort(int tab[], int left, int right, double MaxRekurencji)
//{
//	if (left < right)
//	{
//		if ((right - left+1) < 16)
//			insertionSort(tab, right + 1);
//		else if (MaxRekurencji == 0)
//		{
//			heapSort(tab, right + 1);
//			return;
//		}
//		else 
//		{
//			int pivotIndex = podzielnaPartycje(tab, left, right);
//			IntroSort(tab, left, pivotIndex - 1, MaxRekurencji - 1);
//			IntroSort(tab, pivotIndex + 1, right, MaxRekurencji - 1);
//		}
//	}
//}



//NIEUDANE
//void IntroSort(int tab[], int rozmiar, double MaxRekurencji)
//{
//	int i = podzielnaPartycje(tab, 0, rozmiar - 1);
//	if (MaxRekurencji <= 0)
//	{
//		heapSort(tab, rozmiar);
//		return;
//	}
//	i = podzielnaPartycje(tab, 0, rozmiar - 1);
//
//	if (i > 9)
//		IntroSort(tab, i, MaxRekurencji - 1);
//	if(rozmiar-i-1 > 9)
//		IntroSort(tab+i+1, rozmiar-1-i, MaxRekurencji - 1);
//
//	if (rozmiar <= 1)
//		return;
//	else if (MaxRekurencji = 0)
//			heapSort(tab, rozmiar);
//	else
//	{
//		IntroSort(tab, i, MaxRekurencji - 1);
//		IntroSort(tab, rozmiar - i - 1, MaxRekurencji - 1);
//	}
//
//}
//
//void Hybrid_Introsort(int tab[], int rozmiar)
//{
//	IntroSort(tab, rozmiar, (int(2 * log(double(rozmiar)))));
//	insertionSort(tab, rozmiar);
//
//}
//
//void IntroSort(int tab[], int rozmiar, double MaxRekurencji)
//{
//	int i;
//	if (MaxRekurencji <= 0)
//	{
//		heapSort(tab, rozmiar);
//		return;
//	}
//	i = podzielnaPartycje(tab, 0, rozmiar - 1);
//	if (i > 9)
//		IntroSort(tab, i, MaxRekurencji - 1);
//	if (rozmiar - 1 - i > 9)
//		IntroSort(tab + i + 1, rozmiar - 1 - i, MaxRekurencji - 1);
//
//}

//void IntroSort(int tab[], int rozmiar, double MaxRekurencji)
//{
//	if (MaxRekurencji == 0)
//	{
//		heapSort(tab, rozmiar);
//		return;
//	}		
//	
//int pivotIndex = podzielnaPartycje(tab, 0, rozmiar - 1);
//	/*if (MaxRekurencji > 0)
//	{*/
//		
//		if(pivotIndex > 0)
//		IntroSort(tab, pivotIndex, MaxRekurencji - 1);
//		if(rozmiar-1-pivotIndex > 0)
//		IntroSort(tab + pivotIndex + 1,rozmiar - 1 - pivotIndex, MaxRekurencji - 1);
//	//}
//	
//}
//void IntroSort(int tab[], int left, int right, double MaxRekurencji)
//{
//	if (left < right)
//	{
//		if (MaxRekurencji != 0)
//		{
//			heapSort(tab, right + 1);
//			return;
//		}
//	//	if (MaxRekurencji > 0)
//	//	{
//			int pivotIndex = podzielnaPartycje(tab, left, right);
//			IntroSort(tab, left, pivotIndex-1, MaxRekurencji - 1);
//			IntroSort(tab, pivotIndex + 1, right, MaxRekurencji - 1);
//		//}
//
//	}
//}