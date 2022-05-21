/* Remember that degree of root and leaf is same if root have only one child */
void bfs(ll node){

    if(vis[node])return;

    queue<ll> q; //pair can also be stored according to problem.
    q.push(node);

    while(!q.empty()){

        ll node = q.front();
        q.pop();
        vis[node]=1;

        for(auto child: adj[node]){
            if(vis[child]==0){
                q.push(child);
            }
        } 
    }
}