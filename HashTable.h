#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"

using namespace std;

template <typename T>
class HashTable
{
public:
    HashTable(int size);
    ~HashTable();

    void insert(string key, const Data&  value);
    void remove(string key);
    bool contains(string key) const;
    const Data get(string key) const;
    void print() const;

private:
    // object of linked list node
    vector<Node<T> *> table;

    int size;

    // hash function
    int hash(string key) const;
};

template <typename T>
HashTable<T>::HashTable(int size)
{
    this->size = size;
    table.resize(size, nullptr);
}

template <typename T>
HashTable<T>::~HashTable()
{
    for (int i = 0; i < size; ++i)
    {
        Node *current = table[i];
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
}

template <typename T>
void HashTable<T>::insert(string key, const Data& value)
{
    int index = hash(key);
    Node<T> *newNode = new Node<T>(key, value);
    newNode->next = table[index];
    table[index] = newNode;
}

template <typename T>
void HashTable<T>::remove(string key)
{
    int index = hash(key);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                table[index] = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <typename T>
bool HashTable<T>::contains(string key) const
{
    int index = hash(key);
    Node* current = table[index];

    while (current) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
const Data HashTable<T>::get(string key) const {
    int index = hash(key);
    Node* current = table[index];

    while (current) {
        if (current->key == key) {
            return &(current->value);
        }
        current = current->next;
    }
    return Data();
}

template <typename T>
void HashTable<T>::print() const
{
     for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        if (current) {
            std::cout << "Bucket " << i << ": ";
            while (current) {
                std::cout << "(" << current->key << ", " << current->value << ") ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
}

template <typename T>
int HashTable<T>::hash(string key) const {
    // A simple hash function that sums the ASCII values of characters in the key
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    return sum % size;
}

#endif
