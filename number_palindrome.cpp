#include<iostream>
using namespace std;
/*bool isPalindrome(int x){
	if(x <0) return false;
	int d=1;
	while(x/d>=0) d=d*10;
	while(x>0){
		int l=x/d;
		int r=x%d;
		if(l!=r) return false;
		x=x%d/10;
		d=d/100;
	}
	return true;
}*/
int main(){
	int x=345; 
	int d=1;
   while(x/d>=10) d=d*10;
   cout<<d<<endl;
	return 1;
} 
