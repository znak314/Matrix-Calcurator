#include "MyForm.h"
#include"Functions.h"

using namespace System;
using namespace System::Windows::Forms;

//глобальна змінна нашого класу
SquareMatrix work_matrix, result_matrix;
std::string operation; //змінна для збереження виконаної опції (потрібно для запису у файл)
int actions, iterations; // для підрахунку дій/ітерацій


// інфа про прогу
System::Void COURSEWORK::MyForm::проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("\tЦе мій курсовий проект на тему \"Матричний калькулятор\"\n\t\t\t   Ввід чисел:\n -Цілі числа (напр. 2,0,6)\n -Десяткові дроби (вводяться через крапку/кому)\n\n\tДіапазон допустимих значень - (±10^(-300) , ±10^300)\n\t\tГенерація - числа від -100 до 100\nДужки,букви,операції додавання, віднімання, множення та інші - не підтримуються!", "Інформація про програму");
	return System::Void();
}

// кнопка створення
System::Void COURSEWORK::MyForm::Create_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (work_matrix.GetSize() != Convert::ToInt32(Розмірність->Value))
	{
		Reset();
		work_matrix.deleteMatrix();
		work_matrix.CreateMatrix(Convert::ToInt32(Розмірність->Value), Convert::ToInt32(Розмірність->Value));
		work_matrix.FillWithZero();
		if (result_matrix.GetSize() != 0)
		{
			dataGridView2->Rows->Clear();
			dataGridView2->Columns->Clear();
		}
	}
	else {
		MessageBox::Show("Матриця з такою розмірністю вже створена", "Увага");
		return;
	}
	ShowMatrix();
	return System::Void();
}

//  генерація
System::Void COURSEWORK::MyForm::generate_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	if (work_matrix.GetSize() == 0) {
		MessageBox::Show("Спочатку створіть матрицю!", "Помилка");
		return;
	}
	else if (work_matrix.GetSize() != Convert::ToInt32(Розмірність->Value)) {
		work_matrix.deleteMatrix();
		work_matrix.CreateMatrix(Convert::ToInt32(Розмірність->Value), Convert::ToInt32(Розмірність->Value));
	}
	if (result_matrix.GetSize() != 0)
	{
		dataGridView2->Rows->Clear();
		dataGridView2->Columns->Clear();
	}
	work_matrix.RandomizeFill();
	Reset();
	ShowMatrix();
	return System::Void();
}

// показ вхідної матриці
void COURSEWORK::MyForm::ShowMatrix()
{
	int size = work_matrix.GetSize();
	dataGridView1->RowCount = size;
	dataGridView1->ColumnCount = size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			dataGridView1->Columns[j]->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::LightSteelBlue;
			dataGridView1->TopLeftHeaderCell->Value = "";
			//номери стовпців
			dataGridView1->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//номери строк
			dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			// вивід значень
			dataGridView1->Rows[i]->Cells[j]->Value = work_matrix.GetElement(i,j);
		}
	}

	dataGridView1->RowHeadersDefaultCellStyle->BackColor = Color::PaleGreen;
	dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = Color::PaleGreen;

	//вирівнюємо
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();
}

// скидання налаштувань текстів
void COURSEWORK::MyForm::Reset()
{
	actions = 0;
	iterations = 0;

	operations->Text = " ";
	iter_count->Text = " ";
}

// показ вихідної матриці
void COURSEWORK::MyForm::ShowResultMatrix()
{
	int size = result_matrix.GetSize();
	//створюєм таблицю
	dataGridView2->RowCount = size;
	dataGridView2->ColumnCount = size;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::LightSteelBlue;
			dataGridView2->Columns[j]->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridView2->TopLeftHeaderCell->Value = "";
			//номери стовпців
			dataGridView2->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//номери строк
			dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			// вивід значень
			dataGridView2->Rows[i]->Cells[j]->Value = result_matrix.GetElement(i, j);
		}
	}

	//вирівнюємо
	dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView2->AutoResizeColumns();
}

//валідація матриці х інтерфейсу
int COURSEWORK::MyForm::ReadMatrixFromInterface()
{
	int flag = 1;
	int size = work_matrix.GetSize();
	dataGridView1->RowCount = size;
	dataGridView1->ColumnCount = size;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::LightSteelBlue;
			DataGridViewCell^ cell = dataGridView1->Rows[i]->Cells[j];
			String^ value = cell->Value->ToString();
			std::string temp;
			Convert_String_to_string(value, temp);
			if (is_number_validator(temp))
			{
				std::replace(temp.begin(),temp.end(), ',', '.');
				work_matrix.SetElement(i, j, stod(temp)); //System::Convert::ToDouble(cell->Value)
			}
			else {
				dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
				flag = 0;
			}
		}
	}
	if (!flag)
		MessageBox::Show("Переконайтеся, що вираз введено правильно та заповнено всі поля. Ви можете вводити числа в поля введення. Для отримання додаткової інформації перегляньте пункт \"Про програму\"", "Помилка");
	return flag;
}

