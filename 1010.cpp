#include<iostream>
#include<string> 
#include<math.h>
using namespace std;
/*
首先，先把已经确定了的数转换成十进制
然后，确定未确定的数的上下进制
然后进行二分法查找 
*/ 
char letter[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r',
	's','t','u','v','w','x','y','z'};



long long change(string n,long long weight){
	long long sum=0;
	int site = 0;
	
	int m = 0;
	for(int i=n.length()-1;i>=0; i--){
		site = 0;
		if(weight>10){
			for(int j=0;j<weight-10;j++){
				if(n[i]==letter[j]){
					site = (9+j+1)*int(pow(weight,m));
					sum+=site;
					m++;
					break;
				}
			}
		}
		if(site != 0){
			continue;
		}
		else{
			site = (n[i]-'0')*int(pow(weight,m));
			sum+=site;
			m++;
		}
	}
	return sum;
}

int erfen(string n,long long num,long long low,long long high){
	long long weith = (low+high)/2;
	long long num1 =change(n,weith);
	if(num1<0){
		return erfen(n,num,low,weith-1); 
	}
	//cout<<"weight="<<weith<<",num="<<num1<<endl;
	if(num1 == num){
		return weith;
	}
	else if(num1>num&&low!=weith){
		return erfen(n,num,low,weith); 
	}
	else if(num1<num&&high!=weith){
		return erfen(n,num,weith,high);
	}
	
	return 1;
}
int cha(string n,long long num,long long low,long long high){
	for(int i=low;i<=high;i++){
		long long num1 =change(n,i);
		if(num1 ==num){
			return i;
			break;
		}
	}
	return 1;
	
}

// 6 110 1 10
int main(){
	long long num1,num2,weight;
	string num[2];
	int site; 
	cin>>num[0]>>num[1]>>site>>weight; 
	site = site-1;
	num1 = change(num[site],weight);
	//cout<<num1<<endl;
	
	//另一个数，首先确定他的上下限，首先下限是该数的最高位加一，其次，最高上限等于另一个数或者是该数的最大位较大者加一 
	int len = num[!site].length();
	long long low,high;
	int lastnum[len] = {0};
	bool isnum;
	for(int i=0;i<len;i++){
		isnum = false;
		for(int j=0;j<26;j++){
			if(num[!site][i]==letter[j]){
				lastnum[i] = 10+j;
				isnum = true;
				break;
			}
		}
		if(isnum){
			continue;
		}
		else{
			lastnum[i] = num[!site][i] - '0';
		}
	}
	low = lastnum[0]+1;
	for(int i=1;i<len;i++){
		if(lastnum[i]>low-1){
			low = lastnum[i]+1;
		}
	} 
	if(low>num1+1){
		high = low;
	}
	else{
		high = num1+1;
	}
	
	if(len == 1){
		if(erfen(num[!site],num1,low,high)!=1)
			cout<<erfen(num[!site],num1,low,high)<<endl;
		else
			cout<<"Impossible"<<endl; 
	} 
	else{
	//cout<<"low="<<low<<",high="<<high<<endl;
		if(erfen(num[!site],num1,low,high)!=1)
			cout<<erfen(num[!site],num1,low,high)<<endl;
		else
			cout<<"Impossible"<<endl; 
	}
	
	
	
	return 0;
}
