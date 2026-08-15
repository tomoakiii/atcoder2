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
typedef long double ld;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K; string S;
    cin >> N >> K >> S;
    vector<ld> A(N);
    vector<ll> W(N);
    ll cnt = 0;
    priority_queue<pair<ld,int>> que;
    rep(i,N){
        cnt += (S[i]=='o');
        W[i] = cnt;
        if(cnt >= K) {
            A[i] = (ld)cnt/(ld)(i+1);
            que.push({A[i], i});
        }
    }
    rep(i,N){
        if(i>0){
            while(!que.empty()){
                auto [d,j] = que.top();
                ll nc = (W[j] - W[i-1]);
                if(nc < K) {
                    que.pop(); continue;
                }
                ld np = (ld)nc/(ld)(j-i+1);
                if(chmax(A[j], np)) {
                    que.pop();
                    que.push({A[j], j});
                }
                break;
            }
        }

    }
    ld ans = 0;
    for(auto a:A)chmax(ans,a);
    printf("%.20Lf\n", ans);
    return 0;
}