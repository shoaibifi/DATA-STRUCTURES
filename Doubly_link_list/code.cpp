#include <iostream>
using namespace std;
struct node
{
    int info;
    node *next;
    node *prev;

};

class Doubly_Link_list
{
    private:
        node *head ,*temp, *temp1;
        int key;
        bool found;

    public:
        void add();
        void delet();
        void print();
        Doubly_Link_list();

};
Doubly_Link_list:: Doubly_Link_list()
{
    head = temp = temp1 = NULL;
    found = false;

}

void Doubly_Link_list :: add()
{
    if(head==NULL)
    {
        head = new node;
        cout<<"Enter the first element: ";
        cin>>head->info;
        head->prev = NULL;
        head->next = NULL;
        return;
    }

    temp = head;
    cout<<"After which number you want to add node:";
    cin>>key;

    while(temp!=NULL)
    {
        if(temp->info==key)
        {
            temp1 = new node;
            cout<<"Enter the element: ";
            cin>>temp1->info;


            temp1->next = temp->next;
            temp1->prev = temp;
            temp->next = temp1;
            found = true;

            if(temp1->next != NULL)
    /* This check is for if we are adding the new node on on the last then there will be no further node
    o if we are doing "temp1->next->previous = temp1"  so its a logical bug do it on the page you will understand it*/

            {
                temp1->next->prev = temp1;


            }
            temp = temp->next;  // By this the node will not be added after the new node if same key exists.


        }
        temp = temp->next;

    }

    if(found == false)
    {
        cout<<key<<" not found in this doubly link list!!!"<<endl;

    }

    found = false;



}

void Doubly_Link_list :: print()
{
    if(head == NULL)
    {
        cout<<"Link list is Empty!!"<<endl;
    }

    temp = head;

    while(temp!=NULL)
    {

        cout<<temp->info<<",";
        temp = temp->next;
    }


}

void Doubly_Link_list :: delet()
{
    if(head==NULL)
    {

        cout<<"Doubly link list is Empty!!!"<<endl;
    }



    cout<<"Enter the key you want to delete: ";
    cin>>key;

    temp = head;

    while(temp!=NULL)
    {

       if(temp->info == key)
        {
             if(temp->prev==NULL)
             {
                temp->next->prev = temp->prev;
                head = head->next;
                delete temp;
                temp = head;
                found = true;
             }




             else if (temp->next==NULL)
             {

                temp->prev->next = temp->next;
                delete temp;
                temp = NULL;// for avoiding fom the dangling pointer.
                found = true;
                return;


             }





            else
            {
                temp1 = temp->prev;
                temp->prev->next = temp->next;
                temp->next->prev  = temp->prev;
                delete temp;
                temp = temp1;
                found = true;
            }
        }

        temp = temp->next;

    }


    if(found==false)
        {
            cout<<key<<" not found in this Doubly link list!!!"<<endl;


        }

        found = false;
}






int main()
{

    Doubly_Link_list *l;

    l = new Doubly_Link_list;

    l->add();
    l->add();
    l->add();
    l->delet();
    l->print();
}
