//#pragma comment(linker, "/STACK:200000000")
#pragma comment(linker,  "/HEAP:900000000")
#include <iostream>
#include <cstdlib>
#include<fstream>

#include <stdio.h>
#include <stdlib.h>
using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

float _MXD=99999999999999999.0;
float _MND=-99999999999999999.0;

#define min2(a,b) ((a)<(b)?(a):(b))
#define max2(a,b) ((a)>(b)?(a):(b))
int DistanceType; //{0=ed,1=minabs,2=Manahtin; 0 default}
// return the median value in a vector of 27 floats pointed to by a
float heapMedian3_27( float *a )
{
   float left[14], right[14], median, *p;
   unsigned char nLeft, nRight;

   // pick first value as median candidate
   p = a;
   median = *p++;
   nLeft = nRight = 1;

   for(;;)
   {
       // get next value
       float val = *p++;

       // if value is smaller than median, append to left heap
       if( val < median )
       {
           // move biggest value to the heap top
           unsigned char child = nLeft++, parent = (child - 1) / 2;
           while( parent && val > left[parent] )
           {
               left[child] = left[parent];
               child = parent;
               parent = (parent - 1) / 2;
           }
           left[child] = val;

           // if left heap is full
           if( nLeft == 14 )
           {
               // for each remaining value
               for( unsigned char nVal = 27 - (p - a); nVal; --nVal )
               {
                   // get next value
                   val = *p++;

                   // if value is to be inserted in the left heap
                   if( val < median )
                   {
                       child = left[2] > left[1] ? 2 : 1;
                       if( val >= left[child] )
                           median = val;
                       else
                       {
                           median = left[child];
                           parent = child;
                           child = parent*2 + 1;
                           while( child < 14 )
                           {
                               if( child < 13 && left[child+1] > left[child] )
                                   ++child;
                               if( val >= left[child] )
                                   break;
                               left[parent] = left[child];
                               parent = child;
                               child = parent*2 + 1;
                           }
                           left[parent] = val;
                       }
                   }
               }
               return median;
           }
       }

       // else append to right heap
       else
       {
           // move smallest value to the heap top
           unsigned char child = nRight++, parent = (child - 1) / 2;
           while( parent && val < right[parent] )
           {
               right[child] = right[parent];
               child = parent;
               parent = (parent - 1) / 2;
           }
           right[child] = val;

           // if right heap is full
           if( nRight == 14 )
           {
               // for each remaining value
               for( unsigned char nVal = 27 - (p - a); nVal; --nVal )
               {
                   // get next value
                   val = *p++;

                   // if value is to be inserted in the right heap
                   if( val > median )
                   {
                       child = right[2] < right[1] ? 2 : 1;
                       if( val <= right[child] )
                           median = val;
                       else
                       {
                           median = right[child];
                           parent = child;
                           child = parent*2 + 1;
                           while( child < 14 )
                           {
                               if( child < 13 && right[child+1] < right[child] )
                                   ++child;
                               if( val <= right[child] )
                                   break;
                               right[parent] = right[child];
                               parent = child;
                               child = parent*2 + 1;
                           }
                           right[parent] = val;
                       }
                   }
               }
               return median;
           }
       }
   }
}

//===========
//median
float Median1( float *a,int n ){
	ArrayList ^ar=gcnew ArrayList();
	for (int i=0;i<n;i++){
		ar->Add(a[i]);
	}
	ar->Sort();
	float median=safe_cast <double> (ar[n/2]);
	return median;

}

