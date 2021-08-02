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
  friend class binaryTree;
};

class binaryTree{
private:
  Node* root;
public:
  binaryTree(){
    root=NULL;
  }
// INPUT:- 3 4 -1 6 -1 -1 5 1 -1 -1 -1
//>>Other INPUT:- 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
  //create a  binary tree (Recursively)
  Node* buildTreeRec(){///private function
        int d;
        cin>>d;
        if (d==-1) return NULL;
        Node*n=new Node(d);
        n->left=buildTreeRec();
        n->right=buildTreeRec();
        return n;
    }

    void buildTree(){///public function
       cout<<"Enter Input:"<<" ";
        root=buildTreeRec();
    }

//Print function to print all elements of a binary tree in a given order

void PrintPreOrder(Node* rt){ //ROOT LEFT RIGHT
  if (rt==NULL) return;
  cout<<rt->data<<" ";
  PrintPreOrder(rt->left);
  PrintPreOrder(rt->right);
 }

 void PrintPreOrder(){///public function
     cout<<"PreOrder:";
     PrintPreOrder(root);
     cout<<endl;
 }

void PrintInOrder(Node*rt){ // LEFT ROOT RIGHT
  if (rt==NULL) return;
  PrintInOrder(rt->left);
  cout<<rt->data<<" ";
  PrintInOrder(rt->right);
}

void PrintInOrder(){///public function
    cout<<"InOrder:";
    PrintInOrder(root);
    cout<<endl;
}

void PrintPostOrder(Node*rt){ //  ROOT  LEFT RIGHT -KNOWN AS BOTTOM UP TRAVERSAL*****************************
  if (rt==NULL) return;
  PrintPostOrder(rt->left);
  PrintPostOrder(rt->right);
  cout<<rt->data<<" ";
}

void PrintPostOrder(){///public function
    cout<<"PostOrder:";
    PrintPostOrder(root);
    cout<<endl;
}

void LevelOrder(Node*rt){ // Print all the nodes at same level
  int h=Height(); //iterative solution is much easier and faster
  for(int i=1;i<=h;i++){ //Complexity of O(n2)
     PrintKthLevel(rt,i);
     cout<<endl;
  }
}

void LevelOrder(){///public function
    cout<<"LevelOrder:";
    LevelOrder(root);
    cout<<endl;
}

//For LevelOrder we need to compute height first
int Height(Node* rt){
 if(rt==NULL) return 0;
 int hl=Height(rt->left);
 int hr=Height(rt->right);
 return max(hl,hr)+1;
}

int Height(){
  int h=Height(root);
  return h;
}

//Print Kth level of a binary buildTree
void PrintKthLevel(Node* rt,int k){
  if(rt==NULL) return;
  if(k==1) cout<<rt->data<<" ";
  PrintKthLevel(rt->left,k-1);
  PrintKthLevel(rt->right,k-1);
}

void PrintKthLevel(){
   int k;
   cin>>k;
    PrintKthLevel(root,k);
    cout<<endl;
}

//Best Approach to print or traverse all the nodes in level order is BFS-Breadth first search
//Important Topic
//Tips to remember= Complexity(O(n)) , Using Queue of Node datatype
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

//Some More Problems Based on trees
int countNoOfNodes(Node*rt){
  if(rt==NULL) return 0;
  int c1=countNoOfNodes(rt->left);
  int c2=countNoOfNodes(rt->right);
  return 1+c1+c2;
}

void countNoOfNodes(){
  cout<<"No of Nodes in the tree: "<<countNoOfNodes(root)<<endl;
}

int sumOfNodes(Node*rt){
if(rt==NULL) return 0;
int s1=sumOfNodes(rt->left);
int s2=sumOfNodes(rt->right);
return rt->data+s1+s2;
}

void sumOfNodes(){
cout<<"Sum of Nodes in the tree: "<<sumOfNodes(root)<<endl;
}

int Diameter(Node*rt){ // Print length of Diameter i.e. longest edges of trees are connected
  if(rt==NULL) return 0;
  int h1=Height(rt->left);
  int h2=Height(rt->right);
  int o1=h1+h2; //Case 1:if passes through root
  int o2=Diameter(rt->left); // case 2:if passes only in the left sub tree
  int o3=Diameter(rt->right);// case 3:if passes only in the right sub tree
  return max(o1,max(o2,o3)); //return max of three of the cases
}

void Diameter(){ //In worst case its complexity = O(N2) thats why we have to make it optimised
  int ans=Diameter(root);
  cout<<"Diameter of Tree: "<<ans<<endl;
}

class Pair{ //to understand it better we are using pair clas else we can use STL pair too
public:
    int height;
  int diameter;
};

Pair DiameterOp(Node*rt){//a pair is used to store diameter and height simulataneously- Can use class of pair too
Pair p; //p,first denotes p.height and p.second denotes diameter
  if(rt==NULL){
    p.height=0;
    p.diameter=0;
     return p;
  }
  Pair left=DiameterOp(rt->left);
  Pair right=DiameterOp(rt->right);
  p.height=max(left.height,right.height)+1;
  p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
  return p;
}

void DiameterOp(){ //optimised solution and its complexity = O(N)
  int ph=DiameterOp(root).height;
  int pd=DiameterOp(root).diameter;
  cout<<"Diameter of Tree: "<<pd<<endl;
  cout<<"Height of Tree: "<<ph<<endl;
}

//Easy Recursive Approach for diameter complexity O(n)**********
int DiameterRec(Node*rt,int &d){//&d is used to update the val(Call by value)
if(rt==NULL) return 0;
int lh=DiameterRec(rt->left,d); //left diameter
int rh=DiameterRec(rt->right,d);//right diameter
d=max(d,lh+rh); //max of previous diameter with the new computed diameter
return max(lh,rh)+1; // return max height of tree at each instant
}

void DiameterRec(){
  int d=0;//diameter = max height of left subtree and right subtree
  int h=DiameterRec(root,d);
  cout<<"Diameter of Tree: "<<d<<" "<<endl;
  cout<<"Height of Tree: "<<h<<endl;
}

//Replace root data with sum of its child except the root nodes
int replaceTree(Node*&rt){
  if(rt==NULL) return 0;
  if(rt->left==NULL && rt->right==NULL) {
    return rt->data;
  }
  int leftSum=replaceTree(rt->left);
  int rightSum=replaceTree(rt->right);
  int temp=rt->data;
  rt->data=leftSum+rightSum;
  return temp+rt->data;
}

void replaceTree(){
  replaceTree(root);
  BFS();
}

//sum of left nodes in a tree
int leftNodesSum(Node*rt){
  if(rt==NULL) return 0;
  if(rt->left && !rt->left->left && !rt->left->right) return rt->left->data + leftNodesSum(rt->right);
  return leftNodesSum(rt->left)+leftNodesSum(rt->right);
}

void leftNodesSum(){
  cout<<"Sum of left nodes in a tree: "<<leftNodesSum(root)<<endl;
}

//Height Balanced tree
bool isHeightBalancedTree(Node*rt){
 if(rt==NULL) return true;
 return isHeightBalancedTree(rt->left) && isHeightBalancedTree(rt->right) && abs(Height(rt->left)-Height(rt->right))<=1;
}

void isHeightBalancedTree(){
  bool isBal=isHeightBalancedTree(root);
  cout<<"Is Height Balanced Tree: "<<isBal<<endl;
}

//Mirror of a tree
void Mirror(Node*rt){
  if(rt==NULL) return;
  Mirror(rt->left);
  Mirror(rt->right);
  swap(rt->left,rt->right);
}
void Mirror(){
  Mirror(root);
}

//Build Tree From Array
Node* buildTreeFromArray(int*arr,int s,int e){
  if(s>e) return NULL;
  int mid=(s+e)/2;
  Node* root=new Node(arr[mid]);
  root->left=buildTreeFromArray(arr,s,mid-1);
  root->right=buildTreeFromArray(arr,mid+1,e);
  return root;
}

void buildTreeFromArray(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  root=buildTreeFromArray(arr,0,n-1);
}

//Build a unique tree with preorder and inorder traversal

Node * buildTreeFromTrav(int*in,int*pre,int s,int e){
  static int i=0;
  if(s>e) return NULL;
  Node* root=new Node(pre[i]);
  int idx=-1;
  for(int j=s;j<=e;j++){
    if(pre[i]==in[j]){
      idx=j;
      break;
    }
  }
  i++;
  root->left=buildTreeFromTrav(in,pre,s,idx-1);
  root->right=buildTreeFromTrav(in,pre,idx+1,e);
  return root;
}

void buildTreeFromTrav(){
  int in[]={3,2,8,4,1,6,7,5};
  int pre[]={1,2,3,4,8,5,6,7};
  int n=sizeof(in)/sizeof(int);
  root=buildTreeFromTrav(in,pre,0,n-1);
}

void rightSideView(Node*rt,int lvl,int &mxlvl){
  if(rt==NULL) return;
  if(mxlvl<lvl){
    mxlvl=lvl;
    cout<<rt->data<<" ";
  }
  rightSideView(rt->right,lvl+1,mxlvl);
  rightSideView(rt->left,lvl+1,mxlvl);
}

void rightSideView(){
  int mxlvl=-1;
  cout<<"Right Side View of Binary Tree: ";
  rightSideView(root,0,mxlvl);
  cout<<endl;
}

void printkdistanceNodeDown(Node *rt, int k)
{
    // Base Case
    if (rt == NULL)  return;

    // If we reach a k distant node, print it
    if (k==0)
    {
        cout << rt->data << endl;
        return;
    }

    // Recur for left and right subtrees
    printkdistanceNodeDown(rt->left, k-1);
    printkdistanceNodeDown(rt->right, k-1);
}

// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int printkdistanceNode(Node* rt, Node* target , int &k)
{
    // Base Case 1: If tree is empty, return -1
    if (rt == NULL) return -1;

    // If target is same as root.  Use the downward function
    // to print all nodes at distance k in subtree rooted with
    // target or root
    if (rt == target)
    {
        printkdistanceNodeDown(rt, k);
        return 0;
    }

    // Recur for left subtree
    int dl = printkdistanceNode(rt->left, target, k);

    // Check if target node was found in left subtree
    if (dl != -1)
    {
         // If root is at distance k from target, print root
         // Note that dl is Distance of root's left child from target
         if (dl + 1 == k)
            cout << rt->data << endl;

         // Else go to right subtree and print all k-dl-2 distant nodes
         // Note that the right child is 2 edges away from left child
         else
            printkdistanceNodeDown(rt->right, k-dl-2);

         // Add 1 to the distance and return value for parent calls
         return 1 + dl;
    }

    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int dr = printkdistanceNode(rt->right, target, k);
    if (dr != -1)
    {
         if (dr + 1 == k)
            cout << rt->data << endl;
         else
            printkdistanceNodeDown(rt->left, k-dr-2);
         return 1 + dr;
    }

    // If target was neither present in left nor in right subtree
    return -1;
}

void printkdistanceNode(){
  cout<<"Print all the nodes at distance K from Target Node: ";
  Node*target=root->left->left;
  int k=2;
  printkdistanceNode(root,target,k);
  cout<<endl;
}

Node* lca(Node*rt,int a,int b){
  if(rt==NULL) return NULL;
  if(rt->data==a || rt->data==b) return rt;
  Node*leftans=lca(rt->left,a,b);
  Node*rightans=lca(rt->right,a,b);
  if(leftans!=NULL && rightans!=NULL) return rt;
  if(leftans!=NULL) return leftans;
  else return rightans;
}

void lca(){//Lowest Common Ancestor
  int a,b;
  cin>>a>>b;
  Node* temp=lca(root,a,b);
  cout<<"Lowest Common Ancestor : "<<temp->data<<endl;
}

int maxPathSum(Node*rt,int &ans){
  if(rt==NULL) return 0;
  int l=maxPathSum(rt->left,ans);
  int r=maxPathSum(rt->right,ans);
  //four cases to be considered
  int max_child=max(max(l,r)+rt->data,rt->data); // int op1=rt->data; + // int op2=l+rt->data;+ // int op3=r+rt->data;
  int max_parent=max(max_child,l+r+rt->data); // int op4=l+r+rt->data;
  ans=max(ans,max_parent);     //max of all the four cases is Ans
  return max_child;             //return maxchild
}

void maxPathSum(){
  int ans=INT_MIN;//Ans so initialise as INT_MIN for max path sum
  cout<<"Maximum path sum from any node to any node: "<<maxPathSum(root,ans)<<endl;
}

//Shortest between two nodes in a binary tree-Asked by Amazon

int findDistFromLCA(Node*rt,int key,int lvl){
    if(rt==NULL) return -1;
    if(rt->data==key) return lvl;
    int left=findDistFromLCA(rt->left,key,lvl+1);
    if(left!=-1) return left;
    return findDistFromLCA(rt->right,key,lvl+1);
}

void shortestDistBetNodes(){
int n1,n2;
cin>>n1>>n2;
Node*LCA=lca(root,n1,n2);
int d1=findDistFromLCA(LCA,n1,0);
int d2=findDistFromLCA(LCA,n2,0);
cout<<"Shortest between two nodes in a Binary Tree: "<<d1+d2<<endl;
}

};
// INPUT:- 3 4 -1 6 -1 -1 5 1 -1 -1 -1
//>>Other INPUT:- 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

int main(){
  binaryTree T;
   T.buildTree();
  // T.PrintPreOrder();
  // T.PrintInOrder();
  // T.PrintPostOrder();
  // T.Height();
  // T.PrintKthLevel();
  // T.LevelOrder();
  // T.BFS();
  // T.countNoOfNodes();
  // T.sumOfNodes();
  // T.DiameterOp();
  // T.Diameter();
  // T.DiameterRec();
  // T.replaceTree();
  // T.leftNodesSum();
  // T.isHeightBalancedTree();
  // T.Mirror();
   // T.buildTreeFromArray();
  // T.buildTreeFromTrav();
   T.BFS();
   // T.rightSideView();
   // T.printkdistanceNode();
   // T.lca();
   // T.maxPathSum();
   T.shortestDistBetNodes();
  return 0;
}
