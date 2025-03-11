#include "ladder.h"

void error(string word1, string word2, string msg) {
    std::cout << word1 << ", " << word2 << " " << msg;
}

string lowercase(const string& s) {
    string res = s;
    for (char & c : res)
        c = tolower(c);
    return res;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    string s1 = lowercase(str1);
    string s2 = lowercase(str2);
    int l1 = s1.length();
    int l2 = s2.length();
    if (abs(l1-l2) > d)
        return false;
    int count = 0;
    int n = min(l1, l2);
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            ++count;
        }
    }
    count += abs(l2 - l1);
    return count <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (!word_list.find(end_word)) {
        vector<string> empty;
        return empty;
    }

    if (begin_word == end_word) {
        return {begin_word};
    }
    string begin_lower = lowercase(begin_word);
    string end_lower = lowercase(end_word);


    queue<vector<string>> ladder_queue;
    vector<string> start_vector;
    start_vector.push_back(begin_word);
    ladder_queue.push(start_vector);

    set<string> visited;
    visited.insert(begin_lower);

    while (!ladder_queue.empty()) {
        vector<string> ladder;
        ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        string last_word_lower = lowercase(last_word);
        for (const string& word : word_list) {
            string word_lower = lowercase(word);
            if (is_adjacent(last_word_lower, word_lower)) {
                if (visited.count(word_lower) == 0) {
                    visited.insert(word_lower);
                    vector<string> new_ladder;
                    new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word_lower == end_lower)
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
}

void verify_word_ladder() {

}
