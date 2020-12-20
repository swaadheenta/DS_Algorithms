#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256


void computeTransFun(char* pat, int M, int TF[][NO_OF_CHARS])
{
    int i, lps = 0, x;
    for (x = 0; x < NO_OF_CHARS; x++)
        TF[0][x] = 0;
    TF[0][pat[0]] = 1;

    for (i = 1; i <= M; i++)
    {
       for (x = 0; x < NO_OF_CHARS; x++)
            TF[i][x] = TF[lps][x];
       TF[i][pat[i]] = i + 1;
       if (i < M)
            lps = TF[lps][pat[i]];
    }
}

void search(char pat[], char txt[])
{
    int M = strlen(pat);
    int N = strlen(txt);
    int TF[M + 1][NO_OF_CHARS];
    computeTransFun(pat, M, TF);
    int i, j = 0;
    for (i = 0; i < N; i++)
    {
        j = TF[j][txt[i]];
        if (j == M)
        {
            cout << "pattern found at index " << i - M + 1 << endl;
        }
    }
}

int main()
{
    char txt[] = "STAR CODING";
    char pat[] = "STAR";
    search(pat, txt);
    return 0;
}
