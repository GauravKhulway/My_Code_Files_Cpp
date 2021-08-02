class solution(){
    void dfs(int node,vector<int> &vis,vector<int>adj[],vector<int> &storeDfs){
     storeDfs.push_back(node);//first store node in storeDfs
     visited[node]=1;//then marked visited
     for(auto it:adj[node]){//traverse all its connections
        if(!visited[it]){
           dfs(it,vis,adj,storeDfs);//call them recursively / individually 
        }
     }
    }
public:
//dfs is a recursive approach 
    vector<int>dfsOfGraph(int V,vector<int>adj[]){
     vector<int>storeDfs;
     vector<int>visited(V+1,0);
     for(int i=1;i<=V;i++){
         if(!visited[i]){//if not visited
            dfs(i,vis,adj,storeDfs);//call dfs recursive
         }
     }
     return storeDfs;
    }
};