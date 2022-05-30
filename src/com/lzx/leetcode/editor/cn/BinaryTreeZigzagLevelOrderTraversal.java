//给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[20,9],[15,7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 广度优先搜索 二叉树 👍 633 👎 0

  
package com.lzx.leetcode.editor.cn;

import java.util.*;

public class BinaryTreeZigzagLevelOrderTraversal{
    public static void main(String[] args) {
         Solution solution = new BinaryTreeZigzagLevelOrderTraversal().new Solution();
    }
    //leetcode submit region begin(Prohibit modification and deletion)
  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

        Queue<TreeNode> queue = new ArrayDeque<>();
        List<List<Integer>> results = new ArrayList<>();
        if (root == null) {
            return results;
        }
        queue.add(root);
        boolean isLeft = true;

        while (!queue.isEmpty()) {
            int n = queue.size();
            List<Integer> tmp = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode tempNode = queue.poll();
                if (tempNode.left != null) {
                    queue.add(tempNode.left);
                }
                if (tempNode.right != null) {
                    queue.add(tempNode.right);
                }
                if (isLeft) {
                    tmp.add(tempNode.val);
                } else {
                    tmp.add(0, tempNode.val);
                }
            }
            isLeft = !isLeft;
            results.add(tmp);
        }

        return results;
    }

    public void dfs(TreeNode node, List<List<Integer>> results, int level) {
        if (node == null) return;

        if (results.size() <= level) {
            results.add(new ArrayList<>());
        }
        dfs(node.left, results, level + 1);
        if (level % 2 == 0) {
            results.get(level).add(node.val);
        } else {
            results.get(level).add(0, node.val);
        }
        dfs(node.right, results, level + 1);
    }
}
//leetcode submit region end(Prohibit modification and deletion)

}