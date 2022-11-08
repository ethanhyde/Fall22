#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>

int *AllocateArray(int N)
{
    int *arr = malloc((sizeof(int))* N);
    for (int i = 0; i < N; ++i)
    {
        arr[i] = rand() % 10;
    }
    /* Allocate an array with N integers.
     * The value of each element of the array should be a
     * random number between 0 and 10N.
     * Hint: use the rand() function and a modulo operator.
     */
    return arr;

}

void SortArray(int *A, int N)
{

    int temp; //Temporary variable
	for(int j = 0; j < N-1; ++j)
	{
		for(int z = 0; z < N-1; ++z)
		{
			if(A[z] > A[z+1])
			{
				temp = A[z];
				A[z] = A[z+1];
				A[z+1] = temp;
			
			}
		}
	}
    
}

void DeallocateArray(int *A)
{
	free(A);
}

int main()
{
    int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };

/* For fun:
 *  int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000,
 *                    256000, 512000, 1024000 }; 
 */
    int *p;

	double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
        struct timeval startTime;
        struct timeval endTime;


    for (int i = 0 ; i < 8 ; i++)
    {
        //Allocation timing
        gettimeofday(&startTime, 0);
        p = AllocateArray(sizes[i]);
        gettimeofday(&endTime, 0);
        alloc_time = (double)(endTime.tv_sec - startTime.tv_sec) + (double)(endTime.tv_usec - startTime.tv_usec) / 1000000.;

        //Sorting timing
        gettimeofday(&startTime, 0);
        SortArray(p, sizes[i]);
        gettimeofday(&endTime, 0);
        sort_time = (double)(endTime.tv_sec - startTime.tv_sec) + (double)(endTime.tv_usec - startTime.tv_usec) / 1000000.;

	//Deallocation timing
	gettimeofday(&startTime, 0);
        DeallocateArray(p);
        gettimeofday(&endTime, 0);
        dealloc_time = (double)(endTime.tv_sec - startTime.tv_sec) + (double)(endTime.tv_usec - startTime.tv_usec) / 1000000.;

        /* Call the three functions in a sequence. Also use
         * gettimeofday calls surrounding each function and set the 
         * corresponding variable (alloc_time, sort_time, dealloc_time).
         */

        printf("Timings for array of size %d\n", sizes[i]);
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time, (alloc_time/sizes[i]));
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time, (sort_time/sizes[i]));
        printf("\tTime for deallocation is %g\n", dealloc_time);
    }
}


