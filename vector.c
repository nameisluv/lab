int main()
{
    int n;
    double start, end;
    scanf("%d", &n);
    int a[n], b[n], res[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        b[i] = rand() % 1000;
    }
    printf("Vector A:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nVector B:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    start = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        res[i] = a[i] + b[i];
    }
    end = omp_get_wtime();
    printf("\nResultant vector:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\nTime Taken:- %f\n", end - start);
    return 0;
}
