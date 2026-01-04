#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<long long> a;
int good_count = 0;

bool is_good(int idx)
{
    long long target = a[idx];
    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        if(left == idx)
        {
            left++;
            continue;
        }
        if(right == idx)
        {
            right--;
            continue;
        }

        long long sum = a[left] + a[right];

        if(sum == target)
            return true;
        else if(sum < target)
            left++;
        else
            right--;
    }

    return false;
}

int main()
{
    scanf("%d", &n);
    a.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
        if(is_good(i))
            good_count++;
    printf("%d\n", good_count);
    return 0;
}