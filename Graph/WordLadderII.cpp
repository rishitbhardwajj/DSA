#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());

    queue<vector<string>> q;
    q.push({startWord});

    vector<string> usedOnLevel;
    usedOnLevel.push_back(startWord);

    int level = 0;
    vector<vector<string>> ans;

    while (!q.empty()) {
        vector<string> vec = q.front();
        q.pop();

        if (vec.size() > level) {
            level++;

            for (auto it : usedOnLevel) {
                st.erase(it);
            }

            usedOnLevel.clear();
        }

        string word = vec.back();

        if (word == targetWord) {
            if (ans.size() == 0) {
                ans.push_back(vec);
            }
            else if (ans[0].size() == vec.size()) {
                ans.push_back(vec);
            }
        }

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (st.count(word) > 0) {
                    vec.push_back(word);
                    q.push(vec);

                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }

            word[i] = original;
        }
    }

    return ans;
}

int main() {
    string startWord = "hit";
    string targetWord = "cog";

    vector<string> wordList = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    vector<vector<string>> ans = findSequences(startWord, targetWord, wordList);

    for (auto sequence : ans) {
        for (auto word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}