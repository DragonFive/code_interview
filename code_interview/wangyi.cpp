#include <iostream>   
using namespace std;  
/* 
n个骰子各个点数和出现的概率  
*/  
//n  为骰子个数   
int FindSum(int n)   
{  
    int** array=NULL;  
    array = new int*[n*6+1];  
    int i,j;  
    for(i=0;i<6*n+1;i++)  
        array[i] = new int[n+1];  
    for(j=0;j<=n;j++)  
    {  
        for(i=0;i<=n*6;i++)  
            array[i][j]  =0;  
          
    }     
          
    for(j=1;j<=n;j++)  
    {  
        for(i =j;i<=6*j;i++)  
        {  
            if(j == 1 || i == j || i == 6*j)  
                array[i][j] = 1;  
            else  
            {  
                int k = i-1;  
                for(k = 1;k<=6;k++)  
                    if(i-k>= j-1)  
                        array[i][j] += array[i-k][j-1];                   
            }  
        }  
    }  
      
    for(j=1;j<=n;j++)  
    {  
        for(i=j;i<=6*j;i++)  
            cout<<array[i][j]<<"  ";  
        cout<<endl;  
    }  
    for(i=0;i<6*n+1;i++)  
        delete [] array[i];  
    delete [] array;  
}   
  
   
int main()  
{  
    FindSum(3);   
    return 0;  
}  
