#include <string>
#include <vector>
#include <string.h>   
using namespace std;

int solution(string s) {
    int len = s.length();
    if (len == 1) 
        return 1; 

    int answer = len;

    for (int unit = 1; unit <= len / 2; unit++) {
        string prev = s.substr(0, unit);
        int cnt = 1;
        int comp_len = 0;

        for (int i = unit; i < len; i += unit) {
            string cur = s.substr(i, unit);

            if (cur == prev) {
                cnt++;
            } else {
                if (cnt > 1)
                    comp_len += to_string(cnt).length() + prev.length();
                else
                    comp_len += prev.length();
                prev = cur;
                cnt = 1;
            }
        }

        
        if (cnt > 1)
            comp_len += to_string(cnt).length() + prev.length();
        else
            comp_len += prev.length();

        answer = min(answer, comp_len);
    }

    return answer;
}
