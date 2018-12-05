//
//  main.cpp
//  HashTable
//
//  Created by Андрей on 01.11.18.
//  Copyright © 2018 Андрей. All rights reserved.
//

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

int Hash_1(std::string str, int MLimit) {
    int const ASimple = 3; 
    int hash = 0;

    for(int i = 0; i < str.length(); ++i) {
        hash = hash * ASimple + str[i]; 
    }
    return hash;
}

int Hash_2(std::string str, int MLimit) {
    int hash = (int)str.length() % MLimit; 
    if (hash % 2 == 0 && hash > 0) --hash;
    else if (hash % 2 == 0) ++hash;
    return hash;
}

class HashTable {
public:
    explicit HashTable(int size);
    ~HashTable();
    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;
    
    bool Has(const std::string& key) const;
    bool Add(const std::string& key);
    bool Remove(const std::string& key);
    
public:
    void Resize();
    bool CritialFilling();
    
    int MLimit = 0;
    std::vector<std::string> table;
    int elements = 0;
    const double critical_top = 0.75;
};


HashTable::HashTable(int size)
: table(size), MLimit(size)
{}

HashTable::~HashTable() {}

void HashTable::Resize() {

    std::vector<std::string> copy_table = table; 
    int cpoy_MLimit = MLimit;

    MLimit *= 2;
    std::vector<std::string> new_table(MLimit);
    table = new_table;
    elements = 0;

    for (int i = 0; i < cpoy_MLimit; ++i) {
        if (copy_table[i] == "" || copy_table[i] == "DEL") continue;

        int hash_1 = Hash_1(copy_table[i], MLimit);
        int hash_2 = Hash_2(copy_table[i], MLimit);

        for (int j = 0; j < MLimit; ++j) {
            int index = (hash_1 + j * hash_2) % MLimit;

            if (table[index] == "") {
                table[index] = copy_table[i];
                ++elements;
                break;

            }  else if (table[index] != "") continue;
            else assert(false);
        }
    }
}

bool HashTable::CritialFilling() {
    if (elements == 0) return false;
    return (double)(elements) / MLimit >= critical_top;
}

bool HashTable::Has(const std::string &key) const {

    int hash_1 = Hash_1(key, MLimit);
    int hash_2 = Hash_2(key, MLimit);

    for (int i = 0; i < MLimit; ++i) {
        int index = (hash_1 + i * hash_2) % MLimit;
        
        if (table[index] == key) return true;
        else if (table[index] == "") return false;
        else if (table[index] == "DEL" || table[index] != key) continue;
        else assert(false); 
    }
    
    return false;
}

bool HashTable::Add(const std::string &key) {
    assert(key != "DEL");

    if(Has(key)) return false; 

    if (CritialFilling()) { 
        Resize();
    }

    int hash_1 = Hash_1(key, MLimit);
    int hash_2 = Hash_2(key, MLimit);

    for (int i = 0; i < MLimit; ++i) {
        int index = (hash_1 + i * hash_2) % MLimit;

        if (table[index] == "" || table[index] == "DEL")  {
            table[index] = key;
            ++elements;
            return true;
        } else if (table[index] != key) continue;
        else assert(false);
    }
}

bool HashTable::Remove(const std::string &key) {

    if(!Has(key)) return false; 

    int hash_1 = Hash_1(key, MLimit);
    int hash_2 = Hash_2(key, MLimit);
    
    for (int i = 0; i < MLimit; ++i) {
        int index = (hash_1 + i * hash_2) % MLimit;

        if (table[index] == "DEL" || table[index] != key) continue;
        else if (table[index] == key) {
            table[index] = "DEL";
            --elements;
            return true;
        } else assert(false);
    }

}

int main() {
    int start_size = 8;
    
    HashTable table(start_size);
    char command = 0;
    std::string key;
    while (std::cin >> command >> key) {
        switch (command) {
            case '?':
                std::cout << (table.Has(key) ? "OK" : "FAIL") << std::endl;
                break;
            case '+':
                std::cout << (table.Add(key) ? "OK" : "FAIL") << std::endl;
                break;
            case '-':
                std::cout << (table.Remove(key) ? "OK" : "FAIL") << std::endl;
                break;
            default:
                std::cerr << "bad input" << std::endl;
                return 0;
        }
    }
    return 0;
}

