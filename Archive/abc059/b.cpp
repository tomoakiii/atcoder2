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
    string A,B;
    cin>>A>>B;
    if(A.size() > B.size()) {
        cout << "GREATER" << endl;
        return 0;
    }
    if (A.size() < B.size()) {
        cout << "LESS" << endl;
        return 0;
    }
    if(A == B) {
        cout << "EQUAL" << endl;
        return 0;
    }
    rep(i,A.size()) {
        if(A[i] > B[i]) {
            cout << "GREATER" << endl;
            return 0;
        } else if (A[i] < B[i]) {
            cout << "LESS" << endl;
            return 0;
        }
    }
    return 0;
}