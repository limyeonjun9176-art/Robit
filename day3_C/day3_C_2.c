#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int** num1;
	int** num2;
	int i, j;
	int n = 1;

	printf("배열의 행과 열 수를 정하시오. ");
	scanf("%d %d", &i, &j);

	//num1 2차원 배열로 메모리 할당
	num1 = (int**)(malloc(i * (sizeof(int*))));
    
	if (num1 == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}

	for (int t = 0;t < i;t++)
	{
		num1[t] = (int*)(malloc(j * (sizeof(int))));
		if (num1[t] == NULL)
		{
			printf("메모리 할당 실패\n");
			return 1;
		}
	}
	//num2 2차원 배열로 메모리 할당
	num2 = (int**)(malloc(j * (sizeof(int*))));
	if (num2 == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}

	for (int t = 0;t < j;t++)
	{
		num2[t] = (int*)(malloc(i * (sizeof(int))));
		if (num2[t] == NULL)
		{
			printf("메모리 할당 실패\n");
			return 1;
		}
	}
	int p, q;

	//num1 순서대로 숫자 저장
	for (p = 0;p < i;p++)
	{
		for (q = 0;q < j;q++)
		{
			num1[p][q] = n;
			n++;
			printf("%2d ", num1[p][q]);
		}
		printf("\n");
	}
	printf("\n\n");

	//num2 num1의 행과 열을 바꿔 출력
	for (q = 0;q < j;q++)
	{
		for (p = 0;p < i;p++)
		{
			num2[q][p] = num1[p][q];
			printf("%2d ", num2[q][p]);
		}
		
		printf("\n");
	}
	
    //메모리 해제
	for (int t = 0;t < i;t++)
		free(num1[t]);
	free(num1);

	for (int t = 0;t < j;t++)
		free(num2[t]);
	free(num2);

	return 0;
				
}