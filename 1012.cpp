#include<iostream>
#include<string>

using namespace std;
/*
	输入学生的学号和信息，c，m，e
	权重为：a，c,m,e
	然后有可能会有并排的成绩，这样的成绩就也算排名 
*/ 
struct student{
	string ID;
	int grade[4][2];
}; 


int main(){
	//n个学生，m行查询记录 
	string name[4] = {"A","C","M","E"}; 
	int n,m;
	cin>>n>>m;
	int grades[n][4];
	student students[n];
	string inquire[m];
	//输入数值并同步到grades 
	for(int i=0;i<n;i++){
		int sum = 0;
		cin>>students[i].ID;
		for(int j=1;j<4;j++){
			cin>>students[i].grade[j][0];
			grades[i][j]=students[i].grade[j][0];
			sum+=students[i].grade[j][0];
		}
		students[i].grade[0][0] = sum/3;
		grades[i][0]= students[i].grade[0][0];
	}
	
	
	for(int i=0;i<m;i++){
		cin>>inquire[i];
	}
	
	//进行排序
	int mid;
	//四个数值都要排序 
	for(int e=0;e<4;e++) {
		// 每个数值都有n个数要排 
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(grades[i][e]<grades[j][e]){
					mid = grades[j][e];
					grades[j][e] = grades[i][e];
					grades[i][e] = mid;
				}
				
			}
		}
	}

	//标记到数组中每个结构体的每个成绩排名 
	//n个人 
	for(int i=0;i<n;i++){
		//4个成绩 
		for(int j=0;j<4;j++){
			//n个排名 
			for(int q=0;q<n;q++){
				if(students[i].grade[j][0] == grades[q][j]){
					students[i].grade[j][1]  = q+1;
					break;
				}
			}
		}
	}

	//查找 
	for(int i=0;i<m;i++){
		int u = 0;
		for(int j=0;j<n;j++){
			if(inquire[i]==students[j].ID){
				u = 1;
				int max=0;
				for(int p=0;p<4;p++){
					if(students[j].grade[p][1]<students[j].grade[max][1]){
						max = p;
					}
				}
				cout<<students[j].grade[max][1]<<" "<<name[max]<<endl;
				break;
			}
		}
		if(u == 0){
			cout<<"N/A"<<endl;
		}
	}

	return 0;
	
}

