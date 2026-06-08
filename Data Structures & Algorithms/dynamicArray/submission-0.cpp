#include <vector>
using namespace std;

class DynamicArray {
private:
    vector<int> buffer;
    int capacity;
    int end;   // current size, also next empty index

public:
    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->end = 0;

        buffer.resize(capacity);
    }

    int get(int i) {
        return buffer[i];
    }

    void set(int i, int n) {
        buffer[i] = n;
    }

    void pushback(int n) {
        if (end == capacity) {
            resize();
        }

        buffer[end] = n;
        end++;
    }

    int popback() {
        end--;

        return buffer[end];
    }

    void resize() {
        capacity = capacity * 2;
        buffer.resize(capacity);
    }

    int getSize() {
        return end;
    }

    int getCapacity() {
        return capacity;
    }
};