#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;



ll xPy(ll x, ll y) {
    ll out = 1;
    rep(i, y) {
        out *= x;
        x--;
    }
    return out;
}

int main(){
ll N, K;
    string S;
    cin >> N >> K >> S;
    vector<int> cnt(10, 0);
	sort(S.begin(), S.end());
    ll ans = 0;
    // set<string> st;
	do {
        // if(st.find(S) != st.end()) continue;

        bool flg = false;
		rep(i,N-K+1) {
            bool flg2 = false;
            rep(j,K/2+1) {
                char s1 = S[i+j];
                char s2 = S[i+K-j-1];
                if (s1 != s2) {
                    flg2 = true;
                    break;
                }                
            }
            if (!flg2) {
                flg = true;
                break;
            }
        }
        if (!flg) {
            ans++;
            // st.insert(S);
        }
	} while (next_permutation(S.begin(), S.end()));


    cout << ans << endl;


    return 0;
}