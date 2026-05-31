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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> stN, stP, stZ;
    rep(i,N) {
        cin>>A[i];
        if(A[i] < 0) stN.push_back(A[i]);
        else if (A[i] == 0) stZ.push_back(A[i]);
        else stP.push_back(A[i]);
    }
    sort(stN.begin(), stN.end());
    sort(stP.begin(), stP.end());
    ll nN = stN.size() * stP.size();
    ll nZ = stZ.size() * (stZ.size()-1) / 2 + stZ.size() * stP.size() + stZ.size() * stN.size();
    ll nP = stP.size() * (stP.size()-1) / 2 + stN.size() * (stN.size()-1) / 2;
    if(K <= nN) {
        ll ng = stN[0] * stP[stP.size()-1] - 1, ok = -1; // ok以下になるものはnN個ある。ng以下になるものは1個もない
        while(ok - ng > 1) {
            ll c = (ok + ng) / 2;
            ll cnt = 0; // c以下のものの個数
            for(auto x: stN) {
                if(stP[stP.size()-1] * x <= c) cnt+=stP.size();
                else if (stP[0] * x > c) continue;
                else{
                    int ok2 = 0, ng2 = stP.size();
                    while(ng2 - ok2 > 1) {
                        int c2 = (ok2+ng2) / 2;
                        if(stP[c2] * x <= c) ok2 = c2;
                        else ng2 = c2;
                    }
                    cnt += ok2 + 1;
                }    
            }
            if(cnt >= K) ok = c; 
            else ng = c;
        }
        cout << ok << endl;
    } else if (K <= nN + nZ) {
        cout << 0 << endl;
    } else {
        K -= nN;
        K -= nZ;
        ll ng = 0, ok = 5e18;  // ok以下になるものはKmax個ある。ng以下になるものは1個もない
        reverse(stN.begin(), stN.end());
        for(auto &ssn: stN) ssn*=-1;
        while(ok - ng > 1) {
            ll c = (ok + ng) / 2;
            ll cnt = 0; // c以下になるものの個数
            rep(kkk,2){
                rep(i, (int)stP.size()-1) {
                    if(stP[i] * stP[stP.size()-1] <= c) cnt += stP.size()-i-1;
                    else if(stP[i] * stP[i+1] > c) break;
                    else {
                        int ok2 = i, ng2 = stP.size();
                        while(ng2 - ok2 > 1) {
                            int c2 = (ok2 + ng2) / 2;
                            if(stP[i] * stP[c2] <= c) ok2 = c2;
                            else ng2 = c2;
                        }
                        cnt += ok2 - i;
                    }                
                }
                swap(stP,stN);
            }
            if(cnt >= K) ok = c;
            else ng = c;
        }
        cout << ok << endl;
    }
    return 0;
}