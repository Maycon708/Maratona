t = 1
while(42):
	try:
		n = raw_input()
		n = int(n)
		if n == 0:
			break
		n1 = raw_input()
		n2 = raw_input()
		print "Teste", t
		for i in range(n):
			a, b = raw_input().split()
			a, b = int(a), int(b)
			if (a+b)&1 :
				print n2
			else:
				print n1
		t = t+1
		print 
	except:
		break
