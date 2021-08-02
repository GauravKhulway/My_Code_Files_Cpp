#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;//no of nodes/Vertices
  list<int>*l;//list<int>*l=new list<int>[V]//create of list of pointers pointing to each vertice's/node's neighbours
public:
  Graph(int V){//parameterised constructor
    this->V=V;//set above n(private) to this value of n passing in the function from main
    l=new list<int>[V];//creating V number of list to store their neighbours
  }

  void addEdge(int x,int y){
    l[x].push_back(y);//store y in l[x] as neighbour of x
    l[y].push_back(x);//store x in l[y] as neighbour of y
  }

  void printAdjList(){
     for(int i=0;i<V;i++){
       cout<<"vertex :"<<i<<"->";
       for(auto nbr:l[i]){
         cout<<nbr<<",";
       }
       cout<<endl;
     }
  }
};

int main() {

  Graph g(4);//4 Vertices graph
  g.addEdge(0,1);//0 is connected with 1
  g.addEdge(0,2);
  g.addEdge(2,3);
  g.addEdge(1,2);
  g.printAdjList();
  return 0;
}
