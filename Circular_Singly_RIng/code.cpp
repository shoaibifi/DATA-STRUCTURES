#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;


};

class Singly_Ring
{


    private:
        node *head, *temp, *temp1;
        int key;
        bool found;

    public:
        Singly_Ring();
        void add();
        void print();
        void delet();


};

Singly_Ring :: Singly_Ring()
{
    head = temp = temp1 = NULL;
    found = false;

}

void Singly_Ring :: add()
{
    if(head ==NULL)
    {
        head = new node;
        cout<<"Enter the first element: ";
        cin>>head->info;
        head->next = head;
        return;

    }

    temp = head;
    cout<<"After which element you want to add node: ";
    cin>>key;

    do
    {
        if(key==temp->info)
        {
            temp1 = new node;
            cout<<"Enter the element you want to add: ";
            cin>>temp1->info;
            temp1->next = temp->next;
            temp->next  = temp1;

            temp = temp->next; // to avoid the new node in case same keys.
            found = true;



        }
        temp = temp->next;


    }

    while(temp!=head);

    if(found == false)
    {
        cout<<key<<" not found"<<endl;

    }

    found = false;

}

void Singly_Ring :: delet()
{

        if(head == NULL)
        {
            cout<<"Link list is empty!!"<<endl;
            return;

        }



        temp = head;
        cout<<"Enter the element you want to delete: ";
        cin>>key;

        do
        {
            if(head->info==key) // If the key is on head.
            {
                found = true;
                if(head->next==head)
                {
                    // If there is only head then simply delete it and return

                    delete head;
                    head = temp = NULL;
                    return;


                }

                else    // If there are more nodes after the head then head will point to the next node.
                {
                     while(temp->next != head)
                     {
                        temp = temp->next;

                     }

                     temp->next = head->next;
                     temp1 = head;
                     head = head->next;

                     delete temp1;
                     temp1 = NULL;

                }


            }

            else if(temp->next->info == key)
            {

                temp1 = temp->next;

                temp->next = temp->next->next;

                delete temp1;

                temp1 = NULL;

                found = true;


            }



        }

        while(temp!=head);

        if(found == false)
        {
            cout<<key<<" not found"<<endl;

        }

        found = false;



}



void Singly_Ring :: print()
{

      if(head == NULL)
      {
        cout<<"Link list is empty!!"<<endl;
        return;

      }


        temp = head;
    do
    {
        cout<<temp->info<<", ";
        temp = temp->next;
    }

    while(temp!=head);

    cout<<endl;

}

int main()
{
    Singly_Ring *s;

    s  = new Singly_Ring;

    int key;
    char loop;


    while(true)
    {
        cout<<"Press 1 to add node"<<endl;
        cout<<"Press 2 to delete node"<<endl;
        cout<<"Press 3 to print the elements of node"<<endl;
        cout<<"Press 4 to quit"<<endl;

        cin>>key;

        if(key==1)
        {
            s->add();

             cout<<"Continue (Y/N): ";
             cin>>loop;

            if(loop=='N' || loop == 'n' )
            {
                break;
            }

        }

        else if(key==2)
        {
             s->delet();

             cout<<"Continue (Y/N)";
             cin>>loop;

            if(loop=='N' || loop == 'n' )
            {
                break;
            }

        }

        else if(key==3)
        {
            s->print();

            cout<<"Continue (Y/N)";
            cin>>loop;

            if(loop=='N' || loop == 'n' )
            {
                break;
            }

        }

        else if(key==4)
        {
            break;

        }
        else
        {
            cout<<"Wrong input Continue (Y/N)";
            cin>>loop;

            if(loop=='N' || loop == 'n' )
            {
                break;
            }


        }



    }


}



