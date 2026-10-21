#include <iostream>
using namespace std;

struct node {
    int a, b;
    bool before_flag;
};

int main() {
    int A, B;
    cin >> A >> B;
    node st[128];
    int top = 0;
    st[top] = {A, B, 0};
    int ans = 0;
    while (top >= 0) {
        if (st[top].b == 0) {
            ans = st[top].a;
            top--;
        }
        else if (st[top].before_flag == 0) {
            st[top].before_flag = 1;
            int a = st[top].a;
            int b = st[top].b;
            st[++top] = {b, a % b, 0};
        }
        else {
            top--;
        }
    }
    cout << ans << endl;
}