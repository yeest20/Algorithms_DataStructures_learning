/*************************************************************************
	> File Name: 1.queue.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sun 22 Sep 2024 11:59:45 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

/*typedef struct Vector{
    int *data;
} Vector;

Vector* initVector(int n){
    Vector *v = (Vector*)malloc(sizeof(int) * n);
    return v;
};

void clearVector(Vector *v){
    free();
    return;
}

int insertVector(Vector *v, int pos, int val){
    v->data[pos] = val;
    return;
}
*/
typedef struct Queue{
    int *data;
    int head, tail, size, count;
} Queue;

Queue *initQueue(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * n);
    q->size = n;
    q->head = q->tail = 0;
    q->count = 0;
    return q;
}

void clear(Queue *q){
    if(q == NULL) return;
    free(q->data);
    free(q);
    return;
}
int isEmpty(Queue *q){
    return q->count == 0;
}
int push(Queue *q, int val){
    if(q->count == q->size) return 0;
    q->data[q->tail] = val;
    q->tail += 1;
    if(q->tail == q->size) q->tail = 0;
    printf("head = %d\n", q->head);
    printf("tail = %d\n", q->tail);
    q->count += 1;
    printf("count = %d\n",q->count);
    return 1;
}
int front(Queue *q){
    return q->data[q->head];
}
int pop(Queue *q){
    if(isEmpty(q)) return 0;
    q->head += 1;
    if(q->head == q->size) q->head = 0;
    printf("head = %d\n", q->head);
    printf("tail = %d\n", q->tail);
    q->count -= 1;
    printf("count = %d\n",q->count);
    return 1;
}
void output_queue(Queue *q){
    int index = q->head;
    for(int i = 0; i < q->count; i++){
        if(index + i == q->size) index = -i;
        printf("| %d ", q->data[index + i]);
        
    }
    cout << endl;
}

int main(){
    srand(time(0));
    #define MAX_OP  10
    Queue *q = initQueue(MAX_OP);
    printf("isEmpty = %d\n\n", isEmpty(q));
    for(int i = 0; i < 30; i++){
        int OP = rand() % 4;
        int val = rand() % 10, ret;
        switch(OP){
            case 0:case 1:case 2:
                ret = push(q, val);
                printf("push = %d\nval = %d\n", ret, val);
                output_queue(q);
                break;
            case 3:
                ret = pop(q);
                printf("pop = %d\n", ret);
                output_queue(q);
                break;
        }
        printf("front = %d\n", front(q));
        cout << endl;
    } 
    cout << endl;
    printf("isEmpty = %d\n", isEmpty(q));
    clear(q);

    return 0;
}
