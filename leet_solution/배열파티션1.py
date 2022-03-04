class Solution:
    def arrayPairSum(self, nums: list[int]) -> int:
        
        nums.sort()
        PairSum = 0

        Pair = list()

        for n in nums:
            Pair.append(n)
            if len(Pair) == 2:
                PairSum += min(Pair)
                Pair = []

        return PairSum

    def arrayPairSum(self, nums: list[int]) -> int:
        
        return sum(nums.sort()[::2])

        