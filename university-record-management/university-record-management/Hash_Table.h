// TEMPLATE FOR HASH TABLE
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include "AVLTree.h"

template <typename ValueType>

// HASH TABLE CLASS
class HashTable
{
private:
    // struct for each hash table entry
    struct Item
    {
        int key;
        // an AVL Tree instance for each hash table entry
        AVLTree<ValueType> *value;
        Item(int key, ValueType value) : key(key), value(new AVLTree<ValueType>())
        {
            // values stored in AVL tree nodes
            // insert function of AVLTree template class is called here
            this->value->insert(value);
        }
    };

    // vector named items containing all hash table entries
    std::vector<Item *> items;
    int count;

    // Hash function to calculate the hash table index
    int hashFunction(int key) const
    {
        const int PRIME = 31;
        return key * PRIME % items.size();
    }

public:
    // constructor for hash table class
    HashTable(int size) : count(0)
    {
        // changes size of the vector to given size and fills the elements with nullptr
        items.resize(size, nullptr);
    }

    // destructor for hash table class
    ~HashTable()
    {
        for (auto &item : items)
        {
            if (item != nullptr)
            {
                delete item->value; // delete the AVL tree
                delete item;
            }
        }
    }

    // function to insert data at a hash table index
    void insert(int key, ValueType value)
    {
        // hash index is calculated using hash function
        int index = hashFunction(key);
        Item *current_item = items[index];

        if (current_item == nullptr)
        {
            // key does not exist => create a new item and AVL tree.
            items[index] = new Item(key, value);
            count++;
        }
        else
        {
            // key already exists => just insert the value to the existing AVL tree.
            current_item->value->insert(value);
        }
    }

    // to search data in a hash table
    AVLTree<ValueType> *search(int key)
    {
        int index = hashFunction(key);
        Item *current_item = items[index];

        if (current_item != nullptr && current_item->key == key)
        {
            return current_item->value;
        }

        return nullptr;
    }


    // prints the data to be searched
    void printSearch(int key)
    {
        AVLTree<ValueType> *avlTree = search(key);

        if (avlTree == nullptr)
        {
            std::cout << "Key:" << key << " does not exist\n";
        }
        else
        {
            std::cout << "Key:" << key << ", Values: ";
            avlTree->print_inOrder();
            std::cout << std::endl;
        }
    }

    // prints the data in hash table
    void printTable()
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i] != nullptr)
            {
                // index is the position in the vector where the item is stored => output of the hash function
                // key: integer (eg ID) that identifies the value type (student or book)
                // value is the actual data the table is storing
                std::cout << "-----------------------------\n";
                std::cout << "Index:" << i << "\t Values: ";
                items[i]->value->print_inOrder();
                std::cout << "\n";
            }
        }
    }

    void remove(int key, ValueType value)
    {
        int index = hashFunction(key);
        Item* current_item = items[index];

        if (current_item != nullptr && current_item->key == key)
        {
            current_item->value->remove(value); //using AVL tree remove function
            // delete the tree and the item if the tree becomes empty after removal
            if (current_item->value->isEmpty()) //using AVL tree isEmpty function
            {
                delete current_item->value;
                delete current_item;
                items[index] = nullptr;
                count--;
            }
        }
    }

};

#endif
