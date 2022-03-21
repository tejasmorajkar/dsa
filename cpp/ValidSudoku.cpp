#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int isValidSudoku(const vector<string> &A) {
    int n = A.size();
    vector<unordered_set<char> > rows(n);
    vector<unordered_set<char> > cols(n);
    vector<unordered_set<char> > sub_boxes(n);

    for (int row_num = 0; row_num < n; row_num++)
    {
        for(int col_num = 0; col_num < n ; col_num++)
        {
            char current_element = A[row_num].at(col_num);

            if(current_element == '.')
            {
                continue;
            }

            if (rows[row_num].find(current_element) != rows[row_num].end())
            {
                return 0;
            } else {
                rows[row_num].insert(current_element);
            }

            if (cols[col_num].find(current_element) != cols[col_num].end())
            {
                return 0;
            } else {
                cols[col_num].insert(current_element);
            }

            int box_num = (row_num/3)*3 + (col_num/3);
            if (sub_boxes[box_num].find(current_element) != sub_boxes[box_num].end())
            {
                return 0;
            } else {
                sub_boxes[box_num].insert(current_element);
            }
        }
    }

    return 1;
}

int main()
{
    vector<string> A{"....5..1.", ".4.3.....", ".....3..1", "8......2.", "..2.7....", ".15......", ".....2...", ".2.9.....", "..4......"};
    int result = isValidSudoku(A);
    printf("%d\n", result);
    return 0;
}