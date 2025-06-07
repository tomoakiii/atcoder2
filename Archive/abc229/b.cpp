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
    ll A,B;
    cin>>A>>B;
    while(A + B) {
        if(A%10 + B%10 >= 10) {
            cout<<"Hard"<<endl;
            return 0;
        }
        A/=10, B/=10;
    }
    cout<<"Easy"<<endl;
    return 0;
}