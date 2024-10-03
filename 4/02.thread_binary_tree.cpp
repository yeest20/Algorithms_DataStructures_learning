/*************************************************************************
	> File Name: 02.thread_binary_tree.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Wed 25 Sep 2024 10:22:56 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef struct Node{
    int data;
    int ltag, rtag; //1: thread 0:edge
    struct Node* lchild, *rchlid;
} Node;

Node *getNewNode(int key){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchlid = NULL;
    p->ltag = p->rtag = 0;
    return p;
}

void clear(Node* root){
    if(root == NULL) return;
    if(!root->ltag) clear(root->lchild);
    if(!root->rtag) clear(root->rchlid);
    free(root);
    return;
}

Node *insert(Node *root, int key){
    if(root == NULL) return getNewNode(key);
    if(rand() % 2) root->lchild = insert(root->lchild, key);
    else root->rchlid = insert(root->rchlid, key);
    return root;
}

void preOrder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    
    if(!root->ltag) preOrder(root->lchild);
    if(!root->rtag) preOrder(root->rchlid);
    return;
}

Node *pre_node;
void __buildPreOrderThread(Node* root){
    if(root == NULL) return;

    printf("%d ", root->data);

    if(!root->lchild) {root->lchild = pre_node, root->ltag = 1;}
    if(pre_node && !pre_node->rchlid) {pre_node->rchlid = root, pre_node->rtag = 1;}
    pre_node = root;

    if(!root->ltag) __buildPreOrderThread(root->lchild);
    if(!root->rtag) __buildPreOrderThread(root->rchlid);
    return;
}

void buildPreOrderThread(Node *root){
    __buildPreOrderThread(root);
    pre_node->rchlid = NULL;
    pre_node->rtag = 1;
    return;
}

void inOrder(Node* root){
    if(root == NULL) return;
    if(!root->ltag) inOrder(root->lchild);
    printf("%d ", root->data);
    if(!root->rtag) inOrder(root->rchlid);
    return;
}

void postOrder(Node* root){
    if(root == NULL) return;
    if(!root->ltag) postOrder(root->lchild);
    if(!root->rtag) postOrder(root->rchlid);
    printf("%d ", root->data);
    return;
}

Node* getNext(Node *node){
    if(node->rtag == 1) return node->rchlid;
    if(node->ltag == 0) return node->lchild;
    return  node->rchlid;
}

int main(){
    srand(time(0));
    Node *root = NULL;
    #define MAX_NODE 10
    for(int i = 0; i < MAX_NODE; i++){
        root = insert(root, rand() % 100);
    }

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    
    pre_node = NULL;
    buildPreOrderThread(root);
    cout << endl;

    // 链表遍历
    Node *node = root;
    while(node){
        printf("%d ", node->data);
        node = getNext(node);
    } 
    cout << endl;

    clear(root);
    return 0;
}
