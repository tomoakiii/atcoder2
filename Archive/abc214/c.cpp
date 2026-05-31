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
    vector<ll> S(N);
    vector<pair<ll, int>> T(N);
    rep(i,N) cin>>S[i];
    rep(i,N) {
        cin>>T[i].first;
        T[i].second = i;
    }
    vector<ll> A(N, INFi);
    rep(i,N) A[i] = T[i].first;

    sort(T.begin(), T.end());
    rep(i,N) {
        int p = T[i].second;
        int p2 = p+1; p2%=N;
        ll now = T[i].first;
        while(A[p2] > now + S[p]){
            now += S[p];
            A[p2] = now;
            p = p2;
            p2++; p2%=N;
        }
    }
    rep(i,N) cout<<A[i]<<endl;
    return 0;
}