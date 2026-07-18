class Solution {
    public String minWindow(String s, String t) {

        if (s.length() < t.length()) {
            return "";
        }

        HashMap<Character, Integer> need = new HashMap<>();

        for (char ch : t.toCharArray()) {
            need.put(ch, need.getOrDefault(ch, 0) + 1);
        }

        HashMap<Character, Integer> have = new HashMap<>();

        int left = 0;
        int count = 0;

        int start = 0;
        int size = Integer.MAX_VALUE;

        for (int right = 0; right < s.length(); right++) {

            char ch = s.charAt(right);

            have.put(ch, have.getOrDefault(ch, 0) + 1);

            if (need.containsKey(ch) &&
                have.get(ch) <= need.get(ch)) {
                count++;
            }

            while (count == t.length()) {

                if (right - left + 1 < size) {
                    size = right - left + 1;
                    start = left;
                }

                char first = s.charAt(left);

                have.put(first, have.get(first) - 1);

                if (need.containsKey(first) &&
                    have.get(first) < need.get(first)) {
                    count--;
                }

                left++;
            }
        }

        if (size == Integer.MAX_VALUE) {
            return "";
        }

        return s.substring(start, start + size);
    }
}