// очищення
System::Void COURSEWORK::MyForm::Clear_btn_Click(System::Object^ sender, System::EventArgs^ e)
{
	int size = work_matrix.GetSize();
	if (size == 0) {
		MessageBox::Show("Спочатку створіть матрицю!", "Помилка");
		return;
	}
	else {
		dataGridView2->Rows->Clear();
		dataGridView2->Columns->Clear();
		work_matrix.FillWithZero();
		Reset();
		operation.clear();
		result_matrix.deleteMatrix();
		ShowMatrix();
	}
	return System::Void();
}

//зчитування з файлу
System::Void COURSEWORK::MyForm::file_read_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (file_name->Text == "")
	{
		MessageBox::Show("Уведіть назву файл", "Помилка");
		return;
	}
	else {
		std::string filename;
		Convert_String_to_string(file_name->Text, filename);

		if (FileFormatValidator(filename))
		{
			int size;

			dataGridView2->Rows->Clear();
			dataGridView2->Columns->Clear();

			FileReader matrix_from_file;
			matrix_from_file.deleteMatrix();
			matrix_from_file.FileRead(filename);
			
			size = matrix_from_file.GetSize();
			work_matrix.deleteMatrix();
			work_matrix.CreateMatrix(size,size);
			work_matrix.copyMatrix(matrix_from_file);
			
			dataGridView1->RowCount = size;
			dataGridView1->ColumnCount = size;
			matrix_from_file.deleteMatrix();
			Reset();
			ShowMatrix();
		}
		else if (!fileExists(filename))
		{
			MessageBox::Show("Упс! Схоже, ми не знайшли файлу з таким іменем на цьому пристрої!", "Помилка");
			return;
		}
		else {
			MessageBox::Show("На жаль, формат запису у цьому файлі не підтримується програмою\n Записи у файлі повинні бути записані у форматі:\n\n //розмір\nA_11 ..... A_1n\n.......          .......\nA_n1 ..... A_nn", "Помилка");
			return;
		}
	}

	return System::Void();
}

// кнопка транспонування
System::Void COURSEWORK::MyForm::Transponation_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("Спочатку створіть матрицю!", "Помилка");
		return;
	}
	else if (ReadMatrixFromInterface()) //якщо  не виникло помилок при зчитуванні з матриці
	{
		operation.clear();
		operation = "Обрана дія - транспонування";
		Reset();

		result_matrix.deleteMatrix();
		result_matrix.CreateMatrix(work_matrix.GetSize(),work_matrix.GetSize());
		result_matrix.transpose(work_matrix);
		ShowResultMatrix();			
	}
	return System::Void();
}

// множення
System::Void COURSEWORK::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string const_mult;
	Convert_String_to_string(константа_множення->Text, const_mult);
	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("Спочатку створіть матрицю!", "Помилка");
		return;
	}
	else if (!is_number_validator(const_mult) || const_mult == "")
	{
		MessageBox::Show("Уведіть число!", "Помилка");
		return;
	}
	else if (ReadMatrixFromInterface()){
		Reset();
		operation.clear();
		operation = "Обрана дія - множення на константу";
		result_matrix.deleteMatrix();
		int size = work_matrix.GetSize();
		double constant = stod(const_mult);
		result_matrix.CreateMatrix(size,size);
		result_matrix.MultiplyByNumber(work_matrix, constant);
		ShowResultMatrix();
	}
	return System::Void();
}

// кнопка вставити у вхідну
System::Void COURSEWORK::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView2->RowCount == 0) // якщо пустий
	{
		MessageBox::Show("Вихідна матриця є порожньою.", "Помилка");
		return;
	}
	else {
		int rowCount = dataGridView2->RowCount;
		int columnCount = dataGridView2->ColumnCount;
		Reset();

		// Очистка dataGridView1
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();

		// Додавання стовпців до dataGridView1
		for (int i = 0; i < columnCount; ++i) {
			String^ columnName = dataGridView2->Columns[i]->HeaderText;
			dataGridView1->Columns->Add(columnName, columnName);
		}
		// Копіювання даних з dataGridView2 в dataGridView1
		for (int row = 0; row < rowCount; ++row) {
			DataGridViewRow^ dataGridViewRow = gcnew DataGridViewRow();
			for (int col = 0; col < columnCount; ++col) {
				String^ cellValue = dataGridView2->Rows[row]->Cells[col]->Value->ToString();
				dataGridViewRow->Cells->Add(gcnew DataGridViewTextBoxCell());
				dataGridViewRow->Cells[col]->Value = cellValue;
			}
			dataGridView1->Rows->Add(dataGridViewRow);
			dataGridView1->Rows[row]->HeaderCell->Value = Convert::ToString(row + 1);
		}

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < columnCount; j++)
			{
				dataGridView1->Columns[j]->SortMode = DataGridViewColumnSortMode::NotSortable;
				dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::LightSteelBlue;
			}
		}
		dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		dataGridView1->AutoResizeColumns();

		dataGridView2->Rows->Clear();
		dataGridView2->Columns->Clear();
	}
	return System::Void();
}

