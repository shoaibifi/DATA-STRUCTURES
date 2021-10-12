#include <iostream>
using namespace std;

struct node
{

    int info;
    node *next;

};

class Stack
{
    private:
        node *top,*temp;
        int limit, counter;

    public:
        Stack();
      void  push();
      void   pop();
//      void   top();

};

Stack :: Stack()
{
    top = temp = NULL;
    counter = 0;
    cout<<"Enter the limit for the nodes: ";
    cin>>limit;
}

void Stack :: push()
{

   if(counter == limit)
   {
    cout<<"Stacks limit is over you can't add more nodes...."<<endl;
    return;
    }



    if(top==NULL)
    {
        top = new node;
        cout<<"Enter the element: ";
        cin>>top->info;
        top->next = NULL;
        counter ++;
        return;
    }

    temp = new node;
    cout<<"Enter the element: ";
    cin>>temp->info;
    temp->next = top;
    top = temp;
    counter++;
    return;

}

void Stack :: pop()
{
    if(top==NULL)
    {

        cout<<"Stack is Empty!!"<<endl;
        return;
    }

    temp = top;
    top  = top->next;
    delete temp;
    temp = NULL;
    counter--;
    return;
}

int main()
{

Stack *s;

s = new Stack;

s->push();
s->push();
s->pop();

}
