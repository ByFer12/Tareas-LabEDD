#include <iostream>
using namespace std;

// Definición de la estructura de un nodo de la lista
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Función para insertar un nuevo nodo al final de la lista
void insert(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Función para imprimir los elementos de la lista
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Función para liberar la memoria ocupada por los nodos de la lista
void deleteList(Node* &head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Algoritmo de ordenamiento por inserción para listas enlazadas
void insertionSort(Node* &head) {
    if (!head || !head->next) return;
    
    Node* sorted = nullptr;
    Node* curr = head;
    
    while (curr) {
        Node* nextNode = curr->next;
        if (!sorted || curr->data <= sorted->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = nextNode;
    }
    head = sorted;
}

// Algoritmo de ordenamiento por mezcla para listas enlazadas
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;
    
    Node* result = nullptr;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

void mergeSort(Node* &head) {
    if (!head || !head->next) return;
    
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow->next;
    slow->next = nullptr;
    
    mergeSort(head);
    mergeSort(mid);
    
    head = merge(head, mid);
}

int main() {
    Node* head = nullptr;
    
    // Insertar elementos en la lista
    insert(head, 5);
    insert(head, 3);
    insert(head, 8);
    insert(head, 1);
    insert(head, 9);
    insert(head, 2);
    
    cout << "Lista original:" << endl;
    printList(head);
    
    // Ordenamiento por inserción
    insertionSort(head);
    cout << "Lista ordenada por inserción:" << endl;
    printList(head);
    
    // Liberar memoria de la lista
    deleteList(head);
    
    // Insertar elementos nuevamente
    insert(head, 5);
    insert(head, 3);
    insert(head, 8);
    insert(head, 1);
    insert(head, 9);
    insert(head, 2);
    
    cout << "Lista original:" << endl;
    printList(head);
    
    // Ordenamiento por mezcla
    mergeSort(head);
    cout << "Lista ordenada por mezcla:" << endl;
    printList(head);
    
    // Liberar memoria de la lista
    deleteList(head);
    
    return 0;
}