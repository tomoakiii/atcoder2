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
    if (S.size() < 3) {
        cout << "No" << endl;
        return 0;
    }
    int k = S.size()-1;

    if(S[k-2] == 's' && S[k-1] == 'a' && S[k] == 'n'){
        cout << "Yes"<<endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}