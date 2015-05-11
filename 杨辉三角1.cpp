#include<iostream>
#include<math.h>
#include<stack>
#include<vector>
using namespace std;
vector<vector<int> > generate(int numRows) {
 vector<vector<int> > result;
         vector<int> w;
         vector<int> temp;
        if(numRows==0) return result;
        if(numRows>=1){
            vector<int> v;
            v.push_back(1);
            result.push_back(v);
           if(numRows==1) return result;
        }
        if(numRows>=2){
            vector<int> v;
            w.push_back(1);
            w.push_back(1);
            result.push_back(w);
            if(numRows==2) return result;
        }
        for(int i=3;i<=numRows;i++){
            vector<int> u;
            u.push_back(1);
            int k=0;
            while(k<w.size()-1){
                u.push_back(w[k]+w[k+1]);
                k++;
            }
            u.push_back(1);
            w=u;
            result.push_back(u);
        }
        return result;
        }
		int main(){
		vector<vector<int> > v=generate(16);
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}	
		} 
        
