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
    bool j = true;
    j &= (S[0] >= 'A');
    j &= (S[0] <= 'Z');
    j &= (S[1] >= '1');
    j &= (S[1] <= '9');
    for(int k=2; k<=6; k++) {
        j &= (S[k] >= '0');
        j &= (S[k] <= '9');
    }
    j &= (S[7] >= 'A');
    j &= (S[7] <= 'Z');
    if(j) cout<<"Yes"<<endl;
    else cout << "No" << endl;
    return 0;
}