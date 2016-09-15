def readData():
	test_cases = int(raw_input())
	for i in xrange(test_cases):
		number = int(raw_input())
		phonelist = {}
		for j in xrange(number):
			input = raw_input()
			phonelist[input] = 1
		result(phonelist)
		print phonelist
	return
def result(phonelist):
	status = 0
	for x in phonelist:
		# check = phonelist
		# del check[x]
		if (x in phonelist):
			status += 1
			if (status > 1):
				break
	if (status > 1):
		print "No"
	else:
		print "Yes"
readData()