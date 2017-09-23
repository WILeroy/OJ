/*Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question.*/

/************************     answer  code      ***************************/

int lengthOfLongestSubstring(char* s) {
    int tail = 0;
    int head = 1;
    int cur = 0;
    
    int max_len = 1;
    
    int slen = strlen(s);
    
    if (slen == 1)
    {
        return 1;
    }
    else if (slen == 0)
    {
        return 0;
    }
    
    while (--slen)
    {
        cur = tail;
        
        while (s[cur] != s[head])
        {
            cur++;
        }
        
        if (cur == head)
        {
            if ((head-tail+1) > max_len)
            {
                max_len = head-tail+1;
            }
            head++;
        }
        else
        {
            tail = ++cur;
            head++;
        }
    }
    
    return max_len;
}
