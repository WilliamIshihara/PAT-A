
//date:2020.02.10
//author:ViViWilliam
//issue3
#include<iostream> 
using namespace std;
int main(){
	//������,��·��,���ڵ�,Ŀ�ĵ� 
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
		//�ҵ�һ����ʼ�� 
		for(int d=0;d<N;d++){
			if (h[d]==0){
				minid=d;
				minro=length[d];
				break;
			}
		}
		//���е㶼������ 
		if(minid==10000)
		break;
		//�ҳ���Сֵ,��Ϊ��� 
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
			//�����Ų� 
			for(int j=0;j<N;j++){
				if(h[j] == 0 && road[i][j] != 10000){
				
				if(j==c1)
					continue;
				//�����ǰλ�õĳ��ȼ��ϴ�λ�õ�ĳ���λ��С�ڵ��� 
				if((length[i]+road[i][j])<=length[j]){

					//���С��,�ܵ� 					
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
//input: N:������,M:��·��
//       M��,ÿһ��Ϊc1,c2,length,������֮��ľ���
//output:����㵽ÿ�����е���̾�������·�� 
//
//*/ 
//int main(){
//	int n,m,c1,c2;
//	cin>>n>>m;
//	//��¼ԭʼ��ͼ��Ϣ 
//	int map[n][n];
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			map[i][j] = 1000;
//		}
//	}
//	//��¼ÿ�������̾���
//	int minLength[n]={1000}; 
//	//��¼���õ����̾����·��
//	int lenmap[n][n];
//		for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			lenmap[i][j] = 1000;
//		}
//	} 
//	//��¼ÿ��λ���Ƿ������ 
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
//	//���Ȱ����·�����ó�ԭ���·����Ϣ
//	for(int i=0;i<n;i++){
//		minLength[i] = map[0][i];
//	} 
//	
//	for(int i=0;i<n;i++){
//		cout<<minLength[i]<<" ";
//	}
//	cout<<endl;
//	//һֱ�����м�¼�������� 
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
//		cout<<"��"<<i<<"���·��Ϊ:";
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
