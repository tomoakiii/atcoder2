#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, T, M;
    cin >> N >> T >> M;
    vector AB(N, vector<int>{});
    int a, b;
    for (int i=0; i<M; i++){
        cin >> a >> b;
        a--, b--;
        AB[a].push_back(b);
        AB[b].push_back(a);
    }
    
    ll cnt = 0;
    // ll call = 0;
    auto func = [&](auto func, int i, int j, vector<vector<bool>> vT) -> void{
        vT[j][i] = true;
        int nx = i+1;
        if (nx == N){
            if (vT.size() != T){
                return;
            }
            cnt++;
            return;
        } 
        for(int nj = 0; nj < vT.size(); nj++){
            // call++;
            // cout << call << endl;
            bool flg = true;
            for (auto t : AB[nx]){ // nxをいれてはいけない人                
                if (vT[nj][t]) {
                    flg = false;
                    break;
                }
            }
            if(flg) {
                func(func, nx, nj, vT);
            } else {
                continue;
            }
        }
        if(vT.size() < T){
            vT.push_back(vector<bool>(10, false));
            func(func, nx, vT.size()-1, vT);
        } else {
            return;
        }
    };    
    
    vector<vector<bool>> TM{};
    TM.push_back(vector<bool>(10, false));
    func(func, 0, 0, TM);

    cout << cnt << endl;
    return 0;
}