#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int is_inside(unsigned int * tid)
{
	double x = (double)rand_r(tid) / RAND_MAX;
	double y = (double)rand_r(tid) / RAND_MAX;
	if (x*x + y*y <= 1)
                return 1;
        return 0;
}


double monte_carlo(int n)
{
    int count = 0;
    unsigned int tid;
    srand(time(NULL));

#pragma omp parallel default(none) shared(n, count) private(tid)
    {
        tid = omp_get_thread_num();
#pragma omp for reduction(+:count)
        for (int i = 0; i < n; i++)
        {
            count += is_inside(&tid);
        }
    }
    return 4.0 * count / n;
}


int main()
{
    float start = omp_get_wtime();
    double result = monte_carlo(1e9);
    float end = omp_get_wtime();

    printf("%lf\n", result);
    printf("%f\n", end - start);
    return 0;
}
