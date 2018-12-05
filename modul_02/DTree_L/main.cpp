#include <iostream>
#include <stack>
#include <vector>
#include <queue>

template <typename T>
int MaxWidth(T root) {

    size_t stack_size = 0; ///
    int max_width = 0;
    std::queue<T> queue;

    if (nullptr == root) return max_width;

    queue.push(root);
    queue.push(nullptr);
    stack_size = queue.size(); ///
    int current_width = 0;

    while(!queue.empty()) {
        stack_size = queue.size(); ///

        T current = queue.front();
        queue.pop();
        stack_size = queue.size(); ///

        if (nullptr != current) {
            ++current_width;
            if (nullptr != current->Left) queue.push(current->Left);
            if (nullptr != current->Right) queue.push(current->Right);
        } else if (!queue.empty()) {
            queue.push(nullptr);
            current_width = 0;
        }

        if (current_width > max_width) max_width = current_width;
    }

    return max_width;
}

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

class BTree {
public:
    BTree() = delete;
    explicit BTree(int value);
    ~BTree();

    friend void AddList(BTree*& tree, int value);

public:
    int Data = -1;
    BTree* Parent = nullptr;
    BTree* Left = nullptr;
    BTree* Right = nullptr;
};


class Treap {
public:
    Treap() = delete;
     explicit Treap(int key, int prior);
    ~Treap();

    friend void Add(Treap*& root, int Data, int Prior);

    int Data = -1;
    int Prior = 1;

    Treap* Parent = nullptr;
    Treap* Left = nullptr;
    Treap* Right = nullptr;
};

BTree::BTree(int value)
        : Data(value)
{}

BTree::~BTree() {}

Treap::Treap(int data, int prior)
        : Data(data), Prior(prior)
{}

void AddList(BTree *&tree, int value) {
    if (nullptr == tree) { /// friend потому что компилятор ругался на null_ptr == this
        tree = new BTree(value);
        return;
    }

    BTree* curret = tree;
    BTree* list = new BTree(value);

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

Treap::~Treap() {}

void Splite(Treap* root, int data, Treap*& L, Treap*& R) {
    if (nullptr == root) {
        L = nullptr;
        R = nullptr;
    } else if( root->Data <= data ) {
        Splite( root->Right, data, root->Right, R );
        L = root; } else {
        Splite( root->Left, data, L, root->Left );
        R = root;
    }
}

void Add(Treap *&root, int data, int prior) {
    Treap* treap = new Treap(data, prior);

    if (nullptr == root) {
        root = treap;
        return;
    }

    Treap* prev = nullptr; /// bad

    Treap* current = root;
    Treap* L = nullptr;
    Treap* R = nullptr;

    while (true) {
        if (current->Prior >= prior) {
            if (nullptr == current->Left && current->Data > data) {
                current->Left = treap;
                treap->Parent = current;
                return;
            } else if (nullptr == current->Right && current->Data <= data) {
                current->Right = treap;
                treap->Parent = current;
                return;
            } else if (current->Data > data) { /// >
                prev = current; /// bad
                current = current->Left;
            } else if (current->Data <= data) { /// <=
                prev = current; /// bad
                current = current->Right;
            }
        } else {
            Splite(current, treap->Data, L, R);
            break;
        }
    }


    treap->Left = L;
    treap->Right = R;

    if (current == root) root = treap;
    else if (treap->Data >= prev->Data) prev->Right = treap;
    else prev->Left = treap;

}

int main() {

    int count = 0;
    std::cin >> count;

    BTree* btree_root = nullptr;
    Treap* treap_root = nullptr;

    for (int i = 0; i < count; ++i) {
        int data = -1;
        int prior = -1;
        std::cin >> data >> prior;

        Add(treap_root, data, prior);
        AddList(btree_root, data);
    }

    std::cout << MaxWidth(treap_root) - MaxWidth(btree_root);

    DeleteTree(btree_root);
    DeleteTree(treap_root);

    return 0;
}