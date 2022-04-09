#include <bits/stdc++.h>
using namespace std;
struct DoublyLinkedList
{
    int val;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;
    DoublyLinkedList(int val)
    {
        this->val = val;
        this->next = next;
    }

    void link(DoublyLinkedList* prev, DoublyLinkedList* next) {
        if (prev) {
            prev->next = this;
        }
        if (next) {
            next->prev = this;
        }
        this->prev = prev;
        this->next = next;
    }

    void unlink()
    {

        if (this->next)
        {
            this->next->prev = prev;
        }
        if (this->prev)
        {
            this->prev->next = next;
        }
        this->prev = NULL;
        this->next = NULL;
    }
};

class Deque
{
    DoublyLinkedList *head;
    DoublyLinkedList *tail;
    int size;

public:
    Deque()
    {
        head = new DoublyLinkedList(0);
        tail = head;
        size = 0;
    }

    void push_back(int n)
    {
        DoublyLinkedList *node = new DoublyLinkedList(n);
        node->link(tail, NULL);
        tail = node;
        size++;
    }

    void push_front(int n)
    {
        DoublyLinkedList *node = new DoublyLinkedList(n);
        node->link(head, head->next);
        size++;

        if (size == 1) {
            tail = node;
        }
    }

    int pop_back()
    {
        if (size == 0) {
            return -1;
        }

        DoublyLinkedList *node = tail;
        tail = node->prev;
        node->unlink();
        size--;

        return node->val;
    }

    int pop_front()
    {
        if (size == 0) {
            return -1;
        }

        DoublyLinkedList* node = head->next;
        node->unlink();
        size--;

        if (size == 0) {
            tail = head;
        }

        return node->val;
    }
};

int main() {
    Deque dq;
    dq.push_back(8);
    dq.push_back(15);
    dq.push_front(20);    
    dq.push_back(30);

    cout << dq.pop_back() << endl;
    cout << dq.pop_front() << endl;
    cout << dq.pop_front() << endl;
    cout << dq.pop_front() << endl;

    cout << dq.pop_front() << endl;

    dq.push_back(9);
    cout << dq.pop_front() << endl;
    return 0;
}