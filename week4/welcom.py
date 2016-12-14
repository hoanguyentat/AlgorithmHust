import sys
def ssw(a): sys.stderr.write(str(a))

def checkResult(i, j):
	if (i, j) in mem:
		return mem[(i, j)]
	if (j >= len(phrase)):
		return 1
	if (i >= len(text)):
		return 0
	res = checkResult(i + 1, j)
	if (text[i] == phrase[j]):
		res += checkResult(i + 1, j + 1)
	res %= 10000
	mem[(i, j)] = res
	return res	

for test in range(int(raw_input())):
	ssw("Test %d\n" % (test + 1))
	global text, phrase, mem
	text = raw_input()
	phrase = "welcome to code jam"
	mem = {}
	
	print "Case #%d: %04d" % (test + 1, checkResult(0, 0))