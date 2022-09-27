#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	#pragma omp parallel
	{
		// printf written instead of cout because printf prints everything in the "" in the same instance. In cout, we break the sentence. So, may or may not get printed together
		printf ("hello world %d \n", omp_get_thread_num());
	}
	return 0;
}
