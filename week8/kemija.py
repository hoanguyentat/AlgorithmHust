#! /usr/bin/env python

# Doc str nhap vao tu ban phim
# Chuoi chua cac ki tu nguyen am da duoc thay doi can sua lai
# Tach tung tu bang dau cach duyet tung tu va thay the bang nguyen am phu hop
# Do phuc tap O(n)

check = {"apa" : "a", "upu": "u", "ipi": "i", "epe":"e", "opo":"o"}
str = input()
str =str.strip()
str = str.split(" ")
# print(str)

for x in range(len(str)):
	for y in check:
		str[x] = str[x].replace(y, check[y])
		# print(str[x])
str =  " ".join(str)
print(str)
		
