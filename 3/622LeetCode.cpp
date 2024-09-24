/*************************************************************************
	> File Name: 622LeetCode.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Tue 24 Sep 2024 07:41:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class MyCircularQueue {
public:
    int count;
    int size;
    Node *head, *tail;
    MyCircularQueue(int k) {
        head = new Node();
        tail = head;
        for(int i = 1; i < k; i++){
            tail->next = new Node();
            tail = tail->next;
        }
        tail->next = head; 
        count = 0;
        size = k;
        return;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        tail = tail->next;
        tail->data = value;
        count += 1;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head = head->next;
        count -= 1; 
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1; 
        return head->data;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return tail->data;
    }
    
    bool isEmpty() {
       return  this->count == 0;
    }
    
    bool isFull() {
       return count == size; 
    }
};

int main(){
    MyCircularQueue* q = new MyCircularQueue(5);
    bool param_1 = q->enQueue(1);
    cout << param_1 << endl;
    bool param_2 = q->deQueue();
    cout << param_2 << endl;
    q->enQueue(10086);
    int param_3 = q->Front();
    int param_4 = q->Rear();
    cout << param_3 << param_4 << endl;
    bool param_5 = q->isEmpty();
    cout << param_5 << endl;


    return 0;
    
}




/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull()mZ
 */
