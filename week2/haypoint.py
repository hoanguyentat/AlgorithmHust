rules = {}

def result(data):
	# print "Hello"
	salary = 0
	for x in data:
		# print x
		if (x in rules):
			salary += int(rules[x])
	print salary
	return
def readData():
	test_cases = raw_input();
	test_cases = test_cases.split()
	for i in range(0,int(test_cases[0])):
		prop = raw_input()
		prop = prop.split()
		rules[prop[0]] = prop[1]
		# print rules
	for i in range(0,int(test_cases[1])):
		data = []
		input = raw_input()
		# count = 0
		while (input != "."):
			# print input
			input = input.split()
			data += input
			# count += 1
			# print count
			try:
				input = raw_input()
			except EOFError:
				break
		result(data)
readData()