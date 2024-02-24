#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>
#include <vector>
#include "STI.h"
#include <stdlib.h>

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

static void cat();
string MainMenu(Sportsmen& data);
void ThrowStr(Sportsmen& data, unsigned int number);
void AddStr(Sportsmen& data, bool typeEnter);
void Add(Sportsmen& data);
void RemoveStr(Sportsmen& data);
void SearchStr(Sportsmen& data);
void EditStr(Sportsmen& data);
void ThrowData(Sportsmen& data);
void RemoveStr(Sportsmen& data);
void UpdateFileFromStructure(string path, Sportsmen& data);
void UpdateStructureFromFile(string path, Sportsmen& data);



