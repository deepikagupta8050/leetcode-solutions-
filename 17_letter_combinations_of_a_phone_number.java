class Solution {
    List<String> ans = new ArrayList<>();

    String[] phone = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {

        if (digits.length() == 0) {
            return ans;
        }

        solve(digits, 0, "");

        return ans;
    }

    public void solve(String digits, int index, String word) {

        if (index == digits.length()) {
            ans.add(word);
            return;
        }

        String letters = phone[digits.charAt(index) - '0'];

        for (int i = 0; i < letters.length(); i++) {

            solve(digits,
                  index + 1,
                  word + letters.charAt(i));
        }
    }
}