/**
	* Doc tung dung input
	* Khoi tao bien ban trang thai ban dau la true, tuc la ca ba truong hop deu co the xay ra
		* doc du lieu dau vao tuong ung 1 day gia tri vao trong mang tuong ung, 2 thi lay gia tri ra,
		* trong khi lay gia tri ra kiem tra xem phan tu lay ra ung voi moi kieu co trung voi gia tri nhap vao k
		* neu trung bien trang thai la true, nguoc lai gan bien trang thai thanh false
		* sau khi doc xong kiem tra cac bien trang thai va ghi ra ket qua tuong ung
	* Muc do phuc tap thuat toan O(n)
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	int test, io, x;
	while(scanf("%d", &test) != EOF){
		bool checkS = true, checkQ = true, checkPQ = true;

		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;

		for (int i = 0; i < test; ++i)
		{
			scanf("%d %d", &io, &x);
			switch(io){
				case 1: 
					if (checkS)
					{
						s.push(x);
					}
					if (checkPQ)
					{
						pq.push(x);
					}
					if (checkQ)
					{
						q.push(x);
					}
					break;
				case 2:
					if (checkS)
					{
						if (s.empty() || s.top() != x )
						{
							checkS = false;
						}
						else {
							s.pop();
						}
					}
					if (checkQ)
					{
						if (q.empty() || q.front() != x)
						{
							checkQ = false;
						}
						else {
							q.pop();
						}
					}
					if (checkPQ)
					{
						if (pq.empty() || pq.top() != x)
						{
							checkPQ = false;
						}
						else {
							pq.pop();
						}
					}
					break;
				default: 
					break;
			}
		}
		// cout << checkQ << checkPQ << checkS;
		if (checkPQ == true && checkQ == false && checkS == false)
		{
			cout << "priority queue\n";
		}
		else if (checkPQ == false && checkQ == true && checkS == false)
		{
			cout << "queue\n";
		}
		else if (checkPQ == false && checkQ == false && checkS == true)
		{
			cout << "stack\n";
		}
		else if (checkPQ == false && checkQ == false && checkS == false)
		{
			cout << "impossible\n";
		}
		else cout << "not sure\n";
	}
	return 0;
}