#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	float a, b;
	char calc;
	float answer;

	printf("Input Arithmetic Operation\n");
	printf("ex)\t3.4 * 8.5\n   \t2.9 - 5.4\n   \t3.9 * 8.0\n   \t3.9 ^ 8\n\n");
	
	while (1)
	{
		printf("input : ");
		scanf("%f %c %f", &a, &calc, &b);

		switch (calc)
		{
		case '+':
			answer = a + b;
			printf("%.2f %c %.2f = %.2f", a, calc, b, answer);
			break;

		case '-':
			answer = a - b;
			printf("%.2f %c %.2f = %.2f", a, calc, b, answer);
			break;

		case '*':
			answer = a * b;
			printf("%.2f %c %.2f = %.2f", a, calc, b, answer);
			break;

		case '/':
			if (b != 0)
			{
				answer = a / b;
				printf("%.2f %c %.2f = %.2f", a, calc, b, answer);
				
			}
			else
				printf("0으로 나눌 수 없음");
			break;

		case '^':
			if (b == 0)
				answer = 1;
			else if (b < 0)
			{
				float p=1;
				for (int k = 1; k <= -b;k++)
					p = p * a;
				answer = 1 / p;

			}
			else
			{
				answer = a;
				for (int k = 2;k <= b; k++)
					answer = answer * a;
			}
				printf("%.2f %c %.2f = %.2f", a, calc, b, answer);
			
			break;
		
		default:
			printf("연산자가 잘못 입력됨\n");
			break;


		}
		printf("\n\n");
	}

}