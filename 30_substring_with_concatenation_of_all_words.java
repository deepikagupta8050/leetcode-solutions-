class Solution {
    public List<Integer> findSubstring(String s, String[] words) {

        List<Integer> ans = new ArrayList<>();

        if (s.length() == 0 || words.length == 0) {
            return ans;
        }

        int len = words[0].length();
        int total = words.length;

        HashMap<String, Integer> need = new HashMap<>();

        for (String word : words) {
            need.put(word, need.getOrDefault(word, 0) + 1);
        }

        for (int start = 0; start < len; start++) {

            HashMap<String, Integer> seen = new HashMap<>();

            int left = start;
            int count = 0;

            for (int right = start; right + len <= s.length(); right += len) {

                String word = s.substring(right, right + len);

                if (need.containsKey(word)) {

                    seen.put(word, seen.getOrDefault(word, 0) + 1);
                    count++;

                    while (seen.get(word) > need.get(word)) {

                        String first = s.substring(left, left + len);

                        seen.put(first, seen.get(first) - 1);

                        left += len;
                        count--;
                    }

                    if (count == total) {

                        ans.add(left);

                        String first = s.substring(left, left + len);

                        seen.put(first, seen.get(first) - 1);

                        left += len;
                        count--;
                    }

                } else {

                    seen.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        return ans;
    }
}