// https://atcoder.jp/contests/abc221/tasks/abc221_e

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

typedef modint998244353 mint;
template <class Type> class SegTree {
private:
    struct val_ind{
        Type v;
        int i;
    };

    int n, sz, trsize;
    struct nd{
        int l;
        int r;
        int c;
        Type val;
    };
    vector<nd> tr;
public:
    // tr[n-1] ~ tr[n-1+sz-1] = original vector v
    SegTree(vector<Type> v) {
        sz = (int)v.size();
        n = 1;
        while(n < sz) n *= 2;
        trsize = 2*n-1;
        tr.resize((size_t)trsize);
        for(int i=0; i<sz; i++) {
            tr[i+n-1].val = v[i];
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
                tr[i/2].val = tr[i].val + tr[i+1].val;
            }
            k*=2;
        }
        for(int i=n-2; i>=0; i--) {
            tr[i].l = tr[i*2+1].l;
            tr[i].r = tr[i*2+2].r;
            tr[i].c = (tr[i].l + tr[i].r)/2;
        }
    }


    void AddVal(int ind, Type delta){
        int i = ind+n-1;
        tr[i].val = tr[i].val + delta;
        while(i>0){
            int ii = (i-1)/2;
            tr[ii].val = tr[ii*2+1].val + tr[ii*2+2].val;
            i = ii;
        }
    }


    void SetVal(int ind, Type val){
        int i = ind+n-1;
        tr[i].val = val;
    }

    Type GetSum(int ind, int a, int b){
        if(tr[ind].l == a && tr[ind].r == b){
            return tr[ind].val;
        }
        if (tr[ind].c >= a && tr[ind].c < b) {
            return GetSum(2*ind+1, a, tr[ind].c) +
                GetSum(2*ind+2, tr[ind].c + 1, b);
        }
        if (tr[ind].c >= b) return GetSum(2*ind+1, a, b);
        return GetSum(2*ind+2, a, b);
    }

};

int main(){

    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    vector vu(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        uv[u].emplace_back(v);
        vu[v].emplace_back(u);
    }
    rep(i,N) sort(uv[i].begin(),uv[i].end());
    priority_queue<int,vector<int>,greater<int>> que;
    que.push(0);
    unordered_set<int> del;
    unordered_set<int> skip;
    vector<bool> visit(N);
    visit[0] = true;
    int mx = 0;
    vector<int> ans(N,INFi);
    while(!que.empty()) {
        auto q = que.top();
        que.pop();
        if(del.contains(q)) del.erase(q);
        if(skip.contains(q)) skip.erase(q);

        if(mx<q) {
            for(int i=mx+1; i<q; i++) {
                skip.insert(i);
            }
            mx=q;
        }
        for(auto nx: uv[q]) {
            if(visit[nx]) continue;
            if(nx>q) del.insert(nx);
            visit[nx] = true;
            que.push(nx);
        }
        if(skip.empty()) chmin(ans[mx], (int)del.size()); 
    }
    for(auto a:ans) {
        if(a==INFi) cout<<-1<<endl;
        else cout<<a<<endl;
    }
    return 0;
}
