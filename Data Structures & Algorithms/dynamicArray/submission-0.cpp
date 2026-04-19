class DynamicArray {
    int* arr;
    int capacity = 0;
    int length = 0;
public:

    DynamicArray(int capacity) : capacity(capacity), arr(new int[capacity]) {}

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (length == capacity) {
            resize();
        }
        arr[length++] = n;
    }

    int popback() {
        int num = arr[length - 1];
        length--;
        return num;
    }

    void resize() {
        int new_capacity = capacity * 2;
        int* new_arr = new int[new_capacity];
        for (int i = 0; i < length; ++i) {
            new_arr[i] = arr[i];
        }
        capacity = new_capacity;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;

    }
};
