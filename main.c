#include <stdio.h>
#include <time.h>
#include "algorithms.h"

bool check_ascend(void *el0, void *el1)
{
	int *i_el0 = (int *)el0;
	int *i_el1 = (int *)el1;

	return (*i_el0) > (*i_el1);
}

bool check_descend(void *el0, void *el1)
{
	return !check_ascend(el0, el1);
}

void print_arr(int *buf, size_t length)
{
	{
		int *it;
		for (it = &buf[0]; it != &buf[length]; it = &it[1])
		{
			printf("%i ", *it);
		}

		printf("\n");
	}
}

double algo_timer(
	void *( *alg)(void *buf, 
		size_t length, 
		size_t step, 
		bool( *pfnCheck)(void *el0, void *el1)
	),
	void *buf,
	size_t length, 
	size_t step,
	bool( *pfnCheck)(void *el0, void *el1))
{
	clock_t clk = clock();
	alg(buf, length, step, pfnCheck);
	clk = clock() - clk;

	return (double)clk / CLOCKS_PER_SEC * 1000;
}

void run_algo(
	void *( *alg)(void *buf, 
		size_t length, 
		size_t step, 
		bool( *pfnCheck)(void *el0, void *el1)
	),
	void *buf,
	size_t length, 
	size_t step,
	bool( *pfnCheck)(void *el0, void *el1))
{
	double timer = algo_timer(alg, buf, length, step, pfnCheck);
	printf("\t");
	print_arr(buf, length);
	printf("\tTime: %f\n", timer);
}

int main()
{
	int buf[] = { 1, 9, 2, 5, 3, 4, 4, 0 };
	size_t length = sizeof(buf) / sizeof(buf[0]);
	size_t step = sizeof(buf[0]);

	printf("Original Array: \n\t");
	print_arr(buf, length);
	/* ==================== */
	printf("Bubble Sort: \n");
	run_algo(bubble_sort, buf, length, step, check_descend);
	/* ==================== */
	printf("Insertion Sort: \n");
	run_algo(insertion_sort, buf, length, step, check_ascend);

	return 0;
}