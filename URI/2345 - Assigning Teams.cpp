def min( a, b ):
	if a <= b:
		return a
	else:
		return b

def abs(a):  
	if a < 0:
		return a * -1
	else:
		return a
		
while(42):
	try:
		v = []
		v = map( int, raw_input().split() )
		ans = abs( ( v[0] + v[3] ) - ( v[1] + v[2] ) )
		ans = min( ans, abs( ( v[0] + v[1] ) - ( v[3] + v[2] ) ) )
		ans = min( ans, abs( ( v[0] + v[2] ) - ( v[1] + v[3] ) ) )
		print ans
	except:
		break 
