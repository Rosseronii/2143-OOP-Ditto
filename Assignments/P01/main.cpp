



///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Ross Ditto
// Email:            erditto1223@my.msutexas.edu
// Label:            P01
// Title:            Stack Upgrade
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       Push and Pop values from an input file for an array-based stack. 
//       Prints the starting, max, and end size at end of program.
//       Empty values are prevented from popping.
//       If the stack overflows, then the stack is doubled to make room for more values.
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
 *      - int StartSize()
 *      - int MaxSize()
 *      - int EndSize()
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
    int ArrayMax; //minimum stack size
    int ArrayMin; //maximum stack size
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
        
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        ArrayMin = capacity;    // min stack size
        ArrayMax = ArrayMin;    //starting size set to max
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
        ArrayMin = capacity;    // min stack size
        ArrayMax = ArrayMin;    //starting size set to max
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
        
        
        if(Full())                                                  //if the stack is filled
        {
            int* newStack = new int[capacity *2];                   //double stack value for new stack
            for (int x = 0; x < capacity; x++)
            {
                newStack[x] = S[x];                                 //old stack values added to new
            }
            delete[] S;                                            //old stack erased
            S = newStack;                                          //points toward new stack
            cout << "+ : " << capacity << "---->" << capacity * 2 << endl;
            capacity *=2;                                         //new stack capacity doubled
            if (ArrayMax < capacity)                             
                ArrayMax=capacity;                               //size set to maximum value
        }
        
        top++;                                                   // move top of stack up
        size++;                                                 // increment size
        S[top] = data;                                          // add item to array
        
        if ((capacity != ArrayMin) && (size < capacity/2))      //array reduced if number value less than half of array size
        {
            int* newStack = new int[capacity / 2];              //new stack created (half sized)
            for (int x = 0; x < capacity / 2; x++)
            {
                newStack[x] = S[x];                             //new stack filled with number values
            }
            delete[] S;                                         //stack erased
            S = newStack;                                       //points toward new stack
            cout << "- : " << capacity << "---->" << capacity / 2 << endl;
            capacity /= 2;                                      //new stack capacity halved
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
        if (Empty())                                    //if stack is empty
        {
            cout << "Error: Stack empty!" << endl;      //error messaged printed
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
        for (int i = top; i >= 0; i--) {    //prints values
            cout << S[i] << endl;
        }
    }
/**
     * StartSize:
     *    Returns starting size value of stack
     * Params:
     *    void
     *
     * Returns:
     *     int: stack size
     */
   int StartSize()
   {
       return ArrayMin; //starting size
   }
 /**
     * MaxSize:
     *    Returns maximum size value of stack
     * Params:
     *    void
     *
     * Returns:
     *     int: stack size
     */   
   int MaxSize()
   {
       return ArrayMax;  //largest size
   }
  /**
     * EndSize:
     *    Returns ending size value of stack
     * Params:
     *    void
     *
     * Returns:
     *     int: stack size
     */  
    int EndSize()
    {
        return capacity; //final size
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
  /**
     * MyInfo:
     *    Returns a string with my name, program, and date
     * Params:
     *    void
     *
     * Returns:
     *     string: my information
     */
    string MyInfo()  //my info returned
   {
        return "Name: Ross Ditto \nProgram: P01 \nDate: 15 Sept 2020\n\n\n\n";
    }
int main() {

    cout << MyInfo();                       //my info printed
    Stack S;                                //stack created
    ifstream infile;                        //read from input file
    infile.open("input.txt");
    ofstream outfile;                       //output file created and opened
    outfile.open("output.txt");
    string PushOrPop;                        // pop/push types
    int data;                               //file data
    while (infile >> PushOrPop)            //loop through all data to be read
    {
        if (PushOrPop == "push")           //values added to stack from file
        {
            infile >> data;                // value data retrieved from file
            S.Push(data);                  //added to stack
        }
        if (PushOrPop == "pop")
        {
            S.Pop();                      //values removed from stack
        }
    }
    outfile << "Starting Size: " << S.StartSize() << endl;  //starting size printed to output
    outfile << "Max Size: " << S.MaxSize() << endl;         //max size printed to output
    outfile << "Ending Size: " << S.EndSize();              //ending size printed to output
    infile.close();
    outfile.close();                                        //close files
    return 0;
}
