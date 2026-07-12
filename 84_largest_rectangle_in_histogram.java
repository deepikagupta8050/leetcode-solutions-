import java.util.Stack;

class Solution {

    public int largestRectangleArea(int[] heights) {

        Stack<Integer> stack = new Stack<>();

        int maxArea = 0;

        for (int i = 0; i <= heights.length; i++) {

            while (!stack.isEmpty() &&
                  (i == heights.length || heights[stack.peek()] > heights[i])) {

                int height = heights[stack.pop()];

                int width;

                if (stack.isEmpty()) {
                    width = i;
                } else {
                    width = i - stack.peek() - 1;
                }

                int area = height * width;

                maxArea = Math.max(maxArea, area);
            }

            stack.push(i);
        }

        return maxArea;
    }
}