//quartiles
struct twovalues{
	float v1;
	float v2;
};
twovalues quartiles( float *a,int n ){
	ArrayList ^ar=gcnew ArrayList();
	for (int i=0;i<n;i++){
		ar->Add(a[i]);
	}
	ar->Sort();
	twovalues qr;
	
	qr.v1=safe_cast <double> (ar[25*n/100]);
	qr.v2=safe_cast <double> (ar[75*n/100]);
	return qr;
}
int argmin(float *a,int n){
	// calc the minimum distanc of a class	
	float min=a[0];
	int index=0;
	for (int i=1;i<n;i++)
		if (a[i]<min){
			min=a[i];
			index=i;
		}
return index;
}
int argmin(int *a,int n){
	// calc the minimum distanc of a class	
	int min=a[0];
	int index=0;
	for (int i=1;i<n;i++)
		if (a[i]<min){
			min=a[i];
			index=i;
		}
return index;
}
int argmax(float *a,int n){
	// find the index of the maximum value in are array double	
	float max=a[0];
	int index=0;
	for (int i=1;i<n;i++)
		if (a[i]>max){
			max=a[i];
			index=i;
		}
return index;
}
int argmax(int *a,int n){
	// find the index of the max value in array  of int	
	int max=a[0];
	int index=0;
	for (int i=1;i<n;i++)
		if (a[i]>max){
			max=a[i];
			index=i;
		}
return index;
}
//find the number of non-zeros
long Nonzeros(float *a,int n){
	long ctr=0;	
	for (int i=0;i<n;i++)
		if (a[i]!=0.0){
			ctr++;			
		}
return ctr;
}
//
float minofArr(float *a,int n){
	// calc the minimum value of array	
	float min=a[0];
	for (int i=1;i<n;i++)
		if (a[i]<min){
			min=a[i];
		}
return min;
}
//
//
int MaxofArr(int *a,int n){
	// calc the max value of array	
	int max=a[0];
	for (int i=1;i<n;i++)
		if (a[i]>max){
			max=a[i];
		}
return max;
}
float MaxofArr(float *a,int n){
	// calc the max value of array	
	float max=a[0];
	for (int i=1;i<n;i++)
		if (a[i]>max){
			max=a[i];
		}
return max;
}
//

int compare (const void * a, const void * b)
{

  twovalues *orderA = (twovalues *)a;
  twovalues *orderB = (twovalues *)b;

  return (orderB->v1 < orderA->v1) - (orderB->v1 >  orderA->v1);
  //return ( orderB->v1 - orderA->v1 );
}
void qs(twovalues list[],int n){
	qsort( list, n, sizeof(twovalues), compare);
}

//BS


twovalues BinarySearch2values(twovalues A[], int N, float value ) {
      int low = 0;
      int high = N - 1;
	  int mid;
	  twovalues range;
	  range.v1=low;range.v2=high;
	  bool found=false;
	  while(low <= high && !found) {
          mid = (low + high)/ 2.0;
		  if (A[mid].v1 == value){
			  found=true;
		  }
		  else if (A[mid].v1 > value)
              high = mid - 1;
          else
              low = mid + 1;
      }
	  if (found){
		  int i=mid-1;
		  while (i>-1 && A[i].v1 == value)
			  i--;
			range.v1=i+1;
		  i=mid+1;
		  while (i<N && A[i].v1 == value)
			  i++;
		range.v2=i-1;
		return range;	  
	  }
		//else not eaxact match 

      low = 0;
      high = N - 1;
	  float diff;
	  int oldmid=(low + high)/ 2.0;
	  diff=Math::Abs(A[oldmid].v1 - value);
	  while(low <= high ) {
          mid = (low + high)/ 2.0;
		 // diff=Math::Abs(A[mid].v1 - value);
		  if (Math::Abs(A[mid].v1 - value)<=diff){
			  diff=Math::Abs(A[mid].v1 - value);				
			  oldmid=mid;
		  }
          if (A[mid].v1 > value)
              high = mid - 1;
          else
              low = mid + 1;
	  }
//sequential search for oldmid
		int i=oldmid-1;
		while (i>-1 && Math::Abs(A[i].v1 - value) <= diff)
			  i--;
		range.v1=i+1;
		 i=oldmid+1;
		 while (i<N && Math::Abs(A[i].v1 - value) <= diff)
			  i++;
		range.v2=i-1;
		return range;	  
}


