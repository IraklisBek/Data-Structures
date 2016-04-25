#include "MyAVLTree.h"
#include <iostream>
using namespace std;

MyAVLTree::MyAVLTree() // kataskeuh neou dentrou
{
                      cout<<"Kataskeuh dentrou"<<endl;
                      riza=NULL;
                      //riza->left=NULL;
                      //riza->right=NULL;
                      NumberOfNodes=0;
}
MyAVLTree::~MyAVLTree()//diagrafh dentrou
{
                       delete []riza;
}
int MyAVLTree::HeightBalance(node *v) //upologizei an tha xreiastei kapoia peristrofh to dentro
{
    int LeftHeight; // upsos aristerou upodentoru
    int RightHeight; // upsos deksiou upodentrou
    if(v==NULL)
                    return -1;
    else if(v->right==NULL && v->left==NULL)
                    return 0;
    else
    {
        LeftHeight=HeightBalance(v->left)+1;
        RightHeight=HeightBalance(v->right)+1;        
    }
    if(LeftHeight>RightHeight)
                                return LeftHeight;
    else
                                return RightHeight;
}
void MyAVLTree::RotateLeft(node *riza2) // Peristrofh aristerou upodentrou
{
     node *riza1=riza2->left;
     riza2->left=riza1->right;
     riza1->right=riza2;
     riza2->upsos=(HeightBalance(riza2->left),HeightBalance(riza2->right))+1;
     riza1->upsos=(HeightBalance(riza1->left),riza2->upsos)+1;
     riza2=riza1;
}
void MyAVLTree::RotateRight(node *riza1) // Peristrofh deksiou upodentrou
{
     node *riza2=riza1->right;
     riza1->right=riza2->left;
     riza2->left=riza1;
     riza1->upsos=(HeightBalance(riza1->left),HeightBalance(riza1->right))+1;
     riza2->upsos=(HeightBalance(riza2->right),riza1->upsos)+1;
     riza1=riza2;
}
void MyAVLTree::DoubleRotateLeft(node *riza3) //Diplh peristrofh aristerou upodentrou
{
     RotateRight(riza3->left);
     RotateLeft(riza3);
}
void MyAVLTree::DoubleRotateRight(node *riza1) // Diplh peristrofh deksiou upodentrou
{
     RotateLeft(riza1->right);
     RotateRight(riza1);
}

void MyAVLTree::Insert(int x) // Eisagwgh akeraiou x sto dentro
{
     node *k;//temporary
     if(riza==NULL)
     {
                   riza=new node;
                   riza->timh=x;
                   riza->left=NULL;
                   riza->right=NULL;
                   NumberOfNodes++;
     }
     else
     {
         k=new node;
         k->timh=x;
         if(k->timh < riza->timh)
         {
                        if(riza->left==NULL)
                        {
                                            riza->left=k;
                                            NumberOfNodes++;
                                            
                        }
                        else
                        {
                            Insert(x);
                            if(HeightBalance(k->left)-HeightBalance(k->right)==2) // Elenxos diaforas upsous gia xrhsh peristrofwn 
                            {
                                                                        if(x<k->left->timh)
                                                                                               RotateRight(k);
                                                                        else
                                                                                               DoubleRotateLeft(k);
                            }
                        } 
         }
         else
         {
                        if(riza->right==NULL)
                        {
                                             riza->right=k;
                                             NumberOfNodes++;
                        }
                        else
                        {
                            Insert(x);
                            if(HeightBalance(k->right)-HeightBalance(k->left)==2) //Elenxos diaforas upsous gia xrhsh peristrofwn
                            {
                                                                                       if(x<k->left->timh)
                                                                                                              RotateRight(k);
                                                                                       else
                                                                                                              DoubleRotateLeft(k);
                            }
                        }
         }
     }
}
void MyAVLTree::Delete(int x) // Diagrafh akeraiou stoixeiou x apo to dentro
{
     node *k=riza;
     if(riza==NULL)
     {
                    cout<<"To AVLTree einai adeio"<<endl;
                    NumberOfNodes=0;
     }
     else if(riza->left==NULL && riza->right==NULL)
     {
                         delete k;
                         NumberOfNodes--;
                         cout<<"Epituxhs diagrafh stoixeiou"<<endl;
     }
     else if (riza->left != NULL && riza->right == NULL)
     {
      riza = riza->left;
      delete k;
      NumberOfNodes--;
      cout<<"Epituxhs diagrafh stoixeiou"<<endl;
     }
     else if (riza->left == NULL && riza->right != NULL)
     {
      riza = riza->right;
      delete k;
      NumberOfNodes--;
      cout<<"Epituxhs diagrafh stoixeiou"<<endl;
     }
     else 
     {
             k = riza->left;
             while (k->right != NULL)
             k = k->right;
     }
     riza->timh = k->timh;
     NumberOfNodes--;
}
int MyAVLTree::GetSize() // Megethos Dentrou/ Plh8os komvwn
{
    return NumberOfNodes;
}
MyAVLTree::node* MyAVLTree::Search(int x)//Evresis akeraiou stoixeiou x sto dentro
{
     bool found=false;
     node *nodeptr;
     nodeptr=riza;
     while(!found)
     {
                  if(nodeptr->timh==x)
                  {
                                        found=true;
                                        break;
                  }
                  else
                  {
                      if(nodeptr->timh<x)
                                           nodeptr=nodeptr->right;
                      else
                          if(nodeptr->timh>x)
                                               nodeptr=nodeptr->left;
                  }
     }
}
/*void MyAVLTree::Inorder(int *result) // Inorder diasxish pou apo8hkeuetai ston array result
{
     if(result!=NULL)
     {
                     Inorder(result->left);
                     cout<<result->value<<endl;
                     Inorder(result->right);
     }
}
void MyAVLTree::Preorder(int *result) // Preorder diasxish pou apo8hkeuetai ston array result
{
     if(result!=NULL)
     {
                     cout<<result->value<<endl;
                     Preorder(result->left);
                     Preorder(result->right);
     }
}
void MyAVLTree::Postorder(int *result); // Postorder diasxish pou apo8hkeuetai ston array result
{
     if(result!=NULL)
     {
                     Postorder(result->left);
                     Postorder(result->right);
                     cout<<result->value<<endl;
     }
}*/
