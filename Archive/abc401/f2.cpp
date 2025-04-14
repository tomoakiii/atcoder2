#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,h[N],cnt,h2[N],cnt2,d[N],d2[N],s[N],s2[N],ans[N],ans2[N],mp[N],mp2[N],nm[N],mx,mx2,al;
struct node{int next,to;}a[N<<1],b[N<<1];
void add(int x,int y){a[++cnt].to=y,a[cnt].next=h[x],h[x]=cnt;}
void add2(int x,int y){b[++cnt2].to=y,b[cnt2].next=h2[x],h2[x]=cnt2;}
void dfs(int x,int y)
{
	for(int i=h[x];i;i=a[i].next)
	{
		int k=a[i].to;
		if(k==y) continue;
		dfs(k,x);
		if(d[k]+1>s[x]){s[x]=d[k]+1;if(s[x]>d[x]) swap(s[x],d[x]);}
	}
}
void dfs2(int x,int y)
{
	for(int i=h2[x];i;i=b[i].next)
	{
		int k=b[i].to;
		if(k==y) continue;
		dfs2(k,x);
		if(d2[k]+1>s2[x]){s2[x]=d2[k]+1;if(s2[x]>d2[x]) swap(s2[x],d2[x]);}
	}
}
void dfs3(int x,int y)
{
	for(int i=h[x];i;i=a[i].next)
	{
		int k=a[i].to;
		if(k!=y) ans[k]=max(ans[x],(d[k]+1==d[x]?s[x]:d[x]))+1,dfs3(k,x);
	}
}
void dfs4(int x,int y)
{
	for(int i=h2[x];i;i=b[i].next)
	{
		int k=b[i].to;
		if(k!=y) ans2[k]=max(ans2[x],(d2[k]+1==d2[x]?s2[x]:d2[x]))+1,dfs4(k,x);
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n,mx=mx2=1;
	for(int x,y,i=1;i<n;i++) cin>>x>>y,add(x,y),add(y,x);cin>>m;
	for(int x,y,i=1;i<m;i++) cin>>x>>y,add2(x,y),add2(y,x);
	dfs(1,0),dfs2(1,0),dfs3(1,0),dfs4(1,0);
	for(int i=1;i<=n;i++) mp[max(ans[i],d[i])]++;
	for(int i=1;i<=m;i++) mp2[max(ans2[i],d2[i])]++;
	for(int i=m;i>=0;i--) nm[i]=nm[i+1]+mp2[i]*i;
	for(int i=1;i<=max(n,m);i++) mp2[i]+=mp2[i-1];
	while(1)
	{
		if(!d[mx]) break;
		for(int i=h[mx];i;i=a[i].next){int k=a[i].to;if(d[k]+1==d[mx]){mx=k;break;}}
	}
	while(1)
	{
		if(!d2[mx2]) break;
		for(int i=h2[mx2];i;i=b[i].next){int k=b[i].to;if(d2[k]+1==d2[mx2]){mx2=k;break;}}
	}
	memset(d,0,sizeof(d)),memset(d2,0,sizeof(d2));
	memset(s,0,sizeof(s)),memset(s2,0,sizeof(s2));
	dfs(mx,0),dfs2(mx2,0),mx=max(d[mx],d2[mx2]);
	for(int i=0;i<=n;i++)
	{
		if(i<mx) al+=mx*mp2[mx-i-1]*mp[i];
		al+=nm[max(0ll,mx-i)]*mp[i]+(mp2[m]-(mx-i-1<0?0:mp2[mx-i-1]))*mp[i]*(i+1);
	}
	cout<<al;
	return 0;
}