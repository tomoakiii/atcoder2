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
    int T; cin>>T;
    while(T--){
        ll N;
        cin >> N;
        vector<ll> A(N);
        vector<pair<ll, int>> Aa(N);
        rep(i,N) {
            cin>>A[i];
            Aa[i].first = abs(A[i]);
            Aa[i].second = i;
        }
        sort(Aa.begin(), Aa.end());
        bool flg = true;
        ll ma=INF, mb=INF;
        if(Aa[0].first == Aa[N-1].first) {
            int cnt0 = 0, cnt1 = 0;
            rep(i,N) {
                if(A[i] == Aa[0].first) cnt0++;
                if(A[i] == Aa[0].first * -1) cnt1++;
            }
            if(cnt0 == 0 || cnt1 == 0 || abs(cnt0 - cnt1) <= 1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            continue;
        }
        rep(j,N-1) {
            int i = Aa[j].second;
            int i2 = Aa[j+1].second;
            ll a = A[i], b = A[i2];
            ll g = gcd(a,b);
            a /= g; b /= g;            
            if(a < 0) {
                a *= -1;
                b *= -1;
            }
            if(j==0) {
                ma = a, mb = b;
            } else {
                if(ma != a || mb != b) flg = false;                
            }
        }
        if(flg) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}