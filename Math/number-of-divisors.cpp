//nm gives number of divisors of a number.

const int N = 1e5 + 5;
vector<ll> nm(N+5,0);

void sieve(){
    for(int i=1;i<=N;i++){
        for(int j=i;j<N;j+=i){
            nm[j]++;
        }
    }    
}