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
    ll N,K;cin>>N>>K;
    int R,S,P; cin>>R>>S>>P;
    string T; cin>>T;
    vector<int> v(N);
    rep(i,N) {
        if(T[i] == 'r') v[i]=0;
        if(T[i] == 'p') v[i]=1;
        if(T[i] == 's') v[i]=2;
    }
    ll table[3] = {P, S, R};
    ll score = 0;
    for(int i=0; i<K; i++) {
        int last = -1;
        for(int j=i; j<N; j+=K) {
            if(v[j] == last) {
                last = -1;
            } else {
                last = v[j];
                score += table[v[j]];
            }
        }
    }
    cout << score << endl;
    return 0;
}