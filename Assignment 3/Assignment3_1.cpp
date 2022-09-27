#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

int sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		#pragma omp parallel for
		for (j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


int sort_des(int arr[], int n)
{
	int i,j;
	for (i = 0; i < n; ++i)
	{
		#pragma omp parallel for
		for (j = i + 1; j < n; ++j)
		{
			if (arr[i] < arr[j])
			{
				int a = arr[i];
				arr[i] = arr[j];
				arr[j] = a;
			}
		}
	}
}


int main()
{
	int arr1[5] = {2,1,4,6,3};
	int arr2[5] = {2,1,5,4,3};
	int sum = 0;
	sort(arr1,5);
	sort_des(arr2,5);
	#pragma omp parallel shared(sum)
	{
		#pragma omp for
		for(int i=0; i<5; i++)
		{
			sum += arr1[i] * arr2[i];
		}
	}
	cout<<sum<<endl;
}



