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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    set<vector<ll>> st;
    sort(A.rbegin(), A.rend());
    st.insert(A);
    queue<vector<ll>> que;
    que.push(A);
    while(!que.empty()){
        auto q = que.front();
        que.pop();
        rep(i, N) {
            if(q[i] == 0) break;
            for(int j = i+1; j < N; j++) {
                if(q[j] == 0) break;
                auto q2 = q;
                q2[j] += q[i];
                q2[i] = 0;
                sort(q2.rbegin(), q2.rend());
                if(!st.contains(q2)) {
                    st.insert(q2);
                    que.push(q2);
                }
            }
        }
    }
    set<ll> ans;
    for(auto q : st) {
        ll t = 0;
        rep(i, N) {
            t = t ^ q[i];
        }
        ans.insert(t);
    }
    cout << ans.size() << endl;
    return 0;
}