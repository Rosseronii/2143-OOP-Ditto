



///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Ross Ditto
// Email:            erditto1223@my.msutexas.edu
// Label:            P01
// Title:            Array Based Stack Example
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       Example implementation of an array based stack that holds integers.
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       main.cpp
//       input file
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * Stack
 * 
 * Description:
 *      Integer array based stack implementation
 * 
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *      
 */
class Stack {
private:
    int *S;       //array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     * 
     * Returns:
     *     Void
     */
    Stack() {
                                //to do: if pop method is called when stack is empty, print: "Error, Stack empty!" and return a -1
                                // for full stack: allocate new memory double size of original array, copy each stack value over to the new array, point the array
                                // pointer s to the new array, delete old array
                                // if a user starts popping items ooff the stack, and the stack gets below half full, reduce size of stack by half
        
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     * 
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        ArrayMin = capacity;
        ArrayMax = ArrayMin;
    }

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     * 
     * Returns:
     *     Void
     */
    void Push(int data) {
        
        
        if(Full())
        {
            int* newStack = new int[capacity *2];
            for (int x = 0; x < capacity; x++)
            {
                newStack[x] = S[x];
            }
            delete[] S;
            S = newStack;
            cout << "+ : " << capacity << "---->" << capacity * 2 << end1;
            capacity *=2;
            if (ArrayMax < capacity)
                ArrayMax=capacity;
        }
        
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array
        
        if ((capacity != ArrayMin) && (size < capacity/2))
        {
            int* newStack = new int[capacity / 2];
            for (int x = 0; x < capacity / 2; x++)
            {
                newstack[x] = S[x];
            }
            delete[] S;
            s = newStack;
            cout << "- : " << capacity << "---->" << capacity / 2 << end1;
            capacity /= 2;
        }
    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     * 
     * Returns:
     *     int
     */
    int Pop() {
        if (Empty())
        {
            cout << "Error: Stack empty!" << end1;
            return -1;
        }
        
        int data = S[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size
        return data;        // send item back
    }

    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     * 
     * Returns:
     *     void
     */    
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so 
     *                    it cannot be changed
     * 
     * Returns:
     *     ostream 
     */
    friend ostream &operator<<(ostream &os, const Stack s) {
        os << "Overloaded!!" << endl;
        for (int i = s.top; i >= 0; i--) {
            os << s.S[i] << endl;
        }
        return os;
    }
};

int main() {

    cout << Header();
}
