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
    string S;
    cin >> S;
    int cq = 0;
    rep(i, S.size()) {
        if(S[i] == 'o') {
            if(i>0) S[i-1] = '.';
            if(i<N-1) S[i+1] = '.';
            cq++;
        }
    }    
    if(cq == K) {
        rep(i, S.size()) {
            S[i] = (S[i] == '?')?'.':S[i];
        }
        cout << S << endl;
        return 0;
    }
    vector<pair<ll, ll>> v{};
    int rep = 0;
    int st = -1;
    rep(i,S.size()) {
        if(S[i] == '?') {
            if(rep == 0) st = i;
            rep++;            
        }
        if(S[i] != '?' || (i==N-1 && rep>0)) {
            if(rep > 0) {
                v.push_back({rep, st});                
                cq += (rep+1)/2;
                rep = 0;
            }
        }
    }
    if(cq == K) {
        for(auto [vv, i]: v) {
            if(vv % 2 == 1){
                bool flg = false;
                for(int j = i; j < i + vv; j++){
                    if(!flg) S[j] = 'o';
                    else S[j] = '.';
                    flg = !flg;
                }
            }
        }
    }
    cout << S << endl;
    return 0;
}