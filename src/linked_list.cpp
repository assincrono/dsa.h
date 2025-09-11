#include "dsa.h"
#include <iostream>

Node::Node(int item) {
    this->val = item;
    this->next = NULL;
    this->prev = NULL;
}

LinkedList::LinkedList() {
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

void LinkedList::push_front(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    length++;
}

void LinkedList::push_back(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    length++;
}

int LinkedList::pop_front() {
    int val = head->val;
    head = head->next;
    head->prev = NULL;

    length--;
    return val;
}

int LinkedList::pop_back() {
    int val = tail->val;
    tail = tail->prev;
    tail->next = NULL;

    length--;
    return val;
}

void LinkedList::insert(int index, int val) {
    int count = 0;
    Node* currentNode = head;

    if (index == 0) {
        this->push_front(val);
        return;
    } else if (index == length) {
        this->push_back(val);
        return;
    }

    while (count <= index) {
        if (currentNode == NULL) {
            throw std::out_of_range("Index out of bounds.");
        }

        if (count == index) {
            Node* newNode = new Node(val);
            
            newNode->prev = currentNode->prev;
            newNode->next = currentNode;

            newNode->prev->next = newNode;
            currentNode->prev = newNode;
            
            length++;
            return;
        }

        currentNode = currentNode->next;
        count++;
    }
}

void LinkedList::erase(int index) {
    int count = 0;
    Node* currentNode = head;

    while (count <= index) {
        if (currentNode == NULL) {
            throw std::out_of_range("Index out of bounds.");
        }

        if (count == index) {
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;
            length--;
            return;
        }

        currentNode = currentNode->next;
        count++;
    }
}

int LinkedList::value_n_from_end(int n) {
    Node* currentNode = tail;

    while (n >= 0) {
        if (currentNode == NULL) {
            throw std::out_of_range("Index out of bounds.");
        }

        if (n == 0) {
            return currentNode->val;
        }

        currentNode = currentNode->prev;
        n--;
    }

    return -1;
}

void LinkedList::reverse() {
    Node* currentNode = tail;
    Node* currentHead = head;

    tail = currentHead;
    head = currentNode;

    int count = length;

    while (count > 0) {
        Node* prev = currentNode->prev;
        Node* next = currentNode->next;

        currentNode->prev = next;
        currentNode->next = prev;

        currentNode = currentNode->next;
        count--;
    }
}

int LinkedList::front() {
    return head->val;
}

int LinkedList::back() {
    return tail->val;
}

int LinkedList::size() {
    return length;
}

bool LinkedList::empty() {
    return length == 0;
}