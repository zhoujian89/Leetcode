#include<iostream>
#include<cstring> 
using namespace std;
/*void get_Next(char * T,int * Next){
	int i=0;//ǰ׺ָ�� 
	int j=1;//��׺ָ�� 
	Next[1]=0;
	while(j<T[0]){
	if(i==0 ||T[i]==T[j]){
		i++;
		j++;
		Next[j]=i;
	} 
	else{//T[i]��T[j]ʧ�� 
		i=Next[i];
	}
}
}
int Index_KMP(char * T,char * S,int pos,int *Next){
	int i=pos;//S��ָ�� 
	int j=1;//T��ָ��
	get_Next(T,Next);
	while(i<=S[0]&&j<=T[0]){
		if(j==0||S[i]==T[j]){
			i++;
			j++;	
		}
		else{//ʧ��,next���飻����һ��ʧ�䣬�����T����һ���ַ���֮ƥ�� 
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
	int i=0;//ǰ׺
	int j=1;//��׺
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
	int i=pos;//S��ָ�� 
	int j=1;//T��ָ��
	while(i<=S.length()-1&&j<=T.length()-1){
		if(j==0||S[i]==T[j]){
			i++;
			j++;	
		}
		else{//ʧ��,next���飻����һ��ʧ�䣬�����T����һ���ַ���֮ƥ�� 
			j=Next[j];
		}
	}
	if(j>T.length()-1) {
		return i-(T.length()-1);
	}
	else return 0;
}
//��KMP�㷨��ʱ�临�Ӷ�ΪO(m+n)
    void getNNext(string pattern, int * next){
        int i=1;//��׺����Ե�
        int j=0;//ǰ׺�ǹ̶���
        next[1]=0;
        while(i<pattern.length()-1){
        if(j==0||pattern[i]==pattern[j]){
            i++;
            j++;
            next[i]=j;//�����ʱiλ���ϣ�next�����ֵ; �Դ˸Ľ�
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
    
        int i=1;//st��
        int j=1;//pattern��
        while(i<=str.length()-1&&j<=pattern.length()-1){
            if(j==0||str[i]==pattern[j]){
                i++;
                j++;
            }
            else{
                j=next[j];//��Ϊ��next����,j==0�п��ܣ���j=0����pattern��һ���ַ���ʼƥ��
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
