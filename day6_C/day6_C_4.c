#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Node
{
	char data;
	struct _Node* next;
}Node;

//stack
typedef struct _Stack
{
	Node* top;
}Stack;

//stack 초기화
void Stack_init(Stack* s)
{
	s->top = NULL;
}

//stack push 함수
void push(Stack* s,char c)
{
	Node* newNode = (Node*)(malloc(sizeof(Node)));
	if (newNode == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}
	newNode->data = c;
	newNode->next = s->top;
	s->top = newNode;
}

//stack pop 함수
char pop(Stack* s)
{
	Node* pp = s->top;
	s->top = pp->next;
	char p1 = pp->data;
	free(pp);
	return p1;
}

//Queue
typedef struct _Queue
{
	Node *front;
	Node *rear;
}Queue;

//Queue 초기화
void Queue_init(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
}

//Queue EnQueue 함수
void Enqueue(Queue* q, char c)
{
	Node* newQueue = (Node*)(malloc(sizeof(Node)));
	newQueue->data = c;
	newQueue->next = NULL;
	if (q->rear == NULL)
	{
		q->rear = newQueue;
		q->front = newQueue;
	}
	else
	{
		q->rear->next = newQueue;
		q->rear = newQueue;
	}
}

//Queue Dequeue  
char Dequeue(Queue* q)
{
	Node* pp2 = q->front;
	q->front = pp2->next;
	if (q->front == NULL)
		q->rear = NULL;
	char p2 = pp2->data;
	free(pp2);
	return p2;

}

//회문 판별
//알파벳만 골라 스택과 큐에 push 또는 EnQueue
//pop, Dequeue하면서 비교

//bool -> 참 또는 거짓 저장, <bool 함수> 참 또는 거짓을 반환하는 함수
bool isPalindrome(char* str)
{
	//스택과 큐를 만들어준다. 
	Stack s;
	Queue q;
	//스택과 큐 초기화
	Stack_init(&s);
	Queue_init(&q);

	//str 문자열의 길이 측정
	int len = strlen(str);
	int count = 0;

	for (int i = 0;i < len;i++)
	{
		//문자열에서 알파벳 소문자 범위에 해당하는 문자만 스택과 큐에 저장
		if ('a' <= str[i] && str[i] <= 'z')
		{
			char c = str[i];
			push(&s, c);
			Enqueue(&q, c);
			count++;
		}
	}
	
	bool result = true;
	for (int i = 0;i < count;i++)
	{
		//스택에서 꺼낸 값과 큐에서 꺼낸 값을 비교, 다르다면 result=false
		char stack_m = pop(&s);
		char queue_m = Dequeue(&q);
		if (stack_m != queue_m)
			result = false;
	}
	return result; 
}


int main(void)
{
	char str[256];

	printf("문자열 입력 : ");
	fgets(str, sizeof(str), stdin); //사용자에게 문자열을 입력받아 str에 저장
	str[strcspn(str, "\n")] = '\0'; //사용자가 입력하는 과정에서 \n이 저장될 수 있음. \n 제거
	//strcspn--> str에서 \n이 처음 등장하는 위치를 찾아줌, 그 부분을 \0으로 바꿈

	if (isPalindrome(str)) //isPalindrome 함수가 true를 반환하면 회문, false를 반환하면 회문X 출력
		printf("회문입니다\n");
	else
		printf("회문이 아닙니다\n");

	return 0;
}