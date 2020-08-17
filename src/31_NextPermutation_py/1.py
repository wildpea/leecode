#!/usr/local/bin/python3
#coding: utf8
import unittest

class Solution:
    def nextPermutation(self, nums) -> None:
        if len(nums) == 0:
            return
        
        total = len(nums)
        m_num = nums[total - 1]

        i = total-2
        while i >= 0:
            print(nums)
            if nums[i] < m_num:
                j = i + 1
                #nums[j:].sort()
                while j < total:
                    if nums[j] > nums[i]:
                        nums[i],nums[j] = nums[j],nums[i]
                        nums[j:].sort()
#                         x = j
#                         while x < total - 1:
#                             if (nums[x] > nums[x+1]):
#                                 nums[x],nums[x+1] = nums[x+1],nums[x]
#                             x = x+1
                        break
                    j = j + 1
                return
            else:
                pass
            m_num = nums[i]
            i = i - 1
        nums.sort()
        
class TestSolution(unittest.TestCase):
    def test_nextPermutation(self):
        sol = Solution()
        
#         nums = [1,2,3,4,5]
#         sol.nextPermutation(nums)
#         assert nums == [1,2,3,5,4]
#            
#         nums = [1,1,5]
#         sol.nextPermutation(nums)
#         assert nums == [1,5,1]
#           
#         nums = [3,2,1]
#         sol.nextPermutation(nums)
#         assert nums == [1,2,3]
#           
#         nums = [1,2,3]
#         sol.nextPermutation(nums)
#         assert nums == [1,3,2]
          
        nums = [1,3,2]
        sol.nextPermutation(nums)
        print(nums)
#         assert nums == [2,1,3]
#           
#         nums = [2,1,3]
#         sol.nextPermutation(nums)
#         assert nums == [2,3,1]
#           
#         nums = [3,1,2]
#         sol.nextPermutation(nums)
#         assert nums == [3,2,1]
#           
#         nums = [3,2,1]
#         sol.nextPermutation(nums)
#         assert nums == [1,2,3]
#         
#         nums = [2,3,1]
#         sol.nextPermutation(nums)
#         assert nums == [3,1,2]
        
if __name__ == "__main__":
    nums = [1,2,4,6,4,5,6,4,3,2,1]
    #nums.sort()
    print(nums[5:])
    
    print(nums)
    #unittest.main()
    