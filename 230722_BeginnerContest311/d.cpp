#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector G(N, vector<ll>(M, 0));
    vector<string> S(N);
    for(int i=0; i<N;i++) {        
        cin>>S[i];        
    }
    ll lk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};    
    auto func=[&](auto func, ll y, ll x)->void{
        G[y][x] = 2;        
        for(int i=0; i<4; i++){
            ll ny=y, nx=x;
            while(true){
                ny += lk[i][0];
                nx += lk[i][1];                
                if (S[ny][nx] == '#'){
                    if(G[ny-lk[i][0]][nx-lk[i][1]] != 2){
                        func(func, ny-lk[i][0], nx-lk[i][1]);
                    }
                    break;
                }
                G[ny][nx] = max(G[ny][nx], ll(1));     
            }
        }
    };
    func(func, 1, 1);
    ll cnt=0;
    for(ll i=0; i<N; i++){
        for(ll j=0; j<M; j++){
            if(G[i][j]>0) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}