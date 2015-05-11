#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combination(vector<int> &num, int target,vector<vector<int> > &result, vector<int> & path,int &sum,int start){
        if(sum==target){
            result.push_back(path);
            return ;
        }
        int previous=-1;
        //cout<<"previous: "<<previous<<endl;
        for(int i=start;i<num.size();i++){
           if(num[i]>target) return;
           if(previous!=num[i]){
           //	cout<<"previous: "<<previous<<endl;
            previous=num[i];
            sum+=num[i];
            path.push_back(num[i]);
            if(sum<=target){
            combination(num,target,result,path,sum,i+1);
            }
            sum-=num[i];
            path.pop_back();
           }
             
        }
        
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> path;
        vector<vector<int> > result;
        int sum=0,start=0;
        sort(num.begin(),num.end());
        combination(num,target,result,path,sum,start);
        return result;
        
    }
    int main(){
	vector<int> num;//10,1,2,7,6,1,5
	num.push_back(10);
	num.push_back(1);
	num.push_back(2);
	num.push_back(7);
	num.push_back(6);
	num.push_back(1);
	num.push_back(5);
	num.push_back(5);
	num.push_back(5);
	num.push_back(5);
	num.push_back(5);
	vector<vector<int> > result=combinationSum2(num,8);
	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++){
	for(int j=0;j<result[i].size();j++){
		cout<<result[i][j]<<" , ";
	}
	cout<<endl;
}
	return 1;
}
/* void combination(vector<int> &candidates, int target,vector<vector<int> > &result, vector<int> & path,int &sum,int start){
        if(sum==target){
            result.push_back(path);
            return ;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target) return;
            
            sum+=candidates[i];
            path.push_back(candidates[i]);
            if(sum<=target){
            combination(candidates,target,result,path,sum,i);
            }
            sum-=candidates[i];
            path.pop_back();
            
             
        }
        
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> path;
        vector<vector<int> > result;
        int sum=0,start=0;
        sort(candidates.begin(),candidates.end());
        combination(candidates,target,result,path,sum,start);
        return result;
    }
    int main(){
	vector<int> num;//10,1,2,7,6,1,5
	num.push_back(2);
	num.push_back(3);
	num.push_back(6);
	num.push_back(7);
	vector<vector<int> > result=combinationSum(num,7);
	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++){
	for(int j=0;j<result[i].size();j++){
		cout<<result[i][j]<<" , ";
	}
	cout<<endl;
}
	return 1;
}
    
/*void combination(vector<int> &num, int target,vector<vector<int> > &result,int *x,int sum,int start){
	 //if(t==num.size()){
	 //	cout<<"ff"<<endl;
	 //	sum=0;
	 if(sum==target){
	    sum=0;
	 	vector<int> path;
            for(int i=0;i<num.size();i++){
            	if(x[i]==1){
            		path.push_back(num[i]);
            	}
            }
            result.push_back(path);
             return ;
        }
           
       // }
       
       for(int j=start;j<num.size();j++){
       	for(int k=0;k<=1;k++){
       
        	x[j]=k;
        	// for(int i=0;i<num.size();i++) cout<<x[i]<<" ";
        	// cout<<endl;
        if(k==1)	sum+=num[j];
        	if(sum<=target){
        	combination(num,target,result,x,sum,start+1);	
        }
        	x[j]=0;
        	sum-=num[j];
        
			}
				}
        
 }
 vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> path;
        vector<vector<int> > result;
        int sum=0,start=0;
        int *x;
        x=new int [num.size()];
        for(int i=0;i<num.size();i++) x[i]=0;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
        	cout<<num[i]<<" ";
        }
        cout<<"...."<<endl;
        combination(num,target,result,x,sum,0);
        for(int i=0;i<num.size();i++) cout<<x[i]<<" ";
        return result;
        
    }
int main(){
	vector<int> num;//10,1,2,7,6,1,5
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	vector<vector<int> > result=combinationSum2(num,8);
	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++){
	for(int j=0;j<result[i].size();j++){
		cout<<result[i][j]<<" , ";
	}
	cout<<endl;
}
	return 1;
}
/*void combination(vector<int> &num, int target,vector<vector<int> > &result, vector<int> & path,int &sum,int start){
        if(sum==target&&start<=num.size()){
        	// cout<<"start: "<<start<<endl;
            result.push_back(path);
            return ;
        }
       
        for(int i=start;i<num.size();i++){   	
            sum+=num[i];
            path.push_back(num[i]);
            if(sum<=target){
            combination(num,target,result,path,sum,start+1);
            }
            sum-=num[i];
            path.pop_back();    
        }
        
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> path;
        vector<vector<int> > result;
        int sum=0,start=0;
        int *x;
        x=new int [num.size()];
        for(int i=0;i<num.size();i++) x[i]=0;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
        	cout<<num[i]<<" ";
        }
        cout<<"...."<<endl;
        combination(num,target,result,path,sum,start);
        return result;
        
    }
int main(){
	vector<int> num;//10,1,2,7,6,1,5
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	vector<vector<int> > result=combinationSum2(num,8);
	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++){
	for(int j=0;j<result[i].size();j++){
		cout<<result[i][j]<<" , ";
	}
	cout<<endl;
}
	return 1;
}*/
