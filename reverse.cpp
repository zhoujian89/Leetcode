#include<stdio.h>
#include<string>
#include<stack>
#include<iostream>
using namespace std;
 void reverseWords(string &s){
    int begin=0;
 	int end=s.size()-1;
 	stack<string> st;
 	if(s.size()==0) s="";
 	else {
 	while(begin<=s.size()-1&&s.at(begin)==' ') begin++;
 	while(end>=0&&s.at(end)==' ') end--;
 	//遇到全为' '的串
 	if(begin>end) s="";
 	//遇到首尾都有' '的串
	else  s=s.substr(begin,end-begin+1); //从begin开始共有end-begin+1个子串 
    
	
	begin=0;
	for(int i=0;i<s.size();i++){	
		if(s.at(i)==' '){
			string temp=s.substr(begin,i-begin);
			st.push(temp);
		//若有多个空格
		while(i<s.size()&&s.at(i)==' ')	i++;
		    begin=i;
		}
	
		if(i==s.size()-1){
		string temp=s.substr(begin,s.size()-begin);
			st.push(temp);	
		}
	}
	string ss;
	while(!st.empty()){
		ss.append(st.top()+" ");
		st.pop();	
	}
	//删除最后空格 
	if(!ss.empty()){
	ss.erase(ss.size()-1,1);
	s=ss;  } 
}
 }
int main(){
	//string s="the   sky   is    blue";
	//string s=" ABCD   ";
	//string s=" 1  ";
	string s="";
	//string s="  ";
	//cout<<"test:"<<s.substr(4,7)<<endl;
	reverseWords(s);
	cout<<s<<endl;
	return 1;
}
/*string& trim(string &s)   
{  
    if (s.empty())   
    {  
        return s;  
    }  
    s.erase(0,s.find_first_not_of(" "));  
    s.erase(s.find_last_not_of(" ") + 1);  
    return s;  
}  
void reverse(string &s,int start,int end){
        char temp;
        if(start<=end){
        for(int i=start;i<=(start+end)/2;i++){
            temp=s[i];
            s[i]=s[end-i+start];
            s[end-i+start]=temp;
        }
        }
    
    }
    void reverseWords(string &s) {
        int j=0;
       for( j=0;j<s.size();j++){
            if(s[j]!=' ') break;
        }
       if(j==s.size()) s="";
        
       // j=0;
      //  while(s[j]==' ') j++;
      //  s=s.substr(j,s.size()-1);
      //  reverse(s,0,s.size()-1);
        
        //把字符串s先整体反转
        cout<<s.size()<<endl;
        reverse(s,0,s.size()-1);
       int start=0;
        for(int i=0;i<s.size();i++){
          if(s[i]==' '){
                reverse(s,start,i-1);
                start=i+1;
           }
           if(i==s.size()-1){
           	reverse(s,start,s.size()-1);
           }
        }
    }
    int main(){
    	string s;
    	//s="the sky is blue";
    //	s="the food is delicious!";
    
       // s=" 1";
       s="you are a student";
    	reverseWords(s);
    	cout<<s;
    	cout<<endl;
    //	cout<<"size:"<<s.size()<<endl;
    	
    	return 1;
    }*/
