#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int count;
	int k, t, emp;

	while (1)
	{

		printf("값을 입력하세요. ");
		scanf_s("%d", &count);

		for (k = 1;k <= count - 1;k++)
		{
			for (t = 1;t <= k;t++)
				printf("*");

			emp = 2 * count - 2 * k;
			for (t = 1;t <= emp;t++)
				printf(" ");

			for (t = 1;t <= k;t++)
				printf("*");
			printf("\n");

		}

		for (k = 1;k <= 2 * count;k++)
			printf("*");
		printf("\n");

		for (k = count - 1;k >= 1;k--)
		{
			for (t = 1;t <= k;t++)
				printf("*");

			emp = 2 * count - 2 * k;
			for (t = 1;t <= emp;t++)
				printf(" ");

			for (t = 1;t <= k;t++)
				printf("*");
			printf("\n");

		}

		printf("\n\n\n");
	}
	return 0;
}