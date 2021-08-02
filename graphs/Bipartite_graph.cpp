#include<bits/stdc++.h>
using namespace std;

//using BFS traversal here 
//Bipartite graph that can be coloured using 2 colors such that mo two adjacent nodes have same color

bool bipartiteBfs(int src, vector<int>adj[], int color[]){
    queue<int>q;//create a queue to store
    q.push(src); //push source node 
    color[src] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it] == -1) { //if not coloured
                color[it] = 1 - color[node];// 1 - color of node gives the opposite color to the other node
                q.push(it);//once coloured push it in queue
            }
            else if(color[it] == color[node]) return false; // color is same then return false;
        }
    }
    return true;
}

bool checkBipartite(vector<int>adj[], int n){
    int color[n];//to store the colour of all the nodes
    memset(color,-1,sizeof(color));//initialise it with the  value -1 so no node is coloured now
    for(int i=0;i<n;i++){
        if(color[i] == -1){ //node has not been visited or coloured
           if(!bipartiteBfs(i, adj, color)){
               return false;
           }
        }
    }
    return true;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(checkBipartite(adj, n)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/