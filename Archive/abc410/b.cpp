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

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(Q);
    rep(i,Q) cin>>X[i];
    vector box(N, vector<int>{});
    vector<int> ans(Q);
    rep(i,Q) {
        ll s = INF;
        int tgt;
        if(X[i] == 0) {
            rep(i,N) {
                if(box[i].size() < s) {
                    tgt = i;
                    s = box[i].size();
                }
            }
            box[tgt].push_back(i);
            ans[i] = tgt;
            cout<<tgt+1<<endl;
        } else {
            X[i]--;
            box[X[i]].push_back(i);
            cout<<X[i]+1<<endl;
        }
        
    }
    
    return 0;
}