#include "ladder.h"

void error(string word1, string word2, string msg) {
    std::cout << word1 << ", " << word2 << " " << msg;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    vector<string> start_vector;
    start_vector.push_back(begin_word);
    ladder_queue.push(start_vector);
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder;
        ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (const string& word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (!visited.count(word)) {
                    visited.insert(word);
                    vector<string> new_ladder;
                    new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    vector<string> empty;
    return empty;
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    for (string word; (in >> word);)
        word_list.insert(word);
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    for (int i = 0; i < ladder.size(); ++i)
        cout << ladder[i] << " ";
    cout << "Executed" << endl;
}

void verify_word_ladder() {

}
