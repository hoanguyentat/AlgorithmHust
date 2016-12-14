# Doc input dau vao la chuoi chu thuong
# Dung dictionary luu lai so lan xuat hien cua mot ki tu trong xau
# Ket thuc duyet in ra tong so key co gia tri la le trong dictionary, do cung chinh la so ki tu can loai bo
# Do phuc tap O(n)

from collections import defaultdict
d = defaultdict(int)
s = input()
for c in s:
    d[c]+=1
odds = len([x for x in d.values() if x%2])
if odds:
    print(odds - 1)
else:
    print("0")