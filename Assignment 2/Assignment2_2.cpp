#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

int main()
{
	int *a, *b, *c;
	int n = ARRAY_SIZE;
	a = (int *) malloc(sizeof(int)*n);
	b = (int *) malloc(sizeof(int)*n);
	c = (int *) malloc(sizeof(int)*n);
	
	for (int i = 0; i < n; i++)
		a[i] = b[i] = i;
	
	#pragma omp parallel for
	for (int i = 0; i < n; i++)
		c[i] = a[i] + b[i];
		
	for(int i=0; i<n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
        }
        
    free (a);
    free (b);
    free (c);
	return 0;
}