void fib(int f[],int n){
	f[0]=f[1]=1;
	for (int i=2;i<n;i++)
			f[i]=f[i-1]+f[i-2];
}
//return true if all points are true otherwise false
bool VisitedAll(bool f[],int n){
	for (int i=0;i<n;i++)
			if (!f[i])
				return false;
	return true;
}


/*
1.  h = 0 
2.  for every point ai of A,
      2.1  shortest = Inf ;
      2.2  for every point bj of B
                    dij = d (ai , bj )
                    if dij < shortest then
                              shortest = dij
      2.3  if shortest > h then 
                    h = shortest 
*/
// Hausdorff distance
float Hausdorff(float *a, float *b, int n){
	float h=0;
	for (int i=0;i<n;i++){
		float shortest = _MXD ;
		for (int j=0;j<n;j++){
			float dij=Math::Abs(a[i]-b[j]);
			if (dij<shortest)
				shortest = dij;
		}
		if (shortest > h)
			h = shortest;
	}
return h;

}
///////////////////////////////////////////////////////////////////////////////////////


struct BTreeNode{
	long size;
	long *ExamplesIndx;//this should be long ahmad this is used to get the actual example from the training set
	float MinNorm;//if Tree used, and index of point1 if Tree2RndPnts used
	float MaxNorm;//if Tree used, and index of point2 if Tree2RndPnts used
	long level;
	BTreeNode *left;
	BTreeNode *right;
	
	struct BTreeNode& operator+=(const BTreeNode& rhs) { 
		long newsize=size+rhs.size;
		long *NewExamplesIndx=new long[newsize];
		long i;
		for (i=0;i<size;i++)
			NewExamplesIndx[i]=ExamplesIndx[i];
		for (long j=0;j<rhs.size ;j++)
			NewExamplesIndx[i++]=rhs.ExamplesIndx [j];
		delete []ExamplesIndx;
		ExamplesIndx=NewExamplesIndx;
		return *this; 
	}
};
void Add2BTNode(BTreeNode *lhs, BTreeNode *rhs){
		long newsize=lhs->size+rhs->size;
		long *NewExamplesIndx=new long[newsize];
		long i;
		for (i=0;i<lhs->size;i++)
			NewExamplesIndx[i]=lhs->ExamplesIndx[i];
		for (long j=0;j<rhs->size ;j++)
			NewExamplesIndx[i++]=rhs->ExamplesIndx [j];
		delete []lhs->ExamplesIndx;
		lhs->ExamplesIndx=NewExamplesIndx;
		lhs->size=lhs->size+rhs->size;

}
struct DTreeNode{
	long size;
	long *ExamplesIndx;//this should be long ahmad this is used to get the actual example from the training set
	float MinNorm;//if Tree used, and index of point1 if Tree2RndPnts used
	float MaxNorm;//if Tree used, and index of point2 if Tree2RndPnts used
	long level;
	float *Classint; //this float array stores the accumilated probabities of each class, to show the decision at the leaf node, which is the class with the most accumilated probability
	DTreeNode *left;
	DTreeNode *right;
};
struct Qnode{
	BTreeNode *btrnode;
	Qnode *next;
};


class queue{
public:
	queue(){	head=tail=NULL; }
	~queue(){
		while (head != NULL){
			Qnode * temp=head;
			head=head->next;
			delete [] temp->btrnode->ExamplesIndx;
			delete temp; temp=NULL;
		}
	}
	void push(BTreeNode *btrnode){
		Qnode * newnode=new Qnode;
		newnode->btrnode=btrnode;
		newnode->next=NULL;
		if (head==tail){
			if (head==NULL){
				head=tail=newnode;
			}
			else {
				head->next=newnode;
				tail=newnode;
			}
		}
		else {
			tail->next=newnode;;
			tail=newnode;
		}	
	}
	BTreeNode *pop(){
		if (head!=NULL){
		Qnode * headnode=head;
		BTreeNode *btreenode=headnode->btrnode;
		head=head->next;
		if (head == NULL)
			tail = NULL;
		return btreenode;
		}
		else
			return NULL;
	}
	bool empty(){if (head==NULL) return true; else return false;}
private:
	//long size;
	Qnode * head;
	Qnode * tail;
};

