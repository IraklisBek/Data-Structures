#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "MyAVLTree.h"
#include "MyHeap.h"

using namespace std;

void File()// Dhmiourgia INPUT.TXT arxeiou
{
     ofstream f;
     f.open("input.txt",ios_base::out);
     f<<"AVLTREE_CREATE 1."<<endl; 
     f<<"AVLTREE_INSERT 1,8."<<endl;    
     f<<"AVLTREE_SEARCH 1,8."<<endl;
     f<<"AVLTREE_GETSIZE 1."<<endl;
     f<<"AVLTREE_INORDER 1."<<endl;
     f<<"AVLTREE_PREORDER 1."<<endl;
     f<<"AVLTREE_POSTORDER 1."<<endl;
     f<<"AVLTREE_DELETE 1,8."<<endl;
     f<<"AVLTREE_DESTROY 1."<<endl;
     f<<"HEAP_CREATE 1,10,0."<<endl;  
     f<<"HEAP_INSERT 1,8."<<endl; 
     f<<"HEAP_READTOP 1."<<endl;
     f<<"HEAP_GETSIZE 1."<<endl;
     f<<"HEAP_SORT 1."<<endl;
     f<<"HEAP_PRINT 1."<<endl;
     f<<"HEAP_DELETETOP 1."<<endl;
     f<<"HEAP_DESTROY 1."<<endl;
     f.close();
}
int main(int argc, char *argv[])
{
    ifstream fin; // dhlwsh reumatos eisodou
	ofstream fout; // dhlwsei reumatos eksodou
	char MyBuffer[30]; // Estw oti h kathe entolh einai mikroterh apo 30 xarakthres
	MyAVLTree *AVLTree[20];/* Pinakas tupou MyAVLTRee me pointers pou deixnoun se AVL dentra
                         Exei megethos 20 giati mporoume na dhmiourghsoume mexri 20  AVL dentra*/
	MyHeap *Heap[20];/* Pinakas tupou MyHeap me pointers pou deixnoun se swrous
                         Exei megethos 20 giati mporoume na dhmiourghsoume mexri 20 swrous*/
	int *h=new int[10];	
	char cbuffer[30];/* Pinakas ston opoio apo8hkeuoume thn kathe entolh tou INPUT.TXT 
                         mexri to prwto keno pou tha sunathisoyme*/
	char dbuffer[20]; // Pinakas ston opoio apo8hkeuoume tous arithmous tis kathe entolhs me thn morfh alfarithmitikou
	int a,b,j,k,result[20];
	bool c;
	File();
	fin.open("input.txt", ios::in); // anoigma arxeio eisodou
    if(!fin)// elenxos an anoikse to arxeio eisodou
    {
            cerr<<"To arxeio eisodou den anoikse"<<endl;
    }
    else
    {
            cout<<"To arxeio eisodou anoikse epituxws"<<endl;
    }
    fout.open("output.txt", ios::out);//anoigma arxeio eksodou
    if(!fout)//elenxos an anoikse to arxeio eksodou
    {
             cerr<<"To arxeio eksodou den anoikse"<<endl;
    }
    else
    {
             cout<<"To arxeio eksodou anoikse epituxws"<<endl;
    }
	while(fin.getline(MyBuffer,30))/*epanalhpsh mexri na vrei sto arxeio seira me olo kena, 
                                       dhlagh mexri na teleiwsoun oi entoles sto INPUT.TXT*/
	    {
        int i=0;
        while(MyBuffer[i]!=32)
        {
                cbuffer[i]=MyBuffer[i];
                i++;
        }
        cbuffer[i]='\0';        
        cout<<cbuffer<<endl;
        if(strstr(cbuffer,"AVLTREE_CREATE")) // Dhmiourgia AVLTree me kwdiko a
        {
                                  for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                             dbuffer[j]=MyBuffer[k];
                                  dbuffer[j]='\0';
                                  a=atoi(dbuffer);
                                  AVLTree[a]=new MyAVLTree;
                                  fout<<cbuffer<<" "<<"OK"<<endl;
                                  
        }
        else
        if(strstr(cbuffer,"AVLTREE_DESTROY")) // Katasrofh AVLTree mr kwdiko a
        {
                                   for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                             dbuffer[j]=MyBuffer[k];
                                  dbuffer[j]='\0';
                                  a=atoi(dbuffer);
                                  delete AVLTree[a];
                                  fout<<cbuffer<<" "<<"OK"<<endl;
                                   
        }
        else
        if(strstr(cbuffer,"AVLTREE_INSERT")) // Eisagwgn stoixeiou sto AVLTree me kwdiko a
        {
                                   for(k=i+1, j=0; MyBuffer[k]!=','; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            for(k=k+1,j=0;MyBuffer[k]!='.';k++,j++)
                                                         dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            b=atoi(dbuffer);
                                            AVLTree[a]->Insert(b);
                                            fout<<cbuffer<<" "<<"OK"<<endl;
        }
        else
        if(strstr(cbuffer,"AVLTREE_DELETE")) //Diagrafh apo to AVLTree me kwdiko a
        {
                                  for(k=i+1, j=0; MyBuffer[k]!=','; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            for(k=k+1,j=0;MyBuffer[k]!='.';k++,j++)
                                                         dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            b=atoi(dbuffer);
                                            AVLTree[a]->Delete(b);
                                            fout<<cbuffer<<" "<<"OK"<<endl;                         
        }
        else
        if(strstr(cbuffer,"AVLTREE_SEARCH")) // Anazhthsh sto AVLTree mr kwdiko a
        {
                                  for(k=i+1, j=0; MyBuffer[k]!=','; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            for(k=k+1,j=0;MyBuffer[k]!='.';k++,j++)
                                                         dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            b=atoi(dbuffer);
                                            AVLTree[a]->Search(b);
                                            fout<<cbuffer<<" "<<"OK"<<endl;
                                  
        }
        else
        if(strstr(cbuffer,"AVLTREE_GETSIZE")) // Megethos AVLTree me kwdiko a 
        {
                                    for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            int size = AVLTree[a]->GetSize();
                                            if(size=0)
                                                fout<<"To size tis "<<cbuffer<<" "<<a<<" einai "<<size<<" OK"<<endl;
                                            else
                                                fout<<"Error"<<endl;
        }
        else
        if(strstr(cbuffer,"AVLTREE_INORDER")) // Inorder diasxish sto AVLTree me kwdiko a 
        {
                                   for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                             dbuffer[j]=MyBuffer[k];
                                  dbuffer[j]='\0';
                                  a=atoi(dbuffer);
                                  //AVLTree[a]->Inorder();
                                  fout<<cbuffer<<" "<<"OK"<<endl;                                   
        }
        else
        if(strstr(cbuffer,"AVLTREE_PREORDER")) // Preorder diasxish sto AVLTree me kwdiko a
        {
                                    for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                             dbuffer[j]=MyBuffer[k];
                                  dbuffer[j]='\0';
                                  a=atoi(dbuffer);
                                  //AVLTree[a]->Preorder();
                                  fout<<cbuffer<<" "<<"OK"<<endl; 
        }
        else
        if(strstr(cbuffer,"AVLTREE_POSTORDER")) // Postorder diasxish sto AVLTree me kwdiko a
        {
                                     for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                             dbuffer[j]=MyBuffer[k];
                                  dbuffer[j]='\0';
                                  a=atoi(dbuffer);
                                 // AVLTree[a]->Postorder();
                                  fout<<cbuffer<<" "<<"OK"<<endl;
        }
        else 
        if(strstr(cbuffer,"HEAP_CREATE")) // Dhmiourgia swrou me kwdiko a
        {
            for(k=i+1, j=0; MyBuffer[k]!=','; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            for(k=k+1,j=0;MyBuffer[k]!=',';k++,j++)
                                                         dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            b=atoi(dbuffer);
                                            for(k=k+1,j=0;MyBuffer[k]!='.';k++,j++)
                                                          dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            c=atoi(dbuffer);
                                            Heap[a]=new MyHeap(a,b);           
                                            fout<<cbuffer<<" "<<"OK"<<endl;           
        }
        else
        if(strstr(cbuffer,"HEAP_DESTROY")) //Katastrofh swrou me kwdiko a
        {
                                          for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                             dbuffer[j]=MyBuffer[k];
                                          dbuffer[j]='\0';
                                          a=atoi(dbuffer);
                                          delete Heap[a];
                                          fout<<cbuffer<<" "<<"OK"<<endl;
                                    
        }
        else
        if(strstr(cbuffer,"HEAP_INSERT")) // eisagwgn sto swro me kwdiko a
        {
                                   for(k=i+1, j=0; MyBuffer[k]!=','; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            for(k=k+1,j=0;MyBuffer[k]!='.';k++,j++)
                                                         dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            b=atoi(dbuffer);
                                            Heap[a]->Insert(b);
                                            fout<<cbuffer<<" "<<"OK"<<endl;
        }
        else
        if(strstr(cbuffer,"HEAP_DELETETOP")) // Diagrafh koryfhs swrou me kwdiko a
        {
                                      for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            Heap[a]->DeleteTop();
                                            fout<<cbuffer<<" "<<"OK"<<endl;
        }
        else
        if(strstr(cbuffer,"HEAP_READTOP")) // Anagnwsh koryfhs swrou me kwdiko a
        {
                                    
                                    for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                    {
                                              
                                               dbuffer[j]=MyBuffer[k];
                                    }
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);    
                                            int number = Heap[a]->ReadTop();                                       
                                            fout<<cbuffer<<" "<<number<<" OK"<<endl;
                                            
        }
        else
        if(strstr(cbuffer,"HEAP_GETSIZE")) // Megethos swrou me kwdiko a
        {
                                    for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            int size = Heap[a]->GetSize();
                                            if(size!=0)
                                                fout<<"To megethos tis "<<cbuffer<<" "<<a<<" einai "<<size<<endl;
                                            else
                                                fout<<"Error"<<endl;                                
        }
        else
        if(strstr(cbuffer,"HEAP_SORT")) // Taksinomish swrou me kwdiko a
        {
                                 for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            Heap[a]->Sort();
                                            fout<<cbuffer<<" "<<"OK"<<endl;                       
        }
        else
        if(strstr(cbuffer,"HEAP_PRINT")) // Ektupwsh swrou me kwdiko a
        {
                                  for(k=i+1, j=0; MyBuffer[k]!='.'; k++,j++)
                                                        dbuffer[j]=MyBuffer[k];
                                            dbuffer[j]='\0';
                                            a=atoi(dbuffer);
                                            Heap[a]->GetContents(h);
                                            fout<<cbuffer<<" ";
                                            for(int i=0;i<Heap[a]->GetSize();i++)
                                                    fout<<h[i]<<" ";
                                                    fout<<"OK"<<endl;
        }
        }  
    fin.close();// kleisimo reumatos eisodou
	fout.close(); // kleisimo reumatos eksodou  
    system("pause");
    return EXIT_SUCCESS;
}

