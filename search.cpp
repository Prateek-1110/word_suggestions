#include "search.hpp"
//this finds the first occurence of prefix using binary search
int lower_bound_index(const vector<string>& words, const string& prefix) {
    int left = 0, right = words.size();
    string lower_prefix = to_lowercase(prefix);
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (to_lowercase( words[mid]).compare(0,lower_prefix.size(), lower_prefix) < 0)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

vector<string> get_suggestions(const vector<string>& words, const string& prefix, int max_suggestions) {
    vector<string> suggestions;
    int index = lower_bound_index(words, prefix);
    string lower_prefix = to_lowercase(prefix);
    for (int i = index; i < words.size() && suggestions.size() < max_suggestions; i++) {
        if (to_lowercase(words[i]).find(prefix) == 0) {
            suggestions.push_back(words[i]);
        } else {
            break; 
        }
    }
    return suggestions;
}
