#pragma once
#include"ClassLib.h"
#include"Functions.h"


using namespace System;
using namespace System::Windows::Forms;

extern int actions;
extern int iterations;

// виділення пам'яті під масив
void Matrix::CreateMatrix(int row,int cols)
{
	this->rows = row;
	this->cols = row;
	array = new double* [row];
	for (int i = 0; i < row; i++)
	{
		array[i] = new double[cols];
	}
	//this->FillWithZero();
}

// задання елементу
void Matrix::SetElement(int row, int col, double value)
{
	this->array[row][col] = value;
}

// геттер для елемента матриці
double Matrix::GetElement(int row, int col)
{
	return array[row][col];
}

// заповнення випадковими числами
void SquareMatrix::RandomizeFill()
{
	for (int i = 0; i < this->GetSize(); i++)
	{
		for (int j = 0; j < this->GetSize(); j++)
		{
			this->SetElement(i, j, GenerateDouble());
		}
	}
}

// заповнення матриці нулями
void Matrix::FillWithZero()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->SetElement(i, j, 0);
		}
	}
}

//множення матриці на число
void Matrix::MultiplyByNumber(Matrix& entryMatrix, double num)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->SetElement(i, j, entryMatrix.GetElement(i, j) * num);
		}
	}
}

//очищення пам'яті
void Matrix::deleteMatrix()
{
	if (this->rows != 0)
	{
		if (array != NULL)
		{
			for (int i = 0; i < this->rows; i++)
			{
				delete[] array[i];
			}
			delete[] array;
		}
	}
	this->rows = 0;
	this->cols = 0;
}


// транспонування
void Matrix::transpose(Matrix& other)
{
	for (int i = 0; i < this->GetRows(); i++)
	{
		for (int j = 0; j < this->GetCols(); j++)
		{
			this->SetElement(i, j, other.GetElement(j, i));
		}
	}
}

// віднімання
Matrix Matrix::operator-(const Matrix& other) const
{
	Matrix result(rows, cols);

	for (int i = 0; i < rows; ++i) {
		incrementIter();
		for (int j = 0; j < cols; ++j) {
			incrementIter();
			incrementActions();
			result[i][j] = array[i][j] - other.array[i][j];
		}
	}
	return result;
}

//множення
Matrix Matrix::operator*(const Matrix& other) const
{
	//Matrix result;
	//result.CreateMatrix(this->rows, other.cols);
	Matrix result(rows, other.cols);
	for (int i = 0; i < rows; ++i) {
		incrementIter();
		for (int j = 0; j < other.cols; ++j) {
			incrementIter();
			result.SetElement(i,j,0);
			for (int k = 0; k < cols; ++k) {
				incrementIter();
				incrementActions();
				result.array[i][j] += array[i][k] * other.array[k][j];
			}
		}
	}

	// Повернення результату
	return result;
}

//зчитування з файлу
void FileReader::FileRead(std::string name)
{
	std::ifstream file(name);
	int size;
	if (file.is_open())
	{
		std::string line;
		int row = 0;
		file >> size;
		this->CreateMatrix(size,size);
		while (!file.eof())
		{
			int col = 0;
			while (col < size)
			{
				file >> array[row][col];
				col++;
			}
			row++;
		}
		file.close();
	}
}

// LU-розклад
void Inverser::LU_decomposition(double** LU, int size)
{
	for (int j = 0; j < size; j++)
	{
		incrementIter();
		LU[0][j] = array[0][j];
		if (j > 0)
		{
			incrementActions();
			if (array[0][0])
				LU[j][0] = array[j][0] / array[0][0];
		}
	}

	for (int i = 1; i < size; i++)
	{
		incrementIter();
		for (int j = i; j < size; j++)
		{
			incrementIter();
			double sum = array[i][j];
			for (int k = 0; k <= i - 1; k++)
			{
				incrementIter();
				incrementActions();
				sum -= LU[i][k] * LU[k][j];
			}
			LU[i][j] = sum;
		}

		for (int j = i + 1; j < size; j++)
		{
			incrementIter();
			double sum = array[j][i];
			for (int k = 0; k <= i - 1; k++)
			{
				incrementIter();
				incrementActions();
				sum -= LU[j][k] * LU[k][i];
			}
			incrementActions();
			//
			if (LU[i][i] == 0) // міняємо поточний рядок з попереднім
			{
				for (int k = 0; k < size; k++)
				{
					double temp = LU[i - 1][k];
					LU[i - 1][k] = LU[i][k];
					LU[i][k] = temp;
				}
			}

			LU[j][i] = 1 / LU[i][i] * sum;
		}
	}
	double mult = 1;
	
	for (int i = 0; i < size; i++)
	{
		incrementIter();
		//incrementActions();
		mult *= LU[i][i];
	}
	
	if ( mult == 0)
		SquareMatrix::determinant = 0;
	else {
		determinant = mult;
	}
}

// обернення LU матриці
void Inverser::LU_inverse(double** LU)
{
	int size = this->GetRows();
	incrementActions();
	array[size - 1][size - 1] = 1 / LU[size - 1][size - 1];
	for (int row = size - 1; row >= 0; row--)
	{
		incrementIter();
		for (int col = size - 1; col >= 0; col--)
		{
			incrementIter();
			int n = -1;
			if ((col == row) && col == size - 1)
				continue;
			if (col < row) //нижньотрикутна (L)
			{
				double down_sum = 0;
				for (int i = col + 1; i <= size - 1; i++)
				{
					incrementIter();
					incrementActions();
					down_sum += n * array[row][i] * LU[i][col];
				}
				array[row][col] = down_sum;
			}
			else if (col > row) { //U
				double upper_sum = 0;
				for (int i = row + 1; i <= size - 1; i++)
				{
					incrementIter();
					incrementActions();
					upper_sum += LU[row][i] * array[i][col];
				}
				incrementActions();
				array[row][col] = (-1 / LU[row][row]) * upper_sum;
			}
			else { //  діагональні
				double sum = 1;
				for (int i = row + 1; i <= size - 1; i++)
				{
					incrementIter();
					incrementActions();
					sum -= LU[row][i] * array[i][row];
				}
				incrementActions();
				array[row][col] = 1 / LU[row][row] * sum;
			}
		}
	}
}

