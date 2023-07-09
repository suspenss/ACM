T = int(input())

def sol(a, b):
	print(a + b)

for i in range(T):
	a, b = [int(x) for x in input().split()]
	sol(a, b)
