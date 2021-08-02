//Heap is also called priority queue
//******************* Heap(priority queue)*****************************************************************
//Element with highest priority comes out of the queue
//It is like a queue but having some priority
//Why to use this?
//Finding Max/Min of the N elements
//Types of function and their complexities:
// 1. Insert/push- logN
// 2. pop- logN
// 3. get- O(1)
//what is a heap?
//1. Binary Tree
//2.Complete BT properties (CBTP) means all levels are completely filled except the last level but the filling must be left to right order
//3.Heap order priority (max.min)
//max heap:- every parent > children so that max element is always at the top
//min heap:- every parent < children so that min element is always at the top
//Binary Tree in form of array then(we will visualise as BT but execute in form an array for heap implementation)
//if parent index is i then children are 2i and 2i+1
//if children are i and i+1 then parent is i/2

#include<bits/stdc++.h>
using namespace std;

class Heap{//Heap class implementation
   vector<int> v;
   bool minHeap;
   bool compare(int a,int b){
     if(minHeap){
        return a < b;
     }
     else return a > b;
   }
   void heapify(int idx){
     int left=2*idx;
     int right=left+1;
     int min_idx=idx;
     int last=v.size()-1;
     if(left<=last && compare(v[left],v[idx])){//left and right child index must be exist in vector to replace
        min_idx=left;
     }
     if(right<=last && compare(v[right],v[min_idx])){//compare with left and right child whichever is lowest
       min_idx=right;
     }
     if(min_idx!=idx){
       swap(v[min_idx],v[idx]);//swap these values
       heapify(min_idx); //make a recursive call to adjust the tree
     }
   }

public:
  Heap(int default_size = 10,bool type=true){
    v.reserve(default_size);
    v.push_back(-1); //occupy garbage value at index 0
    minHeap = type;
  }

  void push(int d){
    v.push_back(d);
    int idx=v.size()-1;
    int parent=idx/2;
   //keep pushing to the top till you reach a root node or stop midway because current element is already greater than parent
    while(idx>1 && compare(v[idx],v[parent]) ){
      swap(v[idx],v[parent]);
      idx = parent;
      parent = parent/2;
    }
  }

 int top(){//it will return the top most element of the Heap
   return v[1];
 }

 void pop(){
   int last=v.size()-1;//last element in Heap
   swap(v[1],v[last]);
   v.pop_back();//pop the smallest or the largest element in the vector that is always at the top of a Heap
   heapify(1);//it is a function which will place that last element comes at the top to its real position now in updated vector so it require a idx i.e, 1
 }
 bool empty(){
   return v.size()==1;
 }
};

//*************************************************************************************************************************************/
bool minHeap;
bool compare(int a,int b){
  if(minHeap){
     return a < b;
  }
  else return a > b;
}

void heapify(vector<int>&v,int idx){
  int left=2*idx;
  int right=left+1;
  int min_idx=idx;
  int last=v.size()-1;
  if(left<=last && compare(v[left],v[idx])){//left and right child index must be exist in vector to replace
     min_idx=left;
  }
  if(right<=last && compare(v[right],v[min_idx])){//compare with left and right child whichever is lowest
    min_idx=right;
  }
  if(min_idx!=idx){
    swap(v[min_idx],v[idx]);//swap these values
    heapify(v,min_idx); //make a recursive call to adjust the tree
  }
}

void buildHeapOptimised(vector<int>&v){//logN complexity
   for(int i=(v.size()-1)/2;i>0;i--){
     heapify(v,i);
   }
}

void print(vector<int>&v){
  for(auto x:v) cout<<x<<" ";
  cout<<endl;
}

void heapify(vector<int>&v,int idx,int size){//for heap sort (* is the change ) as passing size so it will sort only a small part
  int left=2*idx;
  int right=left+1;
  int min_idx=idx;
  int last=size-1;//***********v.size() is now size that is passing by the other fn***************
  if(left<=last && compare(v[left],v[idx])){//left and right child index must be exist in vector to replace
     min_idx=left;
  }
  if(right<=last && compare(v[right],v[min_idx])){//compare with left and right child whichever is lowest
    min_idx=right;
  }
  if(min_idx!=idx){
    swap(v[min_idx],v[idx]);//swap these values
    heapify(v,min_idx); //make a recursive call to adjust the tree
  }
}

void heapSort(vector<int>&v){
  buildHeapOptimised(v);
  int n=v.size();
  //remove n-1th element from the heap
  while(n>1){
    swap(v[1],v[n-1]);
    n--;
    heapify(v,1,n);
  }
}

int main(){
   // Heap h;//it work as min heap as passing by default true;
   // Heap h(10,false);//it work as maxheap
   // int n;
   // cin>>n;
   // for(int i=0;i<n;i++){
   //   int no;
   //   cin>>no;
   //   h.push(no);
   // }
   // while(!h.empty()){
   //   cout<<h.top()<<" ";
   //   h.pop();
   // }

  // vector<int> v={-1,10,20,5,6,1,8,9,4};//we have to ignore the 0th index so filled it with -1
  // print(v);
  // // buildHeapOptimised(v);
  // heapSort(v);
  // print(v);
  // return 0;


  ///***************STL*************
  // priority_queue<int> pq;//by default it work as a max heap
//For using a min heap we should pass comparater function and vector int
    priority_queue<int,vector<int>,greater<int> > pq;//Now it work as a min heap
   //pq.push(3);//push operation takes O(logN)
   //pq.pop(3);//pop operation takes O(logN)
   //pq.top();//top operation takes O(1)
}
