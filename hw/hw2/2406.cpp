#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* h = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int* stack = new int[n];
    int top = -1;
    int s_max = 0;
    for (int i = 0; i < n; i++) {
        while (top != -1 && h[i] < h[stack[top]]) {
            int s = h[stack[top]] * ((top > 0) ? (i - stack[top - 1] - 1) : (i));
            top--;
            s_max = max(s, s_max);
        }
        if (top == -1 || h[i] > h[stack[top]]) {
            stack[++top] = i;
        }
    }
    while (top != -1) {
        int s = h[stack[top]] * ((top > 0) ? (n - stack[top - 1] - 1) : n);
        top--;
        s_max = max(s, s_max);
    }
    cout << s_max << endl;
    delete[] h;
    delete[] stack;
}