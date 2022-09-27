#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
//	omp_set_num_threads(2);
	int n, m;
//	cin >> n >> m;
	n = m = 250;
	int a[n][m], b[n][m], c[n][m];
	
	int index = 0;
	
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < m; j++)
		{
			a[i][j] = b[i][j] = (i+j);
		}
	}
	
//	# pragma omp parallel for
	for (int i = 0; i < n; i++)
	{
		# pragma omp parallel for 
		for (int j = 0; j < m; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
