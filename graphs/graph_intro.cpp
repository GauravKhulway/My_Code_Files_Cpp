#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
   cin>>n>>m;

 //Adjaceny matrix:Use only for a small input sets not for 10 to the power 5********************
   //declaration of adjaceny matrix
   int adj[n][m];

   //take edges as input
   for(int i=0;i<m;i++){
       int u,v;
       cin>>u>>v;
       adj[u][v]=1;
       adj[v][u]=1;
   }

//Adjaceny list **********************************************************
 vector<int>adj[n+1]; //use vector<pair<int,int>> if its a weighted graph
 for(int i=0;i<m;i++){
     int u,v; //wt if weighted graph
     cin>>u>>v; //>>wt
     adj[u].push_back(v); //adj[u].push_back({v,wt}) for weighted graph;  
     adj[v].push_back(u); //use this if bidirectional 
     //adj[v].push_back({u,wt}) for weighted graph; ;
 }

   return 0;
}