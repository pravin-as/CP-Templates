class SegTree{
public:
    vector<ll> seg;
    vector<ll> a;
    int n; 
    SegTree(vector<ll> v){
        a = v;
        n = v.size();
        seg.resize(4*n);
        build(0,0,n-1);
    }
void build(ll ind,ll start,ll end){
    if(start == end){
        seg[ind] = a[start];
        return; 
    }
    ll mid = (start+end)>>1;
    build(2*ind+1,start,mid);
    build(2*ind+2,mid+1,end);
    seg[ind] = seg[2*ind+1]+seg[2*ind+2]; // operation may change
}
ll query(ll ind,ll left, ll right, ll start,ll end){
    if(left<=start && right>=end){
        return seg[ind];
    }
    else if(left>end || right<start)return 0ll;
    else {
        ll mid = (start+end) >> 1;
        return query(2*ind+1,left,right,start,mid) + query(2*ind+2,left,right,mid+1,end);// operation may change
 
    }
}
void update(ll ind,ll i,ll k,ll start, ll end){
   if(start == end){
    seg[ind] = k;
    return ;
   }
   ll mid = (start+end) >> 1;
   if(i<=mid){
    update(2*ind+1,i,k,start,mid);
   }
   else{
    update(2*ind+2,i,k,mid+1,end);
   }
   seg[ind] = seg[2*ind+1]+seg[2*ind+2]; // operation may change
}
};