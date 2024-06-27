class Solution(object):
    def removeElement(self, nums, val):
        k = 0  # Pointer for the position to place elements not equal to val
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]  # Place the element at position k
                k += 1  # Move k to the next position
        return k
