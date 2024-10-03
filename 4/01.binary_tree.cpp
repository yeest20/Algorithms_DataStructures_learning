/*************************************************************************
	> File Name: binary_tree.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Tue 24 Sep 2024 09:46:29 PM CST
 ************************************************************************/

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef struct Node{
    int key;
    struct Node* lchild, *rchild;
} Node; 

Node *getNewNode(int key){
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->lchild = n->rchild = NULL;
    return n;
}

void clear(Node *root){
    if(root == NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
void bfs(Node* root){
    if(root == NULL) return;
    cout << "bfs : " << endl;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *p = q.front();
        printf("%d\n", p->key);
        if(p->lchild) {
            q.push(p->lchild);
            printf("    lchild: %d\n", p->lchild->key);
        }
        if(p->rchild) {
            q.push(p->rchild);
            printf("    rchild: %d\n", p->rchild->key);
        }
        q.pop();
    }
    cout << endl;
    return;
}

stack<Node*> s;
void dfs(Node* root){
    if(root == NULL) return;
    s.push(root);
    if(root->lchild) dfs(root->lchild);
    if(root->rchild) dfs(root->rchild);
    printf("%d ", root->key); 
    return;
}

Node *insert(Node *root, int key){
    if(root == NULL) return getNewNode(key);
    if(rand() % 2) root->lchild = insert(root->lchild, key); 
    else root->rchild = insert(root->rchild, key);
    return root;
}

int main(){
    srand(time(0));
    Node *root = NULL;
    #define MAX_NODE 10
    for(int i = 0; i < MAX_NODE; i++){
        root = insert(root, rand() % 100);
    }
    bfs(root);
    cout << "dfs : " << endl;
    dfs(root);
    cout << endl;
    return 0;
}
