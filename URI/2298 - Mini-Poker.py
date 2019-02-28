def sequencia( v ):
	for i in range(5):
		if v[i] != v[0] + i:
			return 0
	return v[0] + 200

def iguais( v ):
	trinca = 0
	par = 0
	par2 = 0
	for i in range(5):
		if v[i] != trinca:
			cnt = 0
			for j in range( i, 5 ):
				if v[i] == v[j]:
					cnt = cnt+1
			if cnt == 4:
				return v[i] + 180
			if cnt == 3:
				trinca = v[i]
			if cnt == 2:
				if par == 0:
					par = v[i]
				else:
					par2 = v[i]
	if trinca:
		if par:
			return trinca + 160
		else:
			return trinca + 140
	else:
		if par:
			if par2:
				return 3 * par2 + 2 * par + 20
			else:
				return par
		else:
			return 0

n = input()
v = []
t = 1
for i in range(n):
	v = map( int, raw_input().split() )
	v.sort()
	print 'Teste', t
	t = t+1
	if sequencia(v) != 0:
		print sequencia(v)
	else:
		print iguais(v)
	print	
