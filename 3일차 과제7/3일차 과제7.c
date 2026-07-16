/* 
순열 : 서로 다른 n개 중에서 r개를 순서를 고려하여 중복 없이 나열 n!/(n-r)!
중복순열 : 서로 다른 n개 중에서 중복을 허용하여 r개를 순서대로 나열 n^r
조합 : 서로 다른 n개 중에서 순서 없이 r개를 선택 n!/r!(n-r)!
중복조합 : 서로 다른 n개 중에서 중복을 허용하여 순서 없이 r개를 선택 (n+r-1)!/r!(n-1)!

반복문 이용해 팩토리얼 계산, 0!이 되는 경우 주의
순열,조합의 경우 중복이 없어야하므로 n>r조건 
팩토리얼 계산 시 값이 기하급수적으로 커지므로 최대한 곱셈 나눗셈 한 번에 진행
나눗셈--> 실수로 형 변환하여 나누기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int choice;
	int n, r;
	int k;

	while (1)
	{
		long p = 1, q = 1;
		printf("계산 방식을 선택하시오. (1. 순열, 2. 중복순열, 3. 조합, 4. 중복조합) : ");
		scanf("%d", &choice);


		printf("n개 중 r개를 나열 또는 선택\n");
		printf("n값을 입력하시오. :");
		scanf("%d", &n);
		printf("r값을 입력하시오. :");
		scanf("%d", &r);

		if (n < 0 || r < 0)
			printf("r, n은 자연수 또는 0을 입력해야함\n");
		else
		{
			switch (choice)
			{
			case 1:

				if (n < r)
				{
					printf("n값이 r값보다 커야함\n");
					break;
				}
				else
				{
					for (k = n;k >= n - r + 1;k--)
						p = p * k;
				}
				printf("%ld\n\n", p);
				break;

			case 2:
				for (k = 1;k <= r;k++)
					p = p * n;

				printf("%ld\n\n", p);
				break;

			case 3:
				if (n < r)
				{
					printf("n값이 r값보다 커야함\n");
					break;
				}
				else
				{
					for (k = n;k >= n - r + 1;k--)
						p = p * k;
					for (k = 1;k <= r;k++)
						q = q * k;
					printf("%.2f\n\n", p / (float)q);
				}

				break;

			case 4:
				for (k = n + r - 1;k >= n;k--)
					p = p * k;
				for (k = 1;k <= r;k++)
					q = q * k;
				printf("%.2f\n\n", p / (float)q);
				break;

			default:
				printf("계산 방식을 잘못 선택함\n");
				break;


			}


		}
	}
	return 0;
}