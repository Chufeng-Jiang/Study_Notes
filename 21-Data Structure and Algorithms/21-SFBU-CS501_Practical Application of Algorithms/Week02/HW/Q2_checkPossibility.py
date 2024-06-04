class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        """ We can only modify at most one element, that means we can only change one of the elements for 1 time."""
        flag = True

        """ 
        We traverse the array,and each time we compare 3 consecutive elements, 
        because we have to consider that after the modification, whether the new array can satisfy 
        that ① the visited elements are non-decreasing and ②the incoming elements are also non-decreasing. 

        Input = [3,4,2,5]:
                        5
                /4     /
             3 /  \\   /
                    \\2
        In this case, we can modify 4 or 2 to make a non-decreasing order.
        However, since the trough 2 is even smaller than the number of 3 which is 2 position in front of it: 
        (1) if we reduce 4 to 2, then [3,2,2,|...] doesn't satisfy our requirement, and need further modification.
        (1) if we increase 2 to 4, then [3,4,4,|...] satisfy our requirement.

        Input = [1,4,2,5]:
                          /5
                  /4     /
                 /  \\   / 
                /    \\2/  
             1 /  
        In this case,  we only need to modify 4, because the trough of 2 is higher than the minimum 1 which is 2 position in front of it.

        """
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:  # [3,4,2,5], i=1, nums[1]= 4 > nums[2]=2
                if flag == False:
                    return False

                if i == 0 or nums[i + 1] >= nums[i - 1]:  # [1,4,2,5], i = 1, nums[1]= 4 > nums[2]=2
                    nums[i] = nums[i + 1]  # [1,2,2,5]

                else:  # [3,4,2,5], i=1, nums[2]=2 < nums[0]=3
                    nums[i + 1] = nums[i]  # [3,4,4,5]

                flag = False
        return True


""""""""""""""""""""""""""""""""


def test():
    solution = Solution()
    nums = [4, 2, 1]

    a = solution.checkPossibility(nums)

    if a == False:
        print("Q2 Test case passed.\n")


test()