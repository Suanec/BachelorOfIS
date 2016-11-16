#include <stdio.h>
#include <string.h>
 
#define MAX_CHAR 256
#define SIZE 256
#define MAX(x, y) (x) > (y) ? (x) : (y)
 
void BoyerMoore(char *pattern, int m, char *text, int n);
 
//int main()
//{
//    char text[256], pattern[256];
// 
//    while (1)
//    {
//        puts("Please input the text and the pattern:(input Q to quit.)");
//        gets(text);
//        if (!strcmp(text, "Q") || ! strcmp(text, "q")) break;
//        gets(pattern);
//        //printf("%s\n", text);
//        //printf("%s\n", pattern);
//        BoyerMoore(pattern, strlen(pattern), text, strlen(text));
//        printf("\n");
//    }
// 
//    return 0;
//}
 
void print(int *array, int n, char *arrayName)
{
    int i;
 
    printf("%s:", arrayName);
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
 
void PreBmBc(char *pattern, int m, int bmBc[])
{
    int i;
 
    for (i = 0; i < MAX_CHAR; i++)
        bmBc[i] = m;
    for (i = 0; i < m - 1; i++)
        bmBc[pattern[i]] = m - 1 - i;
    /*
    printf(""bmBc[]:);
    for (i = 0; i < m; i++)
        printf("%d ",bmBc[pattern[i]]);
    printf("\n");
    */
}
 
void suffix_old(char *pattern, int m, int suff[])
{
    int i, j;
 
    suff[m - 1] = m;
    for (i = m - 2; i >= 0; i--)
    {
        j = i;
        while (j >= 0 && pattern[j] == pattern[m -1 - i + j])
            j--;
        suff[i] = i - j;
    }
}
 
void suffix(char *pattern, int m, int suff[])  //改进计算suffix方法
{
    int f, g, i;
 
    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; --i)
    {
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else
        {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && pattern[g] == pattern[g + m - 1 - f])
                --g;
            suff[i] = f - g;
        }
    }
    //print(suff, m, "suff[]");
}
 
void PreBmGs(char *pattern, int m, int bmGs[])
{
    int i, j;
    int suff[SIZE];
 
    // 计算后缀数组
    suffix(pattern, m, suff);
 
    // 先全部赋值为m，包含Case3
    for (i = 0; i < m; i++)
        bmGs[i] = m;
 
     // Case2
    j = 0;
    for (i = m - 1; i >= 0; i--)
    {
        if (i + 1 == suff[i])
        {
            for (;j < m - 1 - i; j++)
            {
                if (m == bmGs[j])
                    bmGs[j] = m - 1 - i;
            }
        }
    }
 
    // Case1
    for (i = 0; i <= m - 2; i++)
        bmGs[m - 1 - suff[i]] = m - 1 - i;
 
    print(bmGs, m , "bmGs[]");
}
 
void BoyerMoore(char *pattern, int m, char *text, int n)
{
    int i, j, bmBc[MAX_CHAR], bmGs[SIZE];
 
    // Preprocessing
    PreBmBc(pattern, m, bmBc);
    PreBmGs(pattern, m, bmGs);
 
    // Searching
    j = 0;
    while (j <= n - m)
    {
        for (i = m - 1; i >= 0 && pattern[i] == text[i + j]; i--);
        if (i < 0)
        {
            printf("Find it, the position is %d\n", j);
            j += bmGs[0];
            return ;
        }
        else
            j += MAX(bmBc[text[i + j]] - m + 1 + i, bmGs[i]);
    }
 
    printf("No find.\n");
}