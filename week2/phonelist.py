#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Doc tung dong input
# Sau khi đọc xong một test_case thì kiểm tra luôn điều kiện đầu vào
# Dữ liệu mỗi test_case được truyền vào mảng list trong python
  # Sắp xếp dữ liệu theo chiều tăng dần vì vậy nếu tồn tại hai phần 
  #tử mà một trong hai phần tử là prefix của phần tử còn lại thì hai 
  #phần tử đó phải liền nhau, và phần tử là prefix phải được sắp xếp
  #trước phần tử còn lại
# do phuc tap O(n)

def readData():
	test_cases = int(raw_input())
	for i in xrange(test_cases):
		number = int(raw_input())
		phonelist = []
		for j in xrange(number):
			try:
				input = raw_input()
			except EOFError:
				break		
			phonelist.append(input)
		# print len(phonelist)
		result(phonelist)
		# print phonelist
	return
def result(phonelist):
	status = False
	phonelist.sort()
	for k in xrange(len(phonelist)):
		if k == len(phonelist) - 1:
			break
		if (len(phonelist[k+1]) >= len(phonelist[k])):
			check = phonelist[k+1][0:len(phonelist[k])]
			if (check == phonelist[k]):
				status = True
				break
	if (status):
		print "NO"
	else:
		print "YES"
readData()