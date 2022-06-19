#include <stdio.h>
#include <stdlib.h>
#define MAX 200

struct queue
{
	int real;
	int front;
	int queArr[MAX];
};

void init(struct queue *q)
{
	q->real = 0;
	q->front = 0;
}

int isEmpty(struct queue *q)
{
	return (q->real == q->front);
}

int isFull(struct queue *q)
{
	return (q->real == MAX - 1);
}

void enqueue(struct queue *q, int item)
{
		q->queArr[((q->real)++) % MAX] = item;
}

int dequeue(struct queue *q)
{
		return q->queArr[((q->front)++) % MAX];
}

int frontPeek(struct queue *q)
{
	return q->queArr[q->front];
}

int main(int argc, char* argv[])
{
	struct queue q;
	init(&q);

	int T, N, count = 0;
	int value = 0;
	int cost[MAX/2][MAX];
	int result[MAX/2][MAX];
	int cnt[MAX/2];

	scanf("%d", &T);
	for(int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		cnt[i] = N;
		for(int j = 0; j < 2*N; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	for(int i = 0; i < T; i++)
	{
		enqueue(&q, cost[i][0]);
		for(int j = 0; j < 2*N-1; j++)
		{
			value = cost[i][j+1];
			if(value % 4 == 0)
			{
				if(frontPeek(&q) == (value/4)*3)
				{
					result[i][count] = dequeue(&q);
					count++;
				}
				else
				{
					enqueue(&q, value);
				}
			}
			else
			{
				enqueue(&q, value);
			}
		}
		init(&q);
		count = 0;
	}
	for(int i = 0; i < T; i++)
	{
		printf("Case #%d: ", i+1);
		for(int j = 0; j < cnt[i]; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}







/*#include <stdio.h>
#include <stdlib.h>

#define MAX 5000

struct que
{
	int real;
	int front;
	int queArr[MAX];
};

void init(struct que *q)
{
	q->real = -1;
	q->front = -1;
}

int isEmpty(struct que *q)
{
	return (q->real == q->front);
}

int isFull(struct que *q)
{
	return (q->real == MAX - 1);
}

void enqueue(struct que *q, int item, int n)
{
		q->queArr[(++(q->real)) % n] = item;
}

int dequeue(struct que *q, int n)
{
		return q->queArr[(++(q->front)) % n];
}


int main(int argc, char* argv[])
{
	struct que q;
	int N = 0;
	int K = 0;
	int count = 0;
	scanf("%d %d", &N, &K);
	init(&q);

	for(int i = 1; i <= N; i++)
	{
		enqueue(&q, i, N);
	}
	
	printf("<");

	while(!isEmpty(&q))
	{
		int value = dequeue(&q, N);
		count++;
		if(count % K == 0)
		{
			if(isEmpty(&q))
				printf("%d", value);
			else
				printf("%d, ", value);
		}
		else
		{
			enqueue(&q, value, N);
		}
	}
	printf(">\n");
	return 0;
}*/
