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

void calc() {
    int trsize;
    struct nd{
        int l;
        int r;
        ll mn;
        ll val;
    };
    vector<nd> tr;
    
    int N;
    cin >> N;    
    int sz = 1;
    rep(i,N) sz *= 2;
    int n = sz;
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    trsize = 2*sz-1;
    tr.resize((size_t)trsize);
    for(int i=0; i<sz; i++) {
        tr[i+n-1].val = tr[i+n-1].mn = v[i];

    }
    
    int k=1;
    while ((n-1)/k > 0){
        for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
            tr[i/2].mn = min(tr[i].mn, tr[i+1].mn);
        }
        k*=2;
    }
    for(int i=n-2; i>=0; i--) {      
        tr[i].l = 0;
        tr[i].r = 0;
    }

    vector<bool> visit(N);
    vector<ll> ans;
    auto fun = [&](auto fun, int cur) -> void{
        if(2 * cur + 1 >= trsize) {
            ans.push_back(tr[cur].val);
            int ii = cur;
            while(true) {
                tr[ii].mn = INF;
                if(ii==0) break;
                ii = (ii-1)/2;
            }                
            return;                 
        }
        ll mn1 = tr[2*cur+1].mn;
        ll mn2 = tr[2*cur+2].mn;
        if(mn1 < mn2) {
            if(mn1 < INF) fun(fun, 2*cur+1);
            if(mn2 < INF) fun(fun, 2*cur+2);
        } else {
            if(mn2 < INF) fun(fun, 2*cur+2);
            if(mn1 < INF) fun(fun, 2*cur+1);
        }

    };        
    fun(fun, 0);
    for(auto a: ans) cout<<a<<" ";
    cout<<endl;

};

// test case:
// 10 5
// 10 1 6 8 7 2 5 9 3 4

int main(){
    int T; cin>>T;
    while(T--){    
        calc();        
    }
    return 0;
}