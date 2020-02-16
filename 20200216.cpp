//2020.2.16
//author:ViViWilliam
//issue6
#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	string id[n];
	int time[n][6];
	for(int i=0;i<n;i++){
		cin>>id[i];
		scanf("%d:%d:%d %d:%d:%d",&time[i][0],
			   &time[i][1],&time[i][2],&time[i][3],
			   &time[i][4],&time[i][5]);
	}
	int first=0,last=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			if(time[i][j]<time[first][j]){
				first = i;
				break;
			}
			if(time[i][j]==time[first][j]){
				continue;
			}
			else{
				break;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=3;j<6;j++){
			if(time[i][j]<time[last][j]){
				last = i;
				break;
			}
			if(time[i][j]==time[last][j]){
				continue;
			}
			else{
				break;
			}
		}
	}
	
	cout<<id[first]<<" "<<id[last]<<endl;
	return 0;
} 





//issue5
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main(){
//	string input;
//	int sum=0;
//	string output[10]={"zero","one","two","three","four","five",
//						"six","seven","eight","nine"};
//	cin>>input;
//	for(int i=0;i<input.length();i++){
//		sum+=(input[i]-'0');
//	}
//	string out = to_string(sum);
//	int site=out[0]-'0';
//	cout<<output[site];
//	for(int i=1;i<out.length();i++){
//		site = out[i]-'0';
//		cout<<" "<<output[site];
//	}
//	return 0;
//} 
