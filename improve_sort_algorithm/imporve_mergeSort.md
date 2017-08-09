# 代码

```cpp

#include <iostream>  
#include <vector>  
#include <time.h>  
#include <Windows.h>  
using namespace std;  
static int Max = 7;//自定义的使用插入排序的门限  
int _count = 0;//逆序对的个数  
  
/*第一种方法，传入参数为数组指针，左右限*/  
//函数作用：合并[left,mid][mid+1,right]  
void Merge(int a[],int left,int mid,int right)  
{  
    //两段区间的长度  
    int length1 = mid-left+1;  
    int length2 = right-mid;  
  
    //分配两段新的内存空间存储原内容  
    int *l1 = new int[length1];  
    int *l2 = new int[length2];  
  
    for (int i = 0; i < length1; ++i)  
    {  
        l1[i] = a[left+i];  
    }  
    for (int j = 0; j < length2; ++j)  
    {  
        l2[j] = a[j+mid+1];  
    }  
  
    //存入原内容之后，比较两个序列  
    int i = 0,j = 0;  
    int k = length1;  
    //比较两个序列的重合部分，进行排序  
    while (i<length1 && j<length2)  
    {  
        if (l1[i] < l2[j])  
        {  
            a[left++] = l1[i++];  
        }  
        else  
        {  
            a[left++] = l2[j++];  
            //因为l2[j]大于l1[i],所以l2[j]肯定大于[0,length-1]之中[0,i]之间的所有数，产生逆序对  
            if (l2[j] > l1[i])  
            {  
                _count +=  length1-i+1;  
            }         
        }  
    }  
    //两序列的剩余部分分别放于结尾  
    while (i<length1)  
    {  
        a[left++] = l1[i++];  
    }  
  
    while (j<length2)  
    {  
        a[left++] = l2[j++];  
    }  
  
    //分配的内存需要释放掉  
    delete []l1;  
    delete []l2;  
}  
void Merge_sort(int a[],int left,int right)  
{  
    if (left < right)  
    {  
        int mid = (left+right)/2;//首先进行分区，然后递归操作  
        Merge_sort(a,left,mid);  
        Merge_sort(a,mid+1,right);//第一次将其分为两个区间，进行合并操作  
        Merge(a,left,mid,right);  
    }  
}  
  
/*第二种方法，传入参数两个迭代器*/  
//Merge函数的重载，接受三个迭代器  
void Merge(vector<int>::iterator begin,vector<int>::iterator mid,vector<int>::iterator end)  
{  
    int length1 = (mid-begin)+1;  
    int length2 = end-mid;  
  
    int *p1 = new int[length1];  
    int *p2 = new int[length2];  
  
    for (int i=0; i < length1; ++i)  
    {  
        p1[i] = *(begin+i);  
    }  
    for (int j=0; j < length2; ++j)  
    {  
        p2[j] = *(mid+1+j);  
    }  
  
    int i = 0;  
    int j = 0;  
    int k = length1;  
    while (i<length1 && j<length2)  
    {  
        if(p1[i] < p2[j])  
        {  
            *(begin++) = p1[i++];  
        }  
        else  
        {  
            *(begin++) = p2[j++];  
  
        }  
    }  
  
    while(i < length1)  
    {  
        *begin++ = p1[i++];  
    }  
    while(j < length2)  
    {  
        *begin++ = p2[j++];  
    }  
  
    delete []p1;  
    delete []p2;  
}  
//对函数进行重载，传入一对迭代器，并进行第一次改进  
void Merge_sort(vector<int>::iterator begin, vector<int>::iterator end)  
{  
    //若只传递了一个参数，无需进行排序，直接输出  
    if (begin >= end)  
    {  
        return;  
    }  
    //对长度较小的自序列使用插入排序  
//  if ((end-begin) <= Max)  
//  {  
//      Insertion_sort(begin,end);  
//  }  
  
    if (begin != end)  
    {  
        auto mid = begin+(end - begin)/2;  
        Merge_sort(begin,mid);  
        Merge_sort(mid+1,end);//第一次将其分为两个区间，进行合并操作  
        if (*(mid+1) >= *mid)   
        {  
            return;  
        }  
        Merge(begin,mid,end);  
    }  
}  
      
int main(int argc, char **argv)  
{  
    clock_t Start_time = clock();  
    int a[10] = {23,56,78,6,59,15,49,81,15,56};  
    vector<int> vec(a,a+10);  
    Merge_sort(a,0,9);  
    for (size_t i = 0; i != 10; ++i)  
    {  
        cout<<a[i]<<" ";  
    }  
  
    cout<<endl;  
    Merge_sort(vec.begin(),vec.end()-1);//使用迭代器的版本出现的错误很低级，困扰了我一晚上，结果发现是传入的end迭代器是不可访问的  
    for (size_t i = 0; i != 10; ++i)  
    {  
        cout<<vec[i]<<" ";  
    }  
    cout<<endl;  
    cout<<"逆序对个数："<<_count<<endl;  
    clock_t End_time = clock();  
    cout<<"Running time is :"<<static_cast<double>(End_time-Start_time)/CLOCKS_PER_SEC*1000<<" ms"<<endl;  
    cin.get();  
    return 0;  
}  
```
