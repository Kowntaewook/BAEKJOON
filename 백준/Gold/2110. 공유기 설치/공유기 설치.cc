#include <stdio.h>

using namespace std;

int N, C;
int house[200000];

void heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && house[left] > house[largest])
        largest = left;
    
    if (right < n && house[right] > house[largest])
        largest = right;
    
    if (largest != i) {
        int temp = house[i];
        house[i] = house[largest];
        house[largest] = temp;
        heapify(n, largest);
    }
}

void heapsort() {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(N, i);
    
    for (int i = N - 1; i >= 0; i--) {
        int temp = house[0];
        house[0] = house[i];
        house[i] = temp;
        heapify(i, 0);
    }
}

bool check(int dist) {
    int cnt = 1;
    int last = house[0];
    for (int i = 1; i < N; i++) {
        if (house[i] - last >= dist) {
            cnt++;
            last = house[i];
        }
    }
    return cnt >= C;
}

int main() {
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; i++) {
        scanf("%d", &house[i]);
    }
    
    heapsort();
    
    int left = 1;
    int right = house[N - 1] - house[0];
    int answer = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    printf("%d\n", answer);
    return 0;
}