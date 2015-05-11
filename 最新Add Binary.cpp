#include<string>
#include<stack>
#include<iostream>
using namespace std;
string addBinary(string a, string b){
	stack<char> s;
	int flag=0;//½øÎ» 
	if(a.size()==0) return b;
	if(b.size()==0) return a;
	int p=a.size()-1,q=b.size()-1;
	if(p<=q){
		int temp=p;
		p=q;q=temp;
		string c=a;
		a=b;b=c; 
	}
	while(q>=0){
		if(a[p]-'0'+b[q]-'0'+flag==2){
			char temp='0';
			s.push(temp);
			flag=1;
		}
		else if(a[p]-'0'+b[q]-'0'+flag==1) {
			char temp='1';
			s.push(temp);
			flag=0;
		}
		else if(a[p]-'0'+b[q]-'0'+flag==3) {
			char temp='1';
			s.push(temp);
			flag=1;
		}
		else{
			char temp='0';
			s.push(temp);
			flag=0;
		}
		p--;
		q--;
	}
	while(p>=0){
		if(a[p]-'0'+flag==2){
			char temp='0';
			s.push(temp);
			flag=1;
		}
		else if(a[p]-'0'+flag==1){
			char temp='1';
			s.push(temp);
			flag=0;
		}
		else if(a[p]-'0'+flag==3){
			char temp='1';
			s.push(temp);
			flag=1;
		}
		else {
			char temp='0';
			s.push(temp);
			flag=0;
		}
		p--;
	}
	if(flag==1){
		char temp='1';
		s.push(temp);
	}
	string re="";
    while(!s.empty()){
    	 char tem=s.top();
    	 re.push_back(tem);//×·¼Ó×Ö·û
		 //re.append()×·¼Ó×Ö·û´® 
   // cout<<tem;
	s.pop();	
    }
//	cout<<re<<endl;
	return re;
    }
int main(){
//	string a="aaa";
//	cout<<a[1]<<endl;
string a = "1111";
string b = "1111";
cout<<addBinary(a,b)<<endl;
	return 1;
} 
