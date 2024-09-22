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
    int N, K;
    vector<int> arr(N*K);
    int cnt=0;
    rep(i,N) rep(j,K) {        
        arr[cnt++] = i;
    }
    cnt = 0;
    do{
        cnt++;
        if (cnt == ())
    }while(next_permutation(arr.begin(), arr.end()))


    return 0;
}