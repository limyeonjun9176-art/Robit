#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 4. 파일 저장 및 불러오기, 예외 처리 못했습니다*/

//주소 구조체 : 나라, 도, 시, 구를 멤버로 가짐
typedef struct _Address
{
	char country[30];
	char province[30];
	char city[30];
	char district[30];
}Address;

//학생 구조체 : 번호, 이름,주소, 성적 
typedef struct _Student
{
	int number;
	char name[30];
	Address address;
	double grade;
}Student;

int student_count = 0;
Student students[100];

//번호순으로 학생 정렬
void student_num(void)
{
	for (int i = 0;i < student_count - 1;i++)
	{
		for (int j = i + 1;j < student_count;j++)
		{
			if (students[i].number > students[j].number)
			{
				Student tmp = students[i];
				students[i] = students[j];
				students[j] = tmp;
			}
		}
	}
}

//이름순으로 학생 정렬
void student_name(void)
{
	for (int i = 0;i < student_count - 1;i++)
	{
		for (int j = i + 1;j < student_count;j++)
		{
			if (strcmp(students[i].name, students[j].name) > 0)
			{
				Student tmp = students[i];
				students[i] = students[j];
				students[j] = tmp;
			}
		}
	}
}

//성적순으로 학생 정렬
void student_grade(void)
{
	for (int i = 0;i < student_count - 1;i++)
	{
		for (int j = i + 1;j < student_count;j++)
		{
			if (students[i].grade > students[j].grade)
			{
				Student tmp = students[i];
				students[i] = students[j];
				students[j] = tmp;
			}
		}
	}
}
//주소순으로 학생 정렬
void student_addr(void)
{
	int choice;

	printf("1.나라, 2.도, 3.시, 4.구\n");
	printf("주소 정렬 방법을 고르시오.");
	scanf("%d", &choice);

	for (int i = 0;i < student_count - 1;i++)
	{
		for (int j = i + 1;j < student_count;j++)
		{
			switch (choice)
			{
			case 1:
				if (strcmp(students[i].address.country, students[j].address.country) > 0)
				{
					Student tmp = students[i];
					students[i] = students[j];
					students[j] = tmp;
				}
			case 2:
				if (strcmp(students[i].address.province, students[j].address.province) > 0)
				{
					Student tmp = students[i];
					students[i] = students[j];
					students[j] = tmp;
				}
			case 3:
				if (strcmp(students[i].address.city, students[j].address.city) > 0)
				{
					Student tmp = students[i];
					students[i] = students[j];
					students[j] = tmp;
				}
			case 4:
				if (strcmp(students[i].address.district, students[j].address.district) > 0)
				{
					Student tmp = students[i];
					students[i] = students[j];
					students[j] = tmp;
				}
			}
		}
	}
}

//1. 학생 정렬 기능 선택 시
void student_array(void)
{
	int choice;
	printf("정렬 기준을 선택하시오.(1. 번호순, 2. 이름순, 3. 주소순, 4.성적순)");
	scanf("%d", &choice);

	switch (choice)
	{
	case1:student_num();break;
	case2:student_name();break;
	case3:student_addr();break;
	case4:student_grade();break;
	default:printf("잘못된 숫자입니다\n");return;
	}

	//정렬된 학생 목록 출력
	if (student_count == 0)
	{
		printf("등록된 학생이 없습니다.\n");
		return;
	}
	printf("번호   이름    주소         성적\n");
	for (int i = 0;i < student_count;i++)
		printf("%d   %s   %s / %s / %s / %s   %f\n", students[i].number, students[i].name, students[i].address.country, students[i].address.province, students[i].address.city, students[i].address.district, students[i].grade);
}

