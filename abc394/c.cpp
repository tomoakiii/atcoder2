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
    int id = 1;
    while(id < S.size()) {
        if(S[id-1] == 'W' && S[id] == 'A') {
            S[id-1] = 'A';
            S[id] = 'C';
            if(id > 1) id = id-1;
        } else {
            id++;
        }
    }
    cout << S << endl;
    return 0;
}