class Solution {

    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int[] answer = new int[m + n];

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < m && j < n) {

            if (nums1[i] <= nums2[j]) {
                answer[k] = nums1[i];
                i++;
            } else {
                answer[k] = nums2[j];
                j++;
            }

            k++;
        }

        while (i < m) {
            answer[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n) {
            answer[k] = nums2[j];
            j++;
            k++;
        }

        for (int x = 0; x < m + n; x++) {
            nums1[x] = answer[x];
        }
    }
}