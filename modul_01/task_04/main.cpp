///4_1. Жадина.
///Вовочка ест фрукты из бабушкиной корзины. В корзине лежат фрукты разной массы. Вовочка может поднять не более K грамм. Каждый фрукт весит не более K грамм. За раз он выбирает несколько самых тяжелых фруктов, которые может поднять одновременно, откусывает от каждого половину и кладет огрызки обратно в корзину. Если фрукт весит нечетное число грамм, он откусывает большую половину. Фрукт массы 1гр он съедает полностью.
///Определить за сколько подходов Вовочка съест все фрукты в корзине.
///Формат входных данных. Вначале вводится n - количество фруктов и n строк с массами фруктов. Затем K - "грузоподъемность".

/// id 12968115

#include <iostream>


using namespace std;

class Heap {
public:
    Heap(int* buffer, int size);
    ~Heap();
    Heap(const Heap&) = delete;
    Heap(Heap&&) = delete;
    Heap&operator=(const Heap&) = delete;
    Heap&operator=(Heap&&) = delete;

    int ExtractMax();
    void BuildHeap();
    int GetMax() const;
    void Add(int element);
    bool IsEmpty() const ;

//    void ShowBuffer() {
//        for(int i = 0; i < top_; ++i) {
//            cout << buffer_[i] << " ";
//        }
//        cout << endl;
//    }

private:
    void ShiftUp(int i);
    void ShiftDown(int i);
    int* buffer_;
    int size_;
    int top_;
};

Heap::Heap(int* buffer, int size) {
    buffer_ = buffer;
    size_ = size;
    top_ = size;
}

Heap::~Heap() {
    delete [] buffer_;
}

void Heap::Add(int element) {
    buffer_[top_++] = element;
    ShiftUp(top_ - 1);
}

void Heap::ShiftUp(int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(buffer_[i] < buffer_[parent]) return;

        int mnt = buffer_[i];
        buffer_[i] = buffer_[parent];
        buffer_[parent] = mnt;

        i = parent;
    }
}

void Heap::ShiftDown(int i) {
    int LeftChild = 2 * i + 1;
    int RightChild = 2 * i + 2;

    int Largest = i;

    if(LeftChild < top_ && buffer_[LeftChild] > buffer_[i]) {
        Largest = LeftChild;
    }
    if(RightChild < top_ && buffer_[RightChild] > buffer_[Largest]) {
        Largest = RightChild;
    }
    if(i != Largest) {
        int mnt = buffer_[i];
        buffer_[i] = buffer_[Largest];
        buffer_[Largest] = mnt;
        ShiftDown(Largest);
    }
}

bool Heap::IsEmpty() const {
    return 0 == top_;
}

void Heap::BuildHeap() {
    for(int i = size_ / 2 - 1; i >= 0; --i) {
        ShiftDown(i);
    }

}

int Heap::ExtractMax() {
    const int root = 0;
    int result = buffer_[root];
    buffer_[root] = buffer_[--top_];

    if(size_ > 0) {
        ShiftDown(root);
    }

    return result;
}

int Heap::GetMax() const {
    return buffer_[0];
}

int main() {

    int Fruits_count = 0;
    cin >> Fruits_count;

    int* buffer = new int[Fruits_count];
    for(int i = 0; i < Fruits_count; ++i) {
        cin >> buffer[i];
    }

    int MaxM = 0;
    cin >> MaxM;

    Heap heap(buffer, Fruits_count);
    heap.BuildHeap();

    int counter = 0;

    int* BoysBag = new int[MaxM];

    while (!heap.IsEmpty()) {

        int CurrentM = 0;
        int BagIndex = 0;
        while(MaxM - CurrentM >= heap.GetMax() && !heap.IsEmpty()) {
            BoysBag[BagIndex] = heap.ExtractMax();
            CurrentM += BoysBag[BagIndex];
            ++BagIndex;
        }

        for(int i = 0; i < BagIndex; ++i) {
            if(BoysBag[i] == 1) continue;
            else {
                heap.Add(BoysBag[i] / 2);
            }

        }
        ++counter;
    }

    cout << counter << endl;

    delete [] BoysBag;
    /// buffer умирает в деструкторе
    return 0;
}