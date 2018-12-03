#include <iostream>
#include <stdlib.h>
using namespace std;


class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node() {
        prev = NULL;
        next = NULL;
    }
    Node(int num) {
        value = num;
        prev = NULL;
        next = NULL;
    }
};

class Deque {
public:
    Node* front;
    Node* end;
    Deque() {
        front = NULL;
        end = NULL;
    }
    void push_front(int num) {
        Node* n = new Node(num);
        if (front == NULL) {
            front = n;
            end = n;          
        }
        else {
            Node* temp = front;
            front = n;
            
            front->next = temp;
            temp->prev = front;
        }
    }
    void push_back(int num) {
        Node* n = new Node(num);
        if (front == NULL) {
            front = n;
            end = n;          
        }
        else {
            end->next = n;
            n->prev = end;
            end = n;
        }
    }

    void pop() {
        Node* temp = front;
        front = front->next;        
        if (front != NULL) 
            front->prev = NULL;
        free(temp);
        //printAll();
    }

    void move_left() {
        Node* temp = front;
        front = front->next;
        front->prev = NULL;
        end->next = temp;
        temp->prev = end;
        temp->next = NULL;
        end = temp;
        return;
    }
    void move_right() {
        Node* temp = end;
        end = end->prev;
        end->next = NULL;
        temp->next = front;
        temp->prev = NULL;
        front->prev = temp;
        front = temp;
        return;
    }

    int find_left(int num) {
        int cnt = 0;
        Node* cur = front;
        if (cur->value == num) 
            return cnt;
        
        cur = end;
        cnt++;
        while (true) {
            if (cur->value == num) {
                break;
            }
            cur = cur->prev;
            cnt++;
        }
        return cnt;

    }
    int find_right(int num) {
        int cnt = 0;
        Node* cur = front;
        while (true) {
            if (cur->value == num) {
                break;
            }
            cur = cur->next;
            cnt++;
        }
        return cnt;
    }
    
    void printAll() {
        Node* cur = front;
        while(cur != NULL) {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
        return;
    }
};


int main() {
    int N, M;
    cin >> N >> M;
    Deque dq;
    
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    int Answer = 0;
    for (int i = 0; i < M; i++) {
        int find_num;
        cin >> find_num;
        int left_cnt = dq.find_left(find_num);
        int right_cnt = dq.find_right(find_num);
        if (left_cnt > right_cnt) {
            for (int j = 0; j < right_cnt; j++) {
                dq.move_left();
                Answer++;
            }            
        }
        else {
            for (int j = 0; j < left_cnt; j++) {
                dq.move_right();
                Answer++;
            }
        }
        dq.pop();
    }
    
    cout << Answer << endl;
}