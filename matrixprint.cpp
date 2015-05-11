#include <iostream>  
using namespace std;  
  
void PrintMatrixIncircle(int **nArr, int rows, int columns, int nStart)  
{  
    int nEndX = columns - 1 -nStart;  
    int nEndY = rows - 1 -nStart;  
    //�����Ҵ�ӡһ��  
    for (int i=nStart; i<=nEndX; i++)  
    {  
        cout << nArr[nStart][i] << " ";  
    }  
  
    //���ϵ��´�ӡһ��  
    if (nEndY > nStart)  
    {         
        for (int j=nStart+1; j<=nEndY; j++)  
        {  
            cout << nArr[j][nEndX] << " ";  
        }  
    }  
      
    //���ҵ����ӡһ��  
    if (nEndY > nStart && nEndX > nStart)  
    {         
        for (int t=nEndX-1; t>=nStart; t--)  
        {  
            cout << nArr[nEndY][t] << " ";  
        }  
    }  
  
    //���µ��ϴ�ӡһ��  
    if (nEndY -1 > nStart && nEndX > nStart)  
    {         
        for (int n=nEndY-1; n>=nStart+1; n--)  
        {  
            cout << nArr[n][nStart] << " ";  
        }  
    }     
}  
  
//˳ʱ���ӡ��������Ϊrows������Ϊcolumns  
void PrintMatrixClockWisely(int **nArr, int rows, int columns)  
{  
   if (nArr == NULL || rows <= 0 || columns <= 0)  
   {  
       return;  
   }  
  
   int nStart = 0;  
   while (rows>(nStart*2) && columns>(nStart*2))     
   {  
       PrintMatrixIncircle(nArr, rows, columns, nStart);  
       nStart++;  
   }  
}  
  
  void Test(int columns, int rows)  
{  
    cout<<"Test Begin:"<<columns<<" columns,"<<rows<<" rows."<<endl;  
    if(columns < 1 || rows < 1)  
        return;  
  
    int** numbers = new int*[rows];  
    for(int i = 0; i < rows; ++i)  
    {  
        numbers[i] = new int[columns];  
        for(int j = 0; j < columns; ++j)  
        {  
            numbers[i][j] = i * columns + j + 1;  
        }  
  
    }  
     for(int i = 0; i < rows; ++i)  
    {  
        for(int j = 0; j < columns; ++j)  
        {  
            cout<<numbers[i][j]<<" "; 
        }  
        cout<<endl;
  
    }
	cout<<endl; 
    PrintMatrixClockWisely(numbers, rows, columns);
    cout<<endl;  
    for(int i = 0; i < rows; ++i)  
        delete[] (int*)numbers[i];  
    delete[] numbers;  
}  
int main(){
/*	vector< vector<int> > v;
	vector<int> ve;
	ve.push_back(0);
	v.push_back(ve);
	cout<<v[0][0]<<endl;*/
//	 Test(1,1);  
  //  Test(2,2);  
  //  Test(4,4);  
  //  Test(5,5); 
    Test(5,6);
  //  Test(15,15); 
  Test(6,9);
	return 1;
}
