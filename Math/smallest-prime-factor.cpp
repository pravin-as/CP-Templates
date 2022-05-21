//spf stores smallest prime factor of number
const ll N = 1e5 + 5;
vector<ll> spf(N+5);

void sieve(){
    for(ll i = 2; i < N; i++)spf[i] = i;
    for(ll i=2;i*i<N;i++){
        if(spf[i] == i){
            for(ll j=i*i;j<N;j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }    
}