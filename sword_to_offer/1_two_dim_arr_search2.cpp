#include <vector>
#include <iostream>
#define debug
using namespace std;
class Solution {
public:
    typedef vector<vector<int> > vv;
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty() || array[0].empty())
            return false;
        int rows = array.size();
        int cols = array[0].size();
        for (int i=0,j=cols-1;  i<rows && j>=0 ;){
            #ifdef debug
            cout<<i<<" "<<j<<" "<<array[i][j];
            #endif
            if (array[i][j] == target) return true;
            if (array[i][j] > target){
                #ifdef debug
                cout <<">";
                #endif
                j--;
            }
            else  {
                #ifdef debug
                cout<<"<";
                #endif
                i++;
            }
            #ifdef debug
            cout<<target<<endl;
            #endif
        }
        return false;
    }
};

int main()
{
    Solution::vv a={{1,2,8,9}, {2,4,9,12},{4,7,10,13},{6,8,11,15}};
    Solution b;
    bool res = b.Find(16, a);
    cout<<res<<endl;
    cout<<(1,2)<<endl;
    return 0;
}