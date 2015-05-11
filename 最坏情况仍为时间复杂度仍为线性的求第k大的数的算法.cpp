#include <stdlib.h>
#include <stdio.h>
#define swap(a,b) (a)^=(b);(b)^=(a);(a)^=(b)
#define MAX 1000

void sort(int* input, int size){
    printf ( "sort arry size = %d\n", size );
    int i,j;
    for(i = 0; i< size ; i++){
        for(j = 0; j<size-i-1;j++){
            if(input[j]<input[j+1]){
                swap(input[j],input[j+1]);
            } 
        }
    }
}
void output(int * input, int size){
    for(;size>0 && *input;size--,input++){
        printf("%d ", *input);
    }
    printf("\n");

}

int partion(int *input, int size, int key){
    printf ( "--------------Step4---------------\n" );
    printf("key = %d \n", input[key]);
    int *head, *tail;
    head = input;
    tail = head + size - 1;
    swap(*head, input[key]);

    int *k = head;
    while(head<tail){
        while(*tail && *k >= *tail){
            tail--;
        }
        if(tail<=head) break;
        swap(*k,*tail);
        k = tail;
        while(*head && *k < *head)
            head++;
        if(head>=tail) break;
        swap(*k,*head);
        k = head;
    }
    output(input, size);
    printf ( "--------------Step4 done--------------\n" );
    return k-input+1;
}

int kselect(int *input, int size, int k){
    printf ( "start element : %d \n", *input );
    if(size<=5){
        sort(input, size);
        return input[k-1];
    }
    int mid[MAX] = {0};
    int midvalue[MAX] = {0};
    int groups = size/5;
    int i;

    printf ( "-----------------step 1, 2--------------\n" );
    for(i = 0; i<groups;i++){
        sort(input+i*5, (i*5+5 > size) ? (size-1):5);
        printf ( "sorted group %d:\n", i );
        output(input+i*5, 5);
        mid[i] = i*5 + 2;
        midvalue[i] = input[i*5 + 2];
    }

    printf ( "-----------------step 1, 2 done--------------\n" );

    printf ( "---------step3-------------\n" );
    sort(midvalue, groups);
    printf ( "---------step3 done-------\n" );
    int m = -1;
    for(i = 0; i<5;i++){
        if(input[mid[i]] == midvalue[groups/2]){
            m = partion(input, size, mid[i]);
        }
    }
    if(m == k){
        return input[m-1];
    }
    if(k<m){
        return kselect(input,m,k);
    }
    else{
        return kselect(input+m, size - m, k-m);
    }
    return 0xffff;
}

int main(){
    int input[] = {1,3,2,10,5,11, 12, 8 ,6, 7};
    int r = kselect(input,sizeof(input)/sizeof(int), 7);
    printf("result %d \n", r);
    return 0;
}
