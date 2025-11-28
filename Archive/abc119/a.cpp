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
    int y,m,d;
    scanf("%d/%d/%d", &y,&m,&d);
    auto func=[](ll y,ll m,ll d)->ll{
        return y*10000+m*100+d;
    };
    if(func(y,m,d) > func(2019,4,30)) cout<<"TBD"<<endl;
    else cout<<"Heisei"<<endl;

    return 0;
}