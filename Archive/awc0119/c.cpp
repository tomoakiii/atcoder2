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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,A;
    cin >> N >> M >> A;
    deque<ll> H;
    rep(i,N){
        ll h; cin >> h;
        if(h<=A)continue;
        H.push_back(h);
    }
    ll cnt = 0;
    while(H.size()){
        if(M >= H[0]){
            M /= 2;
            cnt++;
            H.pop_front();
        } else {
            break;
        }
    }
    if(H.empty()) cout << cnt << endl;
    else cout << -1 << endl;
    return 0;
}