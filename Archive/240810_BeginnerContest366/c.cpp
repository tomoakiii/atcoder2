#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll Q;
    cin >> Q;
    map<ll, int> mp;
    int cnt=0;
    while(Q--){
        int p;
        ll x;
        cin >> p;
        if(p==1) {
            cin >> x;
            mp[x]++;
            if(mp[x] == 1) cnt++;
        }
        if(p==2) {
            cin >> x;
            if(mp[x] == 1) {
                cnt--;
                mp[x] = 0;
            } else {
                mp[x]--;
            }
        }
        if (p==3) {
            cout << cnt << endl;
        }
    }    
    
    return 0;
}