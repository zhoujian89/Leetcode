#include<iostream>
#include<cstring> 
using namespace std;
/*void get_Next(char * T,int * Next){
	int i=0;//前缀指针 
	int j=1;//后缀指针 
	Next[1]=0;
	while(j<T[0]){
	if(i==0 ||T[i]==T[j]){
		i++;
		j++;
		Next[j]=i;
	} 
	else{//T[i]与T[j]失配 
		i=Next[i];
	}
}
}
int Index_KMP(char * T,char * S,int pos,int *Next){
	int i=pos;//S串指针 
	int j=1;//T串指针
	get_Next(T,Next);
	while(i<=S[0]&&j<=T[0]){
		if(j==0||S[i]==T[j]){
			i++;
			j++;	
		}
		else{//失配,next数组；存在一旦失配，则可拿T中哪一个字符与之匹配 
			j=Next[j];
		}
	}
	if(j>T[0]) {
		return i-T[0];
	}
	else return 0;
}
int main(){
	char T[255]=" ababa";
	char S[255]=" nbcababad";
	T[0]=5;
	S[0]=9;
	int *Next=new int[6];
    cout<<Index_KMP(T,S,1,Next);
	return 1;
} */
void getNext(string T,int * Next){
	int i=0;//前缀
	int j=1;//后缀
	Next[1]=0;
	while(j<T.length()-1){
		if(i==0||T[i]==T[j]){
			i++;
			j++;
			Next[j]=i;
		}
		else{
			i=Next[i];
		}
	} 
}
int IndexKMP(string T,string S,int pos,int *Next){
	int i=pos;//S串指针 
	int j=1;//T串指针
	while(i<=S.length()-1&&j<=T.length()-1){
		if(j==0||S[i]==T[j]){
			i++;
			j++;	
		}
		else{//失配,next数组；存在一旦失配，则可拿T中哪一个字符与之匹配 
			j=Next[j];
		}
	}
	if(j>T.length()-1) {
		return i-(T.length()-1);
	}
	else return 0;
}
//用KMP算法，时间复杂度为O(m+n)
    void getNNext(string pattern, int * next){
        int i=1;//后缀是相对的
        int j=0;//前缀是固定的
        next[1]=0;
        while(i<pattern.length()-1){
        if(j==0||pattern[i]==pattern[j]){
            i++;
            j++;
            next[i]=j;//计算此时i位置上，next数组的值; 对此改进
   // if(pattern[i]!=pattern[j]) next[i]=j;
   // else next[i]=next[j];
        }
        else{
            j=next[j];
        }
        }
    }
    int strStr(string haystack, string needle) {
        string str=haystack.insert(0," ");
        string pattern=needle.insert(0, " ");
        int * next=new int[pattern.length()];
        next[0]=-1;
        //cout<<pattern.length()<<endl;
        getNNext(pattern,next);
        for(int i=0;i<pattern.length();i++){
    	cout<<next[i]<<endl;
    }
    
        int i=1;//st串
        int j=1;//pattern串
        while(i<=str.length()-1&&j<=pattern.length()-1){
            if(j==0||str[i]==pattern[j]){
                i++;
                j++;
            }
            else{
                j=next[j];//因为有next数组,j==0有可能，当j=0，用pattern第一个字符开始匹配
            }
        }
        if(j>pattern.length()-1) return i-(pattern.length()-1);
        else return -1;
        
    }
int main(){
//	char T[255]=" ababa";
//	char S[255]=" nbcababad";
//	T[0]=5;
//	S[0]=9;
//	int *Next=new int[6];
   // cout<<Index_KMP(T,S,1,Next);
   // string T=" ababa";
  //  string S=" nbcababad";
  //  int *Next=new int[T.length()];
   // getNext(T,Next);
    //cout<<IndexKMP(T,S,1,Next)<<endl;
//    for(int i=0;i<T.length();i++){
//    	cout<<Next[i]<<endl;
 //   }
    //cout<<T.length()<<endl;
    string src="mississippi";
	string pattern="ppi";
	cout<<strStr(src,pattern)<<endl;
	
	return 1;
} 
