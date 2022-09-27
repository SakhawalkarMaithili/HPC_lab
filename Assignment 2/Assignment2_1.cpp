#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

int main ()
{
	vector <int> vec (8);
	
	for (int i = 0; i < 8; i++)
		vec[i] = i;
	
	
	int scalar = 5;
	
	#pragma omp parallel firstprivate (scalar)
	{
		#pragma omp for schedule (static)
		for (int i = 0; i < 8; i++)
		{
			vec[i] += scalar;
		}
	}
	
		
	for (int i = 0; i < 8; i++)
		cout << vec[i] << " ";
}
