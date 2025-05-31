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
    cin>>S;
    int k = 0;
    for(int i = S.size()-1; i>=0; i--) {
        if(S[i] == 'a') {
            S.pop_back();
            k++;
        }
        else break;
    }
    reverse(S.begin(), S.end());
    while(k) {
        if(S[S.size() - 1] == 'a') S.pop_back();
        k--;
    }
    rep(i, S.size()/2) {
        if(S[i] != S[S.size() - 1 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}