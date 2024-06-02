#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    vector<vector<ll>> A(3, vector<ll>(3));
    for(int i=0; i<3; i++)for(int j=0; j<3; j++) cin>>A[i][j];
    auto game = [&](auto game, vector<vector<ll>> C, bool turn, pair<ll, ll> score) -> bool {
        vector<pair<int, int>> ij;        
        for(int i=0; i<3; i++)for(int j=0; j<3; j++){
            if (C[i][j]==0) ij.push_back({i, j});
        }
        if (ij.size() == 0) {
            if (score.first > score.second) return true;
            else return false;
        }        
        ll me = (int)turn + 1; // Takahashi 1, Aoki 2;
        for(auto i:ij) {
            auto C2 = C;
            C2[i.first][i.second] = me;
            bool isW=false;
            for(int i=0; i<3; i++){
                isW |= ((C2[i][0]==me) && (C2[i][1]==me) && (C2[i][2]==me));
                isW |= ((C2[0][i]==me) && (C2[1][i]==me) && (C2[2][i]==me));
            }
            isW |= ((C2[0][0]==me) && (C2[1][1]==me) && (C2[2][2]==me));
            isW |= ((C2[0][2]==me) && (C2[1][1]==me) && (C2[2][0]==me));
            if (isW) return turn;
        }

        bool anywin = !turn;
        for(auto i:ij) {
            auto C2 = C;
            C2[i.first][i.second] = me;
            auto sc = score;
            if (turn) sc.first += A[i.first][i.second];
            else sc.second += A[i.first][i.second];
            if(i.first == 1 && i.second == 1){
                int x;
                x=0;
            }
            bool re = game(game, C2, !turn, sc);
            if (re == turn) anywin = turn;
        }
        return anywin;
    };
    vector<vector<ll>> C(3, vector<ll>(3));
    pair<ll, ll> sc = {0, 0};    
    cout << (game(game, C, true, sc)?"Takahashi":"Aoki") << endl;
    return 0;
}
