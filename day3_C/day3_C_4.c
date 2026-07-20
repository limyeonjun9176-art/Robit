#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int* num;
	int max, min;
	int total = 0;

	printf("몇 개의 원소를 할당하겠습니까? : ");
	scanf("%d", &n);

	num = (int*)(malloc(n * sizeof(int))); //사용자의 답변을 이용해 메모리 할당

	if (num == NULL) //메모리 할당 실패 시 경고 메시지 출력
	{
		printf("malloc error\n");
		return(1);
	}


	for (int i = 0;i < n;i++)  //반복문 사용해 정수형 데이터 입력
	{
		int k;
		printf("정수형 데이터 입력:");
		scanf("%d", &k);
		num[i] = k;

		if (i == 0)//첫 번째 입력되는 수를 최대값과 최소값의 기준값으로 사용
		{
			max = k;
			min = k;
		}
		else//최대값, 최소값 비교를 통해 갱신
		{
			if (max < num[i])
				max = num[i];
			if (min > num[i])
				min = num[i];

		}
		total = total + num[i];
	} 

	//결과값 출력
	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);
	printf("전체합 : %d\n", total);
	printf("평균 : %f\n", total/(float)n);

	return 0;
}