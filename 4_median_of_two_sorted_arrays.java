class Solution {

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int m = nums1.length;
        int n = nums2.length;

        int[] merged = new int[m + n];

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < m && j < n) {

            if (nums1[i] < nums2[j]) {
                merged[k] = nums1[i];
                i++;
            } else {
                merged[k] = nums2[j];
                j++;
            }

            k++;
        }

        while (i < m) {
            merged[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n) {
            merged[k] = nums2[j];
            j++;
            k++;
        }

        int size = merged.length;

        if (size % 2 == 0) {

            return (merged[size / 2] + merged[size / 2 - 1]) / 2.0;

        } else {

            return merged[size / 2];

        }
    }
}