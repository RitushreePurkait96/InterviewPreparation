733. Flood Fill
https://leetcode.com/problems/flood-fill/description/

Hint
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.
Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Solution:
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        /* Solution using BFS */

        int originalColor = image[sr][sc];
        if(originalColor == color)
        {
            // If the original color is the same as the new color, no need to proceed
            return image;
        }

        int rows = image.size();
        int cols = image[0].size();

         // Define the directions for adjacent pixels (up, down, left, right)
         vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

         // BFS queue to process each pixel that needs to be filled
         queue<pair<int, int>> q;
         q.push({sr, sc});

         // Start by changing the color of the starting pixel
         image[sr][sc] = color;

         while(!q.empty())
         {
            auto [r, c] = q.front();
            q.pop();

            for(auto [dr, dc] : directions)
            {
                int newRow = r + dr;
                int newCol = c + dc;

                // Check if the new position is within bounds and has the original color
                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    image[newRow][newCol] == originalColor)
                {
                    image[newRow][newCol] = color; // Change color
                    q.push({newRow, newCol}); // Add to queue for further exploration
                        
                }
            }
         }
        return image;
    }
};
