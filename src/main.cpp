#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        std::vector<int> scores;
        scores.reserve(words.size());
        for (auto& word : words)
        {
            int current_word_score = 0;
            auto prefixes = get_prefixes(word);

            for (auto& prefix : prefixes)
            {
                for (auto& w : words)
                {
                    if (w.starts_with(prefix))
                        ++current_word_score;
                }
            }
            scores.emplace_back(current_word_score);
        }
        return scores;
    }
private:
    std::vector<std::string> get_prefixes(const std::string &word) const
    {
        std::vector<std::string> prefixes;
        prefixes.reserve(word.length());

        for (size_t i = 1; i <= word.length(); ++i)
        {
            prefixes.emplace_back(word.substr(0, i));
        }
        return prefixes;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::vector<string> input1 = {string{"abc"}, string{"ab"}, string{"bc"}, string{"b"}};
    std::vector<string> input2 = {"abcd"};

    for (auto& score : s.sumPrefixScores(input1))
    {
        cout << score << " ";
    }
    cout << endl;

    for (auto& score : s.sumPrefixScores(input2))
    {
        cout << score << " ";
    }
    cout << endl;

}
