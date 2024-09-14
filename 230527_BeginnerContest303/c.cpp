#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    int x,y;
    map<pair<int,int>, bool> mp;
    rep(i,M) {
        cin>>x>>y;
        mp[{x,y}]=true;
    }
    int curX=0, curY=0;
    ll pwr=H;
    rep(i,N){
        int nx=0,ny=0;
        if(S[i] == 'R') nx=1;
        if(S[i] == 'L') nx=-1;
        if(S[i] == 'U') ny=1;
        if(S[i] == 'D') ny=-1;
        curX += nx;
        curY += ny;
        pwr--;
        if(pwr<0) {
            cout << "No" << endl;
            return 0;
        }
        if (pwr<K) {
            if(mp.find({curX, curY}) != mp.end()){
                if(mp[{curX, curY}]) {
                    mp[{curX, curY}] = false;
                    pwr = K;
                }
            }
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}