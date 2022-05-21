// firstly make an object of class by - dsu a = dsu(n+1);

class dsu{
public:
    ll n;
    vector<ll> parent;
    vector<ll> size;
    dsu(ll _n): n(_n){
      parent.resize(n+1LL);
      iota(parent.begin(),parent.end(),0LL);
      size.assign(n+1LL,1LL);
    }
    inline ll find_parent(ll a){
        return parent[a] = (parent[a] == a?a:find_parent(parent[a]));
    }
     inline bool union_set(ll a, ll b){
     a = find_parent(a);
     b = find_parent(b);
     if(a!=b){
       if(size[a] < size[b])swap(a,b);
       parent[b] = a;
       size[a] += size[b];
       size[b] = 0;
       return true;
     }
     return false;
    }
};