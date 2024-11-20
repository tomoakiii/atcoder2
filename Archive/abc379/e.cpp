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
    ll N;
    cin >> N;
    string S;
    cin >> S;

    vector<ll> pow10(N);
    string T = "";
    reverse(S.begin(), S.end());

    vector<ll> sigma(N+1, 0);
    sigma[N-1] = S[N-1]-'0';
    ll cnt = 1;
    for(int i=N-2; i>=0; i--) {
        cnt++;
        sigma[i] = sigma[i+1] + cnt*(S[i]-'0');
        
    }
    
    rep(i, N){        
        T = (char)(sigma[i]%10 + '0') + T;
        sigma[i+1] += sigma[i]/10;
    }

    ll rm = sigma[N];
    while(rm > 0) {
        T = (char)((rm % 10) + '0') + T;
        rm /= 10;
    }

    
    string P = "";
    bool flg = true;
    for(auto t: T) {
        if (flg && t=='0') continue;
        P = t + P;
        flg = false;
    }
    reverse(P.begin(), P.end());
    
    cout << P << endl;
    return 0;
}