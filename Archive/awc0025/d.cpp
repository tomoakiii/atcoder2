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
    ll N,S,Q;
    cin >> N>>S>>Q;
    vector<pair<ll,int>> X(N);
    rep(i,N) {
        cin>>X[i].first;
        X[i].second = i;
    }
    sort(X.begin(),X.end());
    int M=100;
    vector nx(M+1, vector<int>(N));
    rep(i,N) {
        if(i==0) nx[0][i] = 1;
        else if(i==N-1) nx[0][i] = N-2;
        else {
            if(X[i+1].first-X[i].first < X[i].first-X[i-1].first) nx[0][i] = i+1;
            else if(X[i+1].first-X[i].first > X[i].first-X[i-1].first) nx[0][i] = i-1;
            else if(X[i+1].second < X[i-1].second) nx[0][i] = i+1;
            else nx[0][i] = i-1;
        }
    }
    rep(k,M) {
        rep(i,N) {
            int p = nx[k][i];
            nx[k+1][i] = nx[k][p];
        }
    }
    int id = 0;
    int ans;
    rep(i,N) if(X[i].second==S-1) ans = i;
    while(Q) {
        if(Q%2) {
            ans = nx[id][ans];
        }
        id++;
        Q/=2;
    }
    cout << X[ans].second+1 << endl;
    return 0;
}