def result(data):
	print data

def readData():
	input = raw_input()
	data = []
	while 1:
		if (input[0:4] == "<top"):
		# 	# print input
			data = data.append(input)
		# 	# print data
		# 	result(data)
		# 	data = []
		else: 
			input = input.split(" ")
			print input
			# data = data.append(input)
			# print data
		try:
			input = raw_input()
		except EOFError:
			break
	result(data)
readData()	