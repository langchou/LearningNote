#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    KMPÀ„∑®
*/
//void get_next(char s[], int next[]);
//int KMP(char s1[], char s2[], int next[]);
//int main() {
//    int i = 0;
//    int next[1000];
//    char s2[] = "abcac";
//    char s1[] = "ababcabcacbab";
//    get_next(s2, next);
//
//    i = KMP(s1, s2, next);
//    printf("%d\n", i);
//    return 0;
//}
//void get_next(char s[], int next[])
//{
//    int len = 0;
//    int i = 0;
//    int j = -1;
//    next[0] = -1;
//    len = strlen(s);
//    while (i < len - 1)
//    {
//        if (j == -1 || s[i] == s[j])
//        {
//            i++;
//            j++;
//            next[i] = j;
//        }
//        else
//        {
//            j = next[j];
//        }
//    }
//}
//int KMP(char s1[], char s2[], int next[])
//{
//    int i = 0;
//    int j = 0;
//    int len1 = strlen(s1);
//    int len2 = strlen(s2);
//    while (i < len1 && j < len2)
//    {
//        if (j == -1 || s1[i] == s2[j])
//        {
//            i++;
//            j++;
//        }
//        else
//        {
//            j = next[j];
//        }
//    }
//    if (j >= len2)
//        return i - len2 + 1;
//    else
//        return -1;
//}


//int main()
//{
//    char arr[] = "djd@123.abc";
//    char tmp[20] = { 0 };
//    char* p = "@.";
//    strcpy(tmp, arr);
//    char* ret = NULL;
//    for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
//    {
//        printf("%s\n", ret);
//    }
// 
//     return 0;
//}