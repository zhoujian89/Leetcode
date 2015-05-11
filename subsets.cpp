#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
 void backtrack(int t,int *x,vector<int> & S,vector<vector<int> > & result,int & n){//
        if(t==n){
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(x[i]==1) temp.push_back(S[i]);
               // cout<<S[i]<<"  ";
            }
           // cout<<endl;
            result.push_back(temp);
            return;
            
        }
        for(int i=0;i<=1;i++){
            x[t]=i;
            backtrack(t+1,x,S,result,n);//result,
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        int n=S.size();
        vector<vector<int> >  result;
        int * x;
        x=new int[n];
        for(int i=0;i<n;i++) x[i]=0;
        sort(S.begin(),S.end());//从小到大排列
        //cout<<S.size()<<"s.size()"<<endl;
        backtrack(0,x,S,result,n);//
     // for(int i=0;i<S.size();i++)
    //  cout<<S[i]<<"  ";
    //  cout<<endl;
        return result;
        
    }
    int main(){
    	vector<int> S;
    	S.push_back(1);
    	S.push_back(2);
    	S.push_back(2);
    	vector<vector<int> > result=subsets(S);
    	for(int i=0;i<result.size();i++){
    		for(int j=0;j<result[i].size();j++){
    			cout<<result[i][j]<<"  ";
    		}
    		cout<<endl;
    	}
    	cout<<result.size()<<endl;
    	string s(8,'.');
    	cout<<s<<endl;
    	s= s.replace(0, 1, "Q");
    	cout<<s<<endl;
		return 1;
    }
    
 /*   int n=3;
    int * x=new int[n];
    int S[3]={3,2,1};
    void backtrack(int t){
    	if(t==n){
    		for(int i=0;i<n;i++){
    			if(x[i]==1)
    			cout<<S[i]<<"  ";
    		}
    		cout<<endl;
    		return;
    	}
    	for(int i=0;i<=1;i++){
    		x[t]=i;
    		backtrack(t+1);
    	}
    }
    int main(){
    	backtrack(0);
    	return 1;
    }*/
