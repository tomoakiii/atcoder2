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
    ll A,B;
    cin >> A >> B;
    dsu UF(13);
    UF.merge(1,3);
    UF.merge(5,3);
    UF.merge(5,7);
    UF.merge(8,7);
    UF.merge(8,10);
    UF.merge(12,10);
    UF.merge(4,6);
    UF.merge(9,6);
    UF.merge(9,11);
    if(UF.same(A,B)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}