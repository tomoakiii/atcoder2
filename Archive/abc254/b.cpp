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
    ll N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        vector<int> newA(N);
        rep(j, i+1) {
            if(j == 0 || j == i) newA[j] = 1;
            else newA[j] = A[j-1] + A[j];
            cout << newA[j] << " ";
        }        
        cout << endl;
        swap(newA, A);
    }
    return 0;
}