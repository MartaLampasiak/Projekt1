#include "mergeSort.hpp"



void merge(int tab[], int left, int mid, int right)
{
	int *tab_pom = new int[right+left];
	int left1 = left, right1 = mid;
	int left2 = mid + 1, right2 = right;
	int i = left1;

	while ((left1 <= right1) && (left2 <= right2))
	{
		if (tab[left1] < tab[left2])
		{
			tab_pom[i] = tab[left1];
			left1++;
		}
		else
		{
			tab_pom[i] = tab[left2];
			left2++;
		}
		i++;
	}
	while (left1 <= right1)
	{
		tab_pom[i] = tab[left1];
		left1++;
		i++;
	}
	while (left2 <= right2)
	{
		tab_pom[i] = tab[left2];
		left2++;
		i++;
	}
	for (i = left; i <= right; i++)
		tab[i] = tab_pom[i];
}

void mergeSort(int tab[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(tab, left, mid);
		mergeSort(tab, mid + 1, right);
		merge(tab, left, mid, right);
	}
}