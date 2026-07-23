#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data; //노드가 저장할 데이터
	struct _Node* next; //next =다음 노드의 주소를 저장하는 포인터, 따라서 이 줄은 다음 노드가 어디에 있는지 그 주소를 저장하는 변수이다.
}Node;

typedef struct stack {
	Node* top; //스택의 가장 위에 있는 노드의 주소, 후입선출을 도와준다.
	int size; //현재 스택에 들어있는 노드의 개수
}Stack;

//stack 초기화->구조체를 가리키는 포인터를 사용해 구조체의 내용을 직접 수정
void init(Stack* s)
{
	s->top = NULL;
	s->size = 0;
}

//push 함수
void push(Stack* s, int data)
{
	//새로운 노드를 만들어준다.
	Node* NewNode;
	NewNode = (Node*)(malloc(sizeof(Node)));

	if (NewNode == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}

	NewNode->data = data; //사용자가 입력한 데이터를 노드의 data 멤버에 대입한다.
	NewNode->next = s->top; //새로운 노드의 다음 노드 주소에 스택의 top 주소를 대입하여 새 노드의 next가 top을 가리키게 한다.
	s->top = NewNode; //새로운 노드가 top이 된다.
	s->size++;
}

//pop 함수
void pop(Stack* s)
{
	//스택이 비어있을 시 비어있다고 출력
	if (s->top == NULL)
		printf("스택이 비어있음\n\n");
	else
	{
		//pp 노드를 새로 만들고 pop할 노드의 주소인 s->top을 대입
		Node* pp = s->top;
		printf("pop된 값 : %d\n\n", pp->data);
		s->top = pp->next; //top을 pp 노드 이전 노드로 갱신
		s->size--;
		free(pp); //pp가 가리키고 있던 노드가 삭제
	}

}

//size 함수
void size(Stack* s)
{
	printf("size : %d\n\n", s->size);
}

//top 함수
void top(Stack* s)
{
	if (s->top == NULL)
		printf("스택이 비어있음\n\n");
	else
		printf("top에 위치한 값 : %d\n\n", s->top->data);
}

//isEmpty 함수-> 스택에 데이터가 있는지 판별
void isEmpty(Stack *s)
{
	if (s->top == NULL)
		printf("true\n\n");
	else
		printf("false\n\n");
}

//printStack 함수-> 스택 내 모든 값 출력
void printStack(Stack *s)
{
	if (s->top == NULL)
		printf("스택이 비어있음\n\n");
	else
	{
		//새로운 노드를 만들어 top부터 한 칸씩 앞으로 이동시킨다.
		Node* printNext = s->top;
		printf("스택 내 모든 값 : ");
		
		//더 이상 이동할 수 없을 때까지(printNect==Null) 한 칸씩 앞으로 이동하며 스택 내의 데이터값을 출력
		while(printNext!=NULL)
		{
				printf("%d ", printNext->data);
				printNext = printNext->next; //printNext(포인터)에 printNext의 next(이전 노드의 주소) 멤버를 대입해 앞으로 한 칸 이동
			}
		
		printf("\n\n");
	}
}


void main()
{
	int opt;
	int data;

	Stack s;

	init(&s);//스택 초기화,


	while (1) {
		//기능을 선택하고 switch ~ case문을 활용해 선택에 따라 실행한다.
		printf("기능을 선택하시오.(1.push, 2.pop, 3.size, 4.top, 5.isEmpty, 6.printStack) ");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			printf("스택에 추가할 정수 데이터를 입력하시오. ");
			scanf("%d", &data);
			printf("\n");
			push(&s, data);
			break;

		case 2:
			pop(&s);
			break;
		case 3:
			size(s);
			break;
		case 4:
			top(s);
			break;
		case 5:
			isEmpty(s);
			break;
		case 6:
			printStack(&s);
			break;
		}

	}
}