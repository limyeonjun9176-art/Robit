#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int p, q;

	printf("행과 열 숫자를 입력하시오. ");
	scanf("%d %d", &p, &q);

	int** num;

	num = (int**)(malloc(p * sizeof(int*)));

	if (num == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}

	for (int i = 0;i < p;i++)
	{
		num[i] = (int*)(malloc(q * sizeof(int)));

		if (num[i] ==NULL)
		{
			printf("메모리 할당 실패 \n");
			return 1;
		}

	}

	int top,bottom;
	int left, right;
	int n;

	top = 0;
	bottom = p - 1;
	left = 0;
	right = q - 1;
	n = 1;

	while(top<=bottom&&left<=right)
	{
		//행을 top으로 고정한 채 왼쪽 --> 오른쪽 이동
		for (int i = left;i <= right;i++)
		{
			num[top][i] = n;
			n++;
		}
		top++;

		//열은 right로 고정한 채 위 --> 아래 이동
		for (int i = top;i <= bottom;i++)
		{
			num[i][right] = n;
			n++;
		}
		right--;

		//행을 bottom으로 고정한 채 오른쪽 --> 왼쪽
		if (top <= bottom) //top > bottom 되는 순간 제외
		{
			for (int i = right;i >= left;i--)
			{
				num[bottom][i] = n;
				n++;
			}
			bottom--;
		}

		//열을 left로 고정한 채 아래 --> 위 이동
		if (left <= right)//left > right 되는 순간 제외
		{
			for (int i = bottom;i >= top;i--)
			{
				num[i][left] = n;
				n++;
			}
			left++;
		}
	}
	//결과값 출력
	for (int i = 0;i < p;i++)
	{
		for (int j = 0;j < q;j++)
			printf("%2d ", num[i][j]);
		printf("\n");
	}

	//메모리 해제
	for (int i = 0;i < p;i++)
		free(num[i]);
	free(num);

	return 0;

}