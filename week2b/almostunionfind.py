def readData():
	_input = raw_input()
	_input = _input.split()
	data = []
	for i in xrange(0, int(_input[0])):
		data.append(i+1)
	for i in xrange(0, int(_input[1])):
		sequen = raw_input()
		sequen = sequen.split()
		for j in xrange(0, len(sequen)):
			sequen[j] = int(sequen[j])
		print data
		if sequen[0] == 1:
			if :
				pass
			data.remove(sequen[1])
			data.remove(sequen[2])
			data.append([sequen[1], sequen[2]])
		elif sequen[0] == 2:
			for x in data:
				if type(x) is list:
					if sequen[2] in x:
						x.append(sequen[1])
				# else:
				# 	data.remove(sequen[1])
				# 	data.remove(sequen[2])
				# 	data.append([sequen[1], sequen[2]])
	print data

readData()