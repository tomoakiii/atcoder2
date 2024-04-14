#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    vector<vector<ll>> A(3, vector<ll>(3)));
    for(int i=0; i<3; i++)for(int j=0; j<3; j++){cin>>A[i][j];}    
    map<vector<vector<ll>>, int> mp;
    vector<vector<ll>> C(3, vector<ll>(3)));        


    auto [&A]game(auto game, vector<vector<ll>> C, int turn) -> int {
        for(int i=0; i<3; i++)for(int j=0; j<3; j++){
            C2 = C;
            if (C[i][j]==0) {
                C2[i][j] = turn;
                bool isW=false;
                for(int i2=0; i2<3; i2++){
                    isW |= (C2[i2][0]==turn) || (C2[i2][1]==turn) || (C2[i2][2]==turn);
                    isW |= (C2[0][i2]==turn) || (C2[1][i2]==turn) || (C2[2][i2]==turn);
                }
                isW |= (C2[0][0]==turn) || (C2[1][1]==turn) || (C2[2][2]==turn);
                isW |= (C2[0][2]==turn) || (C2[1][1]==turn) || (C2[2][0]==turn);
                if (isW) return turn;
                else game(game, C, ((turn==1)?2:1));
            }            
        }
    }
    int turn = 1;
    game(game, C, turn);
    return 0;
}
