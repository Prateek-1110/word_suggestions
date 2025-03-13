#include "dict.hpp"

vector<string> load_dictionary(const string &filename) {
    vector<string> words;
    ifstream file(filename);
    string word;
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }
    while (file >> word) {
        words.push_back(word);
    }
    file.close();
    return words;
}
string to_lowercase(const string &s) {
    string lower_s = s;
    transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);
    return lower_s;
}
void sort_dictionary(vector<string> &words) {
    sort(words.begin(), words.end());
}
