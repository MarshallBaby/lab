import math
import random
import pprint

def f(x):
    return x/math.sqrt(1 + x)

print("x0:")
x0 = float(input())
print("x1:")
x1 = float(input())
print("y0:")
y0 = float(input())
print("y1:")
y1 = float(input())

s_rect = abs((x0 - x1) * (y0 - y1))

n_array = []

print ("N: ")

for i in range(int(input())):
    value = []
    value.append(random(x0, x1))
    value.append(random(y0, y1))
    n_array.append(value)

print(s_rect)