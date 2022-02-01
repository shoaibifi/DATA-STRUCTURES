#include <iostream>
using namespace std;

struct node
{

    node *left, *right;
    int info;
    string LTH, RTH;

};

class TBT
{

        public:

        node *root, *temp1, *dummy, *sucessor;
        int key, tempNumber, check;


        TBT();
        void insertion(node *temp, int key);
        void inOrder(node *temp);
        node* nextInorder(node* p);
        void fastInorder(node* p);
        node  *suc(node *temp);
        void deletion(node *temp, int key);

};


TBT :: TBT()
{
    root = NULL;
    dummy = new node;
    dummy->right = dummy;
    dummy->left  = root;
    dummy->RTH = "child";
    dummy->LTH = "child";

}


void TBT :: insertion(node *temp, int key)
{
    if(root == NULL)
    {
        root = new node;
        root->info = key;
        root->left = dummy;
        root->right = dummy;
        root->RTH = "thread";
        root->LTH = "thread";
        dummy->left  = root;
        return;

    }


    else if(key >temp->info)
    {

        if(temp->RTH != "thread")
        {
                insertion(temp->right, key);
                return;
        }


        else
        {
            temp1 = new node;
            temp1->info = key;
            temp1->left = temp;
            temp1->LTH = "thread";
            temp1->right = temp->right;
            temp1->RTH = "thread";
            temp->right = temp1;
            temp->RTH = "child";
            return;

        }


    }





    else if(key < temp->info)
    {

        if(temp->LTH != "thread")
        {
                insertion(temp->left, key);
                return;
        }


        else
        {
            temp1 = new node;
            temp1->info = key;
            temp1->left = temp->left;
            temp1->LTH = "thread";
            temp1->right = temp;
            temp1->RTH = "thread";
            temp->left = temp1;
            temp->LTH = "child";
            return;

        }


    }




}

