#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main() {
    int N, M;
    cin >> N >> M;
    vector S(N, vector<int>(M));
    string s;
    vector nm(N, vector<bool>(10, false));
    for (int i=0; i<N; i++){
        cin>>s;
        for(int j=0; j<M; j++){
            S[i][j] = s[j] - '0';
            nm[i][S[i][j]] = true;
        }
    }    
    ll mn = INF;
    for(int i=0; i<10; i++){
        bool flg = true;
        for (int j = 0; j < N; j++){
            if (!nm[j][i]) flg = false;
        }
        if (!flg) continue;        
        auto func = [&](auto func, int a, ll cnt, vector<bool> v) -> ll {
            ll nc = INF;
            while(true){
                for (int j = 0; j < N; j++){
                    if (!v[j] && S[j][cnt%M]==i){
                        auto v2 = v;
                        v2[j] = true;                        
                        if(a == N-1) {
                            return cnt;
                        }
                        else {
                            nc = min(nc, func(func, a+1, cnt+1, v2));
                        }                        
                    }
                }
                if (nc != INF) return nc;
                cnt++;
            }
        };        
        vector<bool> visit(N, false);
        mn = min(func(func, 0, 0, visit), mn);
    }
    if (mn == INF) mn = -1;
    cout << mn << endl;
    return 0;
}