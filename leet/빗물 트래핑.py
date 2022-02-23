'''
1. 정수 list 를 입력 받는다.
2. 2개 포인터 사용

pointer case
right pointer가 낮

'''

class Solution:
    def trap(self, height: list[int]) -> int:
        left = 0
        right = 0

        water = 0
        
        while(left < len(height)):
            right+=1

            if right >= len(height):
                left += 1
                right = left
                continue

            if height[left] <= height[right]:
                for i in height[left:right]:
                    water += min(height[left], height[right]) -i
                
                left = right

        return water

test = Solution()

trap = [4,2,3]

print(test.trap(trap))

            
