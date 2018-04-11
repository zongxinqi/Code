#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100;
int v,w,n;
int final[maxn] = {0};
int D[maxn];
int arcs[maxn][maxn];
void Dij()
{
	for(w = 0;w < n;w++)
	D[w] = arcs[0][w];
	final[0] = 1;
	for(int i = 1;i < n;i++)
	{
		int minn = maxn;
		for(w = 0;w < n;w++)
		{
			if(!final[w])
			{
				if(D[w] < minn)
				{
					minn = D[w];
					v = w;
				}
			}
		}
		final[v] = 1;
		for(w = 0;w < n;w++)
		{
			if(!final[w]&&(minn + arcs[v][w] < D[w]))
			D[w] = minn + arcs[v][w];	
		} 
	}
}
int main()
{
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		cin>>arcs[i][j]; 
	}
	Dij();
	for(int i = 0;i < n;i++)
	cout<<i<<" "<<D[i]<<endl; 
	return 0;	
} 
