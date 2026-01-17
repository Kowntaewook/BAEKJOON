#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<int, vector<string>> words_by_length;
map<int, vector<string>> reversed_by_length;

vector<int> solution(vector<string> words, vector<string> queries) {
    // 1. 단어 저장
    for (auto &w : words) {
        int len = w.size();
        words_by_length[len].push_back(w);

        string rev = w;
        reverse(rev.begin(), rev.end());
        reversed_by_length[len].push_back(rev);
    }

    // 2. 정렬
    for (auto &p : words_by_length)
        sort(p.second.begin(), p.second.end());
    for (auto &p : reversed_by_length)
        sort(p.second.begin(), p.second.end());

    vector<int> answer;

    // 3. 쿼리 처리
    for (auto &q : queries) {
        int len = q.size();
        if (words_by_length.count(len) == 0) {
            answer.push_back(0);
            continue;
        }

        string left = q, right = q;
        replace(left.begin(), left.end(), '?', 'a');
        replace(right.begin(), right.end(), '?', 'z');

        // 접미사 ? (fro??)
        if (q[0] != '?') {
            auto &vec = words_by_length[len];
            answer.push_back(
                upper_bound(vec.begin(), vec.end(), right) -
                lower_bound(vec.begin(), vec.end(), left)
            );
        }
        // 접두사 ? (??odo)
        else {
            reverse(left.begin(), left.end());
            reverse(right.begin(), right.end());

            auto &vec = reversed_by_length[len];
            answer.push_back(
                upper_bound(vec.begin(), vec.end(), right) -
                lower_bound(vec.begin(), vec.end(), left)
            );
        }
    }
    return answer;
}

int main()
{

    char word[10001];
    int n, q;
    scanf("%d %d", &n, &q);
    vector<string> words_input;
    
    for(int i = 0; i < n; i++)
    {
        scanf("%s", word);
        words_input.push_back(string(word));
    }

    vector<string> queries;
    for(int i = 0; i < q; i++)
    {
        scanf("%s", word);
        queries.push_back(string(word));
    }

    vector<int> result = solution(words_input, queries);
    for(int i = 0; i < result.size(); i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}