'''
n개의 페어를 이용한 min(a,b)의 합으로 만들 수 있는 가장 큰 수를 출력하라.

1. sorted 로 정렬
2. 한 쌍씩 min 함수 실행

'''

inputs = [1,4,3,2]
output = 4

class Solution:
    def arrayPairSum(self, nums: list[int]) -> int:
        
        nums = sorted(nums)
        PairSum = 0
        for i in range(0,len(nums),2):
            PairSum += min(nums[i], nums[i+1])
        
        return PairSum
    

test = Solution()
print(test.arrayPairSum(inputs))