queue *Q;//temp queue to be used by the binary tree 
struct DTQnode{
	DTreeNode *btrnode;
	DTQnode *next;
};

class DTqueue{
public:
	DTqueue(){	head=tail=NULL; }
	~DTqueue(){
		while (head != NULL){
			DTQnode * temp=head;
			head=head->next;
			delete [] temp->btrnode->ExamplesIndx;
			delete [] temp->btrnode->Classint;

			delete temp; temp=NULL;
		}
	}
	void push(DTreeNode *btrnode){
		DTQnode * newnode=new DTQnode;
		newnode->btrnode=btrnode;
		newnode->next=NULL;
		if (head==tail){
			if (head==NULL){
				head=tail=newnode;
			}
			else {
				head->next=newnode;
				tail=newnode;
			}
		}
		else {
			tail->next=newnode;;
			tail=newnode;
		}	
	}
	DTreeNode *pop(){
		if (head!=NULL){
		DTQnode * headnode=head;
		DTreeNode *btreenode=headnode->btrnode;
		head=head->next;
		if (head == NULL)
			tail = NULL;
		return btreenode;
		}
		else
			return NULL;
	}
	bool empty(){if (head==NULL) return true; else return false;}
private:
	//long size;
	DTQnode * head;
	DTQnode * tail;
};
DTqueue *DTQ;//temp queue to be used by the decision tree 

//===queue for long numbers
struct QnodeLong{
	long ip;
	QnodeLong *next;
};
class queueLong{
public:
	queueLong(){	head=tail=NULL; this->Size=0;}
	~queueLong(){
		while (head != NULL){
			QnodeLong * temp=head;
			head=head->next;
			delete temp; temp=NULL;
		}
	}
	void push(long ip1){
		QnodeLong * newnode=new QnodeLong;
		newnode->ip =ip1;
//		newnode->ip2 =ip2;
		newnode->next=NULL;
		this->Size++;
		if (head==tail){
			if (head==NULL){
				head=tail=newnode;
			}
			else {
				head->next=newnode;
				tail=newnode;
			}
		}
		else {
			tail->next=newnode;;
			tail=newnode;
		}	
	}
long pop(){
		if (head!=NULL){
		QnodeLong * headnode=head;
		head=head->next;
		if (head == NULL)
			tail = NULL;
		long v=headnode->ip;
		delete headnode;
		this->Size--;
		return v;
		}
		else
			return 0;
	}
	bool empty(){if (head==NULL) return true; else return false;}
private:
	//long size;
	QnodeLong * head;
	QnodeLong * tail;
	long Size;
};

queueLong *QL;//temp queue of long numbers 

//////////////////////////////////////////////////////////////// liked list //////////////////
//linked list as alternative to array lidt in vs

struct LinkedNode
{
    long data;
    LinkedNode* next;
};


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    LinkedNode* head;
    long Count;
	long * Data;
    void add(long data);
	void update();
	//long get(long index);
};

LinkedList::LinkedList(){
    this->Count = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    LinkedNode * temp; 
    while(head){
		temp= this->head ;
        head = head->next;
        delete temp;
    }
	if (this->Count > 0 && Data) {
		delete[] Data;
		Data = NULL;
	}
}

void LinkedList::add  (long data){
    LinkedNode * node = new LinkedNode();
	node->data = data;
	node->next = this->head;
    this->head = node;
    this->Count++;}

void LinkedList::update(){
	if (this->Count > 0) {
		this->Data = new long[this->Count];
		long i = 0;
		LinkedNode * node = this->head;
		while (node) {
			this->Data[i] = node->data;
			node = node->next;
			i++;
		}
	}
}
////////////////////////////////////////////////////////////////end linked list //////////////