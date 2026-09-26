#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;


int main(){
    ll X;
    cin >> X;
    string S="ARARARARARARARARARARARARARARARARARARARARARARARARCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRCRC";
    int st = 600;
    while(st > X){
        rep(i, S.size()-2){
            if(S[i]=='A' && S[i+1]=='R' && S[i+2]=='C'){
                S[i]='C';
                S[i+1]='R';
                S[i+2]='A';
                st--;
                break;
            }
        }
    }
    cout << S << endl;
    return 0;
}