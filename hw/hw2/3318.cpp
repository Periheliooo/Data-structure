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
    int* answer = new int[n]();
    for (int i = 0; i < n; i++) {
        while (!(top == -1 || h[stack[top]] >= h[i])) {
            answer[stack[top]] = i - stack[top];
            top--;
        }
        stack[++top] = i;
    }
    
    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    delete[] h;
    delete[] stack;
    delete[] answer;
}