#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int** num;
	int* first;
	int n;
	
	//행과 열의 수를 사용자로부터 입력받음
	printf("숫자를 입력하시오. ");
	scanf("%d", &n);

	//입력받은 수로 숫자를 저장할 2차원 배열 동적 할당
	num = (int**)(malloc(n * sizeof(int*)));

	if (num == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}

	for (int a = 0;a < n;a++)
	{
		num[a] = (int*)(malloc(n * sizeof(int)));

		if (num[a] == NULL)
		{
			printf("메모리 할당 실패\n");
			return 1;
		}
	}
    //대각선의 시작 숫자를 저장할 배열 동적 할당
	first = (int*)(malloc((2 * n - 1) * sizeof(int)));

	if (first == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}

	//first 배열 계산 후 저장
	first[0] = 1;
	int minus = 1;

	for (int i = 1;i < 2 * n -1;i++)
	{
		if (i <= n)
			first[i] = first[i - 1] + i;
		else
		{
			first[i] = first[i - 1] + (n - minus);
			minus++;
		}
	}


	//반복문 사용, 배열의 행과 열 값의 합이 0에서 2n-2가 될 때까지 반복
	//대각선으로 진행하며 숫자가 커짐, 행과 열의 합이 커짐
	for(int plus=0;plus<=2*n-2;plus++)
	{
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				int hap = i + j;

				if (hap == plus)
				{
					num[i][j] = first[hap];
					first[hap]++;

				}

			}

		}
	}
	//결과값 출력
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			printf("%3d ", num[i][j]);

		printf("\n");

	}

	//메모리 해제
	for (int i = 0;i < n;i++)
		free(num[i]);
	free(num);

	return 0;



}