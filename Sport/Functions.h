#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

struct Sportsmen
{
	vector<string> name;
	vector<int> age;
	vector<int> height;
	vector<int> weight;
	vector<string> sport;
	vector<string> sportRank;
};

void cat();
string MainMenu(Sportsmen data, bool tag, bool firstTime);
void ThrowStr(Sportsmen data, unsigned int number);
void AddStr(Sportsmen data, bool typeEnter);
void Add(Sportsmen data);
void RemoveStr(Sportsmen data);
void SearchStr(Sportsmen data);
void EditStr(Sportsmen data);
void ThrowData(Sportsmen data);
void RemoveStr(Sportsmen data);



