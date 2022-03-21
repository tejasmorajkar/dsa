#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

vector<vector<int> > generateSpiralMatrix(int A)
{
	int row_count = A;
	int col_count = A;
	vector<vector<int> > spiral_matrix(row_count, vector<int>(col_count, -1));

	if (A == 1)
	{
		spiral_matrix[0][0] = 1;
		return spiral_matrix;
	}

	int current_element = 0;
	int top_left_col = 0;
	int top_right_row = 0;
	int bottom_left_row = row_count - 1;
	int bottom_right_col = col_count - 1;

	while (top_right_row <= bottom_left_row && top_left_col <= bottom_right_col)
	{
		for (int col_index = top_left_col; col_index <= bottom_right_col; col_index++)
		{
			spiral_matrix[top_right_row][col_index] = ++current_element;
		}

		for (int row_index = top_right_row + 1; row_index <= bottom_left_row; row_index++)
		{
			spiral_matrix[row_index][bottom_right_col] = ++current_element;
		}

		for (int col_index = bottom_right_col - 1; col_index >= top_left_col; col_index--)
		{
			spiral_matrix[bottom_left_row][col_index] = ++current_element;
		}

		for (int row_index = bottom_left_row - 1; row_index >= top_right_row + 1; row_index--)
		{
			spiral_matrix[row_index][top_left_col] = ++current_element;
		}

		top_left_col++;
		top_right_row++;
		bottom_right_col--;
		bottom_left_row--;
	}
	return spiral_matrix;
}

vector<vector<int> > generateSpiralMatrix2(int A)
{
	int n = A;
	enum Direction
	{
		right,
		down,
		left,
		up
	};
	Direction dir = right;
	vector<vector<int> > matrix(n, vector<int>(n, 0));
	int i = 0, j = 0, k = 1;
	while (k <= n * n)
	{
		matrix[i][j] = k++;
		if (dir == right)
		{
			j++;
			if (j == n || matrix[i][j] != 0)
				dir = down, j--, i++;
		}
		else if (dir == down)
		{
			i++;
			if (i == n || matrix[i][j] != 0)
				dir = left, i--, j--;
		}
		else if (dir == left)
		{
			j--;
			if (j < 0 || matrix[i][j] != 0)
				dir = up, j++, i--;
		}
		else if (dir == up)
		{
			i--;
			if (i < 0 || matrix[i][j] != 0)
				dir = right, i++, j++;
		}
	}
	return matrix;
}

int main()
{
	int A = 5;
	auto start = high_resolution_clock::now();
	vector<vector<int> > result = generateSpiralMatrix2(A);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < A; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}