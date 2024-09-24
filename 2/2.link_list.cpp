/*************************************************************************
	> File Name: 2.link_list.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sat 21 Sep 2024 12:47:23 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node* getNewNode(int val){
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Node* insert(Node* head,int pos, int val){ 
    Node new_head, *p = &new_head; //虚拟头节点
    new_head.next = head;
    for(int i = 0; i < pos; i++)  p = p->next;
    
    Node* new_node = getNewNode(val);
    new_node->next = p->next;
    p->next = new_node;
    return head;

}

int output_linklist(Node* head){
    int cnt = 0;
    int i = 0;
    for(Node *p = head; p; p = p->next){
        printf("%3d  ", i++);
    }
    cout <<endl;
    for(Node *p = head; p; p = p->next, cnt++){
        printf("%3d->", p->data);
    }
    cout << endl;
    return cnt;
}

void clear(Node *head){
    if(head == NULL) return;
    for(Node* p = head, *q; p; p = q){
        q = p->next; 
        free(p);
    }
    return;
}

void find(Node *head, int val){
    int n = 0;
    int arr[20] = {0};
    for(Node* p = head; p; p = p->next){
        if(p->data != val){
            arr[n++] = 0;
            continue;
        }
        arr[n++] = 1;
    }
    output_linklist(head);
    for(int i = 0; i < n; i++){
        if(!arr[i]) {
            printf("     ");
            continue;
        }
        printf("  ^  ");
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        if(!arr[i]) {
            printf("     ");
            continue;
        }
        printf("  |  ");
    }
    cout << endl;
}

int main(){
    srand(time(0));
    #define MAX_OP 5
    Node* head = NULL;
    for(int i = 0; i < MAX_OP; i++){
        int pos = rand() % (i  + 1), val = rand() % 100;
        printf("insert %d at %d to linklist\n", val, pos);
        head = insert(head, pos, val);
        output_linklist(head);
    }
    int val;
    while(scanf("%d", &val) != EOF){
        find(head, val);
    }
    clear(head);
    return 0;
}
