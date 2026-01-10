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
typedef pair<ll, vector<int>> pli;
int main(){
    ll N,K,X;
    cin >> N>>K>>X;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.rbegin(), A.rend());
    ll sm = K * A[0];
    vector<int> C(N);
    C[0] = K;
    priority_queue<pli> que;
    que.push({sm, C});
    set<vector<int>> visit;
    visit.insert(C);
    while(!que.empty()) {
        auto [w, vl] = que.top();
        cout << w << endl;
        X--;
        if(X == 0) break;
        que.pop();
        rep(i,N-1) {
            if(vl[i] > 0) {
                vl[i]--;
                vl[i+1]++;
                if(!visit.contains(vl)) {
                    ll w2 = w + A[i+1];
                    w2 -= A[i];
                    visit.insert(vl);
                    que.push({w2, vl});
                }
                vl[i]++;
                vl[i+1]--;
            }
        }
    }
    return 0;
}