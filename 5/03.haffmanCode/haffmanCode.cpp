/*************************************************************************
	> File Name: haffmanCode.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sat 28 Sep 2024 12:14:39 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define ROOT 1
#define FATHER(i) i / 2
#define LEFT(i) i * 2
#define RIGHT(i) i * 2 + 1

struct TreeNode{
    char c;
    int freq;
    TreeNode* left, *right;

    TreeNode(char c, int freq, TreeNode* left, TreeNode* right): c(c), freq(freq), left(left), right(right){}
    ~TreeNode() = default;
    
}; 


inline void submerge(TreeNode** &data, int i, int n){
    while(LEFT(i) < n){
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if(data[ind] > data[l]) ind = l;
        if(data[ind] > data[r]) ind = r;
        if(ind == i) break;
        swap(data[ind], data[i]);
        i = ind;
    }
    return;
}

void surface(TreeNode** &data, int i){
    while(i > ROOT && i < FATHER(i)){
        data[FATHER(i)] = data[i];
        i = FATHER(i);
    }
    return;
}

bool popflag = true;
void mypop(vector<TreeNode*> &heapNodes, int n){
    if(popflag) cout << "POP DEBUG..." << endl;
    popflag = false;
    TreeNode** data = &heapNodes[0] - 1;
    swap(data[1],data[n]); 
    submerge(data, 1, n);
    return;
}

bool pushflag = true;
void mypush(vector<TreeNode*> &heapNodes, int n){
    if(pushflag) cout << "PUSH DEBUG..." << endl;
    pushflag = false;
    TreeNode** data = &heapNodes[0] - 1;
    char c = '0';
    int freq = data[n]->freq + data[n - 1]->freq;
    data[n - 1] = new TreeNode(c, freq, NULL, NULL);
    surface(data, n - 1);
    return;
}

vector<TreeNode*> buildHeap(vector<TreeNode*> nodes){
    vector<TreeNode*> heapNodes = nodes;
    int n = heapNodes.size();
    TreeNode** data = &heapNodes[0] - 1;
    cout << "DEGUG3..." << endl; 
    for(int i = n / 2; i > 0; i--){
        submerge(data, i, n);
    }
    cout << "DEGUG4..." << endl;
    return heapNodes;
}
void output(TreeNode* p){
    string code;
        if(p->left == NULL && p->right == NULL){
            cout << p->c;
            cout << endl;
        }
        if(p->left){
            cout << '0';
            output(p->left);
        }
        if(p->right){
            cout << '1';
            output(p->right);
        }
}
TreeNode* buildHaffmanTree(vector<TreeNode*> &nodes){
    int n = nodes.size();
    cout << "DEGUG1..." << endl;
    vector<TreeNode*> heapNodes = buildHeap(nodes); 
    cout << "DEGUG2..." << endl;
    TreeNode *p1, *p2, *p3;
    for(int i = n; i > 1; i--){
        p1 = new TreeNode(heapNodes[0]->c, heapNodes[0]->freq, NULL, NULL); 
        mypop(heapNodes, i);
        p2 = new TreeNode(heapNodes[0]->c, heapNodes[0]->freq, NULL, NULL); 
        mypop(heapNodes, i - 1);
        p3 = new TreeNode('0', p1->freq + p2->freq, p1, p2); 
        mypush(heapNodes, i);
    }
    cout << "DEGUG5..." <<endl;
    output(p3);
    return p3;
}

int main(){
    TreeNode* root;
    int charSize, freq;
    char c;
    cin >> charSize;
    vector<TreeNode*> nodes;
    for(int i = 0; i < charSize; i++){
        cin >> c >> freq;  
        nodes.push_back(new TreeNode(c, freq, NULL, NULL));
    }
    
    root = buildHaffmanTree(nodes);
    
    for(int i = 0; i < charSize; i++){
        delete nodes[i];
    }
    return 0;
}
