#include <iostream>
using namespace std;
class Reverse_Array
{   public:
        int siz ; // To find the size of an array
        int arr[7]; // array
        int full;   // This data member is for to check whether the array is full or not
        int *p, *s;   /* Two pointers with "p" pointer we we do every work and with "s" pointer when we want to return "p" pointer to 0th index then we will
                        do "p = s" because in constructor we will initallize both at the starting address of an array */
        Reverse_Array(); // constructor;
        void reverse_array(); // Class Method that will reverse an array


};

Reverse_Array :: Reverse_Array()
{

    siz = sizeof(arr)/sizeof(arr[1]); // Finding the size of an array and storing it to "siz" data member
    p = s = arr;                      // Giving the starting address of an array to both pointers
    full = 1;                         // here we are giving 1 to full because its the demand of logic

    // its a good practice to initallize everything for that we are initallizing the whole array with 0;

    for(int i=0; i<siz;i++ )
    {

    *p = 0;
    p++;

    }
    p = s;   // now the pointer p will also point to the starting address of an array


}

void Reverse_Array :: reverse_array()
{


    for(int i=0 ;i<siz;i++)

    {
        cout<<"Enter the "<<i+1<<" element: ";
        cin>>*p;


    if(full==siz)
    break;


    else

    {
        p++;
        full++;
    }

// At the end of this loop the p pointer will be at the last adress of an array so no we will print the loop back and will do p--
    }

    cout<<"Reversed array is  ";

    for(int i=0 ;i<siz;i++)

    {
        cout<<*p<<",";
        p--;

    }



}


int main()
{
    Reverse_Array *r;

    r = new Reverse_Array;

    r->reverse_array();

    return 0;




}



