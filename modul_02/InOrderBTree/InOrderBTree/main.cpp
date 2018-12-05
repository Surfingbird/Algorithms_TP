//
//  main.cpp
//  InOrderBTree
//
//  Created by Андрей on 01.11.18.
//  Copyright © 2018 Андрей. All rights reserved.
//

#include <iostream>
#include <stack>

template <typename T>
void DeleteTree(T*& tree) {
    std::stack<T*> stack;

    if (tree == nullptr) return;

    T* current = tree;

    while (true) {
        if (nullptr != current->Left) {
            stack.push(current);
            if (nullptr != current->Right) stack.push(current->Right);
            current = current->Left;

            continue;
        } else if (nullptr != current->Right) {
            stack.push(current);
            current = current->Right;
            continue;
        }

        if (nullptr != current->Parent) {
            if (current->Parent->Left == current) current->Parent->Left = nullptr;
            else current->Parent->Right = nullptr;
        }
        delete current;

        if (0 == stack.size()) break;
        else {
            current = stack.top();
            stack.pop();
        }
    }
}

class CTree {
public:
    CTree(int value);
    ~CTree();
    
    friend void AddList(CTree*& tree, int value);
    friend void ShowInOrder(CTree* tree);
    
private:
    int Data = -1;
    CTree* Parent = nullptr;
    CTree* Left = nullptr;
    CTree* Right = nullptr;
};

CTree::CTree(int value)
    : Data(value)
{}

CTree::~CTree() {
    std::cout << "Destructor" << std::endl;
}

void ShowInOrder(CTree* tree) {
    std::stack<CTree*> Stack;
    while (Stack.size() != 0 || nullptr != tree) {
        if (nullptr != tree) {
            Stack.push(tree);
            tree = tree->Left;
        } else {
            tree = Stack.top();
            Stack.pop();
            std::cout << tree->Data << " ";
            tree = tree->Right;
        }
    }
}

void AddList(CTree*& tree, int value) {
    if (nullptr == tree) { /// friend потому что компилятор ругался на null_ptr == this
        tree = new CTree(value);
        return;
    }
    CTree* curret = tree;
    CTree* list = new CTree(value);
    
    while (true) {
        if (value < curret->Data && nullptr == curret->Left) {
            list->Parent = curret;
            curret->Left = list;
            return;
        } else if (value < curret->Data) {
            curret = curret->Left;
        } else if (value >= curret->Data && nullptr == curret->Right) {
            list->Parent = curret;
            curret->Right = list;
            return;
        } else if (value >= curret->Data) {
            curret = curret->Right;
        }
    }
}

int main(int argc, const char * argv[]) {
    int count = 0;
    
    std::cout << "Enter count" << std::endl;
    std::cin >> count;
    
    CTree* root = nullptr;;
    int value = 0;
    
    for (int i = 0; i < count; ++i){
        std::cin >> value;
        AddList(root, value);
    }
    
    ShowInOrder(root);
    DeleteTree(root);
    
    return 0;
}
