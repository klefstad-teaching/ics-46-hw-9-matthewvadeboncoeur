#include "ladder.h"


int main() {
    vector<string> res;
    set<string> word_ls;
    load_words(word_ls, "src/words.txt");
    res = generate_word_ladder("apple", "apples", word_ls);
    print_word_ladder(res);
    return 0;
}