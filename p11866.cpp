#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    int M;
    scanf("%d", &M);
    int cnt = 1;
    printf("<");
    while (true) {

        if (cnt < M) {
            int pass = q.front();
            q.pop();
            q.push(pass);
            cnt++;
        }
        else {
            printf("%d", q.front());
            q.pop();
            if (q.empty())
                break;
            printf(", ");
            cnt = 1;
        }
            
        
        
    }
    printf(">\n");
}