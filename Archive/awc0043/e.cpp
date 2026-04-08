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
typedef modint1000000007 mint;

/*
int main(){
    vector<ll> sm(1001);
    for(int kk=1; kk<=1000; kk++) {
        int k=kk;
        int last = k%10;
        k/=10;
        bool flg=false;
        if(last==0) flg=true;
        while(k) {
            int d=k%10;
            sm[kk]+=abs(d-last);
            k/=10;
            last=d;
            if(last==0) flg=true;
        }
        if(flg)sm[kk]*=2;
    }
    rep(i,1000) sm[i+1]+=sm[i];
    rep(i,1001) cout<<i<<" "<<sm[i]<<endl;
    return 0;
}
*/



int main(){
    string s; cin>>s;
    int M=s.size();
    vector<int> S(M);
    rep(i,M) S[i]=s[i]-'0';
    vector dp(2, vector(2, vector<mint>(10,0)));
    vector cnt(2, vector(2, vector<ll>(10,0)));

    for(int i=1; i<S[0]; i++) cnt[0][1][i] = 1;
    cnt[0][0][S[0]]=1;
    for(int d=1; d<M; d++) {
        vector dp_new(2, vector(2, vector<mint>(10)));
        vector cnt_new(2, vector(2, vector<ll>(10,0)));
        rep(i,2) {
            rep(j,2) {
                rep(k,10) {
                    if(cnt[i][j][k]==0) continue;
                    auto update = [&](int x, int y, int z)->void {
                        dp_new[x][y][z] += dp[i][j][k] + abs(k-z) * cnt[i][j][k];
                        cnt_new[x][y][z] += cnt[i][j][k];
                        /*
                        cerr<<d<<":::"<<x<<" "<<y<<" "<<z<<"---"<<i<<" "<<j<<" "<<k<<endl;
                        cerr<<dp_new[x][y][z].val()<<" "<<dp[i][j][k].val()<<endl;
                        */
                    };
                    rep(p,10) {
                        int ni=i;
                        if(p==0) ni=1;
                        if(j==0) { // from even condition
                            if(p==S[d]) update(ni, 0, p);
                            else if(p < S[d]) update(ni, 1, p);
                        } else {
                            update(ni, 1, p);
                        }
                    }
                }
            }
        }
        for(int k=1;k<=9;k++) cnt_new[0][1][k]++;

        swap(dp, dp_new);
        swap(cnt, cnt_new);
    }
    mint ans = 0;
    rep(j,2)rep(k,10) {
        // cerr<<j<<" "<<k<<"---"<<dp[0][j][k].val()<<dp[1][j][k].val()<<endl;
        ans+=dp[0][j][k];
        ans+=2*dp[1][j][k];
    }
    cout<<ans.val()<<endl;
    return 0;
}