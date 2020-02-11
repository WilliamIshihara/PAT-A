
//date:2020.02.10
//author:ViViWilliam
//issue3
#include<iostream> 
using namespace std;
int main(){
	//城市数,道路数,所在地,目的地 
	int N,M,c1,c2; 
	cin>>N>>M>>c1>>c2;
	int team[N]={0};
	int road[N][N];
	int length[N]={0};
	int teamsum[N]={0};
	int min[N]={0},sum;
	sum=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			road[i][j]=10000;
		}
	}
	for(int i=0;i<N;i++){
		cin>>team[i];
	}
	
	for(int i=0;i<M;i++){
		int x,y; 
		cin>>x;
		cin>>y;
		cin>>road[x][y];
		road[y][x] = road[x][y];
	}
	
	for(int i=0;i<N;i++){
		length[i]=road[c1][i];
		if(road[c1][i]!=10000){
		teamsum[i] = team[i]+team[c1];
			min[i]=1;
		}
				
	}
	length[c1]=0;
	min[c1]=1;
	teamsum[c1] = team[c1];
	
	int last,lastnum;
	int i;
	int h[N]={0};
	h[c1]=1;
	int a=0;
//	for(int d=0;d<N;d++){
//		cout<<min[d]<<" ";
//	}
//	cout<<endl;
//	cout<<teamsum[c2]<<endl;
	
	while(1){
		
		int minid=10000,minro=10000;
		//找到一个起始点 
		for(int d=0;d<N;d++){
			if (h[d]==0){
				minid=d;
				minro=length[d];
				break;
			}
		}
		//所有点都遍历完 
		if(minid==10000)
		break;
		//找出最小值,作为起点 
		for(int m=0;m<N;m++){
			if(h[m]==0&&length[m]<minro){
				minid = m;
				minro = length[m];
			}
		}
		h[minid]=1;
		i = minid;
			if(i == c1){
				continue;
			}
			//依次排查 
			for(int j=0;j<N;j++){
				if(h[j] == 0 && road[i][j] != 10000){
				
				if(j==c1)
					continue;
				//如果当前位置的长度加上此位置到某点的位置小于等于 
				if((length[i]+road[i][j])<=length[j]){

					//如果小于,总的 					
						if((length[i]+road[i][j])<length[j]){
							teamsum[j] = teamsum[i]+team[j];
							length[j] = length[i]+road[i][j];
							min[j] = min[i];
//							sum = teamsum[j];
						}
						else if(length[i]+road[i][j]==length[j]){
							min[j]+=min[i];
							if(teamsum[j]<(teamsum[i]+team[j])){
							teamsum[j]=teamsum[i]+team[j];
						}
						
					
				}	
		    }
		    }
			}
//		    cout<<"i="<<i<<endl;
//		for(int c=0;c<N;c++){
//			cout<<c<<":"<<length[c]<<":"<<min[c]<<":"<<teamsum[c2]<<endl;
//		}

	} 
//if(c1==c2){
//	cout<<"1"<<" "<<team[c2];
//}
//else
	cout<<min[c2]<<" "<<teamsum[c2];
return 0; 
}






//date:2020.01.17
//author:ViViWilliam
//
//#include<iostream>
//using namespace std;
///*
//input: N:城市数,M:道路数
//       M排,每一排为c1,c2,length,两城市之间的距离
//output:从零点到每个城市的最短距离和最短路径 
//
//*/ 
//int main(){
//	int n,m,c1,c2;
//	cin>>n>>m;
//	//记录原始地图信息 
//	int map[n][n];
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			map[i][j] = 1000;
//		}
//	}
//	//记录每个点的最短距离
//	int minLength[n]={1000}; 
//	//记录到该点的最短距离的路径
//	int lenmap[n][n];
//		for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			lenmap[i][j] = 1000;
//		}
//	} 
//	//记录每个位置是否访问完 
//	int visit[n]={0};
//	visit[0] = 1; 
//	for(int i=0;i<n;i++){
//		map[i][i] = 0;
//	}
//	
//	for(int i=0;i<m;i++){
//		cin>>c1>>c2;
//		cin>>map[c1][c2];
//	}
//	//首先把最短路径设置成原点的路径信息
//	for(int i=0;i<n;i++){
//		minLength[i] = map[0][i];
//	} 
//	
//	for(int i=0;i<n;i++){
//		cout<<minLength[i]<<" ";
//	}
//	cout<<endl;
//	//一直到所有记录都访问完 
//	while(1){
//		int wite = 1000;
//		int site = 0;
//		for(int i=0;i<n;i++){
//			if(visit[i]==0&&minLength[i]<wite){
//				wite = minLength[i];
//				site = i;
//			}
//		}
//		visit[site] = 1;
//		for(int i=0;i<n;i++){
//			if((wite+map[site][i])<minLength[i]){
//				minLength[i] = wite+map[site][i];
//				visit[i] = 0;  
//			}
//		}
//		int u=0;
//		for(int i=0;i<n;i++){
//			if(visit[i]==0){
//				u++;
//			}
//		}
//		if(u==0)
//		break;
//	}
//	for(int i=0;i<n;i++){
//		cout<<"到"<<i<<"最短路径为:";
//		cout<<minLength[i]<<endl; 
//	}
//	
//} 

/*
6 8
0 2 10
0 5 100
0 4 30
1 2 5
2 3 50
3 5 10
4 3 20
4 5 60
0 1000 10 1000 30 100
*/
