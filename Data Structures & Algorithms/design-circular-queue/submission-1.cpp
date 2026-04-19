class MyCircularQueue {
public:
    int front = 0;
    int back = 0;
    int size;
    int* q;

    MyCircularQueue(int k) : size(k + 1), q(new int[k + 1]) {}
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[back] = value;
        back = (back + 1) % size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[(back - 1 + size) % size];
    }
    
    bool isEmpty() {
        return front == back;
    }
    
    bool isFull() {
        return (back + 1) % size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */