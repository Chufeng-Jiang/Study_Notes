class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        """we define a reverse function to reverse the elements from index_l to index_r in the given nums array"""

        def reverse(index_l, index_r):
            while index_l < index_r:
                nums[index_l], nums[index_r] = nums[index_r], nums[index_l]
                index_l += 1
                index_r -= 1

        """ special cases"""
        if not nums or k == 0: return

        """ 
        Input: nums = [1,2,3,4,5,6,7], k = 3

        1st, we reverse the whole array --> [7,6,5,4,3,2,1]
        2nd, we slice the array into two parts --> [7,6,5] [4,3,2,1]
        3rd, we reverse the individual two arrays separatly --> [5,6,7] [1,2,3,4]

        finally, we get the result and return the array.
        """
        size = len(nums)  # get the length of the array

        """
        To prevent the overflow of k.
        For example when k(103) > size(7),
        the residule of k % size is 5 (103/7=14---5);
        so we rotate the array to the right by 5 steps which is equal to 103 steps.
        """
        k %= size  # revise the steps to rotate

        reverse(0, size - 1)  # [1,2,3,4,5,6,7] --> [7,6,5,4,3,2,1]
        reverse(0, k - 1)  # [7,6,5] -->[5,6,7]
        reverse(k, size - 1)  # [4,3,2,1] --> [1,2,3,4]
        return None


""""""""""""""""""""""""""""""""


def test():
    solution = Solution()
    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3
    solution.rotate(nums, k)
    expected_array = [5, 6, 7, 1, 2, 3, 4]

    if nums == expected_array:
        print("Q1 Test case passed.\n")


test()
