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
    string X; cin>>X;

    int cnt = 0;
    rep(i,1000){
        bool flg = false;
        rep(j,X.size()-2){
            if(X[j]=='A' && X[j+1]=='R' && X[j+2]=='C'){
                X[j]='C';
                X[j+1]='R';
                X[j+2]='A';
                cnt++;
                flg = true;
                break;
            }
        }
        if(!flg) break;
    }
    cout << X.size() << endl;
    cout<<cnt<<endl;
    cout << X << endl;
    return 0;
}