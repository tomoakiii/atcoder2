#include<bits/stdc++.h>
#define int long long
using namespace std;

const int p = 998244353,
d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,tot[1005][1005],cnt,cnt1,s;
char c[1005][1005];
void dfs(int x,int y,int z){
	tot[x][y]=z;
	for(int i=0;i<4;i++){
		int dx=x+d[i][0],dy=y+d[i][1];
		if(c[dx][dy]=='#'&&tot[dx][dy]==0)
			dfs(dx,dy,z);
	}
}
int qm(int y,int x){
	for(int tmp=p-2;tmp;tmp/=2){
		if(tmp&1){
			y*=x;
			y%=p;
		}
		x*=x;
		x%=p;
	}
	return y;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(tot[i][j]==0&&c[i][j]=='#')
				dfs(i,j,++cnt);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(tot[i][j]==0){
				++cnt1;set<int> x;
				for(int k=0;k<4;k++){
					int dx=i+d[k][0],dy=j+d[k][1];
					if(tot[dx][dy]!=0)
						x.insert(tot[dx][dy]);
				}
				s+=cnt-x.size()+1;
			}
		}
	printf("%lld",qm(s,cnt1));
}