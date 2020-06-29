#include<iostream>
using namespace std;


int main(){
	char name[3] = {'W','T','L'};
	double nums[3][3] ={0};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>nums[i][j];
		}
	}
	
	int max[3] = {0};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(nums[i][j]>=nums[i][max[i]]){
				max[i] = j;
			}
			
		}
		
	}
	
	for(int i=0;i<3;i++){
		cout<<name[max[i]]<<" ";
	}
	printf("%.2f",(nums[0][max[0]]*nums[1][max[1]]*nums[2][max[2]]*0.65-1)*2);
	return 0;
}
