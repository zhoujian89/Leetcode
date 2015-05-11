#include<string>
#include<vector> 
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
queue<int> q;//深度优先遍历队列
int m,n;
    /*把当前为'O'的元素加入队列*/
 /*   void add(int x,int y,vector<vector<char> > &board){
        if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='o'){
            board[x][y]='Z';
            q.push(x*n+y);
        }
    }
    //若当前点为'o',将其加入队列
    //看其上下左右，遇到'o'入队列
    void traversal(int x,int y,vector<vector<char> > &board){
        /*把当前元素加入队列*/
 /*       add(x,y,board);
        while(!q.empty()){
            int p=q.front();
            cout<<p<<endl;
            q.pop();
            int i=p/n,j=p%n;
            /*上*/
    //        add(i-1,j,board);
            /*下*/
     //       add(i+1,j,board);
            /*左*/
  //         add(i,j-1,board);
            /*右*/
   //         add(i,j+1,board);
    //    }
        
  //  }
  /*  void solve(vector<vector<char> > &board){
        if(board.empty()||board.size()==0||board[0].size()==0) return ;
        m=board.size();
        n=board[0].size();
        /*从上下边界遍历*/
  /*      for(int i=0;i<n;i++){
            traversal(0,i,board);
            traversal(m-1,i,board);
        }
        /*从左右边界遍历*/
   /*     for(int j=0;j<m;j++){
            traversal(j,0,board);
            traversal(j,n-1,board);
        }
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(board[i][j]=='Z') board[i][j]='o';
            else board[i][j]='X';
        }
        }*/
        /*把当前为'O'的元素加入队列*/
    void add(int x,int y,vector<vector<char> > &board){
        if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='o'){
            board[x][y]='Z';
            q.push(x*n+y);
        }
    }
    //若当前点为'o',将其加入队列
    //看其上下左右，遇到'o'入队列
    void traversal(int x,int y,vector<vector<char> > &board){
        /*把当前元素加入队列*/
        add(x,y,board);
        while(!q.empty()){
            int p=q.front();
            q.pop();
            int i=p/n,j=p%n;
            /*上*/
            add(i-1,j,board);
            /*下*/
            add(i+1,j,board);
            /*左*/
            add(i,j-1,board);
            /*右*/
            add(i,j+1,board);
        }
        
    }
    void solve(vector<vector<char> > &board){
        if(board.empty()||board.size()==0||board[0].size()==0) return ;
        m=board.size();
        n=board[0].size();
        /*从上下边界遍历*/
        for(int i=0;i<n;i++){
            traversal(0,i,board);
            traversal(m-1,i,board);
        }
        /*从左右边界遍历*/
        for(int j=0;j<m;j++){
            traversal(j,0,board);
            traversal(j,n-1,board);
        }
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(board[i][j]=='Z') board[i][j]='o';
            else board[i][j]='X';
        }
    }
int main(){
	vector<vector<char> >  board;
	vector<char> t1;
	t1.push_back('o');
	board.push_back(t1);
/*	t1.push_back('x');
	t1.push_back('x');
	t1.push_back('x');
	t1.push_back('x');
	board.push_back(t1);
	vector<char> t2;
	t2.push_back('x');
	t2.push_back('o');
	t2.push_back('o');
	t2.push_back('x');
	board.push_back(t2);
	vector<char> t3;
	t3.push_back('x');
	t3.push_back('x');
	t3.push_back('o');
	t3.push_back('x');
	board.push_back(t3);
	vector<char> t4;
	t4.push_back('x');
	t4.push_back('o');
	t4.push_back('x');
	t4.push_back('x');
	board.push_back(t4);*/
solve(board);
	  for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
        }
	
	return 1;
} 
