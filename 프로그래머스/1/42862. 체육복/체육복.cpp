#include <stdio.h>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n + 1, 1);

    for(int i = 0; i < lost.size(); i++)
        student[lost[i]]--;
    
    for(int i = 0; i < reserve.size(); i++)
        student[reserve[i]]++;
    
    for(int i = 1; i <= n; i++)
    {
        if(student[i] == 0)
        {
            if(i > 1 && student[i - 1] == 2)
            {
                student[i]++;
                student[i - 1]--;
            }
            else if(i < n && student[i + 1] == 2)
            {
                student[i]++;
                student[i + 1]--;
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        if(student[i] > 0)
            answer++;
    }
    
    return answer;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> lost;

    int lostnum;

    while(1)
    {
        scanf("%d", &lostnum);
        if(lostnum == -1) 
            break;
        lost.push_back(lostnum);
    }
    vector<int> reserve;
    int reservenum;

    while(1)
    {
        scanf("%d", &reservenum);
        if(reservenum == -1)
            break;
        reserve.push_back(reservenum);
    }
    
    printf("%d\n", solution(n, lost, reserve));

    return 0;
}