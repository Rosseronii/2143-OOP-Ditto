///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Ross Ditto
// Email:            ross.ditto@gmail.com
// Label:            H01
// Title:            Commenting Code
// Course:           CMPS 2143
// Semester:         Fall 2020
//
// Description:
//       Prints out the tail value of two lists
//       
//       
//       
//       
//       
//        
//       
// Usage: 
//      - $ ./main filename
//      - 
//      
// Files:            
//      main.cpp    : driver program 
//      
//      
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int A[100];

struct Node
{
    int x;
    Node *next; // Points to next available location
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      contains linked list and methods
 * 
 * Public Methods:
 *      - void push
 *      - void insert
 *      - void printTail
 *      - void print
 *      - int pop
 *      - int operator+
 *      - int operator[]
 * Private Methods:
 *      - no private methods
 * 
 * Usage: 
 * 
 *      - examples of how
 *      - to use your class 
 *      
 */
class List
{
  private:
    Node *Head; // Points to beginning of list
    Node *Tail; // Points to the end of list
    int Size; // size of list

  public:
    List()
    {
        Head = Tail = NULL; //Set starter head/tail values
        Size = 0; // Set list size to 0
    }
 /**
     * Public : Push
     * 
     * Description:
     *      add integer to end of list
     * 
     * Params:
     *      int val - value added to list
     *      
     * 
     * Returns:
     *      nothing
     */
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);
        // see if list is empty
        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        // creates node at end of list, that value now set to be the last in list
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }
 /**
     * Public : Insert
     * 
     * Description:
     *      add integer to part of list
     * 
     * Params:
     *      int val - value added to list
     *      
     * 
     * Returns:
     *      nothing
     */
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }
 /**
     * Public : PrintTail
     * 
     * Description:
     *      prints out last item of the list
     * 
     * Params:
     *      nothing
     *      
     * 
     * Returns:
     *      nothing
     */
    void PrintTail()
    {
        cout << Tail->x << endl;
    }
 /**
     * Public : Print
     * 
     * Description:
     *      list of string is printed
     * 
     * Params:
     *      nothing
     *      
     * 
     * Returns:
     *      string - the list(all its values)
     */
    string Print()
    {
        Node *Temp = Head;
        string list;
        //loops through items in list, puts them into a string
        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
     /**
     * Public : Pop
     * 
     * Description:
     *      returns the value of the value at end of list
     * 
     * Params:
     *      
     *      
     * 
     * Returns:
     *      int - # at end of list
     */
    int Pop()
    {
        Size--;
        return 0; //
    }
     /**
     * Public : operator+
     * 
     * Description:
     *      adds two lists together
     * 
     * Params:
     *      
     *      
     * 
     * Returns:
     *      List - new list with values of two combined lists
     */
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
         /**
     * Public : operator[]
     * 
     * Description:
     *      returns an int value as if the list were an array
     * 
     * Params:
     *      int index - indexes the list to retrieve a value
     *      
     * 
     * Returns:
     *      int - value from the indexing of the list
     */
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size) //used to see if index out of bounds or not
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++) //loops until index completes
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) //25 numbers are added to list L1
    {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) //50 numbers are added to list L2
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail(); 
    L2.PrintTail(); //prints out last number in lists L1 and L2

    List L3 = L1 + L2;
    cout << L3 << endl; //third list is created; L1 and L2 are added

    cout << L3[5] << endl; //the fifth index in list L3 is printed
    return 0;
}
