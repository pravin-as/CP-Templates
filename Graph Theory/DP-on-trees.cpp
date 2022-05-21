/* Remember that degree of root and leaf is same if root have only one child */
void dfs(ll node){


    // For storing from root to node

    for(auto child: adj[node]){
        dp[child] = dp[node];
    }

    if(vis[node]==1)return;
    vis[node] = 1;

    for(auto child: adj[node]){
        if(vis[child]==0){
            dfs(child);
        }
    }

    // vector<ll> temp; Can make vector here and pass it as
    // argument also.

    // For storing from leaf to node

    for(auto child: adj[node]){
        dp[node] = dp[child];   // Since this is after dfs all 
                               // children value are calculated
                              // Any mathematical relation between
                             // child and node.
                                 
    }
    


}