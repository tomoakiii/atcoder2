#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    vector<vector<ll>> A(3, vector<ll>(3));
    for(int i=0; i<3; i++)for(int j=0; j<3; j++) cin>>A[i][j];    
    vector<vector<ll>> C(3, vector<ll>(3));

    auto game = [&A](auto game, vector<vector<ll>> C, int turn) -> int {
        int aturn = ((turn==1)?2:1);        
        vector<pair<int, int>> ij;        
        for(int i=0; i<3; i++)for(int j=0; j<3; j++){
            if (C[i][j]==0) ij.push_back({i, j});
        }
        int whoW;
        bool amIwin = false;
        for(auto i:ij) {
            auto C2 = C;
            C2[i.first][i.second] = turn;
            bool isW=false;
            for(int i=0; i<3; i++){
                isW |= ((C2[i][0]==turn) && (C2[i][1]==turn) && (C2[i][2]==turn));
                isW |= ((C2[0][i]==turn) && (C2[1][i]==turn) && (C2[2][i]==turn));
            }
            isW |= ((C2[0][0]==turn) && (C2[1][1]==turn) && (C2[2][2]==turn));
            isW |= ((C2[0][2]==turn) && (C2[1][1]==turn) && (C2[2][0]==turn));
            if (isW) {
                amIwin = true;
                break;
            };

            bool isCon = false;
            ll sm[3] = {0, 0, 0};
            for(int i=0; i<3; i++)for(int j=0; j<3; j++){
                if (C[i][j] == 0) {
                    isCon = true;
                    break;
                }
                sm[C[i][j]]++;
            }
            int w;
            if (!isCon){
                if(sm[turn] > sm[aturn]) w=turn;
                else aturn;
            } else {
                w = game(game, C, aturn);
            }
            if (w==turn) return turn;
            else continue;            
        }
        return aturn;
    };
    int turn = 1;
    cout << ((game(game, C, turn)==1)?"Takahashi":"Aoki") << endl;
    return 0;
}
