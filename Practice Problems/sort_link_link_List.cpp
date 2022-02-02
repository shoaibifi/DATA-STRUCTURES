#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;

};


class listt
{
    private:
           node *head, *temp, *temp1;
           int key;
           bool found;

    public:
        listt();
        void add();
        void delet();
        void print();
        void sortt();


};

listt :: listt()
{
    head = temp = temp1 = NULL;
    found = false;


}

void listt :: print()
{
    if(head==NULL)
    {
        cout<<"Link list is empty!! "<<endl;
        return;
    }

    temp = head;

    while(temp!=NULL)
    {
        cout<<temp->info<<",";
        temp = temp->next;

    }

}


void listt :: add()
{

    if(head == NULL)
    {

        head = new node ;

        cout<<"Enter the first element: ";
        cin>>head->info ;
        head->next = NULL;
        return ;


    }


    else if(head != NULL)
    {
        temp =  head;
        cout<<"After which Number you want to add Node: ";
        cin>>key;

        while(temp != NULL)
        {

            if(temp->info == key)
            {

                    found = true;
                    temp1 = new node;
                    cout<<"Enter the element: ";
                    cin>>temp1->info;

                    temp1->next = temp->next;
                    temp->next  = temp1;

                    temp = temp->next;


            }
            temp = temp->next;




        }

          if(found==false)
            {
                cout<<key<<" not found!!!"<<endl;


            }

        found = false;
    }

}

void listt :: delet()
{
    if(head==NULL)
    {
        cout<<"There is nothing to delete!!!"<<endl;
        return;
    }

    temp = head;
    cout<<"Enter the key you want to delete: ";
    cin>>key;

    while(temp!=NULL)
    {
        if(head->info==key)

        {
            head = head->next;
            delete temp;
            temp = NULL;
            found = true;
            return;
        }

        else if(temp->next->info==key)
        {

            temp1 = temp->next;

            temp->next = temp->next->next;    // This line can be written as    temp->next = temp1->next;

            delete temp1;

            temp1 = NULL;

            found = true;
            return;

        }

        temp = temp->next;


    }

    if(found == false)
    {
        cout<<key<<" not found."<<key<<"can't be deleted"<<endl;

    }

    found = false;





}

void listt :: sortt()
{
    int n;

    temp = head;
    temp1 = temp->next;


    while(temp!=NULL)
    {
        while(temp1 != NULL)
        {
            if(temp1->info < temp->info)
            {
                n = temp->info;
                temp->info = temp1->info;
                temp1->info = n;

            }

            temp1 = temp1->next;

        }

        temp = temp->next;

        if(temp!=NULL)
        {
            temp1 = temp->next;
        }


    }



}

int main()
{

    listt *l;

    l = new listt;

    l->add();
    l->add();
    l->add();

    l->print();

    l->sortt();

    l->print();

}




