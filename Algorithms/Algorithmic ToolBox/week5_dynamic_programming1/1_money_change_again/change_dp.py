# python3
import math

my_money = int(input())
my_denominations = [1, 3, 4]
my_minCoins = [0] + [math.inf]*my_money

for i in range(1, my_money+1):
    for j in my_denominations:
        if i>=j:
            coins = my_minCoins[i-j]+1
            if coins < my_minCoins[i]:
                my_minCoins[i] = coins

print(my_minCoins[my_money])
