#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> node(3e5+1);
vector<bool> vis(3e5+1, false);

int weight(int a){
    vis[a] = true;
    int w=1;
    for (auto b: node[a]){
        if (!vis[b]){
            w += weight(b);
        }
    }
    return w;
}


int main()
{
    long long N;
    cin >> N;
    for (int i = 0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    vector<int> w0(node[1].size());
    vis[1]=true;
    for (int i = 0; i < node[1].size(); i++){
        w0[i] = weight(node[1][i]);
    }
    sort(w0.begin(), w0.end());
    
    int cnt = 0;
    for (int i = 0; i < w0.size()-1; i++){
        cnt += w0[i];
    }

    cout << cnt+1 << endl;

 	return 0;
}