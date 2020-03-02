#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Matrix {
public:
	Matrix(int row_, int col_) {
		row = row_;
		col = col_;
		array = (float *)malloc(sizeof(float) * row * col);
		memset(array, 0, sizeof(float) * row * col); 
	}
	
	void Concat(Matrix mat2, int axis);
	void Show();
	void Eliminate(int pivot_row, int pivot_col);
	Matrix Mul(Matrix mat1); 

	int row, col;
	float *array;
};

void Matrix::Concat(Matrix mat2, int axis) {
	float * newarray = (float *)malloc(sizeof(float) * (row * col + mat2.row * mat2.col));
	
	if (axis == 0) {
		int newrow = row + mat2.row;
		int newcol = col;
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				newarray[i*col+j] = array[i*col+j];
			}
		}
		for (int i=0; i<mat2.row; i++) {
			for (int j=0; j<mat2.col; j++) {
				newarray[(row+i)*col+j] = mat2.array[i*col+j];
			}
		}
		row = newrow;
		col = newcol;
	}
	
	if (axis == 1) {
		int newrow = row;
		int newcol = col + mat2.col;
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				newarray[i*newcol+j] = array[i*col+j];
			}
		}
		for (int i=0; i<mat2.row; i++) {
			for (int j=0; j<mat2.col; j++) {
				newarray[i*newcol+(col+j)] = mat2.array[i*mat2.col+j];
			}
		}
		row = newrow;
		col = newcol;
	}
	
	free(array);
	array = newarray;
}

void Matrix::Show() {
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			cout << array[i*col+j] << " ";
		} cout << endl;
	}
}

void Matrix::Eliminate(int pivot_row, int pivot_col) {
	float pivot = array[pivot_row*col+pivot_col];
	for (int i=0; i<row; i++) {
		float r = array[i*col+pivot_col] / pivot;
		for (int j=0; j<col; j++) {
			if (i == pivot_row) {
				array[i*col+j] /= pivot;
			}
			else {
				array[i*col+j] -= array[pivot_row*col+j] * r;
			}
		}
	}
} 

Matrix Matrix::Mul(Matrix mat2) {
	Matrix newmat(row, mat2.col);
	int newrow = row;
	int newcol = mat2.col;
	for (int i=0; i<newrow; i++) {
		for (int j=0; j<newcol; j++) {
			float v = 0;
			for (int k=0; k<col; k++) {
				v += array[i*col+k] * mat2.array[k*mat2.col+j];
			}
			newmat.array[i*newcol+j] = v;
		}
	}
	return newmat;
}

int main() {
	
	int N, M;
	cin >> N >> M;
	
	Matrix b(N, 1);
	Matrix c(1, M);
	Matrix A(N, M);
	
	float v;
	for (int i=0; i<N; i++) {
		cin >> v;
		b.array[i] = v;
	}

	int idx1, idx2;
	for (int i=0; i<M; i++) {
		cin >> idx1 >> idx2 >> v;
		c.array[i] = v;
		for (int j=idx1-1; j<idx2; j++) {
			A.array[j*M+i] = 1;
		}
	}
	
	Matrix fakeA(N, N);
	Matrix nIN(N, N);
	Matrix fakec(1, N);
	
	for (int i=0; i<N; i++) {
		fakeA.array[i*N+i] = 1;
		nIN.array[i*N+i] = -1;
	}
	
	fakeA.Concat(A, 1);
	fakeA.Concat(nIN, 1);
	fakeA.Concat(b, 1);
	
	Matrix t(1, M+N+1);
	for (int i=0; i<M+N+1; i++) {
		for (int j=0; j<N; j++) {
			t.array[i] += fakeA.array[j*fakeA.col+i+N];
		}
	}
	
	fakec.Concat(t, 1);
	fakeA.Concat(fakec, 0);
	
	while (1) {
		
		int maxcol;
		float maxv = -1;
		for (int i=0; i<fakeA.col-1; i++) {
			if (fakeA.array[N*fakeA.col+i] > maxv) {
				maxv = fakeA.array[N*fakeA.col+i];
				maxcol = i; 
			}
		}

		if (fakeA.array[N*fakeA.col+maxcol] <= 0) break;

		int minrow;
		float minv=65535;
		for (int i=0; i<fakeA.row-1; i++) {
			if (fakeA.array[i*fakeA.col+maxcol] <= 0) continue;
			else {
				float v =  fakeA.array[i*fakeA.col+fakeA.col-1] / fakeA.array[i*fakeA.col+maxcol];
				if (v < minv) {
					minv = v;
					minrow = i;
				}
			}
		}
		
		fakeA.Show();
		cout << minrow << " " << maxcol << endl;
		fakeA.Eliminate(minrow, maxcol);
		fakeA.Show();
	}
	
	return 0;
}
