#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
    int n; // max_iteration
    scanf("%d", &n);
#pragma omp parallel
    {
        int i;
#pragma omp for schedule(static, 2)
        for (i = 0; i < n; i++)
        {
            printf("Thread No:- %d Iteration No:- %d\n", omp_get_thread_num(), i);
        }
    }
    return 0;
}