#include <iostream>


#ifndef STACKADT_H
#define STACKADT_H

template <class type>
class StackADT {
public:
    virtual void initializeStack() = 0;

    virtual bool isEmptyStack() const = 0;

    virtual bool isFullStack() const = 0;

    virtual void push(const type& newItem) = 0;

    virtual type top() const = 0;

    virtual void pop() = 0;

    virtual ~StackADT() {}
};
#endif // !STACKADT_H

