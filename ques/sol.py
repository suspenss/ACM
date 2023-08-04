from sys  import stdin
from math import sqrt

input = stdin.readline
    
class Point:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y

    def __lt__(self, other):
        self__ = (self.x ** 2) + (self.y ** 2)
        other__ = (other.x ** 2) + (other.y ** 2)
        return self__ < other__


a = Point(1, 3); b = Point(2, 9); c = Point(-1, -101)
print(a < b < c)