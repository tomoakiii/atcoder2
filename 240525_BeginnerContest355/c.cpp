#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, T;
    cin >> N >> T;

    vector<ll> row(N), col(N);
    ll dig0=0, dig1=0;
    ll a;
    ll ans = -1;
    rep(i, T){
        cin >> a;
        a--;
        int v=a/N;
        int l=a%N;
        if (v == l) {
            dig0 ++;
        }
        if (v == N - 1- l){
            dig1 ++;
        }
        row[v]++;
        col[l]++;
        if(dig0 == N || dig1 == N || row[v] == N || col[l] == N) {
            ans = i + 1;
            break;
        }
    }
      
    cout << ans << endl;
    return 0;
}