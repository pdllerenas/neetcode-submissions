class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(len(nums) - i - 1):
                if target - nums[i] == nums[i + j + 1]:
                    return [i,i + j + 1]