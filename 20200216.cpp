//2020.2.16
//author:ViViWilliam
//issue5
#include<iostream>
#include<string>
using namespace std;

int main(){
	string input;
	int sum=0;
	string output[10]={"zero","one","two","three","four","five",
						"six","seven","eight","nine"};
	cin>>input;
	for(int i=0;i<input.length();i++){
		sum+=(input[i]-'0');
	}
	string out = to_string(sum);
	int site=out[0]-'0';
	cout<<output[site];
	for(int i=1;i<out.length();i++){
		site = out[i]-'0';
		cout<<" "<<output[site];
	}
	return 0;
} 
