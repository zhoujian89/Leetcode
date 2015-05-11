#include<iostream>
#include<vector>
using namespace std;
//打印一圈数据 
void printmatrix(int **x,int n,int start,int &num){
	int EndX=n-1-start;
	int EndY=n-1-start;
	for(int i=start;i<=EndX;i++){
		x[start][i]=num;
		num++;
	}
	for(int i=start+1;i<=EndY;i++){
		x[i][EndY]=num;
		num++;
	}
	for(int i=EndX-1;i>=start;i--){
		x[EndY][i]=num;
		num++;
	}
	for(int i=EndY-1;i>=start+1;i--){
		x[i][start]=num;
		num++;
	}
}
vector<vector<int> > generateMatrix(int n) {
vector<vector<int> > ans;
	int **x;
	int start=0,num=1;
	x=new int* [n];
	for(int i=0;i<n;i++) x[i]=new int[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		x[i][j]=0;
	}
	while(n>2*start){
		printmatrix(x, n,start,num);
		start++;
	}
	for(int i=0;i<n;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			temp.push_back(x[i][j]);
		cout<<x[i][j]<<"  ";
			}
			ans.push_back(temp);
		cout<<endl;
	}
	return ans;  
    }
int main(){
	vector<vector<int> > ans=generateMatrix(1);
	cout<<"....."<<endl;
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<"  ";
		
	}
	cout<<endl;
	}
	
	return 1;
} 

