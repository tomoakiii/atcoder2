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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }
    vector<ll> visit(N,-1);
    ll cur = 0, cnt = 0;
    visit[0] = 0;
    while(true) {
        cur = A[cur];
        cnt++;
        if(visit[cur] != -1) {
            K -= visit[cur];
            cnt -= visit[cur];
            ll p = K % cnt;
            rep(i, p) {
                cur = A[cur];
            }
            cout << cur + 1 << endl;
            break;
        }
        visit[cur] = cnt;
        if(cnt == K) {
            cout << cur+1 << endl;
            return 0;
        }
    }

    return 0;
}