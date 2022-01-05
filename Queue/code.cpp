#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;

};

class queuee
{
    private:
        node * frontt, * rear, *temp;
    public:
        void enqueue();
        void dequeue();
        void print();
        queuee();

};


queuee :: queuee()
{
    frontt = rear = NULL;


}

void queuee :: enqueue()
{
    if(rear==NULL)
    {
        rear = new node;
        // We can check this with front==NULL also but rear logically good
        cout<<"Enter the first element: ";
        cin>>rear->info;
        rear->next = NULL;
        frontt = rear;
        return;
    }

    rear->next = new node;
    rear = rear->next;
    cout<<"Enter the element: ";
    cin>>rear->info;

}

void queuee :: dequeue()
{

    if(frontt==NULL)
    {
        cout<<"Nothing to delete: ";
        return;

    }

    temp = frontt;
    frontt = frontt->next;

    if(frontt == NULL)
    {
        rear = NULL;

    }

    delete temp;
    temp = NULL;

}

void queuee :: print()
{

    while(frontt != NULL)
    {
        cout<<frontt->info<<" ";
        dequeue();
    }

}

int main()
{
    queuee *q;

    q = new queuee;

    q->enqueue();

    q->print();

    q->dequeue();



}

