#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    char data;
    bool terminal;
    int cnt;
    unordered_map<char,Node*>children;

    Node(char data){

        this->data=data;
        this->terminal=false;
        this->cnt=0;
    }

};

class tries{

public :
    Node *root;
    ///int count;

    tries(){

        this->root=new Node('\0');
       /// this->count=0;
    }
    void addword(string str){

        Node *temp=root;
        int s=str.size();
        for(int i=0;i<s;i++){

            char ch=str[i];
            if(temp->children[ch] != NULL){
                temp=temp->children[ch];
                temp->cnt = temp->cnt + 1;
            }
            else{
                Node *newNode=new Node(ch);
                temp->children[ch]=newNode;
                temp=newNode;
                temp->cnt=temp->cnt+1;
            }
        }
        temp->terminal=true;
    }

};

//prefix fn gives the unique prefix of

string prefix(string x, tries* t) {
    int i = 0;
    Node* root = t->root;
    int length = x.length();
    string ans = "";
    while(i != length) {
        if((root->children[x[i]])->cnt == 1) {
            ans = ans + x[i];
            return ans;
        } else {
            ans = ans + x[i];
            root = root->children[x[i]];
        }
        i++;
    }

    ans = "-1";
    return ans;
}

int main(){

tries *t=new tries();

string arr[]={"zebra","dog","dove","duck","zebras"};
for(int i=0;i<5;i++){
    t->addword(arr[i]);
}
//cout<<t->root->cnt<<endl;
//char prefix[26];
//uniqueprefixhelper(t->root,prefix,0);
for(int i  = 0; i < 5; i++) {
    cout << prefix(arr[i], t) << endl;
}
return 0;
}
