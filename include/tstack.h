// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T* data;
    int top;
public:
    TStack() {
        data = new T[size];
        top = -1;
    }

    ~TStack() {
        delete[] data;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == size - 1;
    }

    void push(const T& value) {
        if (!isFull()) {
            data[++top] = value;
        }
    }

    T pop() {
        if (!isEmpty()) {
            return data[top--];
        } else {
            return T();
        }
    }

    T get() const {
        if (!isEmpty()) {
            return data[top];
        } else {
            return T();
        }
    }
};

#endif  // INCLUDE_TSTACK_H_
