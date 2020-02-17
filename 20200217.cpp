//2020.2.17
//author:ViViWilliam
//issue7
#include<iostream>
using namespace std;

int main(){
	int n,sum;
	cin>>n;
	int nums[n],dp[n],site[n];
	for(int i=0;i<n;i++){
		cin>>nums[i];
		dp[i] = nums[i];
		site[i] = nums[i];
	}
	//dp
	//找出最大值
	 for(int i=1;i<n;i++){
	 	int nowsum=dp[i];
	 	
	 		nowsum+=dp[i-1];
	 		if(nowsum>dp[i]){
	 			dp[i] = nowsum;
	 			site[i] = site[i-1];
			 }
	 }
	 int max=0;
	 for(int i=1;i<n;i++){
	 	if(dp[i]>dp[max]){
	 		max = i;
		 }
	 }
	 
	 if(dp[max]<0){
	 	dp[max] = 0;
		 cout<<"0 "<<nums[0]<<" "<<nums[n-1];	
	 }
	 else
	cout<<dp[max]<<" "<<site[max]<<" "<<nums[max];
} 



