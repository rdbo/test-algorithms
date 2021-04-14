#include "algorithms.h"

void sort_swap(void *buf0, void *buf1, size_t size)
{
	void *tmp;
	tmp = malloc(size);
	memcpy(tmp, (void *)buf0, size);
	memcpy((void *)buf0, (void *)buf1, size);
	memcpy((void *)buf1, tmp, size);
	free(tmp);
}

void *bubble_sort(void *buf, size_t length, size_t step, bool( *pfnCheck)(void *el0, void *el1))
{
	if (length < 2 || step == 0) return buf; /* Ignore invalid arrays */

	{
		unsigned char *bbuf = (unsigned char *)buf;
		size_t i;
		size_t j;
		bool swapped = true;

		for (i = 0; i < (length - 1) && swapped; ++i) {
			swapped = false;
			for (j = 0; j < (length - i - 1); ++j) {
				unsigned char *el0 = &bbuf[j * step];
				unsigned char *el1 = &bbuf[(j + 1) * step];
				if (pfnCheck((void *)el0, (void *)el1)) {
					sort_swap((void *)el0, (void *)el1, step);
					swapped = true;
				}
			}
		}
	}

	return buf;
}

void *insertion_sort(void *buf, size_t length, size_t step, bool( *pfnCheck)(void *el0, void *el1))
{
	if (length < 2 || step == 0) return buf; /* Ignore invalid arrays */

	{
		unsigned char *bbuf = (unsigned char *)buf;
		unsigned char *i;
		unsigned char *j;
		/* First Iteration */
		for (i = bbuf; i != &bbuf[length * step]; i = &i[step]) {
			/* Second Iteration */
			for (j = &i[step]; j != &bbuf[length * step]; j = &j[step]) {
				if (pfnCheck((void *)i, (void *)j)) {
					/* Swap 'i' and 'j' */
					sort_swap(i, j, step);
				}
			}
		}
	}

	return buf;
}
