
#pragma once
#ifndef GRADE_PermutedIndex1
#define GRADE_PermutedIndex1
#include<iostream>
#include<cctype>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using std::cout;
using std::sort;
using std::find;
using std::cin;
using std::vector;
using std::string;
using std::endl;
using std::max;
using std::isspace;

vector<string>split(const string&);

string rotate(vector<string>&);

bool compare(string&, string&);

vector<string>::size_type port(const vector<string>&, const vector<string>&);

bool dare(vector<string>::size_type&, vector<string>::size_type&);

string paint1(vector<string>&);

vector<string>::size_type cmp(vector<string>&, vector<string>&);

vector<string> unrotate1(vector<string>&, vector<string>&);

vector<string> unrotate2(vector<string>&, vector<string>&);

string nsplit(vector<string>&);

string::size_type long_str(vector<string>&);

vector<string>v_cat(vector<string>&, vector<string>&);

vector<string>h_cat(vector<string>&, vector<string>&);


#endif