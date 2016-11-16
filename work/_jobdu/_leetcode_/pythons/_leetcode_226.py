# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if( root == None ):
        	return root
        if( root.left == None && root.right == None):
            return root
        p = root.right
        root.right = invertTree(root.left)
        root.left = invertTree(p)
        return root
        