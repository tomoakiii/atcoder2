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
    ll M;    
    vector<ll> A{};
    cin >> M;
    vector<ll> div3(21);
    div3[0] = 1;
    rep(i, 20) {
        div3[i+1] = div3[i] * 3;
    }

    while (true) {
        for (int k = 20; k >= 0; k--){
            if (M >= div3[k]){
                M -= div3[k];
                A.push_back(k);
                break;
            }
        }
        if (M == 0) break;
    }

    
    cout << A.size() << endl;
    for(auto a: A) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}