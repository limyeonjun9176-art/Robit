#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
	int size;
}Queue;

void init(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
void Enqueue(Queue* q, int data)
{
	Node* newNode = (Node*)(malloc(sizeof(Node)));
	
	if (newNode == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}
	newNode->data = data; //새 노드에 사용자가 입력한 데이터값을 대입
	newNode->next = NULL; //새 노드의 다음 노드는 없음

	if (q->rear == NULL)//큐가 비어있는 경우
	{
		//front와 rear 모두 newNode를 가리키도록 함
		q->front = newNode; //front의 경우, 첫 번째에 들어온 값이 나가기 전까진 계속 이 노드를 가리키고 있음
		q->rear = newNode;
	}
	else //큐가 비어있지 않은 경우
	{
		q->rear->next = newNode; //기존 rear의 next가 새로운 노드를 가리키고
		q->rear = newNode;//rear를 새로운 노드로 갱신한다
	}
	q->size++;
}

void Dequeue(Queue* q)
{
	if (q->rear == NULL)
		printf("큐가 비어있음\n");
	else //큐가 비어있지 않은 경우
	{
		Node* pp = q->front; //새 노드 pp에 front 대입
		printf("Dequeue된 값 : %d\n\n", pp->data);
		
	    q->front = pp->next; //front가 가리키는 값을 한 칸 뒤로 이동시킨다.=front를 삭제하고 그 뒤의 값이 front로 갱신

		if (q->front == NULL) //삭제된 front가 마지막 노드였다면 현재 q->front는 비어있는 상태
			q->rear = NULL; //rear도 비어있는 상태로 만들어준다
		free(pp); //pp 즉 이전 front 메모리 해제
		q->size--;
	}
}
int size(Queue* q) { return q->size; }

void front(Queue* q)
{
	if (q->front == NULL)
		printf("큐가 비어있음\n\n");
	else
		printf("front : %d\n\n",q->front->data);
}

void rear(Queue* q)
{
	if (q->rear == NULL)
		printf("큐가 비어있음\n\n");
	else
		printf("rear : %d\n\n",q->rear->data);
}

void isEmpty(Queue* q)
{
	if (q->front == NULL)
		printf("True\n\n");
	else
		printf("False\n\n");
}

void printQueue(Queue* q)
{
	if (q->rear == NULL)
	{
		printf("큐가 비어있음\n\n");
		return;
	}

	Node* cur = q->front; //front에서부터 rear까지 이동할 때 쓸 노드를 만든다

	printf("Queue 내 모든 값 : (front) ");
	while (cur != NULL)//
	{
		printf("%d ", cur->data); 
		cur = cur->next; //한 칸 이동
		//이동한 후의 cur 자리가 비어있으면 반복문 종료

	}
	printf("(rear)\n\n");
}

int main(void)
{
	int opt;
	int data;

	Queue q;

	init(&q);//큐 초기화,

    printf("1.Enqueue, 2.Dequeue, 3.size, 4.front, 5.rear, 6.isEmpty 7.printQueue\n");
	while (1) {
		//기능을 선택하고 switch ~ case문을 활용해 선택에 따라 실행한다.
		
		printf("기능을 선택하시오. ");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			printf("큐에 추가할 정수 데이터를 입력하시오. ");
			scanf("%d", &data);
			printf("\n");
			Enqueue(&q, data);
			break;

		case 2:
			Dequeue(&q);
			break;
		case 3:
			printf("size : %d\n\n", size(&q));
			break;
		case 4:
			front(&q);
			break;
		case 5:
			rear(&q);
			break;
		case 6:
			isEmpty(&q);
			break;
		case 7:
			printQueue(&q);
			break;
		}
	}
	return 0;
}


