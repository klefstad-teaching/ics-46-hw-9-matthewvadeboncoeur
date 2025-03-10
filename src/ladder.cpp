#include "ladder.h"

void error(string word1, string word2, string msg) {
    std::cout << word1 << ", " << word2 << " " << msg;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {

}

bool is_adjacent(const string& word1, const string& word2) {

}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {

}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    for (string word; (in >> word);)
        word_list.insert(word);
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {

}

void verify_word_ladder() {

}
