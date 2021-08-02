#include<bits/stdc++.h>
using namespace std;

/*
 BFS-Breadth first search
 -> You start with a given/source node and then you will reach to its neighbours
 -> Its similar to level order traversal in trees
 NOTE: Distance travelled by the level order is the shortest distance.
 (if the graph is the unwaited graph that means all edges have the same cost)
 if weighted graph then Dijkstra's Algorithm
*/
template<typename T>

class Graph{
  map<T,list<T>>l;
public:
  void addEdge(int x,int y){
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void bfs(T src){//src node to traversal
    map<T,bool>visited;//to maintain the check whether i visited the node before or not
    queue<T>q;//to store all the neighbours of a given node
    q.push(src);//push source node first for traversal
    visited[src]=true;//marked as visited
    while (!q.empty()) {
      T node=q.front();
      q.pop();
      cout<<node<<" ";
       for(int nbr:l[node]){
         if(!visited[nbr]){
           q.push(nbr);
           visited[nbr]=true;//mark the neighbours are now visited
         }
       }
    }
  }

  void shortestPath(T src){//src node to traversal
    map<T,int>dist;//to maintain the distance from the source node
    queue<T>q;//to store all the neighbours of a given node

    for(auto node_pair:l){
      T node=node_pair.first;
      dist[node]=INT_MAX;//initialise all the node distance to infinity as we haven't discovered them yet
    }
    q.push(src);//push source node first for traversal
    dist[src]=0;//we take source node distance as 0
    while (!q.empty()) {
      T node=q.front();
      q.pop();
      // cout<<node<<" ";
       for(int nbr:l[node]){
         if(dist[nbr]==INT_MAX){//that means we are visiting this node for the first time
           q.push(nbr);
           dist[nbr]=dist[node]+1;//distance of neighbour is equal to 1 more than the distance of parent
         }
       }
    }
    //print distance to every node
    for(auto node_pair:l){
      T node=node_pair.first;
      int d=dist[node];
      cout<<"Node "<<node<<" distance from src "<< d <<endl;
    }
  }

};

int main(){
  Graph<int>g;//create object with datatype
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);
  g.addEdge(4,5);
  // g.bfs(0);
  g.shortestPath(0);
}
