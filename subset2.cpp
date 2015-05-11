#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//int pre=-1;
/*void backtrack(int t,int *x,vector<int> & S,vector<vector<int> > & result,int & n){
	//int pre=-1;
//	if(S[t]!=pre){
     //   pre=S[t];
        if(t==n){
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(x[i]==1) temp.push_back(S[i]);
            }
            
            result.push_back(temp);
            return;//必须要有返回
            
        }
      //  cout<<"s[t] "<<S[t]<<endl;
  //    if(pre!=S[t]){
      //	pre=S[t];
      //  cout<<"s[t] "<<S[t]<<endl;
        for(int i=0;i<=1;i++){
            x[t]=i;
            backtrack(t+1,x,S,result,n);
            }
            	}
            	
           //  }
      
   // }
    int main () {
        vector<vector<int> > v;
        vector<int> S;
        int pre=-1;
        S.push_back(1);
        S.push_back(2);
        S.push_back(3);
        int n=S.size();
        int * x;
        x=new int[n];
        for(int i=0;i<n;i++) x[i]=0;
        sort(S.begin(),S.end());//从小到大排列
        backtrack(0,x,S,v,n);
        cout<<"size: "<<v.size();
        	for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
        
        
    }*/
 void getSubset(vector<vector<int> > & result,int start,vector<int> &S, vector<int> & temp){
        int i=start;
        if(i==S.size()){
            result.push_back(temp);
        }
        for(;i<=S.size()-1;i++){
            temp.push_back(S[i]); 
            getSubset(result,i+1,S,temp);
            temp.pop_back();
        }
    }
int main(){
	vector<int> S;
	vector<int> temp;
	vector<vector<int> >  v;
	S.push_back(1);
	S.push_back(2);
	S.push_back(3);
	S.push_back(4);
//	S.push_back(5);
//	S.push_back(6);
	//S.push_back(7);
	getSubset(v,0,S,temp);
	for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
}
