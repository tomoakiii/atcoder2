#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
#define ASIZE 102
// #define ASIZE 5

int main(){
    ll N;
    cin >> N;
    int G[ASIZE][ASIZE][ASIZE];
    for(auto &a:G)for(auto &b:a)for(auto &c:b) c=-1;
    int X, Y, Z, X2, Y2, Z2;
    vector<int> vX(N), vY(N), vZ(N), vX2(N), vY2(N), vZ2(N);
    for(int i=0; i<N;i++) {
        cin >> X >> Y >> Z >> X2 >> Y2 >> Z2;
        X++, Y++, Z++, X2++, Y2++, Z2++;
        vX[i] = X; vX2[i] = X2; vY[i] = Y; vY2[i] = Y2; vZ[i] = Z; vZ2[i] = Z2;
        for(int x=X; x<X2; x+=max(1, X2-X-1)) for(int y=Y; y<Y2; y++) for(int z=Z; z<Z2; z++) G[x][y][z] = i;
        for(int y=Y; y<Y2; y+=max(1, Y2-Y-1)) for(int x=X; x<X2; x++) for(int z=Z; z<Z2; z++) G[x][y][z] = i;
        for(int z=Z; z<Z2; z+=max(1, Z2-Z-1)) for(int x=X; x<X2; x++) for(int y=Y; y<Y2; y++) G[x][y][z] = i;
        
    }

    for(int i=0; i<N;i++) {            
        X=vX[i]; X2=vX2[i]; Y=vY[i]; Y2 = vY2[i]; Z = vZ[i]; Z2 = vZ2[i];
        set<int> v;
        for(int x=X-1; x<=X2; x+=X2-X+1) for(int y=Y; y<Y2; y++) for(int z=Z; z<Z2; z++) if(G[x][y][z] != -1) v.insert(G[x][y][z]);
        for(int y=Y-1; y<=Y2; y+=Y2-Y+1) for(int x=X; x<X2; x++) for(int z=Z; z<Z2; z++) if(G[x][y][z] != -1) v.insert(G[x][y][z]);
        for(int z=Z-1; z<=Z2; z+=Z2-Z+1) for(int x=X; x<X2; x++) for(int y=Y; y<Y2; y++) if(G[x][y][z] != -1) v.insert(G[x][y][z]);
        cout << v.size() << endl;
    }
    
    return 0;
}