def readData():
	nsr = raw_input()
	nsr = nsr.split()
	arrS = raw_input()
	arrR = raw_input()
	arrS = arrS.split()
	arrR = arrR.split()
	for i in range(0,len(arrS)):
		arrS[i] = int(arrS[i])
	for i in range(0,len(arrR)):
		arrR[i] = int(arrR[i])
	result = arrS[:];
	for i in arrS:
		# print i
		if (i-1) in arrR:
			arrR.remove(i-1)
			result.remove(i)
		elif (i+1) in arrR:
			arrR.remove(i+1)
			result.remove(i)
	print(len(result))
readData()