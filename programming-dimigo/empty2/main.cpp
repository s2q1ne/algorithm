#include    <iostream>
using namespace std;

int main()
{
    int D, K;
    int * arr;
    int * A;
    int * B;
    cin >> D >> K;

    arr = new int[D];
    arr[D - 1] = K;
    A = new int[D];
    B = new int[D];

    A[0] = 1; A[1] = 0;
    B[0] = 0; B[1] = 1;

    for (int i = 2; i < D; ++i)
    {
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }

    for (int i = 1; i <= K/2; ++i)
    {
        for (int j = i; j <= K; ++j)
        {
            if (K == (i*A[D - 1] + j*B[D - 1]))
            {
                cout << i << endl << j << endl;
                return 0;
            }
            else if (K < (i*A[D - 1] + j*B[D - 1]))
                break;
        }
    }
    //K = x*A[D-1] + y*B[D-1] 인 경우 x, y를 구하시오


    return 0;
}
