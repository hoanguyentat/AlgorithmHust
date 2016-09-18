def readData():
	io = raw_input()
	cookies = []
	while 1:
		if (io == "#"):
			count = len(cookies)
			if count % 2 == 1:
				print cookies.pop((count-1)/2)
			else:
				index = count/2 
				print cookies.pop(index)
		else:
			# print io
			io = int(io)
			cookies.append(io)
			cookies.sort()
		try:
			io = raw_input()
		except EOFError:
			break
readData()