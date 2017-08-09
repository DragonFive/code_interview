# 代码

```cpp

#include <iostream>  
#include <vector>  
using namespace std;  
  
//交换操作  
void Swap(int &a,int &b)  
{  
    int temp = a;  
    a = b;  
    b = temp;  
}  
  
//标准的快排方法  
int partion(int a[],int left,int right)//首先进行分区操作  
{  
    int flag = a[left];//将首元素当作标杆，选择最右边元素最为标杆时代码会有略微不同  
    int j = left;  
    for (int i = left+1; i <= right; ++i)//首先忽略首元素  
    {  
        if (a[i] < flag)  
        {  
            j++;  
            if ( j != i)  
            {  
                Swap(a[i],a[j]);//将标杆数一直往右移动，遇到比标杆数小的就交换到从头开始的位置上  
            }  
        }  
    }  
    Swap(a[j],a[left]);//j位置的元素和首元素互换，即可保证标杆元素左边为小于等于，右边为大于等于  
    return j;  
}  
  
//取区间内随机数的函数    
int Rand(int low, int high)    
{    
    int size = high - low + 1;    
    return  low + rand()%size;     
}   
int partion1(int a[],int left,int right)//首先进行分区操作  
{  
    Swap(a[Rand(left,right)],a[left]);//随机选择区间的一个数,将其与首元素进行交换  
    int flag = a[left];//将首元素当作标杆  
    int j = left;  
    for (int i = left+1; i <= right; ++i)//首先忽略首元素  
    {  
        if (a[i] < flag)  
        {  
            j++;  
            if ( j != i)  
            {  
                Swap(a[i],a[j]);//将标杆数一直往右移动，遇到比标杆数小的就交换到从头开始的位置上  
            }  
        }  
    }  
    Swap(a[j],a[left]);//j位置的元素和首元素互换，即可保证标杆元素左边为小于等于，右边为大于等于  
    return j;  
}  
  
//标准递归版本的快速排序  
void Fast_sort(int a[],int left,int right)  
{  
    if (left < right)  
    {  
        int index = partion1(a,left,right);//partion也可以  
        Fast_sort(a,left,index-1);  
        Fast_sort(a,index+1,right);  
    }  
}  
  
int main(int argc, char **argv)  
{  
    int a[10] = {12,45,748,12,56,3,89,4,48,2};  
  
    Fast_sort(a,0,9);  
    for (size_t i = 0; i != 10; ++i)  
    {  
        cout<<a[i]<<" ";  
    }  
    cin.get();  
    return 0;  
}  
```

## 改进点 

随机选择flag元素


