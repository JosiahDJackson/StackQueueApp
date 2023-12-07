#include <vector>
#include <stdexcept>
#include "stackADT.h"


class StackUnderflowError : public std::underflow_error {
public:
    StackUnderflowError(const char* message = "Error: Cannot perform operation on an empty stack")
        : std::underflow_error(message) {}
};

class StackOverflowError : public std::overflow_error {
public:
    StackOverflowError(const char* message = "Error: Cannot perform operation on a full stack")
        : std::overflow_error(message) {}
};

class InvalidStackSizeError : public std::invalid_argument {
public:
    InvalidStackSizeError(const char* message = "Error: Invalid stack size. Using default size of 100.")
        : std::invalid_argument(message) {}
};

template <class Type>
class StackType : public StackADT<Type> {
public:
    const StackType<Type>& operator=(const StackType<Type>&);

    bool operator==(const StackType<Type>& other) const;

    void initializeStack();

    bool isEmptyStack() const;

    bool isFullStack() const;

    void push(const Type& newItem);

    void push(const std::vector<Type>& items);

    Type top() const;

    void pop();

    StackType(int stackSize = 100);

    StackType(const StackType<Type>& otherStack);

    ~StackType();

private:
    std::vector<Type> stackContainer;

    void copyStack(const StackType<Type>& otherStack);
};

template <class Type>
const StackType<Type>& StackType<Type>::operator=(const StackType<Type>& otherStack) {
    if (this != &otherStack) {
        copyStack(otherStack);
    }
    return *this;
}

template <class Type>
bool StackType<Type>::operator==(const StackType<Type>& other) const {
    return this->stackContainer == other.stackContainer;
}

template <class Type>
void StackType<Type>::initializeStack() {
    stackContainer.clear();
}

template <class Type>
bool StackType<Type>::isEmptyStack() const {
    return stackContainer.empty();
}

template <class Type>
bool StackType<Type>::isFullStack() const {
    return false;
}

template <class Type>
void StackType<Type>::push(const Type& newItem) {
    if (stackContainer.size() < stackContainer.max_size()) {
        stackContainer.push_back(newItem);
    }
    else {
        throw StackOverflowError();
    }
}

template <class Type>
Type StackType<Type>::top() const {
    if (!isEmptyStack()) {
        return stackContainer.back();
    }
    else {
        throw StackUnderflowError();
        return Type();
    }
}

template <class Type>
void StackType<Type>::pop() {
    if (!isEmptyStack()) {
        stackContainer.pop_back();
    }
    else {
        throw StackUnderflowError();
    }
}

template <class Type>
StackType<Type>::StackType(int stackSize) {
    if (stackSize <= 0) {
        throw InvalidStackSizeError();
    }
}

template <class Type>
StackType<Type>::StackType(const StackType<Type>& otherStack) {
    copyStack(otherStack);
}

template <class Type>
StackType<Type>::~StackType() {}

template <class Type>
void StackType<Type>::copyStack(const StackType<Type>& otherStack) {
    stackContainer = otherStack.stackContainer;
}

template <class Type>
void StackType<Type>::push(const std::vector<Type>& items) {
    for (const Type& item : items) {
        push(item);
    }
}
