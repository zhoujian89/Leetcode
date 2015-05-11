  #include<iostream>
  using namespace std;
  void swap(int & u,int & v){
  	int temp=u;
	  u=v;
	  v=temp;
  }
  void sortColors(int A[], int n) {
  	int  low=0,high=n-1,p=0;
    while(p<=high){
    	if(A[p]==0){
    		if(low!=p){
    		swap(A[low],A[p]);
    	}
    		p++;
    		low++;
    	}
    	else if(A[p]==2){
    		swap(A[p],A[high]);
    		high--;
    	}
    	else {
    	 p++;	
    	}
    }
  	
  
  	/* while(low<=high&&A[high]==2) high--;
  	 while(low<=high&&A[low]==0) low++;
  	 p=low;
     while(low<=high){
     	if(A[p]==0&&p!=low){
     	temp=A[low];A[low]=A[p];A[p]=temp;
     	
		while(A[low]==0&&low<=high) low++;//遇到连续的0向前	
     	}
     	if(A[p]==2&&p!=high){
     	temp=A[high];A[high]=A[p];A[p]=temp;
     	
     	while(A[high]==2&&low<=high) high--;//遇到连续的2向后 
     	}
     	p++;
     }
  /*	while(low<=high){
  	while(low<=high&&A[high]==2) high--;
  	while(low<=high&&A[low]==0) low++;
  /*	if(A[high]==0){
  		temp=A[high];A[high]=A[low];A[low]=temp;
  		low++;
  	}
  	if(A[low]==2){
  		temp=A[low];A[low]=A[high];A[high]=temp;
  		high--;
  	}*/
    
	// }
	 
        
    }
    int main(){
    	int n;
    	int *a;
    	a=new int[n];
    	cout<<"输入排序元素个数"<<endl; 
    	cin>>n;
    	cout<<endl;
		cout<<"输入元素"<<endl;
		for(int i=0;i<n;i++)
		cin>>a[i];
		sortColors(a,n);
		cout<<"结果"<<endl;
		for(int i=0;i<n;i++)
		cout<<a[i]<<"   "; 
    	return 1;
    }
