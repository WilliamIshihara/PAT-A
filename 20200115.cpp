//Date:2020.1.15
//Author --ViViWilliam

#include<iostream>
#include<string>
using namespace std;
//pat-A 1002
//input:
//output:
void pat2(){
	
}







//pat-A 1001
//input:a pair of integer a,b
//output:a+b , use , separated three digits
void pat1(){
	int a,b,sum,sumnum;
	string output;
	cin>>a>>b;
	sum = a+b;
	output = to_string(sum);
	int j=0;
	int i=0;
	sumnum = output.length();
	if(output[0]=='-'){
		i+=1;
		sumnum -= 1;
		cout<<"-";
	}
	for(i;i<output.length();i++){
		j++;
		if((sumnum-j+1)%3 == 0&&j!=1){
			cout<<",";
		}
		cout<<output[i];
	}
	
} 

int main(){
//	pat1();
	
	return 0;
}
