#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    ll H, W;
    int N;
    cin >> H >> W >> N;
    vector<pair<int, int>> cd(N);
    map<ll, vector<int>> row, col;
    ll a, b;
    for (int i=0; i<N; i++){
        cin >> a >> b;
        row[a].push_back(i);
        col[b].push_back(i);
        cd[i].first = a;
        cd[i].second = b;
    }
    int cr = 1;
    for (auto r:row){
        for (auto i: r.second) {
            cd[i].first = cr;
        }
        cr++;
    }

    int cc = 1;
    for (auto c:col){
        for (auto i: c.second) {
            cd[i].second = cc;
        }
        cc++;
    }

    for (int i=0; i<N; i++){
        cout << cd[i].first << " " << cd[i].second << endl;
    }
    return 0;
}