//2. 학생 찾기 기능 선택 시
void student_search(void)
{
	int choice;
	char keyword[30];

	printf("찾기 기준을 선택하시오.(1. 번호, 2. 이름, 3. 주소, 4.성적)");
	scanf("%d", &choice);
	printf("검색어 입력 : ");
	scanf("%s", &keyword);
	int found = 0;
	int opt;

	for (int i = 0;i < student_count;i++)
	{
		switch (choice)
		{
		case 1:
			if (strcmp(students[i].number, keyword) == 0)
			{
				printf("%d   %s   %s / %s / %s / %s   %f\n", students[i].number, students[i].name, students[i].address.country, students[i].address.province, students[i].address.city, students[i].address.district, students[i].grade);
				found = 1;
				break;
			}
		case 2:
			if (strcmp(students[i].name, keyword) == 0)
			{
				printf("%d   %s   %s / %s / %s / %s   %f\n", students[i].number, students[i].name, students[i].address.country, students[i].address.province, students[i].address.city, students[i].address.district, students[i].grade);
				found = 1;
				break;
			}
		case 3:
			printf("주소 찾기 세부 기준을 선택하시오.(1.나라, 2.도, 3.시, 4.구)");
			scanf("%d", &opt);

			if (opt == 1)
			{
				if (strcmp(students[i].address.country, keyword) == 0) {
					printf("%d   %s   %s / %s / %s / %s   %f\n", students[i].number, students[i].name, students[i].address.country, students[i].address.province, students[i].address.city, students[i].address.district, students[i].grade);
					found = 1;
					break;
				}
			}
			else if (opt == 2)
			{
				if (strcmp(students[i].address.province, keyword) == 0)
				{
					printf("%d   %s   %s / %s / %s / %s   %f\n", students[i].number, students[i].name, students[i].address.country, students[i].address.province, students[i].address.city, students[i].address.district, students[i].grade);
					found = 1;
					break;
				}
			}

			else if (opt == 3)
			{
				if (strcmp(students[i].address.city, keyword) == 0)
				{
					printf("%d   %s   %s / %s / %s / %s   %f\n", students[i].number, students[i].name, students[i].address.country, students[i].address.province, students[i].address.city, students[i].address.district, students[i].grade);
					found = 1;

					break;
				}
			}
			else if (opt == 4)
			{
				if (strcmp(students[i].address.district, keyword) == 0)
				{
					printf("%d   %s   %s / %s / %s / %s   %f\n", students[i].number, students[i].name, students[i].address.country, students[i].address.province, students[i].address.city, students[i].address.district, students[i].grade);
					found = 1;
					break;
				}
			}
			else
			{
				printf("잘못된 숫자입니다\n");
				return;

			}

		case 4:
			if (strcmp(students[i].grade, keyword) == 0)
			{
				printf("%d   %s   %s / %s / %s / %s   %f\n", students[i].number, students[i].name, students[i].address.country, students[i].address.province, students[i].address.city, students[i].address.district, students[i].grade);
				found = 1;
				break;
			}
		default:
			printf("잘못된 선택입니다\n");
			return;
		}
	}
}
	//3. 학생 추가 및 삭제 기능 선택 시
	void student_AddDelete(void)
	{
		printf("(1. 학생 추가, 2. 학생 삭제)\n");
		printf("세부 기능을 선택하시오. ");
		int choice;
		scanf("%d", &choice);

		//학생 추가
		switch (choice)
		{
		case 1:
			if (student_count >= 100)
			{
				printf("더 이상 학생 정보를 추가할 수 없습니다.\n");
				return;
			}

			Student s;

			printf("번호 입력: ");
			scanf("%d", &s.number);
			printf("이름 입력: ");
			scanf("%s", s.name);
			printf("주소(나라) 입력: ");
			scanf("%s", s.address.country);
			printf("주소(도) 입력: ");
			scanf("%s", s.address.province);
			printf("주소(시) 입력: ");
			scanf("%s", s.address.city);
			printf("주소(구) 입력: ");
			scanf("%s", s.address.district);
			printf("성적 입력: ");
			scanf("%lf", &s.grade);

			students[student_count] = s;
			student_count++;
			printf("학생이 추가되었습니다\n");

			//학생 삭제
		case 2:

			int num, sel, targetIdx;
			int matchIdx[100];
			int matchCount = 0;

			printf("삭제할 학생 번호 입력: ");
			scanf("%d", &num);

			for (int i = 0; i < student_count; i++) {
				if (students[i].number == num) {
					matchIdx[matchCount] = i;
					matchCount++;
				}
			}

			if (matchCount == 0) {
				printf("해당 번호의 학생이 없습니다.\n");
				return;
			}

			if (matchCount == 1) {
				targetIdx = matchIdx[0];
			}
			else {
				printf("중복된 학생이 %d명 있습니다. 삭제할 학생을 선택하세요.\n", matchCount);
				for (int i = 0; i < matchCount; i++) {
					int idx = matchIdx[i];
					printf("%d. 이름:%s 주소:%s/%s/%s/%s 성적:%.2f\n", i + 1,
						students[idx].name, students[idx].address.country,
						students[idx].address.province, students[idx].address.city,
						students[idx].address.district, students[idx].grade);
				}
				printf("선택 (번호): ");
				scanf("%d", &sel);
				targetIdx = matchIdx[sel - 1];
			}

			for (int i = targetIdx; i < student_count - 1; i++) students[i] = students[i + 1];
			student_count--;
			printf("삭제되었습니다.\n");

		}


	}

	void toFile(void);

	int main()
	{
		printf("1. 학생 정렬, 2. 학생 찾기 3. 학생 추가 및 삭제, 4. 출석부 저장 및 불러오기\n");
		
		int choice;
		printf("기능을 선택하시오. ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:student_array(); break;
		case 2:student_search(); break;
		case 3:student_AddDelete(); break;
		case 4:toFile(); break;
		default: printf("잘못된 숫자 입력\n"); return 0;


		}
		return 0;
	}
