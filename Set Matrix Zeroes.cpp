#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
    vector<int> row;
	vector<int> col;
	int rown=matrix.size()-1,coln=-1;
	if(rown>=0) coln=matrix[0].size()-1;
	for(int i=0;i<=rown;i++)
	for(int j=0;j<=coln;j++){
		if(matrix[i][j]==0){
			row.push_back(i);
			col.push_back(j);
		}
	}
	for(int i=0;i<row.size();i++){
	for(int j=0;j<=coln;j++){
		matrix[row[i]][j]=0;
	}
	}  
	for(int i=0;i<col.size();i++){
		for(int j=0;j<=rown;j++){
		matrix[j][col[i]]=0;
	}
	}     
        
    }
int main(){
	vector<vector<int> > matrix;
	vector<int> t1;
	t1.push_back(0);
	t1.push_back(0);
	t1.push_back(0);
	t1.push_back(5);
	matrix.push_back(t1);
	vector<int> t2;
	t2.push_back(4);
	t2.push_back(3);
	t2.push_back(1);
	t2.push_back(4);
	matrix.push_back(t2);
	vector<int> t3;
	t3.push_back(0);
	t3.push_back(1);
	t3.push_back(1);
	t3.push_back(4);
	matrix.push_back(t3);
	vector<int> t4;
	t4.push_back(1);
	t4.push_back(2);
	t4.push_back(1);
	t4.push_back(3);
	matrix.push_back(t4);
	vector<int> t5;
	t5.push_back(0);
	t5.push_back(0);
	t5.push_back(1);
	t5.push_back(1);
	matrix.push_back(t5);
	setZeroes(matrix);
	int rown=matrix.size()-1,coln=-1;
	if(rown>=0) coln=matrix[0].size()-1;
	for(int i=0;i<=rown;i++){
		for(int j=0;j<=coln;j++){
		cout<<matrix[i][j]<<" ";
	}
	cout<<endl;
		
	}
	
	return 1;
} 

