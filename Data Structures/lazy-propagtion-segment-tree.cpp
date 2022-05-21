struct T{
   ll sm=0;
   ll mx=0;
   ll mn=0;
};

class SegTree{
public:
    vector<T> seg; // use ds according to question, for eg. pair
    vector<ll> a;
    vector<ll> lazy;
    int n; 
    SegTree(vector<ll> v){
        a = v;
        n = v.size();
        seg.resize(4*n);
        lazy.resize(4*n);
        build(0,0,n-1);
    }
void build(int ind,int start,int end){
    if(start == end){
        seg[ind].sm = seg[ind].mx = seg[ind].mn = a[start];
        return; 
    }
    int mid = (start+end)>>1;
    build(2*ind+1,start,mid);
    build(2*ind+2,mid+1,end);
    seg[ind].sm = seg[2*ind+1].sm+seg[2*ind+2].sm; // operation may change to min,max,add,xor
    seg[ind].mx = max(seg[2*ind+1].mx,seg[2*ind+2].mx);
    seg[ind].mn = min(seg[2*ind+1].mn,seg[2*ind+2].mn);
}
T query(ll ind,ll left, ll right, ll start,ll end){
    if(lazy[ind]!=0){
    seg[ind].sm += (end-start+1)*lazy[ind]; // when min or max remove (end-start+1)
    seg[ind].mx += lazy[ind]; 
    seg[ind].mn += lazy[ind]; 
    if(start!=end){
        lazy[2*ind+1]+=lazy[ind];
        lazy[2*ind+2]+=lazy[ind];
    }
    lazy[ind] = 0;
  }
    if(left<=start && right>=end){
        return seg[ind];
    }
    else if(left>end || right<start)return {0,-INF,INF};
    else {
        ll mid = (start+end) >> 1;
        T p1 = query(2*ind+1,left,right,start,mid);
        T p2 = query(2*ind+2,left,right,mid+1,end);
        return {p1.sm+p2.sm,max(p1.mx,p2.mx),min(p1.mn,p2.mn)}; // operation may change to min,max,add,xor
 
    }
}
void update(int ind,ll i,ll j,ll k,int start, int end){
   if(lazy[ind]!=0){
    seg[ind].sm += (end-start+1)*lazy[ind]; // when min or max remove (end-start+1)
    seg[ind].mx += lazy[ind]; 
    seg[ind].mn += lazy[ind]; 
    if(start!=end){
        lazy[2*ind+1]+=lazy[ind];
        lazy[2*ind+2]+=lazy[ind];
    }
    lazy[ind] = 0;
   }
   if(start>j || i>end )return;
   if(start>=i && end<=j){
    seg[ind].sm += (end-start+1)*k; // when min or max remove (end-start+1)
    seg[ind].mx += k;
    seg[ind].mn += k;
    if(start!=end){
        lazy[2*ind+1]+=k;
        lazy[2*ind+2]+=k;
    }
    return ;
   }
   int mid = (start+end)>>1; 
   update(2*ind+1,i,j,k,start,mid);
   update(2*ind+2,i,j,k,mid+1,end);
    seg[ind] = {seg[2*ind+1].sm+seg[2*ind+2].sm,max(seg[2*ind+1].mx,seg[2*ind+2].mx),min(seg[2*ind+1].mn,seg[2*ind+2].mn)}; // operation may change to min,max,add,xor
}
};