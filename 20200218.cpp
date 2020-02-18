//2020.2.18
//author:ViViWilliam
//issue9
#include<iostream>
using namespace std;

class polynomials{
	public:
		int k;
		double nums[2001]={0};
		int site[2001]={0};
};

//∂‡œÓ Ω 
int main(){
	polynomials num[2];
	for(int i=0;i<2;i++){
		cin>>num[i].k;
		for(int j=0;j<num[i].k;j++){
			cin>>num[i].site[j];
			cin>>num[i].nums[j];
		}
	} 
	polynomials sum;
	
	sum.k = num[0].site[0]*num[1].site[0]+1;
	//3
	for(int i=0;i<num[0].k;i++){
		for(int j=0;j<num[1].k;j++){
			sum.nums[num[0].site[i]+num[1].site[j]]+=num[0].nums[i]*num[1].nums[j];
		}
	}
	int h=0;
	for(int i=0;i<=2001;i++){
		if(sum.nums[i]!=0){
			h++;	
		}
	}
	cout<<h;
	for(int i=2000;i>=0;i--){
		if(sum.nums[i]!=0)
		printf(" %d %.1f",i,sum.nums[i]);
//		cout<<" "<<sum.nums[i];
	}
	return 0;
}








//issu8
//int main(){
//	int n;
//	cin>>n;
//	int sum=n*5;
//	int nums[n];
//	for(int i=0;i<n;i++){
//		cin>>nums[i];
//	}
//	
//	int j=0;
//	int lastfloor = 0;
//	while(1){
//		if(j==n)
//			break;
//		if(nums[j]>lastfloor){
//			sum+=(nums[j]-lastfloor)*6;
//			lastfloor = nums[j];
//			j++;
//			continue;
//		}
//		else{
//			sum+=(lastfloor-nums[j])*4;
//			lastfloor = nums[j];
//			j++;
//			continue;
//		}
//	}
//	cout<<sum;
//} 
