/*************************************************************************
	> File Name: 2.queue_list.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Mon 23 Sep 2024 03:33:38 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

typedef struct Linklist{
    Node head, *tail;
} Linklist;

Linklist* initLinklist(){
    Linklist* l = (Linklist *)malloc(sizeof(Linklist));
    l->head.next = NULL;
    l->tail = &(l->head);
    return l;
}

void clearLinklist(Linklist *l){
    Node *n = l->head.next;
    Node *temp;
    while(n) {
        temp = n->next;
        free(n);
        n = temp;
    }
    free(l);
    return;
}

int insertTail(Linklist *l, int val){
    Node *n =(Node*) malloc(sizeof(Node));
    n->data = val;
    n->next =NULL;
    l->tail->next = n;
    l->tail = n;
    return 1;
}

int eraseHead(Linklist *l){
    Node* temp = l->head.next;
    l->head.next = l->head.next->next;
    free(temp);
    if(l->head.next == NULL) l->tail = &(l->head); //处理tail， 否则容易出BUG 
    return 1;
}
int front_linklist(Linklist *l){
    if(l->head.next == NULL) return 0;
    Node* n = l->head.next;
    return n->data;

}
typedef struct Queue{
    Linklist *l;
    int count;
} Queue;

Queue* initQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->l = initLinklist();
    q->count = 0;
    return q;
}

void clear(Queue *q){
    if(q == NULL) return;
    clearLinklist(q->l);
    free(q);
    return;
}

int isEmpty(Queue *q){
    return q->count == 0;
}

int front(Queue *q){
    if(isEmpty(q)) return 0;
    return front_linklist(q->l);
}

int push(Queue *q, int val){
    insertTail(q->l, val);
    q->count += 1;
    return 1;
}

int pop(Queue *q){
    if(q->l->head.next == NULL) return 0;
    eraseHead(q->l); 
    q->count -= 1;
    return 1;
}

void output_queue(Queue *q){
    Node *n = q->l->head.next;
    while(n){
        printf("| %d ", n->data);
        n = n->next;
    }
    cout << endl;
    return;
}
int main(){
    srand(time(0));
    #define MAX_OP 10
    Queue *q = initQueue();
    printf("q is empty = %d\n", isEmpty(q));
    cout << endl;
    for(int i = 0; i < MAX_OP; i++){
        int OP = rand() % 5;
        int val = rand() % 10, ret;
        switch(OP){
            case 0: case 1: case 2:
                ret = push(q, val);
                printf("push %d into q is %d\n", val, ret);
                output_queue(q);
                cout << endl;
                break;
            case 3: case 4:
                ret = pop(q);
                printf("pop from q is %d\n", ret);
                output_queue(q);
                printf("front of q is %d\n", front(q));
                cout << endl;
                break;
        } 
    }
    printf("q is empty = %d\n", isEmpty(q));
    clear(q);
    return 0;
}


