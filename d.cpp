#include<bits/stdc++.h>
using namespace std;

int Q[300003],tot,s[300003],ans;
bool vis[300003],op[300003];
long long dis[300003];

struct edge{int v,c,n,num;}e[300003<<1];
#define Push(u,v,c,n) push(u,v,c,n),push(v,u,c,n)
inline void push(int u,int v,int c,int num){e[++tot]=(edge){v,c,s[u],num};s[u]=tot;}
inline void bfs()
{
	deque<int> Q;
	Q.push_back(1);
	dis[1]=0; 
	while (!Q.empty())
	{
		int h=Q.front();Q.pop_front();
		vis[h]=0;
		for (int i=s[h];i;i=e[i].n) if (dis[e[i].v]>dis[h]+e[i].c)
		{
			dis[e[i].v]=dis[h]+e[i].c;
			if (!vis[e[i].v])
			{
				vis[e[i].v]=1;
				if (Q.empty()||dis[e[i].v]<=dis[Q.front()]) Q.push_front(e[i].v);
				else Q.push_back(e[i].v);
			}
		}
	}
}

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++)
	{	
		int u,v,c;
		cin >> u >> v >> c;
		Push(u,v,c,i);
	}
	bfs();
	vis[1]=1;
	Q[1]=1;
	for (int l=1,r=1;l<=r;l++) for (int i=s[Q[l]];i && ans<k;i=e[i].n) if (dis[e[i].v]==dis[Q[l]]+e[i].c && !vis[e[i].v])
	{
		vis[Q[++r]=e[i].v]=1;
		op[e[i].num]=1;
		ans++;
	}
	cout << ans << endl;
	for (int i=1;ans;i++) if (op[e[i].num])
	{
		printf("%d%c",e[i].num,--ans?' ':'\n');
		op[e[i].num]=0;
	}
}