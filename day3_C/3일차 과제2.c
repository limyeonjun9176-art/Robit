#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	printf("숫자n을 입력받아, n번째 피보나치 수를 출력하는 프로그램(n:1~1000)\n");
	printf("------------------------------------------------------------\n\n");

	int n,k;
	int num[1000];
	num[0] = 0;
	num[1] = 1;
	
	printf("숫자를 입력하시오. ");
	scanf("%d", &n);
	
	if (n < 1 || n>1000)
		printf("1에서 1000 사이의 숫자만 입력하시오.\n");
	else
	{
		for (k = 2;k <= n - 1;k++)
			num[k] = num[k - 2] + num[k - 1];

		printf("%d번째 피보나치 수 : %d\n", n, num[n - 1]);
	}
	

		
}