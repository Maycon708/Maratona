t = 0
while(42):
	try:
		n = raw_input()
		n = int(n)
		if n == 0:
			break
		t = t+1
		a = 0
		b = 0
		for i in range(n):
			x, y = raw_input().split()
			x, y = int(x), int(y)
			a = a + x
			b = b + y
		print 'Teste', t
		if a > b:
			print 'Aldo'
		else:
			print 'Beto'
		print
	except:
		break
