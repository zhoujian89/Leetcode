#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool set(vector<vector<char> > &board,int i,int j,vector<vector<int> > &visit){
	int row=board.size()-1,col=board[0].size()-1;
	int x=i-1,y=j;
	int flag1=false,flag2=false,flag3=false,flag4=false;
	//判断上方的点 
	if(x>=0&&board[x][y]=='o'){
	visit[x][y]=1;
	flag1=true;	
	} 
	//判断下方的点
	x=i+1;
	if(x<=row&&board[x][y]=='o') {
	visit[x][y]=1;
	flag2=true;	
	}
	//判断左边的点
	x=i;
	y=j-1;
	if(y>=0&&board[x][y]=='o') {
	visit[x][y]=1;
	flag3=true;		
	}
	//判断右边的点
	y=j+1; 
	if(y<=col&&board[x][y]=='o'){
	visit[x][y]=1;
	flag4=true;	
	} 
	return flag1||flag2||flag3||flag4;
}

void solve(vector<vector<char> > &board,vector<vector<int> >  &visit) {
  int row=board.size()-1,col=board[0].size()-1;
  for(int i=0;i<=row;i++)
  for(int j=0;j<=col;j++){
  	if(board[i][j]=='o') {
  	if(set(board,i, j,visit))board[i][j]='x';
  	}
  }
  for(int i=0;i<=row;i++){
  	for(int j=0;j<=col;j++){
  		if(visit[i][j]==1) board[i][j]='x';
  	cout<<board[i][j];
  }
  cout<<endl;
  }   
}
int main(){
	vector<vector<char> >  board;
	vector<vector<int> >  visit;
	vector<char> t1;
	t1.push_back('x');
	t1.push_back('x');
	t1.push_back('x');
	//t1.push_back('x');
	board.push_back(t1);
	vector<char> t2;
	t2.push_back('x');
	t2.push_back('o');
	t2.push_back('x');
//	t2.push_back('x');
	board.push_back(t2);
	vector<char> t3;
	t3.push_back('x');
	t3.push_back('x');
	//t3.push_back('o');
	t3.push_back('x');
	board.push_back(t3);
//	vector<char> t4;
//	t4.push_back('x');
//	t4.push_back('o');
//	t4.push_back('x');
//	t4.push_back('x');
//	board.push_back(t4);
	int row=board.size()-1,col=board[0].size()-1;
	for(int i=0;i<=row;i++){
		vector<int> temp;
  	for(int j=0;j<=col;j++){
	temp.push_back(0);
}
visit.push_back(temp);
}
solve(board,visit);
	//cout<<visit[2][2]<<endl;
	//cout<<visit[3][1]<<endl;
	return 1;
}
