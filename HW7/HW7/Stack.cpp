/*
 Author: Satish Singhal
 */

#include "Stack.hpp"
//------------------------------- Default Constructor
Stack::Stack() : top_position (-1),items(new ItemType[MAX]),numItems(0),arrayCapacity(MAX)
{
    cout << "From Stack default constructor." << endl;
}

//------------------------------- Explicit Constructor
//Stack::Stack(int topPos, ItemType itms, size_t nmItms, size_t arrCap) : top_position(topPos), items(new ItemType(itms)), numItems(nmItms), arrayCapacity(arrCap)
//{
//    cout << "From Stack explicit constructor" << endl;
//}

//------------------------------- Copy Constructor
Stack::Stack(const Stack & st) {
    if (this == & st)
    {
        cout << "Self copy is prohibited. Exiting." << endl;
        exit(1);
    }
    copy(st);
    
    cout << "From Stack Copy Constructor." << endl;
}

//-----------------------------------
bool Stack::isEmpty() const
{
    return (top_position == -1);
}

//------------------------------------
bool Stack::isFull() const
{
    return (top_position == MAX - 1);
}

//-----------------------------------
ItemType Stack::top() const
{
    if (isEmpty())
    {
        throw "Stack is empty";
    }
    else
    {
        return items[top_position];
    }
}

//------------------------------------
void Stack::pop()
{
    if (isEmpty())
    {
        cerr << "The stack is empty.\n";
        return;
    }
    else
    {
        top_position--;
    }
}

//------------------------------------------
void Stack::push(ItemType newItem)
{
    if (arrayCapacity > this->numItems)
    {
        top_position++;
        items[top_position] = newItem;
        numItems = numItems + 1;
    }
    else {
        size_t len = arrayCapacity + GROWBY;
        ItemType * Temp;
        
        Temp = new ItemType[len];
        
        for (size_t index = 0; index < this->numItems; index++)
        {
            Temp[index] = items[index];
        }
        
        delete[] items;
        items = Temp;
        Temp = nullptr;
        arrayCapacity = len;
        
        top_position++;
        items[top_position] = newItem;
        this->numItems = this->numItems + 1;
    }
    
}

//------------------------------------------
void Stack::copy(const Stack & Stk) {
    this->items = new ItemType[Stk.arrayCapacity];
    
    for (size_t i = 0; i < Stk.arrayCapacity; i++)
    {
        this->items[i] = Stk.items[i];
    }
    this->arrayCapacity = Stk.arrayCapacity;
    this->numItems = Stk.numItems;
    this->top_position = Stk.top_position;
}

//------------------------------------------
const Stack & Stack::operator = (const Stack & Stk) {
    if (this != &Stk)
    {
        delete[] items;
        copy(Stk);
    }
    
    cout << "From Stack Assignment operator." << endl;
    return *this;
}

//------------------------------------------
size_t Stack::getArrayCapacity() const {
    return arrayCapacity;
}

//------------------------------------------
size_t Stack::getNumItems() const {
    return numItems;
}


//---------------------------------- Deconstructor
Stack::~Stack()
{
    delete [] items;
    cout << "From Stack Destructor." << endl;
}



