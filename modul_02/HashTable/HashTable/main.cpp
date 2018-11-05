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
    int const ASimple = 137;
    int hash = 0;
    for(int i = 0; i < str.length(); ++i) {
        int charecter = str[i];
        hash = (hash * ASimple + charecter) % MLimit;
    }
    return hash;
}

int Hash_2(std::string str, int MLimit) {
    int hash = (int)str.length() % MLimit;
    if (hash % 2 == 0) --hash; /// условно пустую строку передавать нельзя
    return hash;
}

class HashTable {
public:
    explicit HashTable(int size); /// неконвертируемая
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
    int new_MLimit = 2 * MLimit;
    std::vector<std::string> new_table(new_MLimit);
    
    for (int i = 0; i < MLimit; ++i) {
        if (table[i] == "" || table[i] == "DEL") continue;
        
        for (int j = 0; j < new_MLimit; ++j) {
            int index = (Hash_1(table[i], new_MLimit) + j * Hash_2(table[i], new_MLimit)) % new_MLimit;
            if (new_table[index] == "") {
                new_table[index] = table[i];
                break;
            }
        }
    }
    
    table = new_table;
    MLimit = new_MLimit;
}

bool HashTable::Add(const std::string &key) {
    assert(key != "DEL");
    
    if (CritialFilling()) {
        Resize();
    }
    
    int InsertPos = -1;
    
    for (int i = 0; i < MLimit; ++i) {
        int index = (Hash_1(key, MLimit) + i * Hash_2(key, MLimit)) % MLimit;
        
        if (table[index] == key) {
            return false;
        } else if (InsertPos == -1 && table[index] == "DEL") {
            InsertPos = index;
        } else if (table[index] == "") {
            if (InsertPos == -1) InsertPos = index; /// поправил этот момент
            break;
        }
    }
    
    table[InsertPos] = key;
    ++elements;
    return true;
}

bool HashTable::CritialFilling() {
    if (elements == 0) return false;
    return (double)(elements) / MLimit >= critical_top;
}

bool HashTable::Has(const std::string &key) const {
    for (int i = 0; i < MLimit; ++i) {
        int index = (Hash_1(key, MLimit) + i * Hash_2(key, MLimit)) % MLimit;
        
        if (table[index] == key) return true;
        else if (table[index] == "") return false;
    }
    
    return false;
}

bool HashTable::Remove(const std::string &key) {
    
    int RemovePos = -1;
    
    for (int i = 0; i < MLimit; ++i) {
        int index = (Hash_1(key, MLimit) + i * Hash_2(key, MLimit)) % MLimit;
        
        if (table[index] == "") {
            return false;
        } else if (table[index] == key) {
            RemovePos = index;
            break;
        } else if (RemovePos == -1 && table[index] == "DEL") {
            RemovePos = index;
        }
    }
    
    table[RemovePos] = "DEL";
    --elements;
    return true;
}

int main() {
    int start_size = 4;
    
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
