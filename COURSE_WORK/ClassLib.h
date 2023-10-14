#pragma once
#include<string>

class Matrix
{
protected:
	int rows;
	int cols;
	double** array;

public:
	void CreateMatrix(int rows, int cols);
	void SetElement(int row, int col, double value);
	void SetAdress(double** adr) { array = adr; }
	void deleteMatrix();
	void MultiplyByNumber(Matrix& entryMatrix, double num);
	void copyMatrix(Matrix& matrix);
	void FillWithZero();
	void operator*(double num) const;
	void transpose(Matrix& other);

	double GetElement(int row, int col);
	double** GetAdress() { return array; }
	double* operator[](int row) { return array[row]; }
	int GetRows() { return rows; }
	int GetCols() { return cols; }	
	
	Matrix() { rows = 0; cols = 0; };
	Matrix(int r, int c);

	Matrix::Matrix(const Matrix& other);
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
};

class SquareMatrix: public Matrix
{
protected:
	double determinant;
public:
	void SetDet(double det) { determinant = det; }
	void RandomizeFill();
	void CreateSquareMatrix(int size) { CreateMatrix(size, size); }

	int GetSize() { return rows; }
	double GetDet() { return determinant; }
};

class FileReader:public SquareMatrix
{
public:
	void FileRead(std::string name);
};

class Inverser : public SquareMatrix
{
public:
	void LU_decomposition(double** LU, int size);
	void LU_inverse(double** LU);
	Inverser() { rows = 0; cols = 0;}
};


Matrix BlockWiseInversion(Matrix m);
Matrix MergeBlocks(Matrix A, Matrix B, Matrix C, Matrix D);
std::tuple<Matrix, Matrix, Matrix, Matrix> DivideIntoBlocks(Matrix m);