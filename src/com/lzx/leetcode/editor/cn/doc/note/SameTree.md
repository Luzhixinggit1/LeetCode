### 深度优先搜索
1. 如果两颗二叉树都为空，则两颗二叉树相同
2. 如果两颗二叉树都不为空，那么比较两颗二叉树的值是否相同如果相同，则两颗二叉树相同
3. 再按照这样的方式比较两颗二叉树的左子树是否相同以及右子树是否相同
4. 这是一个递归的过程

```java
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
        return true;
        } else if (p == null || q == null) {
        return false;
        } else if (p.val != q.val) {
        return false;
        } else {
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        }
    }
```
