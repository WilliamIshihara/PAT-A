#include <cstdio>
#include <algorithm>
using namespace std;
//图的深度优先遍历
//每个点找最短连通
int m,n,k;
int visit[1010];
int road[1010][1010] = {0};

//深度优先遍历 
void dfs(int r){
	visit[r]=1;
	for(int i=1;i<=m;i++){
		if(road[i][r]==1&&visit[i]!=1){
			dfs(i);
		}
	}
}



int main(){
	
	scanf("%d%d%d", &m, &n, &k);
	int road1,road2;
	for(int i=0;i<n;i++){
		scanf("%d%d", &road1, &road2);
		road[road1][road2] = road[road2][road1] = 1;
	}
	int occupied;
	for(int i=0;i<k;i++){
		fill(visit, visit + 1010, 0);
		scanf("%d", &occupied);
		int repair = 0;
		visit[occupied] = 1;
		for(int i=1;i<m+1;i++){
			if(visit[i]==0){
				dfs(i);
				repair++;
			}
		}
		printf("%d\n", repair - 1);
		//visit[occupied] = 0;
	}
	return 0;
}
