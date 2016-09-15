def readData():
	input = raw_input()
	while (input != "0 0"):
		input = input.split()
		jack = {}
		jin = {}
		count = 0
		for i in xrange(0,int(input[0])):
			cd = int(raw_input())
			jack[cd] = 1
		for i in xrange(0,int(input[1])):
			jin = int(raw_input())
			if (jin in jack):
				count+=1
		# print jack
		input = raw_input()
		print count
	return
readData()