// розбиття
std::tuple<Matrix, Matrix, Matrix, Matrix> DivideIntoBlocks(Matrix m)
{
	int size = m.GetRows();
	int p;
	if (size % 2 == 1)
	{
		incrementActions();
		p = size / 2 + 1;
	}
	else {
		incrementActions();
		p = size / 2;
	}

	Matrix A(p, p);
	Matrix B(p, size - p);
	Matrix C(size - p, p);
	Matrix D(size - p, size - p);

	for (int i = 0; i < size; ++i)
	{
		incrementIter();
		for (int j = 0; j < size; ++j)
		{
			incrementIter(); 
			if ((i < p) && (j < p))
			{
				A[i][j] = m[i][j];
			}
			else if (i < p)
			{
				B[i][j - p] = m[i][j];
			}
			else if (j < p)
			{
				C[i - (int)p][j] = m[i][j];
			}
			else
			{
				D[i - (int)p][j - p] = m[i][j];
			}
		}
	}
	return std::make_tuple(A, B, C, D);
}

//об'єднання 
Matrix MergeBlocks(Matrix A, Matrix B, Matrix C, Matrix D)
{
	incrementActions();
	int a_size = A.GetCols();
	int n_columns = a_size + B.GetCols();
	int n_rows = a_size + C.GetRows();
	Matrix result(n_rows, n_rows);
	for (int i = 0; i < n_rows; i++)
	{
		incrementIter();
		for (int j = 0; j < n_columns; j++)
		{
			incrementIter();
			if ((i < a_size) && (j < a_size))
			{
				result[i][j] = A[i][j];
			}
			else if (i < a_size)
			{
				result[i][j] = B[i][j - a_size];
			}
			else if (j < a_size)
			{
				result[i][j] = C[i - (int)a_size][j];
			}
			else
			{
				result[i][j] = D[i - (int)a_size][j - a_size];
			}
		}
	}
	return result;
}

// обернення
Matrix BlockWiseInversion(Matrix m)
{
	double det;

	// для знаходження визначника
	Inverser temporary1, temporary2;

	temporary1.copyMatrix(m);
	temporary2.CreateMatrix(m.GetRows(),m.GetRows());
	temporary1.LU_decomposition(temporary2.GetAdress(), temporary2.GetSize());
	det = temporary1.GetDet();
	temporary1.deleteMatrix();
	temporary2.deleteMatrix();
	if (!det)
	{
		throw std::runtime_error("error"); //"Одна з матриць, отриманих при розбитті, є виродженою. Неможливо знайти обернену цим методом"
	}
	else {
		if (m.GetRows() == 1)
		{
			m[0][0] = 1 / m[0][0];
			incrementActions();
		}
		else if (m.GetRows() == 2) {
			incrementActions();
			double temp = m[0][0];
			m[0][0] = m[1][1] / det;
			incrementActions();
			m[1][1] = temp / det;
			incrementActions();
			m[0][1] = -m[0][1] / det;
			incrementActions();
			m[1][0] = -m[1][0] / det;
		}
		else {
			Matrix A, B, C,D;
			std::tuple<Matrix, Matrix, Matrix, Matrix> result = DivideIntoBlocks(m);
			std::tie(A, B, C, D) = result;

			Matrix K, L, M, N, X, Y, temp;

			m.deleteMatrix();
			D = BlockWiseInversion(D);
			X = B * D;
			Y = D * C;
			temp = X * C;

			K = BlockWiseInversion(A - temp);
			temp.deleteMatrix();

			L = K * X;
			L*(-1);

			M = Y * K;
			M* (-1);
			temp = Y * L;
			N = D - temp;

			temp.deleteMatrix();
			X.deleteMatrix();
			Y.deleteMatrix();
			A.deleteMatrix();
			B.deleteMatrix();
			C.deleteMatrix();
			D.deleteMatrix();

			m = MergeBlocks(K, L, M, N);
			K.deleteMatrix();
			L.deleteMatrix();
			M.deleteMatrix();
			N.deleteMatrix();
		}
	}
	return m;
}

//копіювання з Matrix у Inverser
void Matrix::copyMatrix(Matrix& A)
{
	if (this->GetRows() != 0)
		this->deleteMatrix();
	int size = A.GetRows();
	this->CreateMatrix(size,size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			this->SetElement(i, j, A.GetElement(i, j));
		}
	}
}


Matrix::Matrix(int r, int c)
{
	rows = r;
	cols = c;
	array = new double* [rows];
	for (int i = 0; i < rows; i++)
		array[i] = new double[cols];
}


void Matrix::operator*(double num) const {

	// Множення на константу
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			array[i][j] *= num;
		}
	}
}

Matrix::Matrix(const Matrix& other) {
	rows = other.rows;
	cols = other.cols;

	// Виділення пам'яті для нового масиву
	array = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		array[i] = new double[cols];
	}

	// Копіювання значень з існуючого масиву
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			array[i][j] = other.array[i][j];
		}
	}
}