#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0f0F0F0F;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> to(N);
    int a, b;
    for (int i=0; i<N-1; i++){
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for (auto &t : to){
        sort(t.begin(), t.end());
    }    
    auto step = [&](auto step, int cur, int par) -> void {
        cout << cur+1 << ' ';
        for (auto mn : to[cur]) {
            if (mn == par) continue;
            step(step, mn, cur);
            cout << cur+1 << ' ';
        }
    };
    step(step, 0, -1);
    return 0;
}

