/*There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5*/

/************************     answer  code      ***************************/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = 0;
    int n = 0;
    
    int lastval = 0;
    int llastval = 0;
    
    int mn = (nums1Size + nums2Size) / 2 + 1;
    for (int i=0; i<mn; i++)
    {
        if (m<nums1Size && n<nums2Size)
        {
            if (nums1[m] < nums2[n])
            {
                llastval = lastval;
                lastval = nums1[m];
                m++;
            }
            else
            {
                llastval = lastval;
                lastval = nums2[n];
                n++;
            }
        }
        else if (m < nums1Size)
        {
            llastval = lastval;
            lastval = nums1[m];
            m++;
        }
        else
        {
            llastval = lastval;
            lastval = nums2[n];
            n++;
        }
   }
   
   return (nums1Size+nums2Size)%2 ? (double)lastval : (llastval+lastval)/2.0;
}
