#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int year;
	
		printf("년도를 입력하세요 : ");
		scanf("%d", &year);

		if (year % 4 != 0)
			printf("평년\n");
		else
		{
			if (year % 100 != 0)
				printf("윤년\n");
			else
			{
				if (year % 400 != 0)
					printf("평년\n");
				else
					printf("윤년\n");
			}

		}
	
}