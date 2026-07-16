#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void main()
{
	float num;
	float total = 0;
	float max, min;

	printf("1 번째 실수를 입력하시오. ");
	scanf("%f", &num);
	max = num;
	min = num;
	total += num;

	for (int i = 2;i <= 5;i++)
	{
		printf("%d 번째 실수를 입력하시오. ", i);
		scanf_s("%f", &num);
		total += num;

		if (max < num)
			max = num;
		if (min > num)
			min = num;
	}
    printf("--------결과----------\n");
	printf("평균은 %f입니다\n", total / 5);
	printf("최댓값은 %f입니다.\n", max);
	printf("최솟값은 %f입니다.\n", min);
}