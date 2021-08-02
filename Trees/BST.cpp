//**********PROPERTIES OF BST*********************************************************************
//Same as Binary Tree with some special properties
//Elements are ordered and each subtree is also a BST
//ex:-          5
//      3                8
//   2    4          7       9
// 1              6    7.5(if here value is 10 then its not a BST)
//In this, If root has some data D then left subtree contain data less than D and right subtree contain data more than D.
#include<bits/stdc++.h>
using namespace std;

class Node{
private:
  int data;
  Node* left;
  Node* right;
public:
  Node(int d){
    data=d;
    left=NULL;
    right=NULL;
  }
  friend class BST;
};

class BST{
private:
  Node* root;
public:
  BST(){
    root=NULL;
  }

//Build tree or insertion in BST according to the data
Node* buildBST(Node*root,int d){
  //Base Case
  if(root==NULL) return new Node(d);
  //Rec case=Insert in subtree and update pointers
  if(d<=root->data){
    root->left=buildBST(root->left,d);
  }
  else root->right=buildBST(root->right,d);
  return root;
}

 void insertionInBST(){
   cout<<"Enter data: ";
   int d;
   cin>>d;
   while(d!=-1){
     root=buildBST(root,d);
     cin>>d;
   }
   cout<<endl;
 }

//InOrder Print of BST
//****NOTE: InOrder Print of BST is always sorted in increasing order**************************************************************
void PrintInOrder(Node*rt) {
  if(rt==NULL) return;
  PrintInOrder(rt->left);
  cout<<rt->data<<" ";
  PrintInOrder(rt->right);
}

void PrintInOrder(){///public function
    cout<<"InOrder:";
    PrintInOrder(root);
    cout<<endl;
}

//BFS-Breadth First Search (LevelOrder)
 void BFS(Node*rt){//modify this so that i can get staircase output (* used for modified reference)
   queue<Node*>q; //declare a queue of Node datatype
   q.push(rt); //push root in queue
   q.push(NULL);
   while(!q.empty()){ //do operations until the queue gets empty
     Node*f=q.front();
     if(f==NULL){ //***This contain condition such that we can print endl
       cout<<endl;
       q.pop();
       if(!q.empty()){
         q.push(NULL);
       }
     }//***
     else{//**
       cout<<f->data<<" ";//print front
       q.pop();  // delete front
       if(f->left) q.push(f->left); //push its children if not NULL
       if(f->right) q.push(f->right);
     }
   }
 }
 void BFS(){
   cout<<"BFS :";
   BFS(root);
   cout<<endl;
 }

//Searching for the element in the BST
Node*searchAdd(Node*rt,int s){//return address of the node find while Searching
  if(rt==NULL || rt->data==s) return rt;
  return (s<rt->data) ?  searchAdd(rt->left,s) : searchAdd(rt->right,s);
}

bool search(Node*rt,int s){
  if(rt==NULL) return false;
  if(rt->data==s) return true;
  if(s<rt->data) search(rt->left,s);
  else search(rt->right,s);
  return false;
}

void search(){
  int s;
  cin>>s;
  bool ans=search(root,s);
  if(ans) cout<<"Present"<<endl;
  else cout<<"Absent"<<endl;
}

//Delete a Node in a BST
Node *deleteNode(Node *rt,  int x)
{
   if(rt==NULL) return NULL;
   else if(x<rt->data){
       rt->left=deleteNode(rt->left,x);
       return rt;
   }
   else if(x==rt->data){
       if(rt->left==NULL && rt->right==NULL){
           delete rt;
           return NULL;
       }
       if(rt->left!=NULL && rt->right==NULL){
           Node*temp=rt->left;
           delete rt;
           return temp;
       }
       if(rt->left==NULL && rt->right!=NULL){
           Node*temp=rt->right;
           delete rt;
           return temp;
       }
       Node*replace=rt->right;
       while(replace->left!=NULL){
           replace= replace->left;
       }
       rt->data=replace->data;
       rt->right=deleteNode(rt->right,replace->data);
       return rt;
   }
   else{
       rt->right=deleteNode(rt->right,x);
       return rt;
   }
}

void deletionInBST(){
  int x;
  cin>>x;
  deleteNode(root,x);
}

//find if the tree is a valid BST or not
bool isBST(Node* rt,long minV,long maxV){
if(rt==NULL) return true;
if(rt->data <=minV || rt->data>=maxV ) return false;
return isBST(rt->left,minV,rt->data) && isBST(rt->right,rt->data,maxV);
}

void isBST(){
 if(isBST(root,LONG_MIN,LONG_MAX)) cout<<"Yes,It is a BST";
 else cout<<"No,It is not a BST";
 cout<<endl;
}

//Convert BST to sorted LinkedList
class LinkedList{
public:
  Node*head;
  Node*tail;
};

LinkedList flattern(Node*rt){
  LinkedList l;
  if(rt==NULL){
    l.head=l.tail=NULL;
    return l;
  }
  //if leaf Node
  if(rt->left==NULL && rt->right==NULL){
    l.head=l.tail=rt;
    return l;
  }
  //if leaf is not NULL
  if(rt->left!=NULL && rt->right==NULL){
    LinkedList leftLL=flattern(rt->left);
    leftLL.tail->right=rt;
    l.head=leftLL.head;
    l.tail=rt;
    return l;
  }
  //Right is not NULL
 if(root->left==NULL && root->right!=NULL){
   LinkedList rightLL=flattern(rt->right);
   rt->right=rightLL.head;
   l.head=rt;
   l.tail=rightLL.tail;
   return l;
 }
 //if both sides are not NULL
 LinkedList leftLL = flattern(rt->left);
 LinkedList rightLL = flattern(rt->right);

 leftLL.tail->right= rt;
 rt->right=rightLL.head;
 l.head=leftLL.head;
 l.tail=rightLL.tail;
 return l;
}

void flattern(){
  LinkedList l=flattern(root);
  Node*temp=l.head;
  cout<<"BST to Sorted LinkedList: ";
  while(temp!=NULL){
    cout<<temp->data<<"  ";
    temp=temp->right;
  }
  cout<<endl;
}

//Build BST from preorder traversal
Node* buildBSTfromPreOrder(int arr[],int &i,int bound,int n){
  if(i==n || arr[i]>bound) return NULL; //return if value of arr[i] greater than bound or i is at the end of arr
  Node* rt=new Node(arr[i++]);//create a new node and after that increment i
  rt->left=buildBSTfromPreOrder(arr,i,rt->data,n);
  rt->right=buildBSTfromPreOrder(arr,i,bound,n);
  return rt;
}

void buildBSTfromPreOrder(){
  int i=0;
  int n;
  cin>>n;
  int arr[n];
  for(int j=0;j<n;j++){
    cin>>arr[j];
  }
  root=buildBSTfromPreOrder(arr,i,INT_MAX,n);
}

};

//INPUT :  5 3 7 1 6 8 -1

int main(){
  BST T;
  // T.insertionInBST();
  // T.BFS();
  // T.PrintInOrder();
  // T.search();
  // T.deletionInBST();
  // T.BFS();
  // T.isBST();
  // T.flattern();
  T.buildBSTfromPreOrder();
  T.BFS();
  T.PrintInOrder();
  return 0;
}
