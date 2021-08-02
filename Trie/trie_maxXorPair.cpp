#include<bits/stdc++.h>
using namespace std;

class Node{//There are only 2 pointers needed in trie for traversing 0 and 1 bit
public:
  Node*left; //for 0
  Node*right;//for 1
};

class trie{
  Node*root;
public:
  trie(){//trie constructor
    root=new Node();
  }
  //Now need a insert function to store all the bits of a number
  //ex: 5 =00000101 [32 bit integer]
  void insert(int n){
    Node*temp=root;
    //we have to store the first bit from left so take that bit use (n>>i)&1
    //n>>i gives ith bit from the right
    for(int i=31;i>=0;i--){//we are inserting from MSB to LSB
      int bit =(n>>i)&1;
      if(bit==0){
        if(temp->left==NULL){//if temp's left is null
          temp->left=new Node();
        }
        temp=temp->left;
      }
      else {//bit is 1
        if(temp->right==NULL){//if temp's left is null
          temp->right=new Node();
        }
        temp=temp->right;
       }
      }
    }
    //helper function to find max XOR
    int max_xor_helper(int val){
      Node*temp=root;
      int current_ans=0;
        for(int j=31;j>=0;j--){
          int bit=(val>>j)&1;
          if(bit==0){
            //find a complementary value
            if(temp->right!=NULL){
              temp=temp->right;
             current_ans+=(1<<j);
             //suppose we have bits 01000 then we are looking for 1 so that it can make it 11000 and that starting 1 is contributing 2 raised to the power j in it
             // and 2 raise to power j is equal to 1<<j
            }
            else{//if 1 is not there,then we have no other option we have to go to 0
              temp=temp->left;//0 is not contributing anything to the answer we are not updating current value here
              // as XOR of 0 and 0 is 0
            }
          }
          else{//if current bit is 1
            if(temp->left!=NULL){//we have to find 0 now so that XOR of 1 and 0 is 1
              temp=temp->left;
              current_ans+=(1<<j);
            }
            else{
              temp=temp->right;
            }
          }
        }
        return current_ans;
    }
    int max_xor(int *input,int n){
      int max_xor=0;
      for(int i=0;i<n;i++){
        int val=input[i];
        insert(val);
        int current_xor=max_xor_helper(val);
        cout<<current_xor<<" ";
        max_xor=max(current_xor,max_xor);
      }
      return max_xor;
    }
};

 int main() {
  int input[]={3,10,5,25,2,8};
  trie t;
  cout<<t.max_xor(input,6)<<endl;
  return 0;
}
