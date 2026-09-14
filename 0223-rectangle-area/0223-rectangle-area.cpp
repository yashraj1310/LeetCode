class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        if(bx2 <= ax1 || ax2 <= bx1 || ay1 >= by2 || by1 >= ay2)
            return (abs(ax1-ax2)*abs(ay1-ay2) + abs(bx1-bx2)*abs(by1-by2));

        int overlap = 0;

        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int top = min(ay2, by2);
        int bottom = max(ay1, by1);

        overlap = abs(left-right)*abs(top-bottom);

        return (abs(ax1-ax2)*abs(ay1-ay2) + abs(bx1-bx2)*abs(by1-by2)) - overlap;
    }
};