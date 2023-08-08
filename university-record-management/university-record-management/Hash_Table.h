#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include "AVLTree.h"

template <typename ValueType>
class HashTable
{
private:
    struct Item
    {
        int key;
        AVLTree<ValueType>* value;
        Item(int key, ValueType value) : key(key), value(new AVLTree<ValueType>())
        {
            this->value->insert(value);
        }
    };

    std::vector<Item*> items;
    int count;

    int hashFunction(int key) const {
        const int PRIME = 7; 
        return key * PRIME % items.size();
    }


public:
    HashTable(int size) : count(0)
    {
        //changes size of the vectory to given size and fills the elements with nullptr
        items.resize(size, nullptr);
    }

    ~HashTable()
    {
        for (auto& item : items)
        {
            if (item != nullptr)
            {
                delete item->value; //delete the AVL tree
                delete item;
            }
        }
    }

    void insert(int key, ValueType value)
    {
        int index = hashFunction(key);
        Item* current_item = items[index];

        if (current_item == nullptr)
        {
            //key does not exist => create a new item and AVL tree.
            items[index] = new Item(key, value);
            count++;
        }
        else
        {
            //key already exists => just insert the value to the existing AVL tree.
            current_item->value->insert(value);
        }
    }

    AVLTree<ValueType>* search(int key)
    {
        int index = hashFunction(key);
        Item* current_item = items[index];

        if (current_item != nullptr && current_item->key == key)
        {
            return current_item->value;
        }

        return nullptr;
    }

    void printSearch(int key)
    {
        AVLTree<ValueType>* avlTree = search(key);

        if (avlTree == nullptr)
        {
            std::cout << "Key:" << key << " does not exist\n";
        }
        else
        {
            std::cout << "Key:" << key << ", Values: ";
            avlTree->print_sorted();
            std::cout << std::endl;
        }
    }

    void printTable()
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i] != nullptr)
            {
                //index is the position in the array where the item is stored output of the hash function
                //integer (eg ID) that identifies the value type (student or book)
                //value is the actual data the table is storing
                std::cout << "-----------------------------\n";
                std::cout << "Index:" << i << "\t Values: ";
                items[i]->value->print_inOrder();
                std::cout << "\n";
            }
        }
    }
};

#endif
