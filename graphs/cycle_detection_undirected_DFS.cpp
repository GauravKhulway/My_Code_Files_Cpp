#include<bits/stdc++.h>
using namespace std;

//We are using DFS traversal here
class Solution { 

public:
bool checkForCycle(int node, int parent, vector<int>&visited, vector<int>adj[]){
     visited[node]=1;
 for(auto it:adj[node]){
      if(visited[it]==0){
          if(checkForCycle(it,node,visited,adj)) return true; //whenever finds it true return true
      }
      else if(it!=parent) return true; //if previous node is not the parent of current node
  }
   return false;
}

public:
bool isCycle(int V,vector<int>adj[]){
        vector<int>visited(V+1,0);
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                if(checkForCycle(i, -1,  visited, adj)) return true;//if found then true
            }
        }
        return false;//if cycle not found
     }
};

// { Driver Code Starts.
int main(){  
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1 \n";
		else cout << "0 \n";
	}
	return 0;
}  // } Driver Code Ends