#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, r;
	long p, q = 1;
	int k;

	printf("n을 입력하시오. :");
	scanf("%d", &n);
	printf("r을 입력하시오. :");
	scanf("%d", &r);

	if (n < 0 || r < 0)
		printf("r, n은 0 이상의 정수를 입력해야함\n");
	
	else if (n < r)
		printf("n값이 r값보다 크거나 같아야 함\n");
	
	else if (n > 12)
		printf("n은 12 이하만 입력 가능함\n");
	else
	{
		p = 1;
		for (k = n;k >= n - r + 1;k--)
			p = p * k;
		printf("순열 : %ld\n", p);
		
		p = 1;
		for (k = 1;k <= r;k++)
			p = p * n;
        printf("중복순열 : %ld\n", p);

		p = 1;
		q = 1;

		for (k = n;k >= n - r + 1;k--)
			p = p * k;
		for (k = 1;k <= r;k++)
			q = q * k;
		printf("조합 : %.2f\n\n", p / (float)q);

		p = 1;
		q = 1;
		for (k = n + r - 1;k >= n;k--)
			p = p * k;
		for (k = 1;k <= r;k++)
			q = q * k;
		printf("중복조합 : %.2f\n\n", p / (float)q);


	}
	return 0;

}
