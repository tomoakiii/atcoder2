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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> S(2);
    cin>>S[0]>>S[1];
    if(S[0] == "AD" || S[1] == "AD" ||S[0] == "DA" || S[1] == "DA" ){
        cout<<"Yes"<<endl;
        return 0;
    }
    string T0(2,'-');
    T0[0] = S[0][0];
    T0[1] = S[1][0];
    string T1(2,'-');
    T1[0] = S[0][1];
    T1[1] = S[1][1];

    if(T0 == "AD" || T1 == "AD" ||T0 == "DA" || T1 == "DA" ){
        cout<<"Yes"<<endl;
        return 0;
    }

    cout<<"No"<<endl;
    return 0;
}