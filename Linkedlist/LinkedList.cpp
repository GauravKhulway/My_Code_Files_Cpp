#include<bits/stdc++.h>
using namespace std;

class Node{
private:
  int data;
  Node* next;
public:
  Node(int d){
    data=d;
    next = NULL;
  }
  friend class Linkedlist;
};

class Linkedlist{
private:
  Node*head;
public:
  Linkedlist(){
    head=NULL;
  }

  //Insertion in Linkedlist

  void insertAtHead(int d){
    Node*nn=new Node(d);
    nn->next=head;
    head=nn;
  }

  void insertAtEnd(int d){
    Node*temp=head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    Node*nn=new Node(d);
    temp->next=nn;
  }

  void insertAtK(int d,int k){
    Node*temp=head;
    while(k>1){
      temp=temp->next;
      k--;
    }
    Node*nn=new Node(d);
    nn->next=temp->next;
    temp->next=nn;
  }

  //Deletion in Linkedlist

  void deleteAtHead(){
    Node*temp=head;
    head=head->next;
    delete temp;
  }

  void deleteAtEnd(){
    Node* temp=head;
         while (temp->next->next!=NULL){
             temp=temp->next;
         }
         delete temp->next;
         temp->next=NULL;
  }

  void deleteAtK(int k){
    Node*temp=head;
    if(k==0) deleteAtHead();
    while(temp->next->next!=NULL && k>1){
       temp=temp->next;
       k--;
    }
    Node *t=temp->next;
        temp->next=temp->next->next; /// temp->next=t->next;
        delete t;
  }

  //searching a node in Linkedlist
  void searchingAtK(int k){//searching at position or index
   Node*temp=head;
   if(k==0) cout<<temp->data<<endl;
   while(temp->next!=NULL && k>0){
     temp=temp->next;
     k--;
   }
   cout<<temp->data<<endl;
  }

  void searchingForData(int val){//searching for data or value
   Node*temp=head;
   int idx=0;
   while(temp->data!=val && temp->next!=NULL){
     temp=temp->next;
     idx++;
   }
   if(temp->data==val) cout<<idx<<endl;
   else cout<<"-1"<<endl;
  }

  //Reverse a Linkedlist

  void reverse(){
    Node*cur=head;
    Node*nxt=NULL;
    Node*pre=NULL;
    while(cur!=NULL){
      nxt=cur->next;
      cur->next=pre;
      pre=cur;
      cur=nxt;
    }
    head=pre;
  }

  //Print the Linkedlist
  void print(){
    while (head!=NULL) {
      cout<<head->data<<" ";
      head=head->next;
    }
    cout<<"\n";
  }
};


int main() {
  Linkedlist LL;
  LL.insertAtHead(3);
  LL.insertAtHead(2);
  LL.insertAtHead(1);
  LL.insertAtHead(0);
  LL.insertAtEnd(4);
  LL.insertAtEnd(5);
  LL.insertAtK(-1,3);
  LL.deleteAtHead();
  LL.deleteAtEnd();
  LL.deleteAtK(2);
  // LL.searchingAtK(1);
  // LL.searchingForData(7);
  LL.reverse();
  LL.print();
  return 0;
}
