class MyAVLTree
{
      private:
              struct node
              {
                     int timh; // timh komvou 
                     int upsos; //
                     struct node *left; // aristero upodentro
                     struct node *right; // deksi upodentro
            
              };
              int NumberOfNodes;// arithmos komvwn
              node *riza; // riza dentrou
      public:
             MyAVLTree(); // constructor
             ~ MyAVLTree(); // destructor
             void Insert (int x); // eisagwgh tou stoixeiou x sto dentro
             void Delete (int x); // diagrafh tou x
             node *Search (int x); // anazhthsh an uparxei to x h oxi
             int HeightBalance(node *v); // upologizei an tha xreiastei kapoia peristrofh to dentro
             void RotateLeft(node *r2); // peistrofh aristerou upodentrou
             void RotateRight(node *r1); // peristrofh deksiou upodentrou
             void DoubleRotateLeft(node *r3); //diplh peristrofh aristerou upodentrou
             void DoubleRotateRight(node *r1); // diplh peristrofh deksiou upodentrou
             int GetSize(); // plhthos stoixeiwn dentrou
             void Inorder (int *result); // h inorder diasxish apo8hkeuetai ston array result
             void Preorder (int *result); // h preorder diasxish apo8hkeuetai ston array result
             void Postorder (int *result); // h postorder diasxish apo8hkeuetai ston array result
      
};
