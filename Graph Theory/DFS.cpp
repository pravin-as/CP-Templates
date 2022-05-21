/* Remember that degree of root and leaf is same if root have only one child */
void dfs(ll node, ll val){

    if(vis[node]==1)return;
    vis[node] = 1;

    for(auto child: adj[node]){
        if(vis[child]==0){
            dfs(child, val); //Change val according to problem.
        }
    }

}