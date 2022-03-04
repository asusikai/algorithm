'''
배열을 입력받아 output[i]가 자신을 제외한 나머지 모든 요소의 곱셈 결과가 되도록 출력하라.

for 문 활용하여 전체 곱에서 나누기 실행
=======================

slicing 으로 문제 해결

O(1) 시간 복잡도로 해결할 수 있나?


'''

class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:

        product = 1
        result = list()
        product_list = list()
    
        for n in nums[::-1]:
            
            product_list.append(product)
            product *= n


        p = 1

        for i, n in enumerate(nums):
            
            
            result.append(product*product_list[len(product_list)-i-1])
            product *= n

        return result


test = Solution()
nums = [1,2,3,4]

print(test.productExceptSelf(nums))