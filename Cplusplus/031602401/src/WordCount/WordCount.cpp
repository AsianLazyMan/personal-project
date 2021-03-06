#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include <fstream>
#include <algorithm>
using namespace std;
map<string, int> ma;
int min(int a, int b) {
	if (a >= b) return b;
	else return a;
}
void lower(string& str) {//大写转化成小写
	for (int j = 0; j < str.size(); j++)
	{
		if (str[j] <= 'Z'&&str[j] >= 'A') {
			str[j] = str[j] + 32;
		}
	}
}
int Judge(string Word) {//判断是不是四个英文字母开头 后面跟着字母数字符号

	if (Word.empty()) return 0;
	if (Word.size() < 4) return 0;
	if (Word[0] >= 'a'&&Word[0] < 'z'&&Word[1] >= 'a'&&Word[1] <= 'z'&&Word[2] >= 'a'&&Word[2] <= 'z'&&Word[3] >= 'a'&&Word[3] <= 'z')
		return 1;
	else
		return 0;
}
int getCharNum(char* filename)
{
	ifstream file(filename);
	string temp;
	int charNumEachLine=0;
	int charNum=0;
	while (getline(file, temp)) {
		bool space = false;
		for (int i = 0; i < (int)temp.size(); i++) {
			if (temp[i] > 32)
			{
				space = true;
				break;
			}
		}
		if (space == true) {
			charNumEachLine = temp.size()+1;
			charNum = charNum + charNumEachLine;
		}
	}
	file.close();
	return charNum;
}
int getLineNum(char* filename) 
{
	ifstream file(filename);
	string temp;
	int lineNum = 0;
	while (getline(file, temp)) {
		bool space = false;
		for (int i = 0; i < (int)temp.size(); i++) {
			if (temp[i] > 32)
			{
				space = true;
				break;
			}
		}
		if (space == true) {
			lineNum++;
		}
	}
	file.close();
	return lineNum;
}
void countWord(char* filename) {
	ifstream file(filename);
	string temp;
	string word;
	char c;
	while ((c = file.get()) != EOF) {
		temp.append(1, c);
	}
		lower(temp);
		for (int y = 0; y < temp.size(); ) {
			if (temp[y]<48||((57<temp[y])&&(temp[y]<97))||temp[y]>122)
			{
				if (y > temp.size())break;
				y++;
				continue;
			}
			else {//发现一个单词
				while ((temp[y] >= 'a'&&temp[y] <= 'z') || (temp[y] >= '0'&&temp[y] <= '9')) {
					word.append(temp, y, 1);
					y++;
					if (y > temp.size())break;
				}
				if (Judge(word)) {
					ma[word] ++;
				}
				word.clear();
			}
		}
	file.close();
}
typedef pair<string, int> PAIR;
bool cmp(PAIR a, PAIR b)
{
	if (a.second > b.second)             return true;
	if (a.second < b.second)             return false;
	if (a.first==b.first)    return true;
	return false;
}
int main(int argc, char **argv)
{
	if (argc == 1)	printf("It is short of filename!\n");
	else if (argc > 2)	printf("Too many parametes!\n");
	else {
		countWord(argv[1]);
		int num1 = getCharNum(argv[1]);
		int num2 = ma.size();
		int num3 = getLineNum(argv[1]);
		vector<PAIR> name_times_vec(ma.begin(), ma.end());
		sort(name_times_vec.begin(), name_times_vec.end(), cmp);
		ofstream ofile("result.txt");
		ofile << "characters:" << num1 << endl;
		ofile << "words:" << num2 << endl;
		ofile << "lines:" << num3 << endl;
		for (int i = 0; i < min(10, name_times_vec.size()); i++)
		{
			ofile << "<" << name_times_vec[i].first << ">: " << name_times_vec[i].second << endl;
		}

	}
}

	
