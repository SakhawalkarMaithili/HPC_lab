#include <stdio.h>
#include <omp.h>

int main()
{	
	int a1[200];
	int scalar = 30;
	
	for (int i = 0; i < 200; i++)
		a1[i] = i;
	
	int i;
	#pragma omp parallel for shared (a1) private(i) firstprivate(scalar) schedule(static, 4)
	for(i = 0; i < 200; i++)
	{
		
		#pragma omp critical
		printf("Thread Number: %d\n", omp_get_thread_num());
//		printf("%d  +  %d   =   %d\n",a1[i], scalar, a1[i] + scalar);
		a1[i] += scalar;
	}
	
}
