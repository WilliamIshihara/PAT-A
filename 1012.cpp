#include<iostream>
#include<string>

using namespace std;
/*
	����ѧ����ѧ�ź���Ϣ��c��m��e
	Ȩ��Ϊ��a��c,m,e
	Ȼ���п��ܻ��в��ŵĳɼ��������ĳɼ���Ҳ������ 
*/ 
struct student{
	string ID;
	int grade[4][2];
}; 


int main(){
	//n��ѧ����m�в�ѯ��¼ 
	string name[4] = {"A","C","M","E"}; 
	int n,m;
	cin>>n>>m;
	int grades[n][4];
	student students[n];
	string inquire[m];
	//������ֵ��ͬ����grades 
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
	
	//��������
	int mid;
	//�ĸ���ֵ��Ҫ���� 
	for(int e=0;e<4;e++) {
		// ÿ����ֵ����n����Ҫ�� 
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

	//��ǵ�������ÿ���ṹ���ÿ���ɼ����� 
	//n���� 
	for(int i=0;i<n;i++){
		//4���ɼ� 
		for(int j=0;j<4;j++){
			//n������ 
			for(int q=0;q<n;q++){
				if(students[i].grade[j][0] == grades[q][j]){
					students[i].grade[j][1]  = q+1;
					break;
				}
			}
		}
	}

	//���� 
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

