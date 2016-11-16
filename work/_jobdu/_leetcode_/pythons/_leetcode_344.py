class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        size = len(s)
        for i in range(size):
            res += s[size-i-1]
        return res
