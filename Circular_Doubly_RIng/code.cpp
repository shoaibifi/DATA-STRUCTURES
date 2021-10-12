#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next, *prev;

};

class Doubly_Ring
{
    private:
        node * head, *temp, *temp1;
        int key;
        bool found;

    public:
        Doubly_Ring();

        void add();
        void delet();
        void print();
};

Doubly_Ring :: Doubly_Ring()
{
    head = temp = temp1 = NULL;
    found = false;


}

void Doubly_Ring :: add()
{

    if(head == NULL)
    {

        head = new node;
        cout<<"Enter the first Element: ";
        cin>>head->info;
        head->next = head->prev = head;
        return;
    }


    temp = head;
    cout<<"After which node you want to add node: ";
    cin>>key;

    temp = head;


    do
    {

        if(temp->info==key)
        {
            temp1 = new node;

            cout<<"Enter the element: ";
            cin>>temp1->info;

            temp1->prev = temp;

            temp1->next = temp->next;

            temp->next  = temp1;

            temp1->next->prev = temp1;
            found = true;

        }
        temp = temp->next;
    }

        while(temp!=head);

        if(found == false)
        {
            cout<<key<<" not found!!"<<endl;

        }

        found = false;







}

void Doubly_Ring :: delet()
{
    if(head == NULL)
    {
        cout<<"Link list is empty!!"<<endl;

    }

    temp = head;

    cout<<"Enter the element you want to delete: ";
    cin>>key;

    do
    {


        if(head->info==key)
        {
            if(head->next == head)
            {
                delete head;
                head = NULL;
                return;

            }

            else
            {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
                delete temp;
                temp = head;


            }




        }






       else if(temp->info == key)
        {

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;


            temp1 = temp;
            temp = temp->prev;

            delete temp1;

        }

        temp = temp->next;
    }

        while(temp!=head);







    }


void Doubly_Ring :: print()
{
    if(head == NULL)
    {
        cout<<"Link list is Empty:";
        return;
    }

    temp = head;

    do
    {
        cout<<temp->info<<",";
        temp = temp->next;


    }

    while(temp!=head);



}

int main()
{
    Doubly_Ring *d;

    d = new Doubly_Ring();

    d->add();
    d->add();
    d->add();
    d->delet();
    d->print();



}

