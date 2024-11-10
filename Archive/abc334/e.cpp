#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long pow(long long a, long long n){
    long long ret=1;
    for(; n>0; n>>=1, a=a*a % MOD ){
        if(n % 2 == 1){
            ret = ret * a % MOD;
        }
    }
    return ret;
}

long long modinv(long long a){
    return pow(a, MOD - 2);
}


vector<vector<int>> S;
int d[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
void dfs(int y,int x,int z){
	S[y][x] = z;
	for(int i=0; i<4; i++){
		int dy = y + d[i][0], dx = x + d[i][1];
		if(S[dy][dx] == 0){
			dfs(dy, dx, z);
        }
	}
}

long long qm(long long y, long long x){
	for(long long tmp=MOD-2;tmp;tmp/=2){
		if(tmp&1){
			y*=x;
			y%=MOD;
		}
		x*=x;
		x%=MOD;
	}
	return y;
}


int main(){
    int H, W;
    cin >> H >> W;
    long long acnt = 0, dcnt = 0;
    S.resize(H+2, vector<int>(W+2, -1));
    for(int h=1;h<=H;h++) for(int w=1;w<=W;w++){
        char ctmp;
        cin >> ctmp;
        if (ctmp == '.'){
            dcnt++;
            S[h][w] = -1;
        } else {
            S[h][w] = 0;
        }
    }
    int ind=0;
    int y,x;
    for(int h=1;h<=H;h++) for(int w=1;w<=W;w++){
        if (S[h][w] == 0){
            dfs(h, w, ++ind);
        }
    }
    for(int h=1;h<=H;h++) for(int w=1;w<=W;w++){
        if (S[h][w] == -1){
            set<int> s;
            for (int i=0; i<4; i++){
                y=h+d[i][0];
                x=w+d[i][1];
                if (S[y][x] > 0){
                    s.insert(S[y][x]);
                }
            }
            acnt += ind - (s.size() - 1); // 0->1, 2->0, 3->-1, 1->0
        }
    }
//    acnt = (acnt * modinv(dcnt)) % MOD;
    acnt = qm(acnt, dcnt);
    cout << acnt << endl;
    return 0;
}