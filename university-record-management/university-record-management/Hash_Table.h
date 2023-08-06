#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>
#include <functional> // comment this out if needed not sure yet
#include "AVLTree.h"

using namespace std;

// individual array element would be a struct of type item
template <typename ValueType>
struct item
{
    int *key;
    AVLTree<ValueType> *value; // AVL TREE OF VALUES OR ATTRIBUTES
};

template <typename ValueType>
class HashTable
{
private:
    // Contains an array of pointers to items.
    item<ValueType> **items;
    int size;
    int count;

public:
    HashTable(int size) : size(size), count(0)
    {
        // Allocates memory on the heap for an array of pointers to item
        items = new item<ValueType> *[size];

        for (int i = 0; i < size; i++)
            items[i] = nullptr;
    }

    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            if (items[i] != nullptr)
            {
                delete[] items[i]->key;
                delete items[i]->value; // Delete the AVL tree
                delete items[i];
            }
        }
        delete[] items;
    }

    int hash_function(const int &key) const
    {
        // Simple hash function (modulus)
        return key % size;
    }

    item<ValueType> *create_item(const int &key, const ValueType &value)
    {
        // Creates a pointer to a new HashTable item.
        item<ValueType> *new_item = new item<ValueType>;
        new_item->key = new int(key);
        new_item->value = new AVLTree<ValueType>(); // Initialize an empty AVL tree for values.

        return new_item;
    }

    HashTable<ValueType> *create_table(int size)
    {
        // Creates a new HashTable.
        HashTable<ValueType> *table = new HashTable<ValueType>(size);
        return table;
    }

    void free_item(item<ValueType> *item)
    {
        // Frees an item.
        delete item->key;
        delete item->value; // AVL tree (std::set) is deleted automatically when item is deleted.
        delete item;
    }

    void insert_item(const int &key, const ValueType &value)
    {
        // Computes the index.
        int index = hash_function(key);

        item<ValueType> *current_item = items[index];

        if (current_item == nullptr)
        {
            // Key does not exist.
            if (count == size)
            {
                // HashTable is full.
                std::cout << "Insert Error: Hash Table is full\n";
                return;
            }

            // Insert directly.
            items[index] = create_item(key, value);
            count++;
        }

        // Collision occurred
        else
        {
            if (*(current_item->key) == key)
            {
                // Key already exists, add the value to the AVL tree.
                current_item->value->insert(value);
            }
            else
            {
                // Scenario 2: Handle the collision.
                handle_collision(index, key, value);
            }
        }
    }

    void handle_collision(int index, const int &key, const ValueType &value)
    {
        // re-hash by using linear probing.

        int newIndex = index;

        while (items[newIndex] != nullptr)
        {
            newIndex = (newIndex + 1) % size;
            if (*(items[newIndex]->key) == key)
            {
                items[newIndex]->value->insert(value);
                return;
            }
        }

        items[newIndex] = create_item(key, value);
        count++;
    }

    AVLTree<ValueType><ValueType> *search(const int &key)
    {
        // Searches for the key in the HashTable.
        // Returns NULL if it doesn't exist.
        int index = hash_function(key);
        item<ValueType> *current_item = items[index];

        if (current_item != nullptr && *(current_item->key) == key)
        {
            return current_item->value;
        }

        // Provide only non-NULL values.
        return nullptr;
    }

    void print_search(const int &key)
    {
        AVLTree<ValueType> *avlTree = search(key);

        if (avlTree == nullptr)
        {
            cout << "Key:" << key << " does not exist\n";
        }
        else
        {
            cout << "Key:" << key << ", Values: ";
            for (const auto &value : *val)
            {
                cout << value << " ";
            }
            cout << endl;
        }
    }

    void print_table()
    {
        for (int i = 0; i < size; i++)
        {
            if (items[i] != nullptr)
            {
                cout << "Index:" << i << ", Key:" << *(items[i]->key) << ", Values: ";
                if (items[i]->value != nullptr)
                {
                    items[i]->value->print_sorted(); // Call AVL tree print_sorted function
                }
                cout << "\n";
            }
        }
    }
};

#endif