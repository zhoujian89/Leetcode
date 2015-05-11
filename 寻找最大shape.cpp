#include <vector>  
#include <iostream>  
using namespace std; 
//每个点只搜索一次，用bool状态数组设置，当之前被访问过，后面就不再访问 
void dfs(vector< vector<int> > &input,vector<vector<bool> > &visit,int i,int j,int & range){
	int rows=input.size()-1;
	int columns=input[0].size()-1;
	//边界条件 
	if(i<0||j<0||i>rows||j>columns) return;
	if(visit[i][j]==true||input[i][j]==0) return;
	visit[i][j]=true;
	range++;
//	cout<<"dfs : range: "<<range<<endl;
	//往上走
	dfs(input,visit,i-1,j,range);
	//往左走
	dfs(input,visit,i,j-1,range);
	//往右走
	dfs(input,visit,i,j+1,range); 
	//往下走
	dfs(input,visit,i+1,j,range); 	
}
int getMaxDFS(vector< vector<int> > &input) {
	int rows=input.size()-1;
	int columns=input[0].size()-1;
	if(rows==-1||columns==-1) return 0;
	vector<vector<bool> > visit;
	for(int i=0;i<=rows;i++){
			vector<bool> temp;
		for(int j=0;j<=columns;j++){
			temp.push_back(false);
		}
		visit.push_back(temp);
	}
	int maxSize=0;
	for(int i=0;i<=rows;i++){
		for(int j=0;j<=columns;j++){
			if(input[i][j]==1){
				int range=0;
				 dfs(input, visit,i, j,range);
				// cout<<range<<" range"<<endl;
				 maxSize=maxSize>range?maxSize:range;
			}
			
		}
	}
	return maxSize;
	
	
	
	
}
/*
                {0,0,1,0,0},
                {0,0,1,0,0},
                {0,0,1,1,1},
                {1,0,0,0,0}
*/
int main(){
	vector< vector<int> > input;
	vector<int> temp1;
	temp1.push_back(0);
	temp1.push_back(0);
	temp1.push_back(1);
	temp1.push_back(0);
	temp1.push_back(0);
	input.push_back(temp1);
	vector<int> temp2;
	temp2.push_back(0);
	temp2.push_back(0);
	temp2.push_back(1);
	temp2.push_back(0);
	temp2.push_back(0);
	input.push_back(temp2);
	vector<int> temp3;
	temp3.push_back(0);
	temp3.push_back(0);
	temp3.push_back(1);
	temp3.push_back(1);
	temp3.push_back(1);
	input.push_back(temp3);
	vector<int> temp4;
	temp4.push_back(1);
	temp4.push_back(0);
	temp4.push_back(0);
	temp4.push_back(0);
	temp4.push_back(0);
	input.push_back(temp4);
	cout<<getMaxDFS(input)<<endl;
	return 1;
}

