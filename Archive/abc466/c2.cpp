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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll ans=0;
    int i = 1;
    int r = 2;
    while(i<=N) {
        if(i==r) r++;
        while(r <= N){
            cout << "? " << i << " " << r << endl;
            string x; cin>>x;
            if(x == "Yes"){
                r++;
                continue;
            } else {
                break;
            }
        }

        int i2 = i+1;
        while(i2<r) {
            cout << "? " << i << " " << r << endl;
            string x; cin>>x;
            if(x != "Yes"){
                i2++;
                continue;
            } else {
                break;
            }
        }
        if(i == i2){
            ll len = r-i;
            ans += len * (len-1) / 2;
        } else {

        }
        i = i2;
    }
    cout << "! " << ans << endl;
    return 0;
}