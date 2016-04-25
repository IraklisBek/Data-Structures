class MyHeap
{
      private:
              int *ArrayHeap; // pinakas pou krataei ta stoixeia
              int currentSize, maxSize;// trexon megethos , megisto megethos
              bool HeapType;// tups swrou( megistwn/elaxistwn)
                      
      public:
             MyHeap(int maxSize, bool HeapType); // constructor
             ~MyHeap(); // destructor
             void Insert (int x); // eisagwgh tou steixeiou x
             void DeleteTop (); // diagrafh ths korufhs
             int ReadTop (); // anagnwsh ths korufhs
             int GetSize(); // plhthos stoixeiwn sto swro
             void Sort(); // taksinomish
             void GetContents(int *h); // antigrafei ta periexomena tou swrou sto array h
};
