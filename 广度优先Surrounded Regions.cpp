#include<string>
#include<vector> 
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
queue<int> q;//������ȱ�������
int m,n;
    /*�ѵ�ǰΪ'O'��Ԫ�ؼ������*/
 /*   void add(int x,int y,vector<vector<char> > &board){
        if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='o'){
            board[x][y]='Z';
            q.push(x*n+y);
        }
    }
    //����ǰ��Ϊ'o',����������
    //�����������ң�����'o'�����
    void traversal(int x,int y,vector<vector<char> > &board){
        /*�ѵ�ǰԪ�ؼ������*/
 /*       add(x,y,board);
        while(!q.empty()){
            int p=q.front();
            cout<<p<<endl;
            q.pop();
            int i=p/n,j=p%n;
            /*��*/
    //        add(i-1,j,board);
            /*��*/
     //       add(i+1,j,board);
            /*��*/
  //         add(i,j-1,board);
            /*��*/
   //         add(i,j+1,board);
    //    }
        
  //  }
  /*  void solve(vector<vector<char> > &board){
        if(board.empty()||board.size()==0||board[0].size()==0) return ;
        m=board.size();
        n=board[0].size();
        /*�����±߽����*/
  /*      for(int i=0;i<n;i++){
            traversal(0,i,board);
            traversal(m-1,i,board);
        }
        /*�����ұ߽����*/
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
        /*�ѵ�ǰΪ'O'��Ԫ�ؼ������*/
    void add(int x,int y,vector<vector<char> > &board){
        if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='o'){
            board[x][y]='Z';
            q.push(x*n+y);
        }
    }
    //����ǰ��Ϊ'o',����������
    //�����������ң�����'o'�����
    void traversal(int x,int y,vector<vector<char> > &board){
        /*�ѵ�ǰԪ�ؼ������*/
        add(x,y,board);
        while(!q.empty()){
            int p=q.front();
            q.pop();
            int i=p/n,j=p%n;
            /*��*/
            add(i-1,j,board);
            /*��*/
            add(i+1,j,board);
            /*��*/
            add(i,j-1,board);
            /*��*/
            add(i,j+1,board);
        }
        
    }
    void solve(vector<vector<char> > &board){
        if(board.empty()||board.size()==0||board[0].size()==0) return ;
        m=board.size();
        n=board[0].size();
        /*�����±߽����*/
        for(int i=0;i<n;i++){
            traversal(0,i,board);
            traversal(m-1,i,board);
        }
        /*�����ұ߽����*/
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
