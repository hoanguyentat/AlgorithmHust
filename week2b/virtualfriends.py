# Doc du lieu dau vao theo tung dong va luu vao mot list da duoc khai bao
# Doi voi moi mot lan co them mot cap ban se luu ket qua vao mot mang khac
# Cap ban thu i se kiem tra tung nguoi mot xem co trong cac cap ket qua tu 0 -> i-1 k
	# Neu co thi them vao ket qua thu i, kiem tra trung lap
	# (Noi hai mang ma chua hai ban da la ban voi nhung nguoi khac)
	# Neu khong thi them ban moi vua doc duoc vao trong bien ket qua
# Muc do phuc tap cua thuat toan O(n2)


def readData():
	test_cases = int(raw_input())
	for i in xrange(test_cases):
		num = int(raw_input())
		data = []
		result = [[]]*num
		for j in xrange(int(num)):
			just_friend = raw_input()
			just_friend = just_friend.split(" ")
			data.append(just_friend)
		result[0] = data[0]
		for j in xrange(1, num):
			result[j] = []
			for k in xrange(0,j):
				if data[j][0] in result[k]:
					for x in result[k]:
						if x not in result[j]:
							result[j].append(x)
				else:
					if data[j][0] not in result[j]:
						result[j].append(data[j][0])
				if data[j][1] in result[k]:
					for x in result[k]:
						if x not in result[j]:
							result[j].append(x)
				else:
					if data[j][1] not in result[j]:
						result[j].append(data[j][1])
		for x in result:
			print len(x)
readData()
