#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int p, q;
	int** num;
	
	printf("행 열 숫자 입력(홀수) :");
	scanf("%d %d", &p, &q);

	//2차원 배열 동적 할당
	num = (int**)(malloc(p * sizeof(int*)));
	if (num == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}

	for (int i = 0;i < p;i++)
	{
		num[i] = (int*)(malloc(q * sizeof(int)));
		if (num[i] == NULL)
		{
			printf("메모리 할당 실패\n");
			return 1;
		}
	}

	int center_x = (q - 1) / 2;
	int center_y = (p - 1) / 2; //중심 좌표 계산
	int n = 1;

	num[center_y][center_x] = n; //중심 좌표에 1 대입
	n++;

	int nemo = ((q - 1) / 2) + ((p - 1) / 2); //마름모의 총 갯수 계산

	for (int k = 1;k <= nemo;k++)
	{
		//아래쪽: dc = -(k-1) ~ (k-1), dr = k - |dc|
		for (int dc = -(k - 1); dc <= (k - 1); dc++)
		{
			int dr = k - abs(dc);
			int r = center_y + dr, c = center_x + dc;

			if (r >= 0 && r < p && c >= 0 && c < q)
			{
				num[r][c] = n;
				n++;
			}
		}

		//오른쪽 꼭짓점
		if (center_y >= 0 && center_y < p && center_x + k >= 0 && center_x + k < q)
		{
			num[center_y][center_x + k] = n;
			n++;
		}

		//위쪽: dc = (k-1) ~ -(k-1), dr = -(k - |dc|)
		for (int dc = (k - 1); dc >= -(k - 1); dc--) {
			int dr = -(k - abs(dc));
			int r = center_y + dr, c = center_x + dc;
			if (r >= 0 && r < p && c >= 0 && c < q)
			{
				num[r][c] = n;
				n++;
			}
		}

		//왼쪽 꼭짓점
		if (center_y >= 0 && center_y < p && center_x - k >= 0 && center_x - k < q)
		{
			num[center_y][center_x - k] = n;
			n++;
		}
	}


	for (int i = 0;i < p;i++)
	{
		for (int j = 0;j < q;j++)
			printf("%2d ", num[i][j]);
		printf("\n");

		free(num[i]);
	}

	free(num);
	
	return 0;



}