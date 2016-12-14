

str = input()
str = str.lower()
while (1):
	count = 1
	n = int(len(str))
	for i in range(1,n):
		while str[i] != str[i % count]:
			count+=1;
	if (n % count != 0):
		print("1")
	else:
		print(int(n/count))	
	try:
		str = input()
	except ValueError as e:
		break
	