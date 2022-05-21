// number of components following certain property
// in this case number of components with xor = xr.
ll cnt = 0;
ll dfs(ll node, ll xr){

    if(vis[node]==1)return 0LL;
    vis[node] = 1;
    ll temp = A[node];

    for(auto child: adj[node]){
        if(vis[child]==0){
            temp ^= dfs(child,xr);
        }
    }
        if(temp  ==  xr){
            temp = 0;
            cnt++;
        }
    return temp;

}