//знаходження визначника
System::Void COURSEWORK::MyForm::find_determinant_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("Спочатку створіть матрицю!", "Помилка");
		return;
	}
	else if (ReadMatrixFromInterface()) {//якщо  не виникло помилок при зчитуванні з матриці
		Reset();
		operation.clear();
		operation = "Обрана дія - знаходження визначника";
		if (work_matrix.GetSize() == 2)
		{ 
			double res = work_matrix.GetElement(0, 0) * work_matrix.GetElement(1, 1) - work_matrix.GetElement(1, 0) * work_matrix.GetElement(0, 1);
			work_matrix.SetDet(res);
		}
		else {
			Inverser A;
			A.copyMatrix(work_matrix);
			Matrix LU;
			LU.CreateMatrix(A.GetSize(), A.GetSize());
			A.LU_decomposition(LU.GetAdress(), A.GetSize());
			LU.deleteMatrix();
			work_matrix.SetDet(A.GetDet());
		}
		if (isnan(work_matrix.GetDet()))
		{
			MessageBox::Show("На жаль, алгоритм програми  не може обрахувати визначник для цієї матриці ", "Результат");
		}
		else {
			std::string text = " Визначник цієї матриці = " + std::to_string(work_matrix.GetDet());
			String^ message = gcnew String(text.c_str());
			MessageBox::Show(message, "Результат");
		}
	}
	return System::Void();
}

//обернення LU матриці
System::Void COURSEWORK::MyForm::LU_inverse_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("Спочатку створіть матрицю!", "Помилка");
		return;
	}
	else if (ReadMatrixFromInterface()) {
		Reset(); 
		Inverser A;
		Matrix LU;

		A.copyMatrix(work_matrix);
		int size = A.GetSize();
		LU.CreateMatrix(size,size);
		A.LU_decomposition(LU.GetAdress(), size);
		if (A.GetDet() != 0 && !isnan(A.GetDet()))
		{
			operation.clear();
			operation = "Обрана дія - обернення матриці методом LU-розкладу";
			A.LU_inverse(LU.GetAdress());
			result_matrix.deleteMatrix();
			result_matrix.CreateMatrix(size,size);
			result_matrix.copyMatrix(A);

			operations->Text = "Операції: " + actions;
			iter_count->Text = "Ітерації: " + iterations;
			ShowResultMatrix();
		}
		else if (!A.GetElement(0, 0))
		{
			MessageBox::Show("Неможливо знайти обернену матрицю цим методом, адже елемент з індексом [0][0] дорівнює нулю", "Увага");
		}
		else if (isnan(A.GetDet()))
		{
			MessageBox::Show("Неможливо знайти обернену матрицю цим методом, адже один з діагональних елементів матриці U рівний нулю", "Увага");
		}
		else {
			MessageBox::Show("Оскільки визначник цієї матриці = 0, то оберненої матриці не існує", "Увага");
		}
		LU.deleteMatrix();
		A.deleteMatrix();
	}
	return System::Void();
}

// кнопка збереження 
System::Void COURSEWORK::MyForm::зберегтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!operation.empty())
	{
		std::string fileName = "Matrix Calculator file";
		std::ofstream file(fileName, std::ios::out | std::ios::trunc);

		if (file.is_open()) {
			processFile(file, work_matrix,0,0);
			file << std::endl << operation << std::endl << std::endl;
			if (operation == "Обрана дія - знаходження визначника")
			{
				file << "Визначник матриці = " << work_matrix.GetDet() << std::endl;
			}
			else {
				processFile(file, result_matrix, actions,iterations);
			}
			MessageBox::Show("Дані успішно записані у файл \"Matrix Calculator file\" ", "Результат");
			file.close();
		}
		else {
			MessageBox::Show("Неможливо створити файл", "Помилка");
		}
	}
	else {
		MessageBox::Show("Ще не було виконано жодної операції", "Помилка");
	}
	return System::Void();
}

// обернення розбиттям на клітки
System::Void COURSEWORK::MyForm::squares_inverse_Click(System::Object^ sender, System::EventArgs^ e)
{
	actions = 0;
	iterations = 0;

	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("Спочатку створіть матрицю!", "Помилка");
		return;
	}
	else if (ReadMatrixFromInterface()) {
		operation.clear();
		operation = "Обрана дія - обернення матриці методом розбиття на клітки";
		Reset();
		Matrix mtr;
		mtr.copyMatrix(work_matrix);
		try {
			mtr = BlockWiseInversion(mtr);
			result_matrix.deleteMatrix();
			result_matrix.copyMatrix(mtr);
			operations->Text = "Операції: " + actions;
			iter_count->Text = "Ітерації: " + iterations;
			ShowResultMatrix();
		}
		catch (const std::runtime_error& e) {
			
			MessageBox::Show("Одна з матриць, отриманих при розбитті, є виродженою. Неможливо знайти обернену цим методом", "Помилка");
		}
		mtr.deleteMatrix();
	}
	return System::Void();
}

// інкременування к-ті ітерацій
void incrementIter() {
	iterations++;
}

// інкременування к-ті операцій
void incrementActions() {
	actions++;
}