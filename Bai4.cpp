// by Thanhnhan
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long
struct seg{
    vector<ll> a;
    vector<ll> t;
    void init(int n){
        a.resize(n+1);
        t.resize(4*n+1);
        build(1,1,n);
    }
    void build(int id, int l, int r){
        if(l>r) return;
        if(l==r){
            t[id] = 0;
            return;
        }
        int mid = (l+r)>>1;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        t[id] = t[id*2] + t[id*2+1];
    }
    ll getk(int id, int l, int r, int u, int v){
        if(u>v) return 0;
        if(r<u || v<l) return 0;
        if(u<=l&&r<=v){
            return t[id];
        }
        int mid = (l+r)>>1;
        return getk(id*2,l,mid,u,v) + getk(id*2+1,mid+1,r,u,v);

    }
    void update(int id, int l, int r, int u, ll val){
        if(r<u || u<l) return;
        if(l==r){
            t[id] += val;
            return;
        }
        int mid = (l+r)>>1;
        update(id*2,l,mid,u,val);
        update(id*2+1,mid+1,r,u,val);
        t[id] = t[id*2] + t[id*2+1];
    }
};

int main(){
    seg T;
    int n; cin>>n;
    vector<ll> a(n+1,0);
    map<ll,int> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        k[a[i]] = 0;
    }
    int id = 0;
    for(auto &x : k){
        x.second = ++id;
    }
    for(int i=1;i<=n;i++){
        a[i] = k[a[i]];
    }

    T.init(n+1);
    ll res = 0; // quan trong
    for(int i=1;i<=n;i++){
        res += T.getk(1,1,n,a[i]+1,n);
        T.update(1,1,n,a[i],1);
    }
    cout<<res;
    return 0;
}