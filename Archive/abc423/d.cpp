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
typedef pair<ll,int> pli;
int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N), C(N);
    rep(i,N) cin>>A[i]>>B[i]>>C[i];
    ll t = A[0];
    ll cap = K-C[0];
    priority_queue<pli, vector<pli>, greater<pli>> que;    
    que.push({A[0]+B[0], 0});    
    vector<ll> ans(N);
    ans[0] = A[0];
    for(int i = 1; i < N; i++) {
        chmax(t, A[i]);
        while(!que.empty()) {
            auto [et, ind] = que.top();
            if(et <= t) {
                que.pop();
                cap += C[ind];
            }
            else break;
        }
        while(cap < C[i]) {
            auto [et, ind] = que.top();
            cap += C[ind];
            que.pop();
            t = et;
        }
        ans[i] = t;
        que.push({t+B[i], i});
        cap -= C[i];
    }
    for(auto a: ans) cout << a << endl;

    return 0;
}