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

ll solve(){
    ll A,B,X,Y;
    cin>>A>>B>>X>>Y;
    X=abs(X), Y=abs(Y);
    ll ans=0;
    ll P;
    auto func = [](ll p, ll a, ll b)->ll{
        ll ret = 0;
        if(a*3<=b) {
            if(p%2==0) {
                ret += 2*a*p;
            } else {
                p--;
                ret += 2*a*p;
                ret += 3*a;
            }
        } else {
            ll d = (p+1)/2;
            ret += d*b;
            ll e = p/2;
            ret += e*a;
        }
        return ret;
    };
    if(A<=B) {
        if(Y<=X) {
            ans+=2*Y*A;
            P=X-Y;
            if(P==0) return ans;
            P--;
            ans+=A;
        } else {
            ans += 2*X*A;
            P=Y-X;
        }
        if(P==0){
            return ans;
        }
        ans += func(P,A,B);
        return ans;
    } else {
        if(X<=Y){
            ans += 2*X*B;
            P = Y-X;
            if(P==0) return ans;
            P--;
            ans+=B;
        } else {
            ans += 2*Y*B;
            P = X-Y;
        }
        if(P==0) return ans;
        ans += func(P,B,A);
        return ans;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    rep(i,N) {
        cout <<solve() << endl;
    }
    return 0;
}