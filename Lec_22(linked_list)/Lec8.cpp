/*
Circular Linked List
*/

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = NULL;
    }

    // inseart at begin
    void insert_at_begin(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
            /*
            without head pointer
            newNode->next = tail->next;
            tail->next = newNode;
            */
        }
    }

    // insert at tail / end
    void insert_at_end(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    //delete the node from head / front
    void delete_at_front() {
        if(head == NULL) {
            return;
        }
        else if(head == tail) {
            delete head;
        } else {
        Node* temp = head;
        head = head->next;
        tail->next = head;

        temp->next = NULL;
        delete temp;
        }
    }

    // delete from end / tail
    void delete_from_tail() {
        if (head == NULL) return;
        else if(head == tail) {
            delete head;
        } else {
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail) {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    // print
    void print() {
        if(head == NULL) return;

        cout << head->data << "->";
        Node* temp = head->next;

        while(temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << temp->data << endl;
    }
    


};

int main() {
    CircularList cll;
    cll.insert_at_begin(3);
    cll.insert_at_begin(2);
    cll.insert_at_begin(1);
    cll.insert_at_end(4);
    cll.insert_at_end(5);

    cll.delete_at_front();

    cll.delete_from_tail();
    cll.print();

    return 0;
}