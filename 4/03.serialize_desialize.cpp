/*************************************************************************
	> File Name: 03.serialize_desialize.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Wed 25 Sep 2024 06:26:10 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<stack>
using namespace std;

typedef struct Node{
    int key;
    int lflag, rflag;
    struct Node *lchild, *rchild;
} Node;

Node* getNewNode(int key){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    p->lflag = p->rflag = 0;
    return p;
}

void clear(Node* root){
    if(root == NULL) return;
    if(!root->lflag) clear(root->lchild);
    if(!root->rflag) clear(root->rchild);
    free(root);
    return;
}

Node* insert(Node* root, int key){
    if(root == NULL) return getNewNode(key); 
    if(rand() % 2) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;

}

char buff[1000];
int len = 0;

void __serialize(Node *root){
    if(root == NULL) return;
    printf("%d ", root->key);
    len += sprintf(buff + len, "%d", root->key);
    if(root->lchild == NULL && root->rchild == NULL) return;
    len += sprintf(buff + len, "(");
    __serialize(root->lchild);
    if(root->rchild) len += sprintf(buff + len, ",");
    __serialize(root->rchild);
    len += sprintf(buff + len, ")");
    return;
}

void serialize(Node* root){
    cout << "serialize : " << endl;
    memset(buff, 0, sizeof(buff));
    __serialize(root);
    return;
}
Node* deserialize(char* buff, int len){
    stack<Node*> s; 
    int flag = 0, scode = 0;
    Node *p = NULL, *root = NULL;
    for(int i = 0; buff[i]; i++){
        // 状态机算法
        switch(scode){
            case 0:{
                if(buff[i] >= '0'&& buff[i] <= '9') scode = 1;
                else if(buff[i] == '(') scode = 2;
                else if(buff[i] == ',') scode = 3;
                else scode = 4;
                i -= 1;
            }break;
            case 1:{
                int key = 0;
                while(buff[i] <= '9' && buff[i] >= '0'){
                    key = key * 10 + (buff[i] - '0');
                    i += 1;
                }
                p = getNewNode(key);
                if(!s.empty() && !flag) s.top()->lchild = p;
                if(!s.empty() && flag) s.top()->rchild = p;
                i -= 1;
                scode = 0;
            }break;
            case 2:{
                s.push(p);
                flag = 0;
                scode = 0;
            }break;
            case 3:{
                flag = 1;
                scode = 0;
            }break;
            case 4:{
                if(!s.empty()) root = s.top();
                s.pop();
                scode = 0;
            }break;
        } 
    }

return root;

}


int main(){
    srand(time(0));
    #define MAX_NODE 10
    Node *root = NULL;
    for(int i = 0; i < MAX_NODE; i++) root = insert(root, rand() % 100);
    serialize(root);    
    cout << endl;
    for(int i = 0; i < len; i++) printf("%c", buff[i]);
    cout << endl;
    clear(root);

    Node *new_root = deserialize(buff, len);
    serialize(new_root);
    cout << endl;
    clear(new_root);
    return 0;
}
