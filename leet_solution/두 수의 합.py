#in을 이용한 탐색

def twoSum(self, nums: list[int], target:int)-> list[int]:
    for i, n in enumerate(nums):
        complement = target - n

        if complement in nums[i+1:]:
            return [i, nums[i+1:].index(complement)+i+1]


#첫 번째 수를 뺀 결과 key 조회

def twoSum(self, nums: list[int], target:int)-> list[int]:
    nums_dict = dict()

    for i, n in enumerate(nums):
        nums_dict[n] = i

    for i, n in enumerate(nums):
        if target - n in nums_dict:
            return [ i , nums_dict[target-n]]

#질문 : dict 의 같은 key에 다른 값을 넣고자 하면 어떻게 되는가?
#답 : 나중에 넣은 값으로 수정된다.
