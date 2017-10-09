//This is the implementation file stack.cpp.
//This is the implementation of the class Stack.
//The interface for the class Stack is in the header file stack.h.
#include <iostream>
#include <cstddef>
#include "stack.h"
using namespace std;


    //Uses cstddef:
    Stack::Stack( ) : top(NULL)
    {
        //Body intentionally empty.
    }

    //Uses cstddef:
    Stack::Stack(const Stack& a_stack)
    {
        if (a_stack.top == NULL)
            top = NULL;
        else
        {
            StackFramePtr temp = a_stack.top;//temp moves
                //through the nodes from top to bottom of 
                //a_stack.
            StackFramePtr end;//Points to end of the new stack.

            end = new StackFrame;
            end->data = temp->data;
            top = end;
            //First node created and filled with data.
            //New nodes are now added AFTER this first node.

            temp = temp->link;
            while (temp != NULL)
            {
                end->link = new StackFrame;
                end = end->link;
                end->data = temp->data;
                temp = temp->link;
            }
            end->link = NULL;
        }
    }

    Stack::~Stack( )
    {
        char next;
        while (! empty( ))
           next = pop( );//pop calls delete.
    }

    //Uses cstddef:
    bool Stack::empty( ) const
    {
        return (top == NULL);
    }

    //Uses cstddef:
    void Stack::push(char the_symbol)
    {
        StackFramePtr temp_ptr;
        temp_ptr = new StackFrame;

        temp_ptr->data = the_symbol;

        temp_ptr->link = top;
        top = temp_ptr;
    }

    //Uses iostream:
    char Stack::pop( )
    {
        if (empty( ))
        {
            cout << "Error: popping an empty stack.\n";
            exit(1);
        }

        char result = top->data;

        StackFramePtr temp_ptr;
        temp_ptr = top;
        top = top->link;

        delete temp_ptr;

        return result;
    }



