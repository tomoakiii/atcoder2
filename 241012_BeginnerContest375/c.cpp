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
    ll N;
    cin >> N;
    vector<string> G(N);
    rep(i,N) cin>>G[i];
    
    rep(i, N/2) {
        vector<char> tmp(N*N);
        int ind = 0;
        int y, x;
        y = i;
        for(x = i; x < N-1-i; x++) tmp[ind++] = G[y][x];
        x = N-1-i;
        for(y = i; y < N-1-i; y++) tmp[ind++] = G[y][x];
        y = N-1-i;
        for(x = N-1-i; x>i; x--) tmp[ind++] = G[y][x];
        x = i;
        for(y = N-1-i; y>i; y--) tmp[ind++] = G[y][x];                

        ind = 0;
        if(i%4 == 3){       
          // nothing to do                
        } else if (i%4 == 0) {            
            x = N-1-i;
            for(y = i; y < N-1-i; y++) G[y][x] = tmp[ind++];
            y = N-1-i;
            for(x = N-1-i; x>i; x--) G[y][x] = tmp[ind++];
            x = i;
            for(y = N-1-i; y>i; y--) G[y][x] = tmp[ind++];
            y = i;
            for(x = i; x < N-1-i; x++) G[y][x] = tmp[ind++];
        } else if (i%4 == 1){
            y = N-1-i;
            for(x = N-1-i; x>i; x--) G[y][x] = tmp[ind++];
            x = i;
            for(y = N-1-i; y>i; y--) G[y][x] = tmp[ind++];
            y = i;
            for(x = i; x < N-1-i; x++) G[y][x] = tmp[ind++];
            x = N-1-i;
            for(y = i; y < N-1-i; y++) G[y][x] = tmp[ind++];            
        } else if (i%4 == 2){
            x = i;
            for(y = N-1-i; y>i; y--) G[y][x] = tmp[ind++];
            y = i;
            for(x = i; x < N-1-i; x++) G[y][x] = tmp[ind++];
            x = N-1-i;
            for(y = i; y < N-1-i; y++) G[y][x] = tmp[ind++];
            y = N-1-i;
            for(x = N-1-i; x>i; x--) G[y][x] = tmp[ind++];

        }


    }

    rep(i,N) cout<<G[i]<<endl;
    return 0;
}


