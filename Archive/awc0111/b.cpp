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
    ll N, M;
    cin >> N >> M;
    vector<ll> S(M);
    rep(i,M) {
        cin>>S[i];
        S[i]--;
    }
    if(M==1) {
        cout << "0/1" << endl;
        return 0;
    }
    sort(S.begin(), S.end());
    S.push_back(S[0] + N);
    ll mx = 0;
    rep(i,M) chmax(mx, abs(S[i+1] - S[i]));
    ll dl = (N - mx + 1) / 2;
    ll p = dl*360;
    ll g = gcd(p, N);
    p/=g;
    ll q = N/g;
    cout << p << "/" << q << endl;
    return 0;
}