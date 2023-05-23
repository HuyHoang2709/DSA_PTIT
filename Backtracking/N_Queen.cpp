#include <bits/stdc++.h>

using namespace std;

int n;
int X[20];
int A[20];
int Xuoi[20];
int Nguoc[20];

void Init()
{
    cin >> n;
    for (int i = 1; i <= 20; ++i) X[i] = A[i] = Xuoi[i] = Nguoc[i] = 1;
}

void Result() 
{
    for(int i = 1; i <= n; ++i) cout << X[i] << ' ';
    cout << '\n';
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (A[j] && Xuoi[i - j + n] && Nguoc[i + j - 1]) {
            // Đánh dấu vị trí để thử
            X[i] = j;  

            // Đánh dấu các cột và đường chéo
            A[j] = 0;
            Xuoi[i - j + n] = 0;
            Nguoc[i + j - 1] = 0;

            // In kết quả nếu thỏa mãn
            // Nếu không thỏa mãn thì quay lui thử tiếp
            if (i == n) Result();
            else Try(i + 1);

            // Trả lại vị trí để thử các TH tiếp theo
            A[j] = 1;
            Xuoi[i - j + n] = 1;
            Nguoc[i + j - 1] = 1;
        }
    }
}

int main()
{
    Init();
    Try(1);
    return 0;
}