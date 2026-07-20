#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int count, k, t;

	while (1)
	{
		printf("값을 입력하세요. ");
		scanf("%d", &count);

		for (k = 1;k <= count - 1;k++) //별 하나만 입력되는 첫 번째 줄: 반복문으로 공백 입력, 공백 갯수 count-1
			printf(" ");
		printf("*\n");

		for (k = 2;k <= count - 1;k++) //count에 입력된 값은 총 줄의 갯수, 반복문 사용
		{
			for (t = 1;t <= count - k;t++) //공백-별-공백-별 순서
				printf(" ");
			printf("*");
			for (t = 1;t <= 2 * k - 3;t++)
				printf(" ");
			printf("*\n");
		}
		if (count > 1) //count=1 제외 별만 입력되는 마지막 줄 반복문 사용해 입력
		{
			for (t = 1;t <= 2 * count - 1;t++)
				printf("*");
			printf("\n");
		}
		printf("\n");
	}

}

