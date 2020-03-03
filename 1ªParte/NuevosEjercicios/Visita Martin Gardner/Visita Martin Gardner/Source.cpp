

#include <iostream>
#include <algorithm>
#include <cassert>
#include <iomanip>

using namespace std;
#define MAX 100000
// Precomputed
const int SUMP[] = { 0, 1, 3, 6, 10, 15, 21, 28, 36, 45 }; // O(1) in SPACE


// : P : N > 0
unsigned long long solveSSNG(const unsigned long long N,
    const unsigned long long total,
    const unsigned long long sum,
    const unsigned long long pow)
{
    //  cout << "trace in " << N << " " << total << " " << sum << " " << pow << endl;
    if (!N) return total;
    return solveSSNG(N / 10, total + SUMP[N % 10] + (N % 10) * SUMP[9] * sum, sum + pow, 10 * pow);
}

unsigned long long solveSSN(const unsigned long long N)
{
    return solveSSNG(N, 0, 0, 1);
}

int main(int argc, char* args[])
{
    unsigned long long N;
    for (cin >> N; N; cin >> N)
        cout << solveSSN(N) << endl;
}
