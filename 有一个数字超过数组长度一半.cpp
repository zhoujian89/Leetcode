#include<iostream>
#include<map> 
using namespace std;
int findvalue(int * arr,int n){
	map<int,int> m;
	map<int,int>::iterator iter;
	for(int i=0;i<n;i++){
		iter=m.find(arr[i]);
		if(iter==m.end()){//没有找到 
			m.insert(map<int,int>::value_type(arr[i],1));
		}
		else {
			m[arr[i]]++;
		}
	}
	for(iter=m.begin();iter!=m.end();iter++){
		if(iter->second>n/2) {
			cout<<iter->first;
			break;
		}
	}
	return iter->first;
}
int fun(int *data,int n){
	int current=data[0];
	int num=1;
	for(int i=1;i<n;i++){
		if(data[i]==current){
			num++;
		}
		else{
			num--;
			if(num==0) {
				current=data[i];
				num=1;
			}		
		}
	}
	cout<<"个数："<<num<<endl;
	return current;
	
	
}
int main(){
	int array[]={2,3,4,5,6,7,2,2,2,2,2,2,2,2};
	findvalue(array,14);
	char *p="abcvvv";//字符串常量，常量不能赋值 
	//p[0]='c';
	cout<<endl;
	cout<<fun(array,14);
	return 1;
}
