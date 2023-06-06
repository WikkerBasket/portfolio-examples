#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() { head = nullptr; tail = nullptr; }

    void insertNode(int data);

    void deleteNode(int nodeOffset);

    void printList();

    void printListBack();
};

int main() {
    LinkedList list;

    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    std::cout << "Elements of the list are: ";
    list.printList();

    list.deleteNode(4);

    std::cout << "Elements of the list are: ";
    list.printList();

    std::cout << "Elements of the list in reverse order are: ";
    list.printListBack();

    return 0;
}

void LinkedList::deleteNode(int nodeOffset) {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* temp = head;
    int currentPosition = 1;

    if (nodeOffset == 1) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
        return;
    }
    
    while (temp != nullptr && currentPosition < nodeOffset) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) {
        std::cout << "Invalid position to delete." << std::endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp == tail) {
        tail = temp->prev;
    }
    delete temp;
}

void LinkedList::printList() {
    Node* temp = head;

    if (temp == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


void LinkedList::insertNode(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void LinkedList::printListBack() {
    Node* temp = tail;

    if (temp == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}