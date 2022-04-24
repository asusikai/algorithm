
'''
i째 날에 샀을 때를 생각해서

그때마다 정렬을 해서 최대 차이를 구한다.(시간 초과)

'''

class Solution:
    def maxProfit(self, prices: list[int]) -> int:

        min_price = prices[0]

        profit = 0

        for price in prices:

            min_price = min(price, min_price)

            profit = max(profit, price-min_price)
        
        return profit

test = Solution()
inputs = [7,1,5,3,6,4]
print(test.maxProfit(inputs))