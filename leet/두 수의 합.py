'''
덧셈하여 target의 수를 만들 수 있는 두 숫자의 인덱스를 반환 한다

덧셈의 모든 경우의 수를 체크한다.

'''

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:

        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j] == target:
                    return [i,j]


test = Solution()

nums = [3,3]
target = 6

print(test.twoSum(nums, target))
