while(42):
	try:
		w = 994393873
		n = input()
		v = []
		v = map( int, raw_input().split() )
		ans = 1
		last = -w
		for i in range(1, n):
			if last == -w:
				last = v[i] - v[i-1]
			if v[i] - v[i-1] != last:
				ans = ans+1
				last = -w
		print ans
	except:
		break
