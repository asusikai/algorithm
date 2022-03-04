import sys

class Solution:
    def maxProfit(self, prices: list[int]) -> int:

        min_price = sys.maxsize
        profit = 0

        for price in prices:

            min_price = min(price, min_price)

            profit = max(profit, price-min_price)
        
        return profit