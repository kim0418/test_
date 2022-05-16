#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX_QUEUE_SIZE 5
#define MAX_NAME 10

typedef struct {
                char name[MAX_NAME];
}name;

typedef struct {                                // 큐 타입
                int  front;
                        int rear;
                                name  data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(char* message)
{
                fprintf(stderr, "%s\n", message);
                        exit(1);
}

void init_queue(QueueType* q)
{
                q->rear = -1;
                q->front = -1;
}

void queue_print(QueueType* q)
{
        printf("\n");
                for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
                                        if (i <= q->front || i > q->rear)
                                                                        printf(" | ");
                                                        else
                                                                                        printf("%s| ", q->data[i].name);
                                                                }
                printf("\n");
}

int is_full(QueueType* q)
{
                if (q->rear == MAX_QUEUE_SIZE - 1)
                                        return 1;
                        else
                                                return 0;
}

int is_empty(QueueType* q)
{
                if (q->front == q->rear)
                                        return 1;
                        else
                                                return 0;
}

void enqueue(QueueType* q, char *item)
{
                if (is_full(q)) {
                                        error("큐가 포화상태입니다.");
                                                        return;
                                                                }
                        strcpy(q->data[++(q->rear)].name, item);
}

char* dequeue(QueueType* q)
{
                if (is_empty(q)) {
                                        error("큐가 공백상태입니다.");
                                                                }
                else    return q->data[++(q->front)].name;
}

int main(void)
{
        char item[MAX_NAME];
        char name[MAX_NAME];
                QueueType q;

                init_queue(&q);

                fgets(name, MAX_NAME, stdin);
                name[strlen(name)-1] = '\0';
                enqueue(&q, name); queue_print(&q);

                fgets(name, MAX_NAME, stdin);
                name[strlen(name)-1] = '\0';
                enqueue(&q, name); queue_print(&q);

                fgets(name, MAX_NAME, stdin);
                name[strlen(name)-1] = '\0';
                enqueue(&q, name); queue_print(&q);

                strcpy(item, dequeue(&q)); queue_print(&q);
                strcpy(item, dequeue(&q)); queue_print(&q);
                strcpy(item, dequeue(&q)); queue_print(&q);
                return 0;
}
