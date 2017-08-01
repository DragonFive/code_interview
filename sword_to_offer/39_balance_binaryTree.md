# source

[剑指offer-判断平衡二叉树](https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

# solution

```cpp
    bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth;
        return IsBalanced(pRoot, depth);
    }
    bool IsBalanced(TreeNode * pRoot, int &depth){
        if (pRoot == NULL){
            depth = 0;
            return true;
        }
        int leftDept = 0, rightDept = 0;
        if (IsBalanced(pRoot->left, leftDept) && IsBalanced(pRoot->right, rightDept)){
            int diff = leftDept - rightDept;
            if (diff <= 1 && diff >= -1){
                depth = max(leftDept, rightDept) + 1;
            	return true;
            }
            return false;
        }
        return  false;
    }
```
