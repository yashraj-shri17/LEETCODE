
class Solution(object):
    def strStr(self, h, n):
        i, j = 0, 0
        while i < len(h) and j < len(n):
            if h[i] == n[j]:
                i += 1
                j += 1
            else:
                i -= j - 1
                j = 0
        return i - j if j == len(n) else -1