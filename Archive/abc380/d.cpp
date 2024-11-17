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
    string S;    
    cin >> S;
    string S2 = S;
    for(char &c:S2) {
        if(c>='a' && c<='z') {
            c = c - 'a' + 'A';
        } else {
            c = c - 'A' + 'a';
        }
    }
    string Sc = S + S2;
    string Sc2 = S2 + S;
    ll ssize = (ll)Sc.size();
    vector<ll> P(101);
    P[0] = ssize;
    rep(i, 100) {
        if(P[i] >= INF) {
            P[i+1] = INF;
        } else {
            P[i+1] = P[i] * 2;
        }        
    }
    
    int Q;
    cin >> Q;
    while(Q--) {
        ll K;
        cin >> K;
        K--;
        bool flg = true;
        while(K >= ssize){        
            auto id = lower_bound(P.begin(), P.end(), K);
            int j = id - P.begin();            
            if (P[j] == K) K-=P[j];
            else if(j > 0) {                
                K -= P[j-1];
            }
            flg = !flg;
        }
        if(flg) cout << Sc[K] << " ";
        else cout << Sc2[K] << " ";

    }
    cout << endl;

    return 0;
}