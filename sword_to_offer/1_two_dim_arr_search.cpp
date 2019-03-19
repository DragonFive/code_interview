#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    typedef vector<vector<int> > vv;
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty() || array[0].empty())
            return false;
        return bin_search(array, 0, array[0].size()-1, target);
    }
    bool bin_search(const vv &arr, size_t begin_line, size_t end_col, int target){
        auto rows = arr.size();
        auto cols = arr[0].size();
        
        if (begin_line == rows-1 && end_col == 0){
            if (arr[begin_line][end_col] != target)return false;
            return true;
        }
        if (begin_line == rows-1){
            int res= search_line(arr, begin_line, end_col, target);
            if (res>=cols && arr[rows-1][res] != target)return false;
            return true;
        }
        if (end_col == 0){
            int res = search_col(arr, begin_line, 0, target);
            if (arr[res][0] == target)return true;
            return false;
        }
        //cout<<"hehe"<<endl;
        int res2 = search_col(arr, begin_line, end_col, target);
        if (res2>=rows)return false;
        //cout <<res2<<" get "<<end_col<<" "<< arr[res2][end_col]<<endl;
        if (arr[res2][end_col] == target) return true;
        return bin_search(arr, res2, end_col-1, target);
    }
    int search_line(const vv &arr, size_t row, size_t end, int target){
        int i = 0, j = end;
        while (i<=j){
            int mid = (i+j)/2;
            if (arr[row][mid] == target)
                return mid;
            if (arr[row][mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return i;
    }
    int search_col(const vv &arr, size_t begin_line, size_t col, int target){
        int rows = arr.size();
        int i = begin_line, j = rows-1;
        while (i<=j){
            int mid = (i+j)/2;
            //cout<<"mid " << mid << endl;
            if (arr[mid][col] == target)
            {
                //cout<<col<<" get2 "<<mid<<" "<<target<<endl;
                return mid;
            }
            if (arr[mid][col] > target)
                j = mid-1;
            else
                i = mid+1;
        }
        return i;
    }
};

int main()
{
    Solution::vv a={{1,2,8,9}, {2,4,9,12},{4,7,10,13},{6,8,11,15}};
    Solution b;
    bool res = b.Find(16, a);
    cout<<res<<endl;
    return 0;
}