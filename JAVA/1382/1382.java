/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int size = 0;
    int[] nums = new int[10000];
    
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length == 0){
            return null;
        }
        int index = nums.length / 2;
        TreeNode node = new TreeNode(nums[index]);
        int[] leftArray = new int[index];
        for(int i = 0;i<leftArray.length;i++) {
            leftArray[i] = nums[i];
        }
         node.left = sortedArrayToBST(leftArray);
         int[] rightArray = new int[nums.length - index - 1];
         for(int i = 0;i<rightArray.length;i++) {
             rightArray[i] = nums[index + 1 + i];
         }
         node.right = sortedArrayToBST(rightArray);
        return node;
}

    public void bianli(TreeNode root){
        if(root.left != null) bianli(root.left);
        nums[size++] = root.val;
        if(root.right != null) bianli(root.right);
    }
    
    public TreeNode balanceBST(TreeNode root) {
        bianli(root);
        int[] results = new int[size];
        results = Arrays.copyOfRange(nums, 0, size);
        return sortedArrayToBST(results);
    }
}