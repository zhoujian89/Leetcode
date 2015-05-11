#include <vector>  
#include <iostream>  
using namespace std;
//��̬�滮���
int minPathSum(vector<vector<int> > &grid) {
	int rows=grid.size();
	int columns=grid[0].size();
	int **x;
//	cout<<rows<<" "<<columns<<endl;
	x=new int *[rows];
	for(int i=0;i<rows;i++){
		x[i]=new int[columns];
	}
	for(int i=0;i<rows;i++)
	for(int j=0;j<columns;j++)
	x[i][j]=0;
	
	//��(0,0)��(m-1,n-1)
	//��m==1&&n==1 
	x[0][0]=grid[0][0];
	//��n=1&&m!=1��ֻ��down���� 
	for(int i=1;i<rows;i++) 
	x[i][0]=x[i-1][0]+grid[i][0];
	//��m=1&&n!=1;ֻ��right����
	for(int i=1;i<columns;i++) 
	x[0][i]=x[0][i-1]+grid[0][i];
	for(int i=1;i<rows;i++)
	for(int j=1;j<columns;j++){
		int temp=x[i-1][j]>x[i][j-1]?x[i][j-1]:x[i-1][j]; 
		x[i][j]=temp+grid[i][j];
	}
	for(int i=0;i<rows;i++){
	for(int j=0;j<columns;j++){
		cout<<x[i][j]<<" ";
	}
	cout<<endl;
	}
	return x[rows-1][columns-1];
        
    } 
int main(){
	vector< vector<int> > input;
	vector<int> temp1;
	temp1.push_back(1);
	temp1.push_back(2);
	input.push_back(temp1);
	vector<int> temp2;
	temp2.push_back(1);
	temp2.push_back(1);
	input.push_back(temp2);
	minPathSum(input); 
	return 1;
} 

