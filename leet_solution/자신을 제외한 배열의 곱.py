class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:

        p = 1
        p_list = list()
        
        for n in nums:
            
            p_list.append(p)
            p *= n

        p = 1

        for i in range(len(nums)-1, -1 , -1):
            p_list[i] = p_list[i]*p
            p = p*nums[i]


        return p_list


test = Solution()
nums = [1,2,3,4]

print(test.productExceptSelf(nums))