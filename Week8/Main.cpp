#include <iostream>
#include <queue>
#include "stackType.h"
using namespace std;

int main()

{
	StackType<int> stack1(50);
	StackType<int> stack2(50);

	stack1.initializeStack();
	stack1.push(23);
	stack1.push(45);
	stack1.push(38);

	stack2 = stack1;

	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	stack2.pop();
	stack2.push(32);

	cout << "\n**** After pop and push operations on stack2 ****" << endl;
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	stack2.push(11);

	cout << "\n**** After another push operation on stack2 ****" << endl;
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	StackType<int> stack3;
	stack3.push(1);
	stack3.push(2);
	stack3.push(3);

	StackType<int> stack4;
	stack4.push(4);
	stack4.push(5);
	stack4.push(6);

	std::queue<StackType<int>> stackQueue;

	stackQueue.push(stack3);
	stackQueue.push(stack4);

	while (!stackQueue.empty()) {
		StackType<int> frontStack = stackQueue.front();

		cout << "\n\nTop element of the front stack: " << frontStack.top();

		stackQueue.pop();

		cout << "\nPopped the front stack.";
	}
	return 0;
}