#include <stdlib.h>

int largestRectangleArea(int* heights, int size) {
    int stack[size + 1];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= size; i++) {
        int currHeight = (i == size) ? 0 : heights[i];
        while (top != -1 && heights[stack[top]] > currHeight) {
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            int area = h * width;
            if (area > maxArea) maxArea = area;
        }
        stack[++top] = i;
    }

    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || *matrixColSize == 0) return 0;

    int cols = *matrixColSize;
    int heights[cols];
    for (int i = 0; i < cols; i++) heights[i] = 0;

    int maxArea = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        int area = largestRectangleArea(heights, cols);
        if (area > maxArea) maxArea = area;
    }

    return maxArea;
}
