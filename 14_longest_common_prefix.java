class Solution {

    public String longestCommonPrefix(String[] strs) {

        String answer = "";

        for (int position = 0; position < strs[0].length(); position++) {

            char currentChar = strs[0].charAt(position);

            for (int word = 1; word < strs.length; word++) {

                if (position >= strs[word].length() ||
                    strs[word].charAt(position) != currentChar) {

                    return answer;
                }
            }

            answer += currentChar;
        }

        return answer;
    }
}