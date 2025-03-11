#include "ladder.h"


int main() {
    vector<string> res;
    set<string> word_ls;
    load_words(word_ls, "src/words.txt");
    string word1 = "cat";
    string word2 = "dog";
    res = generate_word_ladder(word1, word2, word_ls);
    print_word_ladder(res);
    return 0;
}