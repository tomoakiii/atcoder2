#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

const ll OFS = 2000001;
// const ll OFS = 3;

int main(){
    ll N, D;
    cin >> N >> D;
    vector<ll> x(N), y(N);
    rep(i, N) {
        cin >> x[i] >> y[i];
        x[i] += OFS;
        y[i] += OFS;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<ll> xd(3*OFS + 1, 0), yd(3*OFS + 1, 0);
    rep(i, N) {
        xd[0] += x[i];
        yd[0] += y[i];
    }
    int k=N;
    int j=0;
    for(int i=1; i<3*OFS + 1; i++) {
        for(;x[j]<i && j<N;j++){      
            k-=2;
        }
        xd[i] = xd[i-1] - k;        
    }
    k=N;
    j=0;
    for(int i=1; i<3*OFS + 1; i++) {
        for(;y[j]<i && j<N;j++){
            k-=2;
        }
        yd[i] = yd[i-1] - k;        
    }
    sort(xd.begin(), xd.end());
    sort(yd.begin(), yd.end());
    j=0;
    ll ans=0;
    for(int i=xd.size()-1; i>=0; i--) {
        while(xd[i] + yd[j] <= D) {
            j++;            
        }
        ans+=j;
    }
    cout << ans << endl;

    return 0;
}