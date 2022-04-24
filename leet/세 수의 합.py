'''
1. list 정렬
2. 양 끝의 포인터에서 시작

case
1. 양끝의 합이 0일 때
음 양-> 0 탐색, 0,0 -> 사이에 0 탐색
2. 양끝의 합이 양수 일 때
음 양-> 음수 찾기, 양 양 -> X
3. 양끝의 합이 음수 일 때
음 음-> X, 음 양 -> 양수 찾기
'''


class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        
        nums.sort()
        result = list()

        for i in range(len(nums)-2):
            
            if nums[i] > 0:
                break

            
            left = i+1
            right = len(nums)-1

            


        return result

test = Solution()
nums = [-1,0,1,2,-1,-4]

print(test.threeSum(nums))