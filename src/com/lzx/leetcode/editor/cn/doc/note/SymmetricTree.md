### 深度优先搜索

1. 如果一颗左子树与右子树是镜像的，那么这棵树是对称的
2. 两棵树是镜像的应该满足如下条件：
   1. 它们的两个根节点的值是相同的
   2. 每个树的右子树和左子树都是镜像的对称的

```java

public boolean isSymmetric(TreeNode root) {
        if (root == null) {
        return true;
        }

        return isSame(root.left, root.right);
        }

private boolean isSame(TreeNode node1, TreeNode node2) {
        if (node1 == node2) {
        return true;
        }

        if (node1 == null || node2 == null) {
        return false;
        }

        return node1.val == node2.val && isSame(node1.left, node2.right) && isSame(node1.right, node2.left);
        }
```
