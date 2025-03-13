#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <bits/stdc++.h>
using namespace std;

vector<string> load_dictionary(const string &filename);
void sort_dictionary(vector<string> &words);
string to_lowercase(const string &s);
#endif
