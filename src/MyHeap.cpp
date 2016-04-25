#include "MyHeap.h"
#include <iostream>

using namespace std;

MyHeap:: MyHeap(int maxsize, bool HeapType) // Constructor
{
        maxSize=maxsize;
        HeapType=HeapType;
        currentSize=0;
        ArrayHeap = new int[maxSize];
}

MyHeap::~MyHeap() //Destructor
{
                 delete []ArrayHeap;
}

void MyHeap::Insert(int x) // Eisagwgh stoixeiou x
{
     int i = 0;
     i = ++currentSize; 
     if (i>maxSize) // elexnos an o swros einai gematos
     { 
                     cout << "O soros einai gematos" << endl; 
                     return; 
     } 
     if (HeapType==true)// eisagwgh se swro megistwn
     {
                       
                        while ((i>1) && (ArrayHeap[i/2]<x)) 
                        { 
                              ArrayHeap[i] = ArrayHeap[i/2]; 
                              i /= 2; 
                        } 
                        ArrayHeap[i] =x; 
                        return; 
     }
     else//eisagwgh se swro elaxiston
     {
         while ((i>1) && (ArrayHeap[i/2]>x)) 
         { 
                      ArrayHeap[i] = ArrayHeap[i/2]; 
                      i /= 2; 
         } 
         ArrayHeap[i] =x; 
         currentSize++;
         return; 
     }
} 

void MyHeap::DeleteTop()  // Diagrafh korufhs    
{
     if (currentSize==0) // elenxos an o swros einai adeios
     { 
                       cout << "O soros einai adeios"<< endl; 
                       return; 
     } 
     ArrayHeap[0]=ArrayHeap[currentSize];
     currentSize--;
     Sort(); // anadomish swrou
}
 

int MyHeap::ReadTop()//epistrofh ths korufhs
{
    if ( currentSize==0)// elenxos an o swros einai adeios
        return -1;
    else
        return ArrayHeap[0];    
}

int MyHeap::GetSize()// epistrofh plhthous stoixeiwn sto swro
{
    return currentSize;
}

void MyHeap::Sort()//taksinomish swrou
{
     int k,temp;
     for(k=currentSize/2;k>=0;k--)
     {                        
                              if(ArrayHeap[(2*k)+1] < ArrayHeap[(2*k)+2] && (2*k+1)<=currentSize && (2*k+2)<=currentSize)
                              {
                                             temp = ArrayHeap[(2*k)+1];
                                             ArrayHeap[(2*k)+1] = ArrayHeap[(2*k)+2];
                                             ArrayHeap[(2*k)+2] = temp;
                              }
                              if(ArrayHeap[(2*k)+1] > ArrayHeap[k] && (2*k+1)<=currentSize && k<=currentSize)
                              {
                                             temp = ArrayHeap[(2*k)+1];
                                             ArrayHeap[(2*k)+1] = ArrayHeap[k];
                                             ArrayHeap[k] = temp;
                              }
     }
     if ( HeapType==false)// Soros elaxistwn
     {
          for( int i=0; i<currentSize/2; i++)
          {
               int temp=ArrayHeap[i];
               ArrayHeap[i]=ArrayHeap[currentSize-1-i];
               ArrayHeap[currentSize-1-i]=temp;
          }
     }
}

void MyHeap::GetContents(int *h)//antigrafei ta periexomena tou swrou sto array h
{    
     for (int j=0;j<=currentSize;j++)
         h[j]=ArrayHeap[j];
}
