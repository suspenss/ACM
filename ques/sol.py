def sol():
	n = int(input())
	A = [int(x) for x in input().split()]
	B = [int(x) for x in input().split()]

	s = set()

	for i in range(n):
		if (A[i] == 0 and B[i] == 0):
			continue
		cur = 0
		a = A[i]
		b = B[i]
		while a > 0:
			b %= 2 * a
			[a, b] = (b, abs(a - b))
			cur += 1

		s.add(cur % 3)

	if (len(s) <= 1):
		print("YES")
	else:
		print("NO")

def main():
	T = int(input())
	for i in range(T):
		sol()

main()