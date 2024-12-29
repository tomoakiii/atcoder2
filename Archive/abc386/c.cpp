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
    ll K;
    cin >> K;
    string S, T;
    cin >> S >> T;
    if (abs((int)S.size() - (int)T.size()) > 1) {
        cout << "No" << endl;
        return 0;
    }
    bool flg = false;
    int k = 0;
    if(S.size() == T.size()) {
        rep(i, S.size()) {
            if(S[i] != T[k] && !flg) {
                flg = true;
            } else if (S[i] != T[k] && flg) {        
                cout << "No" << endl;
                return 0;
            }
            k++;
        }
        cout << "Yes" << endl;
        return 0;
    }
    if(S.size() > T.size()) swap(S, T);
    rep(i, S.size()) {
        if(S[i] != T[k] && !flg) {
            k++;
            if(k > T.size()) {
                cout << "No" << endl;
                return 0;   
            }
            flg = true;
        }
        if (S[i] != T[k] && flg) {
            
            cout << "No" << endl;
            return 0;   
        
        }
        k++;
    }
    cout << "Yes" <<endl;

    return 0;
}