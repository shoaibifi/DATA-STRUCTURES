#include <iostream>
using namespace std;
struct node
{
    char info[15];


};

class Trial
{
    private:
        node obj1, *temp1, *temp2, *temp3;
        int i, length;
        char *p, *q;

    public:
        Trial();  // constructor
        ~Trial(); // destructor
        void startin(); // Method
};

int main()
{

    Trial t;
    t.startin();


}
Trial::Trial()
{
    temp1 = temp2 = temp3 = NULL;
    p  = q = NULL;
    i = length = 0;



}

Trial ::~Trial()
{
    delete temp1,temp2,temp3;
    delete []p,q;



}

void Trial :: startin()
{

    temp1 = new node ;
    temp2 = new node ;

    cout<<"\n Enter the information about temp1: ";
    cin>>temp1->info;

    cout<<"\n Enter the information about temp2: ";
    cin>>temp2->info;

    temp3 = &obj1;
    // obj is the object of the struct "node" and we are stroing its adrress in the pointer of node also.

    cout<<"\n Enter the information about temp3: ";
    cin>>temp3->info;

    cout<<"\n Showing Inforamtion of temp1: ";
    cout<<temp1->info;

    cout<<"\n Showing Inforamtion of temp2: ";
    cout<<temp2->info;

    cout<<"\n Showing Inforamtion of temp3: ";
    cout<<temp3->info;

    cout<<"\n----------------------------------------------------------------------------------------------\n";

    cout<<"Now enter the length of character array \n";
    cin>>length;

    p = new char [length];
    // no named an array has been made at dynamic memory...
    q = p;
    // now q pointer is pointing at the same where p is pointing.

    cout<<"Now enter the "<<length<<" characters to fill an array.\n";

    for(i=0; i<length;i++)
    {
        cin>>*p;
        // taking the characters as input by using derefrencing operator on p pointer
        p = p+1;
        /* At the moment p pointer has the address of 0 index of an array by doing this "p = p+1 " we can get the input at in full array until the loop ends
        and when the loop will ends... */
    }

    p = q;
    /* q has the starting address of an array so at the moment q is the address of last index of an array and by doing this we are setting back it to
    staring address of an array */



    cout<<"Now showing the character array .\n";

    for(i =0; i<length; i++)
    {

        cout<<*p<<",";
        p = p+1;

    }
    cout<<endl;

    p = q;
 cout<<"End of start in function"<<endl;

}













