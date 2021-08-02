#include<bits/stdc++.h>
using namespace std;

vector<int>bfsOfGraph(int V,vector<int>adj[]){//V here is number of nodes
  vector<int>bfs;
  vector<int>visited(V+1,0);//visited vector to store if node was visited before
  for(int i=1;i<=V;i++){
     if(!visited[i]){//if node not visited then perform actions
         queue<int>q;
         q.push(i); //store it in a queue
         visited[i]=1;//and marked it as visited
         while(!q.empty()){//iterate until queue is not empty
            int node=q.front();//store in node
            q.pop();//pop from the queue
            bfs.push_back(node);//and store in bfs for output
            for(auto it:adj[node]){//take all the adjacent nodes 
                if(!visited[it]){//if not visited
                    q.push(it);//take them inside the queue
                    visited[i]=1;//marked them visited
                }
            }
         }
     }
  }
  return bfs;
}

int main(){
    int n,m;
   cin>>n>>m;
 vector<int>adj[n+1]; //use vector<pair<int,int>> if its a weighted graph
 for(int i=0;i<m;i++){
     int u,v; //wt if weighted graph
     cin>>u>>v; //>>wt
     adj[u].push_back(v); //adj[u].push_back({v,wt}) for weighted graph;  
     adj[v].push_back(u); //use this if bidirectional 
     //adj[v].push_back({u,wt}) for weighted graph; ;
 }
 bfsOfGraph(m,adj);
   return 0;
}