#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{    
    int H, W;
    cin >> H >> W;    
    vector<string> S(H);    
    vector<map<char, int>> row(H), col(W);
    vector<map<char, vector<int>>> rowi(H), coli(W);
    vector<vector<char>> rv(H, vector<char>{}), cv(W, vector<char>{});
    for (int i=0; i<H; i++){
        cin >> S[i];
        for (int j=0; j<W; j++){
            char c = S[i][j];
            row[i][c]++;
            col[j][c]++;
            rowi[i][c].push_back(j);
            coli[j][c].push_back(i);
        }
    }
        

    while(true){
        queue<int> rq;
        queue<int> cq;
        bool flg = false;
        for (int i=0; i<H; i++){
            if (row[i].size() == 1){                
                char c = row[i].begin()->first;
                if (row[i][c] == 1) continue;
                flg = true;
                rq.push(i);
            }
        }
        for (int j=0; j<W; j++){
            if (col[j].size() == 1){                
                char c = col[j].begin()->first;
                if (col[j][c] == 1) continue;
                flg = true;
                cq.push(j);
            }
        }

        while (!rq.empty()){
            int i = rq.front();
            char c = row[i].begin()->first;
            rq.pop();
            row[i].erase(c);            
            for (auto j: rowi[i][c]){
                if (col[j].size() > 0){                    
                    col[j][c]--;
                    if (col[j][c] <= 0){
                        col[j].erase(c);
                    }
                }
            }
        }
            

        while (!cq.empty()){
            int j = cq.front();
            char c = col[j].begin()->first;
            cq.pop();
            col[j].erase(c);                
            for (auto i: coli[j][c]){
                if (row[i].size() > 0){
                    row[i][c]--;
                    if (row[i][c] <= 0){
                        row[i].erase(c);
                    }
                }
            }
        }

        if (!flg) break;
    }
    
    int sm = 0;
    for (auto r: row){
        for (auto x: r){
            sm += x.second;
        }
    }

    cout << sm << endl;
    return 0;
}