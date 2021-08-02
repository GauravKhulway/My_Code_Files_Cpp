#include<bits/stdc++.h>
using namespace std;

//We are using BFS traversal here
class Solution{
public:

    bool checkForCycle(int s, int V, vector<int>adj[], vector<int>&visited){
      //s is the starting node
      //create queue for BFS
       queue<pair<int,int>>q; //pair is (one current node , previous node from which the current node is coming)
       visited[s]=true;//marked starting node as visited
       q.push({s,-1}); //push s as current node and -1 as previous node

       while(!q.empty()){
           int node=q.front().first;
           int pre=q.front().second;
           q.pop();

           for(auto it:adj[node]){//traverse all its neighbour nodes
               if(!visited[it]){
                   visited[it]=true;
                   q.push({it,node});
               }
               else if(pre!=it) return true;
           }
       }
       return false;
    }

     bool isCycle(int V,vector<int>adj[]){
        vector<int>visited(V+1,0);
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                if(checkForCycle(i, V, adj, visited)) return true;//if found then true
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
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends