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
    char ab, ac, bc;
    cin >> ab >> ac >> bc;
    int a=10, b=20, c=30;
    
    if (ab == '<') {
        if (bc == '<') {
            cout << "B" << endl;
        } else {
            if (ac == '<') {
                cout << "C" << endl;
            } else {
                cout << "A" << endl;
            }
        }
    } else {
        if (bc == '>') {
            cout << "B" << endl;
        } else {
            if (ac == '<') {
                cout << "A" << endl;
            } else {
                cout << "C" << endl;
            }
        }
    }

    return 0;
}