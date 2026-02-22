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
    ll M,A,B;
    cin >> M >> A >> B;
    ll ans = 0;
    vector success(M+1, vector<bool>(M+1));
    vector fail(M+1, vector<bool>(M+1));
    vector visit(M+1, vector<bool>(M+1));
    for(ll x = 1; x <= M-1 ; x++) for(ll y = 1; y <= M-1 ; y++) {
        ll s1 = x, s2 = y;
        if(success[s1][s2]) {
            ans++;
            continue;
        }
        if(fail[s1][s2]) {
            continue;
        }
        vector<pair<int,int>> tmp;
        tmp.push_back({s1,s2});
        visit[s1][s2] = true;
        ll s3 = A * s2 + B * s1;
        s3 %= M;
        bool flg = true;
        auto op_f = [&]()->void{
            for(auto [i,j]: tmp) {
                fail[i][j] = true;
                visit[i][j] = false;
            }
        };
        auto op_s = [&]()->void{
            for(auto [i,j]: tmp) {
                success[i][j] = true;
                visit[i][j] = false;
            }
        };
        if(s3 == 0) {
            flg = false;
            op_f();
            continue;
        }
        while(!visit[s2][s3]) {
            tmp.push_back({s2,s3});
            visit[s2][s3] = true;
            s1 = s2;
            s2 = s3;
            s3 = A * s2 + B * s1;
            s3 %= M;
            if(s3 == 0) {
                flg = false;
                op_f();
                break;
            }
        }
        if(flg) {
            op_s();
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}