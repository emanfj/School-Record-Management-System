#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Struct representing the values corresponding to each key
struct Data
{
    int value1;
    double value2;
    // Add more members as needed
};

// NODE CLASS
template <class T>
class Node
{
public:
    T *key

        // object of struct
        Data value;
    Node<T> *next;
    Node()
    {
        key = nullptr;
        next = nullptr;
    }
    Node(T *key, Data value)
    {
        key = key;
        value = value;
        next = nullptr;
    }
};

// LINKED LIST CLASS
template <class T>
class LinkedList_
{
public:
    Node<T> *head;
    // for hash collisions
    int collisions;

    LinkedList_()
    {
        head = nullptr;
        collisions = 0;
    }

    LinkedList_(T *newValue)
    {
        head = new Node<T>(newValue);
        head->next = nullptr;
        collisions = 0;
    }

    // insertion
    void ADD(T *additem)
    {
        if (!SearchItem(additem))
        {
            Node<T> *newitem = new Node<T>(additem);
            collisions++;
            if (head == nullptr)
            {
                head = newitem;
            }
            else
            {
                Node<T> *temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newitem;
            }
        }
    }

    // searching
    bool SearchItem(T *SearchItem)
    {
        Node<T> *helper = head;
        while (helper != nullptr)
        {
            if (*(SearchItem) == *(helper->key))
            {
                return true;
            }
            helper = helper->next;
        }
        return false;
    }

    // returns nodes
    Node<T> *GetPointerObject(T *SearchItem)
    {
        Node<T> *helper = head;
        while (helper != nullptr)
        {
            if (*(SearchItem) == *(helper->key))
                return helper;
            helper = helper->next;
        }
        return nullptr; // If nullptr returned it means object not found.
    }

    // prints
    void Displayall()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << *(temp->key) << "->";
            temp = temp->next;
        }
    }

    // deletes
    void DeleteNode(T *DeleteObject)
    {
        if (SearchItem(DeleteObject))
        {

            if (*(DeleteObject) == *(head))
            {
                Node<T> *item = head;
                head = head->next;
                delete item;
            }
            else
            {
                Node<T> *item = head;
                Node<T> *previtem;
                while (item != nullptr && (*(DeleteObject) != *(item)))
                {
                    previtem = item;
                    item = item->next;
                }
                previtem->next = item->next;
                delete item;
            }
        }
        else
            return;
    }
};

#endif