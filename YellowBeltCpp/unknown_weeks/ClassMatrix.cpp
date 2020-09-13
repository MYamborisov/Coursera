#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix 

class Matrix {
public:
	Matrix() {
		size_m = 0;
		size_n = 0;
	}
	Matrix(const int& num_rows, const int& num_cols) {
		Reset(num_rows, num_cols);
	}
	vector<vector<int>> GetMatrix() const {
		return mat;
	}
	void Reset(int num_rows, int num_cols) {
		if (num_cols < 0 or num_rows < 0) {
			throw out_of_range("");
		}
		if (num_cols == 0 or num_rows == 0) {
			num_rows = num_cols = 0;
		}
		mat.assign(num_rows, vector<int>(num_cols));
		size_n = num_rows;
		size_m = num_cols;
	}
	int At(const int& num_row, const int& num_col) const {
		return mat.at(num_row).at(num_col);
	}
	int& At(const int& num_row, const int& num_col) {
		return mat.at(num_row).at(num_col);
	}
	int GetNumRows() const {
		return size_n;
	}
	int GetNumColumns() const {
		return size_m;
	}
private:
	vector<vector<int>> mat;
	int size_n;
	int size_m;
};

istream& operator>>(istream& stream, Matrix& mat) {
	int n, m;
	stream >> n >> m;
	mat.Reset(n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			stream >> mat.At(i, j);
		}
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Matrix& m) {
	stream << m.GetNumRows() << " " << m.GetNumColumns() << endl;
	for (int i = 0; i < m.GetNumRows(); ++i) {
		for (int j = 0; j < m.GetNumColumns(); ++j) {
			stream << m.At(i, j);
			if (j != m.GetNumColumns() - 1) {
				stream << " ";
			}
		}
		stream << endl;
	}
	return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows() or
	lhs.GetNumColumns() != rhs.GetNumColumns() or
	lhs.GetMatrix() != rhs.GetMatrix()) {
		return false;
	}
	return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows() or
	lhs.GetNumColumns() != rhs.GetNumColumns()) {
		throw invalid_argument("");
	}
	int n = lhs.GetNumRows(), m = lhs.GetNumColumns();
	Matrix result(n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
		}
	}
	return result;
}

int main() {
  Matrix one;
  Matrix two;


  cin >> one >> two;

	cout << "test: " <<(one == two);


  return 0;
}
