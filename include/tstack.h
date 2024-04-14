#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T* data; // Указатель на массив данных стека
    int top; // Индекс вершины стека

 public:
    // Конструктор
    TStack() {
        data = new T[size];
        top = -1;
    }

    // Деструктор
    ~TStack() {
        delete[] data;
    }

    // Проверка на пустоту стека
    bool isEmpty() const {
        return top == -1;
    }

    // Проверка на полноту стека
    bool isFull() const {
        return top == size - 1;
    }

    // Помещение элемента на вершину стека
    void push(const T& value) {
        if (!isFull()) {
            data[++top] = value;
        }
    }

    // Извлечение элемента с вершины стека
    T pop() {
        if (!isEmpty()) {
            return data[top--];
        } else {
            return T();
        }
    }

    // Получение элемента с вершины стека (без извлечения)
    T get() const {
        if (!isEmpty()) {
            return data[top];
        } else {
            return T();
        }
    }
};

#endif  // INCLUDE_TSTACK_H_
