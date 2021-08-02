#include<bits/stdc++.h>
using namespace std;

class Graph{
  //adj_list
  unordered_map<string,list<pair<string,int>>>l;
public:
   void  addEdge(string x,string y,bool Bidir,int wt){
     l[x].push_back(make_pair(y,wt));//store y and wt i.e,edge length in l[x]
     if(Bidir){//if bidirectional vertice then add the other way too
        l[y].push_back(make_pair(x,wt));
     }
   }

   void printAdjList(){

     for(auto p:l){
      string city=p.first;
      list<pair<string,int>>nbrs=p.second;
      cout<<city<<"->";
      for(auto nbr:nbrs){
        string des=nbr.first;
        int dist=nbr.second;
        cout<<des<<" "<<dist<<" ";
      }
      cout<<endl;
     }
   }
};

int main(){
   Graph g;
   g.addEdge("A","B",true,20);
   g.addEdge("B","D",true,40);
   g.addEdge("A","C",true,10);
   g.addEdge("C","D",true,40);
   g.addEdge("A","D",false,50);
   g.printAdjList();
}
