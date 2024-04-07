#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

struct node{
    int i;
    vector<int> c;
    int p;
    int n;
};

int main(){
    int N, K;
    vector<set<int>> nw(N);
    vector<node> tr(N);
    int a, b;
    for (int i=0; i<N-1; i++){
        cin >> a >> b;
        nw[a].insert(b);
        nw[b].insert(a);        
    }
    tr[0].i = 0;
    tr[0].p = -1;
    queue<node> que;
    que.push(0);
    while(!que.empty()) {
        auto a = que.front();
        que.pop();
        for (int i = 0; nw[a].size(); i++){
            int nn = nw[a][i];
            if (tr[a].p == nn) continue;

            tr[a].c.push_back(nn);
        }
        
    }
    
    cin >> N >> K;
    dp[][]
    cout << endl;
    
    return 0;
}