void TBT :: deletion(node *temp, int key)
{

    // IF key is on the root node
   if(key == root->info)
   {
        // case 1

        if((root->LTH =="thread" ) && (root->RTH == "thread"))
        {
            delete root;
            dummy->left = dummy;
            dummy->LTH = "thread";
            root = NULL;
            return;

        }

        // case 2

        else if((root->LTH== "thread") && (root->RTH != "thread"))
        {
            temp1 = root;
            root = root->right;
            delete temp1;
            temp1 = NULL;
            return;


        }

        else if((root->LTH!= "thread") && (root->RTH == "thread"))
        {
            temp1 = root;
            root = root->left;
            delete temp1;
            temp1 = NULL;
            return;


        }

        // Case 3


        else if((root->LTH != "thread") && (root->RTH != "thread"))
        {

           if(root->right->LTH == "thread")
           {


            sucessor = root->right;
            cout<<"Sucessor from deletion is: "<<sucessor->info<<endl;
            tempNumber = root->info;
            root->info = sucessor->info;
            sucessor->info = tempNumber;
            delete sucessor;
            root->right = NULL;
            return;
        }
            sucessor = suc(root->right);
            cout<<"Sucessor from deletion is: "<<sucessor->left->info<<endl;
            tempNumber = root->info;
            root->info = sucessor->left->info;
            sucessor->left->info = tempNumber;
            delete sucessor->left;
            sucessor->left = NULL;
            return;



        }
   }




   else if(key>temp->info)
    {


        if(temp == NULL)
        {
            if(check == 0)
            {

                cout<<"Binary Tree is empty "<<endl;
                return;
            }

            else
            {
                cout<<key<<" not found "<<endl;
                return;

            }

         }



        else if(temp->right->info == key )
        {

            // case 1
            cout<<"key found"<<endl;

            if((temp->right->RTH=="thread") && (temp->right->LTH=="thread"))
            {
                cout<<"Check found"<<endl;
               temp1 = temp->right;
               temp->right = temp->right->right;
               temp->RTH = "thread";
               delete temp1;
               return;

            }

            // Case 2 leaf has 1 child

            else if((temp->right->LTH != "thread" ) && (temp->right->RTH == "thread"))
            {
                        temp1 = temp->right;
                        temp->right->left->right = temp->right->right;
                        temp->right = temp->right->left;
                        delete temp1;
                        temp1 = NULL;
                        return;


            }

            else if((temp->right->LTH == "thread") && (temp->right->RTH != "thread"))
            {

                        temp1 = temp->right;
                        temp->right->right->right->left = temp; //Predecessor
                        temp->right = temp->right->right;
                        delete temp1;
                        temp1 = NULL;
                        return;

            }


            // Case 3 "X" has two childs
            else if((temp->right->RTH != "thread") && (temp->right->LTH != "thread"))
            {


                if(temp->right->right->LTH == "thread")
               {

                sucessor = temp->right; // Actually sucessor is temp->right->right but we have to delete it one step backward....
                // So now sucessor will be "sucessor->right"


                cout<<"Successsor from the deletion updated code: ";
                cout<<sucessor->right->info<<endl;
                tempNumber = temp->right->info;
                temp->right->info = sucessor->right->info;
                sucessor->right->info = tempNumber;
                temp1 =  sucessor->right;
                sucessor->right = sucessor->right->right; // predecessor
                sucessor->RTH = "thread";

                delete temp1;
                return;
                }


                else
                {


                sucessor = suc(temp->right->right);

                // Actually sucessor is equal to sucessor->left...But we have to delete it so one step back we are doing this.
                cout<<"Successsor from the deletion: ";
                cout<<sucessor->left->info<<endl;
                tempNumber = temp->right->info;
                temp->right->info = sucessor->left->info;
                sucessor->left->info = tempNumber;
                temp1 = sucessor->left;
                sucessor->left = sucessor->left->left; //thread predecessor
                sucessor->LTH = "thread"; //predecessor
                delete temp1;
                return;

                }
            }
        }


        else
        {
            check = 1;
            if((temp->right->RTH=="thread") && (temp->right->LTH == "thread"))
            {
                 cout<<key<<" not found"<<endl;
                 return;

            }
            else
            {
                cout<<"giving call"<<endl;
                deletion(temp->right,key);

            }
        }


    }

    else if(key < temp->info)
    {

        if(temp == NULL)
        {

           if(check == 1)
           {

                cout<<key<<" not found!"<<endl;
                return;

           }

           else
           {

                cout<<"Binary Search Tree is empty "<<endl;
                return;
            }
        }



        if(temp->left->info==key)
        {


            // Check for the case 1

            if((temp->left->LTH == "thread") && (temp->left->RTH == "thread"))
            {

                    temp1 = temp->left;
                    temp->left = temp->left->left;
                    delete temp1;
                    temp->LTH = "thread";
                    return;
            }


            // Case 2

            else if ((temp->left->LTH != "thread") && (temp->left->RTH == "thread"))
            {


                    temp1 = temp->left;
                    temp->left->left->left->right = temp;
                    temp->left = temp->left->left;
                    delete temp1;
                    temp1 = NULL;
                    return;
            }


            else if((temp->left->LTH == "thread") && (temp->left->RTH != "thread"))
            {
                    temp1 = temp->left;
                    temp->left->right->left = temp->left->left;
                    temp->left = temp->left->right ;
                    delete temp1;
                    temp1 = NULL;
                    return;
            }

            // Case 3


            else if((temp->left->LTH != "thread") && (temp->left->RTH != "thread"))
            {

               if(temp->left->right->LTH == "thread")
               {

                sucessor = temp->left; // Actually sucessor is temp->left->right but we have to delete it one step backward....
                // So now sucessor will be "sucessor->right"


                cout<<"Successsor from the deletion: ";
                cout<<sucessor->right->info<<endl;
                tempNumber = temp->left->info;
                temp->left->info = sucessor->right->info;
                sucessor->right->info = tempNumber;
                sucessor->right = temp1;
                sucessor->right  = sucessor->right->right;
                delete temp1;
                sucessor->RTH = "thread";
                return;
                }

                else
                {


                sucessor = suc(temp->left->right);
                cout<<"Sucessor : "<<sucessor->left->info<<endl;
                tempNumber = temp->left->info;
                temp->left->info = sucessor->left->info;
                sucessor->left->info = tempNumber;
                temp1 =  sucessor->left;
                sucessor->left = sucessor->left->left;
                sucessor->LTH = "thread";
                return;

                }

            }


        }



        else
        {

            check = 1;

            if(temp->left->LTH == "thread")
            {
                cout<<key<<" nOt found"<<endl;
                return;

            }

            else
            {
                deletion(temp->left,key);

            }


        }

    }


}

















node* TBT :: nextInorder(node* p)
{
  if(p->RTH == "thread")
  return(p->right);
  else {
    p = p->right;
    while(p->LTH == "child")
      p = p->left;
    return p;
  }
}

void TBT :: fastInorder(node* p)
{
	while(  ( p=nextInorder(p) ) != dummy )
		cout << p->info<<endl;
}



node*  TBT ::  suc(node *temp)
{

    // Checking Sucessor one step backward because after deleting it we have make it null....



    if((temp->left->left==NULL) && (temp->left->right==NULL))
    {
        cout<<"Sucessor: "<<temp->info<<endl;
        /*Actually the sucessor is temp->left but we have to Make sure that after deletion
         the node of sucessor should be equal to NULL thats why we are returning one node behind*/
        return temp;
    }

    suc(temp->left);





}




int main()

{
    TBT *t;

    t = new TBT;
    t->insertion(t->root, 50);
    t->insertion(t->root, 100);
    t->insertion(t->root, 80);
   // t->insertion(t->root,130);
   t->fastInorder(t->dummy);
   t->deletion(t->root, 80);

    cout<<endl;

     t->fastInorder(t->dummy);


}



