#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num[5][5];
	int n = 1;

	//반복문 사용, 2차원 배열에 숫자 저장
	for (int p = 0;p < 5;p++)
	{
		for (int q = 0;q < 5;q++)
		{
			//모래시계 모양의 규칙성 이용, 모래시계의 가운데를 기준으로 규칙성이 바뀜
			if (q >= p && q <= 4 - p)
			{
				num[p][q] = n;
				n++;
			}
			else if (q <= p && q >= 4 - p)
			{
				num[p][q] = n;
				n++;
			}
			else
				num[p][q] = 0;

			printf("%3d", num[p][q]); //결과 출력
		}
		printf("\n");
	}

	return 0;
}