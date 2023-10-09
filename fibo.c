#include <stdio.h>
#include <omp.h>
int main()
{
    int n; // number of Fibonacci numbers you want to calculate
    scanf("%d", &n);
    // Initialize Fibonacci sequence
    long long int fib[n];
    // Set the first two numbers in the sequence
    fib[0] = 0;
    fib[1] = 1;
// Use OpenMP parallelism to calculate the Fibonacci sequence
#pragma omp parallel
    {
        int i;
// Use a loop to calculate Fibonacci numbers in parallel
#pragma omp for schedule(dynamic) // Use dynamic scheduling to avoid race conditions
        for (i = 2; i < n; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
            printf("Thread %d: Calculating fib[%d]\n", omp_get_thread_num(), i);
        }
    } // End of parallel region
    // Print the Fibonacci sequence
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", fib[i]);
    }
    printf("\n");
    return 0;
}