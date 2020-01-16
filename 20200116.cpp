//Date:2020.1.16
//Author --ViViWilliam

#include<iostream>
#include<string>
using namespace std;
//pat-A 1002
//input: k, ni,ani
//output:sum ni,ani
void pat2(){
	int k,num,output;
	float numz; 
	float c[1001] = {0};
	output = 0;
	for(int m =0;m<2;m++){
		cin>>k;
		for(int i=0;i<k;i++){
			scanf("%d",&num);
			
			 scanf("%f",&numz);
			 c[num]+=numz;
		}
	}
	
	for(int i=0;i<1001;i++){
		if(c[i]!=0.0){
			output++;
		}
	}
	cout<<output;
	for(int i=1000;i>=0;i--){
		if(c[i]!=0.0){
			printf(" %d %.1f", i, c[i]);
		}
	}
}


int main(){
	pat2();	
	return 0;
}
