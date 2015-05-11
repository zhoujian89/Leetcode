  #include<iostream>
  #include<string>
  using namespace std;
  void getStr(string s){
  	int len=s.size()-1;
  	for(int pos=0;pos<=len;pos++)
  	for(int length=len-pos+1;length>=1;length--){
  		string temp=s.substr(pos,length);
  		cout<<temp<<endl;
  	}
  	cout<<"..............."<<endl;
	cout<<0x7FFFFFFF<<endl;
  }
  int main(){
  	string s="aab";
  	getStr(s);
  	return 1;
  } 
