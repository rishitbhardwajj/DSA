#include <bits/stdc++.h>
using namespace std;

void dfs(string word, vector<string>& seq, vector<vector<string>>& ans,
         unordered_map<string, int>& mpp, string& b) {
    if (word == b) {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }

    int steps = mpp[word];
    int sz = word.size();

    for (int i = 0; i < sz; i++) {
        char original = word[i];

        for (char ch = 'a'; ch <= 'z'; ch++) {
            word[i] = ch;

            if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                seq.push_back(word);
                dfs(word, seq, ans, mpp, b);
                seq.pop_back();
            }
        }

        word[i] = original;
    }
}

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                        vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        unordered_map<string, int> mpp;

        q.push(beginWord);
        mpp[beginWord] = 1;

        int sz = beginWord.size();
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord)
                break;

            for (int i = 0; i < sz; i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }

                word[i] = original;
            }
        }

        vector<vector<string>> ans;

        if (mpp.find(endWord) == mpp.end())
            return ans;

        vector<string> seq;
        seq.push_back(endWord);

        dfs(endWord, seq, ans, mpp, beginWord);

        return ans;
    }
};

int main() {
    Solution obj;

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    vector<vector<string>> ans =
        obj.findLadders(beginWord, endWord, wordList);

    for (auto sequence : ans) {
        for (auto word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}