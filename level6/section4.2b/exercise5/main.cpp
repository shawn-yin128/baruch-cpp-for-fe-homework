#include "stack.hpp"
#include "stack_exception.hpp"
#include <iostream>

using namespace std;

int main(void) {			
	Stack<int> stack1(3);
    Stack<int> stack2(stack1); // copy cosntructor
	Stack<int> stack3 = stack2; // test assignment operator

    try {
        Stack<int> stack4(5);
        for (int i = 0; i < 6; i++) {
            stack4.Push(i);
        }
    }
    catch (StackException& ex) {
        cout << ex.GetMessage();
    }

    try {
        Stack<int> stack5(5);
        for (int i = 0; i < 5; i++) {
            stack5.Push(i);
        }
        for (int i = 0; i < 6; i++) {
            cout << stack5.Pop() << endl; // test pop exception
        }
    }
    catch (StackException& ex) {
        cout << ex.GetMessage();
    }

	return 0;
}
