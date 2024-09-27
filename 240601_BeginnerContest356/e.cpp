#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N;
    cin >> N;
    const int M = 1000005;
    vector<ll> C(M+5);
    set<int> st;
    rep(i, N) {
        ll a;
        cin >> a;
        C[a]++;
        st.insert(a);
    }
    vector Cs=C;
    rep(i, M+4) Cs[i+1] += Cs[i];
    auto f = [&](int l, int r) {
        return Cs[r] - Cs[l-1];
    };
    ll ans = 0;
    for(auto s:st) {
        int k = 1;
        ans += C[s]*(C[s] - 1)/2;
        while (k * s <= M+3){
            int l;
            if (k==1){
                l = s + 1;
            } else {
                l = s*k;
            }
            
            int r = min(s*(k+1)-1, M+3);
            ll tans = f(l, r) * k;
            tans *= C[s];
            ans += tans;
            k++;
        }
    }
    cout << ans << endl;
    return 0;
}