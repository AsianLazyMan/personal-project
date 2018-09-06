// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#pragma warning(disable:4996)
using namespace std;
const int N = 1e5 + 7;
#define de(x) cout<<#x<<" = "<<x<<endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
struct node {
	node *next[36];
	int gs;
}root;
string line[N];
int num_line,eft_num;
int Atoatoint(char c) {
	if (c >= 'A'&&c <= 'Z')c += 'A' - 'a';
	if(c>='a'&&c<='z') return c-'a';
	else return 26+c-'0';
}
void qinsert(string s) {
	int len = s.size(), tmp;
	node *p;
	p = &root;
	rep(i, 0, len) {
		tmp = Atoatoint(s[i]);
		if (p->next[tmp]==NULL) {
			p->next[tmp] = new node();p->gs = 0;
		}
		p = p->next[tmp];
		if (i == len - 1) { p->gs++;  }
	}
}
void MYscanf(char s[]) {
	freopen(s, "r", stdin);
	string str;
	while ( getline(cin, str) ) {
		int len = str.size();
		line[num_line++] = str;
		if (len == 0)continue;
		bool f=0;
		rep(i, 0, len) {
			if (str[i] != ' ')f = 1;
		}
		if (f) {eft_num++;}
	}
}
int CountChar() {}
int CountWord() {}
int CountMxWord() {}
void MYprint() {}
int main(int argc,char *argv[])
{
	MYscanf(argv[1]);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
