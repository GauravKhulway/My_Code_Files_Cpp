#include<bits/stdc++.h>
using namespace std;
//Prefix tree is known as Trie
//It is also same as Generic Tree or n-ary Tree
//Example: Trie is a better approach for making a phonebook if the data/contacts is going to be large but
//hashmap is a good way if data is limited till 1000 contacts.

class Node{//Node class declaration
public:
  char data;//It contains data
  unordered_map<char,Node*>children;//Address of its children and data of children
  bool terminal;//It tells us about the node is terminal or not that means node has no futher children
  Node(char d){
    data=d;
    terminal=false;//by default it is false
  }
};

class Trie{
  Node* root;//it contain a root
  int cnt;//and it contain a count that is number of children
public:
  Trie(){
    root=new Node('\0');//initialise default with null in it
    cnt=0;//count is also 0 as default
  }

  //Insert function (char array)
  void insert(char *w){
    Node* temp=root;
    for(int i=0;w[i]!='\0';i++){//traverse each children
      char ch=w[i];
      if(temp->children.count(ch)){//check if the given character is found or not and this is given by count fn in hashmap
        temp=temp->children[ch];//if found then temp is going to that children Node
      }
      else{//if node is point at NULL then
        Node* n=new Node(ch);//create a new node
        temp->children[ch]=n;//Now children is pointing to the new child node 'n'
        temp=n;//temp is now on new node so that it is pointing to next node which is NULL in order to exit the condition
      }
    }
    temp->terminal=true;//Now after loop is over temp is at the end at new node
  }

  //insert function (string )


//Find function
bool find(char *w){//passing a char to find
  Node*temp=root;
  for(int i=0;w[i]!='\0';i++){
    char ch=w[i];
    if(temp->children.count(ch)==0){//if not found return false
       return false;
    }
    else{//point to the next children
      temp=temp->children[ch];
    }
  }
  return temp->terminal;//whether it is a terminal node or not
}

};


int main(){
  Trie t;
  char words[][10]={"a","hello","not","news","apple"};
  char w[10];
  cin>>w;
  for(int i=0;i<5;i++){
     t.insert(words[i]);
  }
  if(t.find(w)){
    cout<<"P";
  }
  else cout<<"A";
  return 0;
}
