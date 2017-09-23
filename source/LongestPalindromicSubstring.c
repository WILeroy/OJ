/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example:

Input: "cbbd"

Output: "bb"*/

/************************     answer  code      ***************************/

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int max_middle = -1;
    int max_dmiddle = -1;
    int max_halfsize = -1;
    int max_dhalfsize = -1;
    
    for (int i=0; i<len; i++)
    {
        int ssize = len - i;
        int dssize = ssize - 1;
        for (int j=0; j<=i&&j<ssize; j++)
        {
            if (s[i-j] != s[i+j])
            {
                break;
            }
            else if (j > max_halfsize)
            {
                max_middle = i;
                max_halfsize = j;
            }
        }
        
        for (int j=0; j<=i&&j<dssize; j++)
        {
            if (s[i-j] != s[i+1+j])
            {
                break;
            }
            else if (j > max_dhalfsize)
            {
                max_dmiddle = i;
                max_dhalfsize = j;
            }
        }
    }
    
    int dsize = 2*max_dhalfsize+2;
    int size = 2*max_halfsize+1;
    
    if (size > dsize)
    {
        int i;
        char *result = (char *)malloc(sizeof(char) * (size+1));
        for (i=0; i<size; i++)
        {
            result[i] = s[max_middle-max_halfsize+i];
        }
        result[i] = '\0';
        return result;
    }
    else
    {
        int i;
        char *result = (char *)malloc(sizeof(char) * (dsize+1));
        for (i=0; i<dsize; i++)
        {
            result[i] = s[max_dmiddle-max_dhalfsize+i];
        }
        result[i] = '\0';
        return result;
    }
}
