#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>


// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> {
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
    std::vector<T> stack;
    int index;
};
        //end of header file
        //implementations
    template <typename T >
    Stack<T>::Stack(){
        index = 0;
    }

    template <typename T >
    Stack<T>::~Stack(){
        index = 0;
    }

    template <typename T >
    bool Stack<T>::empty() const{
        return (index==0);
    }

    template <typename T >
    size_t Stack<T>::size() const{
        return index;
    }

    template <typename T >
    void Stack<T>::push(const T& item){
        stack.push_back(item);
        index++;
    }

    template <typename T >
    void Stack<T>::pop(){  // throws std::underflow_error if empty
    if (index == 0){
        throw std::underflow_error("empty stack");       //not working
    }
    stack.pop_back();
    index--;
    }

    template <typename T >
    const T& Stack<T>::top() const{// throws std::underflow_error if empty
    if (index == 0){
        throw std::underflow_error("empty stack"); // not working
    }
    else 
    return stack[index-1];

    } 

#endif