// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T arr[size];
    int topIndex;

public:
    TStack() {
        topIndex = -1;
    }

    void push(T value) {
        if (topIndex < size - 1) {
            topIndex++;
            arr[topIndex] = value;
        }
    }

    T pop() {
        if (topIndex >= 0) {
            topIndex--;
            return arr[topIndex + 1];
        }
        return T();
    }

    T get() const {
        if (topIndex >= 0) {
            return arr[topIndex];
        }
        return T();
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
