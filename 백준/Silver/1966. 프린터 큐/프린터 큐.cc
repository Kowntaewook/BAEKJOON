#include <stdio.h>
#include <queue>

using namespace std;

struct Document {
    int index;
    int priority;
};

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        queue<Document> q;
        int priorityCount[10] = {0}; // 중요도 1~9 카운트

        for (int i = 0; i < n; i++) {
            int p;
            scanf("%d", &p);
            q.push({i, p});
            priorityCount[p]++;
        }

        int printOrder = 0;
        while (!q.empty()) {
            Document front = q.front();
            q.pop();

            bool hasHigher = false;
            for (int i = front.priority + 1; i <= 9; i++) {
                if (priorityCount[i] > 0) {
                    hasHigher = true;
                    break;
                }
            }

            if (hasHigher) {
                q.push(front);
            } else {
                printOrder++;
                priorityCount[front.priority]--;
                if (front.index == m) {
                    printf("%d\n", printOrder);
                    break;
                }
            }
        }
    }

    return 0;
}
