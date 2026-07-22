#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//달팽이 모양으로 숫자를 저장한 2차원 배열 arr을 출력하는 함수
//row와 col의 경우 함수 내에서 변수값이 변하지 않으므로 매개변수의 형을 int row,int col,int** pArr로 지정해도 됨
void print(int* row, int* col, int** pArr)
{
	for (int i = 0; i < *row;i++)
	{
		for (int j = 0;j < *col;j++)
		{
			printf("%3d ", pArr[i][j]);
		}
		printf("\n");
	}
}

//달팽이 모양으로 숫자를 arr 2차원 배열에 저장하는 함수
void arr_ij(int* sizeRow, int* sizeCol, int** pArr)
{
	//네모 테두리를 따라 top, bottom, left, right를 지정
	int top = 0;
	int bottom = *sizeRow - 1;
	int left = 0;
	int right = *sizeCol - 1;
	int n = 1;

	//테두리를 따라 돌며 숫자 저장 ->반복문 사용
	//top이 bottom보다 크거나 right가 left보다 작아지면 반복문 중지
	//row와 col이 짝X짝, 홀X홀,짝X홀, 홀X짝인 모든 경우에서 top고정 반복문 또는 bottom 고정 반복문에서 숫자 저장이 종료된다.
	//top과 bottom 사이 관계가 변화하는 시점에서 종료될지 결정됨--> while문 안에서 조건문을 한 번 더 써줘야함
	while (top <= bottom && right >= left)
	{
		int i;

		//top을 고정한 채 왼쪽-->오른쪽 이동
		for (i = left;i <= right;i++)
		{
			pArr[top][i] = n;
			n++;
		}
		//이동이 끝나면 top=top+1을 해줘 다음 오른쪽 이동 시작점을 바꿈
		top++;

		//왼쪽-->오른쪽으로 한 번 이동한 후 top++가 된다. 이 때 top>bottom이면 아래 반복문이 실행되지 않도록 한다.
		//right를 고정한 채 위쪽 -->아래쪽 이동
		if (top <= bottom)
		{
			for (i = top;i <= bottom;i++)
			{
				pArr[i][right] = n;
				n++;
			}
			right--;

			for (i = right;i >= left;i--)
			{
				pArr[bottom][i] = n;
				n++;
			}
			bottom--;
		}

		//만약 이 위의 반복문이 적용이 되었다면 top과 bottom 사이 관계성이 한 번 더 변한다.--> 조건문 다시 한 번 실행
		//left를 고정한 채 아래쪽-->위쪽 이동
		if (top <= bottom)
		{
			for (i = bottom;i >= top;i--)
			{
				pArr[i][left] = n;
				n++;
			}
			left++;
		}


	}
}

int main(void)
{
	int** arr = NULL;
	int row, col, sizeRow, sizeCol;

	//사용자로부터 행과 열의 수를 입력받음
	printf("열의 수를 입력하세요: ");
	scanf("%d", &sizeCol);
	printf("행의 수를 입력하세요: ");
	scanf("%d", &sizeRow);


	row = sizeRow;
	col = sizeCol;
	//입력받은 row,col값으로 arr 2차원 배열 동적 할당
	arr = (int**)(malloc(row * sizeof(int*)));
	if (arr == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}
	for (int i = 0;i < row;i++)
	{
		arr[i] = (int*)(malloc(col * sizeof(int)));
		if (arr[i] ==NULL)
		{
			printf("메모리 할당 실패\n");
			return 1;
		}
	}
	
	//arr_ij 함수(숫자를 달팽이 모양으로 저장) 실행
	arr_ij(&sizeRow, &sizeCol, arr);

	//print 함수(저장한 숫자 출력) 실행
	print(&row, &col, arr);

	//2차원 배열 동적 할당 메모리 해제
	for (int i = 0;i < row;i++)
		free(arr[i]);
	free(arr);

	return 0;
}