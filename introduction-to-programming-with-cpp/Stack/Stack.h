#ifndef STACK_H
#define STACK_H

template<typename T, int capacity>
class Stack
{
public:
    Stack();
    bool isEmpty() const;
    T peek() const;
    void push(T value);
    T pop();
    int getSize() const;

private:
    T elements[capacity];
    int size;
};

template<typename T, int capacity>
Stack<T, capacity>::Stack()
{
    size = 0;
}

template<typename T, int capacity>
bool Stack<T, capacity>::isEmpty() const
{
    return size == 0;
}

template<typename T, int capacity>
T Stack<T, capacity>::peek() const
{
    return elements[size - 1];
}

template<typename T, int capacity>
void Stack<T, capacity>::push(T value)
{
    elements[size++] = value;
}

template<typename T, int capacity>
T Stack<T, capacity>::pop()
{
    return elements[--size];
}

template<typename T, int capacity>
int Stack<T, capacity>::getSize() const
{
    return size;
}

#endif // STACK_H
