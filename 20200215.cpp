//2020.2.15
//author：ViViWilliam
//issue4
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

//每一个有孩子的节点 
class point{
	public:
		string id;
		int depth;
		int childnum;
		bool childs=false;
		string child[100];
		
};

point points[100];
int depths[100],maxdepth = -1;

void dfs(string id,int depth,int n){
	
	for(int i=0;i<n;i++){
		if(points[i].id == id){
			if(points[i].childs==false){
				depths[depth]++;
				maxdepth=max(maxdepth,depth);
				return;
			}
			else{
				for(int j=0;j<points[i].childnum;j++){
					dfs(points[i].child[j],depth+1,n);
				}
			}
			return;
		}
	}
	depths[depth]++;
	maxdepth=max(maxdepth,depth);
} 


int main(){
	int n,m,site;
	site = 0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>points[site].id;
		points[site].childs = true;
		cin>>points[site].childnum;
		for(int j=0;j<points[site].childnum;j++){
			cin>>points[site].child[j];
		}
		site++;
	}
	for(int i=0;i<n;i++){
		depths[i]=0;
	}
	dfs("01",0,n);
	cout<<depths[0];
	
	for(int i=1;i<=maxdepth;i++){
		cout<<" "<<depths[i];
	}
	return 0;
}






////2020.2.15
////author：ViViWilliam
////issue4
//#include<iostream>
//using namespace std;
// 
//class point{
//	public:
//		string id;
//		int depth;
//		bool child=false;
//		string father;
//		
//}; 
//
//point points[100];
////将各个子树连接起来 
//void finddepth(string id,int depth,int n){
//	//cout<<id;
//	for(int i=0;i<n;i++){
//		if(points[i].father == id){
//			//cout<<"1"<<endl;
//			points[i].depth = depth+1;
//			finddepth(points[i].id,depth+1,n);
//			
//		}
//	}
//}
//
//
//int main(){
// 	int n,m,z,maxdepth;
// 	z=0;
// 	cin>>n>>m;
// 	
// 
// 	maxdepth = 0;
// 	
// 	int childnum=0;
// 	string num;
// 	//num,k,ki
// 	for(int i=0;i<m;i++){
// 		cin>>num;
// 		int a=0;
// 		for(int j=0;j<n;j++){
// 			if(points[j].id==num){
// 				a=1;
//				break;
//			 }
//		 }
//		 if(a==0){
//		 	points[z].id = num;
//		 	points[z].child = true;
//		 	z++;
//		 }
//		 cin>>childnum;
//		 for(int j=0;j<childnum;j++){
//		 	string id;
//			int b;
//		 	b=0;
//		 	cin>>id;
//		 	for(int s=0;s<n;s++){
//		 		if(points[s].id == id){
//		 			b=1;
//					points[s].father = num;	
//				 }
//			 }
//			 if(b==0){
//			 	points[z].id;
//				points[z].father = num; 
//				z++;
//			 }
//		 }
//	}
//	//cout<<"1";
//	for(int i=0;i<n;i++){
//		if(points[i].id == "01"){
//			points[i].depth=0;
//			points[i].father="9999";
//		
//		}
//	}
//	finddepth("01",0,n);
//	
//	for(int i=0;i<n;i++){
//		if(points[i].depth>maxdepth){
//			maxdepth = points[i].depth;
//		}
//	}
//	int sum[maxdepth+1]={0};
//	for(int i=0;i<n;i++){
//		if(points[i].child==false){
//			sum[points[i].depth]++;
//		}
//	}
//	cout<<sum[0];
//	for(int i=1;i<maxdepth+1;i++){
//		cout<<" "<<sum[i];
//	} 
//} 












////2020.2.15
////author：ViViWilliam
////issue4
//#include<iostream>
//using namespace std;
// 
//class point{
//	public:
//		int id;
//		int depth;
//		bool child=false;
//		int father;
//		
//}; 
//
//
//int main(){
// 	int n,m,z,fatherdepth,maxdepth;
// 	z=0;
// 	cin>>n>>m;
// 	point points[n];
// 
// 	maxdepth = 0;
// 	
// 	int childnum=0;
// 	int num;
// 	
// 	for(int i=0;i<m;i++){
// 		if(i==0){
// 			cin>>points[0].id;
//	 		points[0].depth = 0;
// 			points[0].child = true;
// 			points[0].father = 99999;
// 			fatherdepth = points[0].depth;
// 			num=points[0].id;
//			z++;		
//		 }
//		 else{
//		 	cin>>num;
//		 	int is = 0;
//		 	for(int j=0;j<n;j++){
//		 		if(points[j].id==num){
//		 			points[j].child = true;
//		 			fatherdepth = points[j].depth;
//		 			is = 1;
//				}
//			}
//			if(is == 0){
//				points[z].id = num;
//			}
//			  
//		 }
//		 cin>>childnum;
//		 for(int j=0;j<childnum;j++){
//		 	cin>>points[z].id;
//		 	points[z].depth = fatherdepth+1;
//		 	if(points[z].depth>maxdepth)
//			 maxdepth = points[z].depth;  
//		 	points[z].father = num;
//		 	z++;
//		 }
//	}
//	maxdepth++;
//	
//	int sum[maxdepth]={0};
//	for(int i=0;i<n;i++){
//		if(points[i].child==false){
//			sum[points[i].depth]++;
//		}
//	}
//	cout<<sum[0];
//	for(int i=1;i<maxdepth;i++){
//		cout<<" "<<sum[i];
//	} 
//} 
