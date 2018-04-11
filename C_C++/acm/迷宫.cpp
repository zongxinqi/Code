#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const LL maxn = 0x3f3f3f;
const int N = 5;
int Maze[5][5];
pair<int,int> path[N][N];
const int BLOCK = 1;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
inline bool isLegal(int x,int y)
{
	return x >= 0 && y >= 0 && x < N && y < N && !Maze[x][y];
}
template<typename T>
inline bool equ(T t1,T t2){return t1 == t2;}
void bfs(int sx = 0,int  sy = 0,int ex = 4,int ey = 4)
{
	queue<pair<int,int> > qu;
	qu.push(make_pair(ex,ey));
	path[ex][ey] = make_pair(-1,-1);
	Maze[ex][ey] = BLOCK;
	while(!qu.empty())
	{
		pair<int,int> fa = qu.front();
		qu.pop();
		for(int i = 0;i < 4;i++)
		{
			int nx = dx[i] + fa.first,ny = dy[i] + fa.second;
			if(!isLegal(nx,ny)) continue;
			path[nx][ny] = fa;
			if(equ(nx,sx)&&equ(ny,sy))	return;
			qu.push(make_pair(nx,ny));
			Maze[nx][ny] = BLOCK;
		}	
	} 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j< N;j++)
		{
			cin>>Maze[i][j];
		}
	}
	bfs();
	int x = 0,y = 0;
	while(x != -1)
	{
		cout<<"("<<x<<","<<y<<")"<<"->";
		int nx = path[x][y].first;
		int ny = path[x][y].second;
		x = nx, y = ny;	
	} 
	return 0;
}
