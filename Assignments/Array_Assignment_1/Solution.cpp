#include <iostream>
using namespace std;
class Array
{
    private:

        int index ,siz,full;
        int *p ,*current; // pointers these will hold the address of an array
        bool stop;


    public:

        Array(); // constructor
        void start();
        void endd();
        int length();
        int get();
        void update(int number);
        void next();
        void back();
        void add_at_start(int n);
        void add_at_end(int n);
        void add_at_desired_index(int index, int number);
        void remove();
        void print();


};

// constructor;
Array::Array()
{

    cout<<"Enter the size of an array: ";
    cin>>siz;
    p = new int [5]; // by doing this "current" will point to the 0th index of an array
    current = p;
    index =  full = 0;
    stop = false;
    int elements;

    cout<<"Size of an array is "<<siz<<endl<<"How many elements you want to assign to an array: ";
    cin>>elements;

    if(elements>siz)
    {
        cout<<"Size of an array is "<<siz<<" you can't add "<<elements<<" elements"<<endl;

    }

    else
    {

        for(int i=0; i<elements;i++)
        {
            cout<<"Enter the "<<i+1<<" element: ";
            cin>>*current;
            full++;
            next();

        }


    cout<<endl;

  }
}


/*We are initallizing a pointer to an array...
and "an address of an array is an starting address of an array" that's why we are doing "p = arr" means now pointer is pointing the
0 index of an array */


void Array :: start()   // With this function  "current" pointer will point to 0th index ;
{

    current = p;
    index = 0;
}

void Array :: endd()   // This function will move the "current" pointer to the last index
{

    for(int i=0 ; i<siz ; i++)
        {
            if(index+1 <siz )   /* It means when index+1 less then size of an array move the "current" pointer and  when this condition becomes false
                                    then the current pointer will be on the last index let suppose "index is 3" and "size of an array is 4"
                                    so "3+1 < 4" becomes false and in the "else" the loop will gonna stopped.. */
            {
                current++;
                index++;
            }

            else
            {
                break;

            }
        }

}


int Array :: length()
{

    return full;
}

int  Array ::  get()  // This function will retrun the element where the current pointer is pointing
{

    return *current;

}


void Array :: update(int number)   //  This function will update this number with where the "current" pointer is pointing
{


    *current =  number ;

}


void Array :: next()
{
    if(index+1==siz) /* if the size of "index+1" and "siz" variable will be same then according to the logic the pointer will on last index of an array
                       ans it can't move further */
    {
        cout<<"current pointer can't be move further. It is on the last index"<<endl;

    }

    else
    {
        current++;
        index++;
    }

}

void Array :: back()
{

    if(index == 0 )    /* In the constructor we have initallized the index = 0 and when the index is equal to 0 it means that the "current"
                           pointer is on the first index because when we had initallized both the "current pointer at 0th index" and the "index = 0"
                            and it means when current "pointer" will be on 0th index then the index will be equal to zero. */
    {
            cout<<"Pointer can't be back, it's on the first index"<<endl;
    }

    else
    {

            current--;
            index--;
    }

}

void Array :: add_at_start(int n) // This Function will add the number at 0th index....
{
    if(full==siz)
    {

        cout<<"Array is full...Further can't be added"<<endl;

    }

    else
    {

    start();


    int temp = index ;

    endd();

    for(int i=0;i<siz;i++)
    {

        if(temp==index)
        {

            *current = n;
            full++;
            break;

        }

        else
        {
            *current = *(current-1);
            back();

        }

    }
    }
}


void Array :: add_at_end(int n)  // This function will add the number at the last index
{
    if(siz == full)
    {

        cout<<"Array is already full.....More elements can't be added"<<endl;

    }


    else
    {
        endd();
        *current = n;
        full++;
    }

}







void Array :: add_at_desired_index(int index , int number)
{
    /* In this function when we are using "this->index" it means that the "global index" and we are using the only index it means that the local index
    of this function */

        if(siz == full ) /*when full is equal to siz it means that the an array is already full and we can't add more to it... and
                         and whenever we are adding any element to the array we have done this "full++" so with the help of full
                        we can find whether the array is full or not */
        {
            cout<<"Array is already full....Further elements can't be added"<<endl;

        }


        else if(index>siz)  // if index is greater then size it means that index is out of range and we cant add the number on the given index
        {

            cout<<"Index out of range"<<endl;

        }


     else
     {

            start();
            for(int i=0 ;i<siz;i++)
            {

                next();
            }

            for(int i=0; i<siz; i++)
            {

                if(this->index == index)  // The index where we add element will gonna equal to the index of the code.
                                            // "this->index" is a variable which tells us that where is the current pointer is pointing.
                {
                    *current = number;
                    full++;
                }

                else
                {

                    *current=*(current-1);
                    back();
                }

            }



    }


}

void Array :: remove()   // This function will remove the element where the current pointer is pointing at the moment
{
    int n;
    cout<<"Enter the number you want to delete: ";
    cin>>n;

    if(full == 0)
    {

        cout<<"Array is already empty!!!"<<endl;

    }

    else if(full !=0)
    {   start();


        for(int i=0; i<full ;i++)
        {
        if(*current==n)
        {

            if(i+1==full)
            {



              for(int j=i+1; j<full+1; j++)
              {
                    *current = *(current+1);
                     next();

              }

            }

            else
            {

                for(int j=i+1; j<full; j++)
                {
                    *current = *(current+1);
                    next();


                }
                stop = true;
                break;


            }
        }

        else
        {
                next();
        }



    }
  }

     if(stop == false)
        {

            cout<<"Key not found"<<endl;

        }




}


void Array :: print()
{
    start();

    for(int i=0;i<siz;i++)
    {
        cout<<"Arr["<<i<<"] = "<<*current<<endl;
        next();


    }


}




int main()

{
    Array a;
    a.print();
    a.add_at_desired_index(0,46);
    a.print();
    a.remove();
    a.print();
}

