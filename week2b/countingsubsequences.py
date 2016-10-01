def readData():
	test_cases = raw_input()
	for i in xrange(0,int(test_cases)):
		num = raw_input()
		space = raw_input()
		input = raw_input()
		input = input.split(" ")
		data = [0]
		data+= input
		for j in xrange(len(data)):
			data[j] = int(data[j])
		for j in xrange(1, len(data)):
			data[j] += data[j-1]
		dict = {}
		dict[0] = 1

		count = 0
		for j in xrange(1,len(data)):
			key = data[j] - 47
			if key not in dict:
				dict[key] = 0
			count = count + dict[key]
			dict[data[j]] = 1
		print count
readData()