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



