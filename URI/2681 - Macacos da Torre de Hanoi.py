def fastExp(b,e):
	ans = 1
	while(e):
		if e&1:
			ans = ( ans * b )%86400
		b = ( b * b )%86400
		e = e/2
	return ans

while(42):
	try:
		n = input()
		ans = fastExp(2, n)-1
		h = ans/3600
		m = (int)(ans%3600)/60;
		s = (int)(ans%60)
		print '{0:02d}:{1:02d}:{2:02d}'.format(h, m, s)
		
		
	except:
		break