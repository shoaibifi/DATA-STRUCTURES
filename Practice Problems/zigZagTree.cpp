#include <iostream>
using namespace std;
struct node
{
    int info;
    node *left, *right;
};

class BST
{
    public:

        node *root, ;
        int left, right;

        BST();
        void zigzag(int key, node *temp);


};

BST :: BST()
{

    root = NULL;
    left = right = 0;


}

void BST :: zigzag(int key, node *temp)
{
    if(root==NULL)
    {
        root = new node;
        root->info = key;
        root->left  = NULL;
        root->right = NULL;
        right = 1;
        return;


    }


    else if(right == 1)
    {
        if(temp->left!=NULL)
        {
            zigzag(key,temp->left);
        }

        else
        {
            temp->right  = new node;
            temp->right->info = key;
            temp->right->right = NULL;
            temp->right->left  = NULL;
            right = 0;
            left  = 1;
            return;


        }
    }



        else if(left == 1)
    {
        if(temp->right!=NULL)
        {
            zigzag(key,temp->right);
        }

        else
        {
            temp->left  = new node;
            temp->left->info = key;
            temp->left->right = NULL;
            temp->left->left  = NULL;
            right = 1;
            left  = 0;
            return;


        }



    }




}


int main()
{
        BST *b;
        b = new BST;

        b->zigzag(44, b->root);




}
