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
   
    return arr;

}
int compute(const void * A, const void * B)
{
    return(*(int*)A) - (*(int*)B);

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
        //SortArray(p, sizes[i]);
        qsort(p, 8, sizeof(int*), compute);
        gettimeofday(&endTime, 0);
        sort_time = (double)(endTime.tv_sec - startTime.tv_sec) + (double)(endTime.tv_usec - startTime.tv_usec) / 1000000.;

	    //Deallocation timing
	    gettimeofday(&startTime, 0);
        DeallocateArray(p);
        gettimeofday(&endTime, 0);
        dealloc_time = (double)(endTime.tv_sec - startTime.tv_sec) + (double)(endTime.tv_usec - startTime.tv_usec) / 1000000.;

        printf("Timings for array of size %d\n", sizes[i]);
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time, (alloc_time/sizes[i]));
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time, (sort_time/sizes[i]));
        printf("\tTime for deallocation is %g\n", dealloc_time);
    }
}

