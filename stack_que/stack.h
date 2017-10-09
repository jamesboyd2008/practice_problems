//This is the header file stack.h. This is the interface for the class Stack,
//which is a class for a stack of symbols.
#ifndef STACK_H
#define STACK_H

    struct StackFrame
    {
        char data;
        StackFrame *link;
    };

    typedef StackFrame* StackFramePtr;

    class Stack
    {
    public:
        Stack( );
        //Initializes the object to an empty stack.

        Stack(const Stack& a_stack);
        //Copy constructor.

        ~Stack( );
        //Destroys the stack and returns all the memory to the freestore.

        void push(char the_symbol);
        //Postcondition: the_symbol has been added to the stack.

        char pop( );
        //Precondition: The stack is not empty.
        //Returns the top symbol on the stack and removes that  
        //top symbol from the stack.

        bool empty( ) const;
        //Returns true if the stack is empty. Returns false otherwise.
    private:
        StackFramePtr top;
    };
#endif //STACK_H
