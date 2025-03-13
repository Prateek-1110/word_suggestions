#include "dict.hpp"
#include "search.hpp"

int main() {
    vector<string> dict = load_dictionary("words_alpha.txt");
    sort_dictionary(dict);
    
    while (true) {
        cout << "\nEnter choice:\n";
        cout << "1. Need Suggestions\n";
        cout << "2. Exit\n";
        
        int choice;
        cin >> choice;
        if (choice == 2) break;

        if (choice == 1) {
            cout << "Enter the word for suggestions: ";
            string input;
            cin >> input;
            transform(input.begin(), input.end(), input.begin(), ::tolower); 
            vector<string> results = get_suggestions(dict, input, 5);
            if (results.empty()) {
                cout << "No suggestions found.\n";
            } else {
                cout << "Suggestions for '" << input << "':\n";
                for (const string &word : results) {
                    cout << word << "\n";
                }
            }
        }
    }
    return 0;
}
