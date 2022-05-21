/* pref[i] gives the longest strictly increasing subsequence size for prefix 
   [0, i] while suff[i] is longest strictly increasing subsequence size for 
   suffix [i, n - 1]. If you want to print the subsequence print lis.
*/
vector<ll> pref, suff;
void Longest_Strictly_Increasing_Subsequence(vector<ll> A, ll n){

    pref.assign(n,0LL);suff.assign(n,0LL);
    vector<ll> lis;

    for(ll i = 0; i < n; i++){
        auto it = lower_bound(lis.begin(),lis.end(),A[i]) - lis.begin();
        if(it == lis.size()){
            lis.push_back(A[i]);
        }else{
            lis[it] = A[i];
        }
        pref[i] = lis.size();
    }

    lis.clear();

    for(ll i = n - 1; i >= 0; i--){
        auto it = lower_bound(lis.begin(),lis.end(),-A[i]) - lis.begin();
        if(it == lis.size()){
            lis.push_back(-A[i]);
        }else{
            lis[it] = -A[i];
        }
        suff[i] = lis.size();
    }

}