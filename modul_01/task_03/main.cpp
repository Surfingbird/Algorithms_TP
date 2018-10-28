#include <iostream>
#include <assert.h>

//Реализовать очередь с динамическим зацикленным буфером.
//Обрабатывать команды push back и pop front.


/// 12397183

int MagicSize = 10;

using namespace std;

class CQueue {
public:
    CQueue();
    ~CQueue();
    CQueue(const CQueue&) = delete;
    CQueue(CQueue&&) = delete;
    CQueue&operator=(const CQueue&) = delete;
    CQueue&operator=(CQueue&&) = delete;
    void ShowBuffer() const;


    bool IsEmpty() const;
    void Enqueue(int element);
    int Dequeue();
    bool IsFull() const;

private:

    void Resize();

    int* buffer;
    size_t BufferSize;
    size_t head;
    size_t tail;
    size_t count;
};

CQueue::CQueue()
        : head(0), tail(0), BufferSize(MagicSize), buffer(nullptr), count(0)
{
    buffer = new int[BufferSize];
}

CQueue::~CQueue() {
    delete [] buffer;
}

bool CQueue::IsEmpty() const {
    return head == tail;
}

bool CQueue::IsFull() const {
    return count == BufferSize - 1;
}

void CQueue::Resize() {

    int* NewBuffer = new int[2 * BufferSize];
    size_t IndexInNew = 0;

    if (BufferSize - 1 == tail) {
        for (size_t i = head; i < BufferSize; ++i) {
            NewBuffer[IndexInNew] = buffer[i];
            ++IndexInNew;
        }
        tail = --IndexInNew;
    } else {
        for(size_t i = 0; i < BufferSize; ++i) {
            NewBuffer[IndexInNew] = buffer[i];
            ++IndexInNew;
        }
        for (size_t i = 0; i < tail; ++i) {
            NewBuffer[IndexInNew] = buffer[i];
            ++IndexInNew;
        }
        tail = IndexInNew;
    }

    head = 0;
    delete [] buffer;
    buffer = nullptr;
    BufferSize *= 2;
    buffer =  NewBuffer;
}

void CQueue::Enqueue(int element) {
    assert(element >= 0);
    if (IsFull()) {
        Resize();
    }
    buffer[tail] = element;
    ++count;
    tail = (tail + 1) % BufferSize;
}

int CQueue::Dequeue() {
    if (IsEmpty()) {
        return -1;
    }
    int result = buffer[head];
    head = (head + 1) % BufferSize;
    --count;
    return  result;
}

void CQueue::ShowBuffer() const {
    for(size_t i = 0; i < BufferSize; ++i) {
        cout << buffer[i] << " ";
    }
    cout << endl;
}

int main() {
    CQueue queue;
    size_t CommandCount = 0;
    cin >> CommandCount;
    int CommandID = 0;
    int CommandValue = 0;
    for (size_t i = 0; i < CommandCount; ++i) {
        cin >> CommandID >> CommandValue;
        if(CommandID == 3) {
            queue.Enqueue(CommandValue);
        } else if(CommandID == 2) {
            int current = queue.Dequeue();
            if (current != CommandValue) {
                cout << "NO";
                return 0;
            }
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
