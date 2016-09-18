# Doc tung dong input
# Lưu dữ liệu của jack vào trong một dictionary trong python(giống json)
# ứng với mỗi dữ liệu đọc được từ jin kiểm tra xem có thuộc trong jack k có thì cộng thêm 1
	# vào biến đếm, đọc cho đến khi gặp kí tự kết thúc vào in ra biến count
# do phuc tap O(n*m)

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