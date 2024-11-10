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
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    map<ll, bool> mp;
    auto f = [&](auto f, ll cnt, char a, bool isT) -> bool{
        bool tmp = false;
        rep(i, N) {
            if (S[i][0] == a && ((cnt>>i)&1) == 0) {
                ll ncnt = cnt | ((ll)1<<i);
                if (mp.count(ncnt) == 0){
                    mp[ncnt] = f(f, ncnt, *(S[i].rbegin()), !isT);
                }
                tmp |= (isT == mp[ncnt]);
            }
        }
        if (tmp) return isT;
        else return !isT;
    };

    bool ans = false;
    rep(i, N) {        
        ans |= f(f, (ll)1<<i, *(S[i].rbegin()), false);
    }
    
    if(ans) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}