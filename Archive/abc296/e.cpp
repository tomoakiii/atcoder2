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
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;        
    }
    vector<int> visit(N, -1);    
    rep(i,N){        
        auto f = [&](auto f, int cur)->void {            
            if (visit[cur] == INFi) return;            
            int nx = A[cur];            
            if (visit[nx] > -1 && visit[nx] < i) return;
            if (visit[cur] == i) {
                visit[cur] = INFi;
            } else {
                visit[cur] = i;
            }        
            f(f, nx);
        };
        if(visit[i] == -1) {
            f(f, i);
        }
    }
    int cnt=0;
    rep(i,N) {
        if(visit[i] >= INFi) cnt++;
    }
    cout << cnt << endl;
    return 0;
}