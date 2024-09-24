#include <iostream>
#include <vector>
#include <unordered_set>

// using namespace std;

class Solution
{
public:
    int longestCommonPrefix(std::vector<int> &arr1, std::vector<int> &arr2)
    {
        int max_prefix_length = 0;
        int current_max_prefix_length = 0;
        for (int i = 0; i < arr1.size(); ++i)
        {
            store_prefixes(arr1[i]);
        }

        for (int i = 0; i < arr2.size(); ++i)
        {
            current_max_prefix_length = get_max_prefix_length(arr2[i]);
            max_prefix_length = std::max(current_max_prefix_length, max_prefix_length);
        }
        return max_prefix_length;
    }
    void store_prefixes(int number)
    {
        int n = number;
        int m = 1;
        int prefix = 0;

        while (n > 9)
        {
            n /= 10;
            m *= 10;
        }
        while (m > 0 && number != prefix)
        {
            prefix = number / m;
            this->prefixes.insert(prefix);
            m /= 10;
        }
    }
    int get_max_prefix_length(int number)
    {
        int n = number;
        int m = 1;
        int prefix = 0;
        int current_max_prefix_length = 0, max_prefix_length = 0;

        while (n > 9)
        {
            n /= 10;
            m *= 10;
        }
        while (m > 0 && number != prefix)
        {
            ++current_max_prefix_length;
            prefix = number / m;
            if (this->prefixes.find(prefix) != this->prefixes.end())
            {
                max_prefix_length = std::max(current_max_prefix_length, max_prefix_length);
            }
            m /= 10;
        }
        return max_prefix_length;
    }

private:
    std::unordered_set<int> prefixes;
};

int main(int argc, char *argv[])
{
    std::vector<int> v1 = {1, 10, 100};
    std::vector<int> v2 = {1000};
    std::vector<int> v3 = {1, 2, 3};
    std::vector<int> v4 = {4, 4, 4};
    Solution s;
    int lcp1 = s.longestCommonPrefix(v1, v2);
    int lcp2 = s.longestCommonPrefix(v3, v4);
    std::cout << "LCP1: " << lcp1 << '\n';
    std::cout << "LCP2: " << lcp2 << '\n';
}
