#include<iostream>
using namespace std;
bool isPalindrome(int x){
        int d=1;
        if(x<0) return false;
        while(x/d>=10) d=d*10;
        while(x>0){
            int l=x/d;
            int r=x%10;
            cout<<"l: "<<l<<"  r: "<<r<<endl;
            if(l!=r) return false;
            x=x%d/10;
            d=d/100;
        }
        return true;
        
}
int main(){
	int x=121; 
    cout<<isPalindrome(x)<<endl;
	return 1;
} 
