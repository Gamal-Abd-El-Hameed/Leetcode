class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = 0, i2 = 0, counter, nums1Limit = m;
        while (i1 < nums1Limit && i2 < n) {
            if (nums1[i1] > nums2[i2]) {
                counter = m + n - 1;
                while (counter > i1) {
                    nums1[counter] = nums1[counter - 1];
                    counter--;
                }
                nums1Limit++;
                nums1[i1] = nums2[i2++];
            }
            i1++;
        }
        while (i2 < n) {
            nums1[i1++] = nums2[i2++];
        }
    }
};