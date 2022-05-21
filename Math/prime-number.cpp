const ll N = 1e5 + 5;
vector<ll> prime(N+5,1LL);

void sieve(){
    prime[0] = prime[1] = 0;
    for(ll i=2;i*i<=N;i++){
        for(ll j=i*i;j<N;j+=i){
            prime[j] = 0;
        }
    }    
}