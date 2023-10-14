#include "MyForm.h"
#include"Functions.h"

using namespace System;
using namespace System::Windows::Forms;

//��������� ����� ������ �����
SquareMatrix work_matrix, result_matrix;
std::string operation; //����� ��� ���������� �������� ����� (������� ��� ������ � ����)
int actions, iterations; // ��� ��������� ��/��������


// ���� ��� �����
System::Void COURSEWORK::MyForm::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("\t�� �� �������� ������ �� ���� \"��������� �����������\"\n\t\t\t   ��� �����:\n -ֳ� ����� (����. 2,0,6)\n -�������� ����� (��������� ����� ������/����)\n\n\tĳ������ ���������� ������� - (�10^(-300) , �10^300)\n\t\t��������� - ����� �� -100 �� 100\n�����,�����,�������� ���������, ��������, �������� �� ���� - �� ������������!", "���������� ��� ��������");
	return System::Void();
}

// ������ ���������
System::Void COURSEWORK::MyForm::Create_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (work_matrix.GetSize() != Convert::ToInt32(���������->Value))
	{
		Reset();
		work_matrix.deleteMatrix();
		work_matrix.CreateMatrix(Convert::ToInt32(���������->Value), Convert::ToInt32(���������->Value));
		work_matrix.FillWithZero();
		if (result_matrix.GetSize() != 0)
		{
			dataGridView2->Rows->Clear();
			dataGridView2->Columns->Clear();
		}
	}
	else {
		MessageBox::Show("������� � ����� ��������� ��� ��������", "�����");
		return;
	}
	ShowMatrix();
	return System::Void();
}

//  ���������
System::Void COURSEWORK::MyForm::generate_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	if (work_matrix.GetSize() == 0) {
		MessageBox::Show("�������� ������� �������!", "�������");
		return;
	}
	else if (work_matrix.GetSize() != Convert::ToInt32(���������->Value)) {
		work_matrix.deleteMatrix();
		work_matrix.CreateMatrix(Convert::ToInt32(���������->Value), Convert::ToInt32(���������->Value));
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

// ����� ������ �������
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
			//������ ��������
			dataGridView1->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//������ �����
			dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			// ���� �������
			dataGridView1->Rows[i]->Cells[j]->Value = work_matrix.GetElement(i,j);
		}
	}

	dataGridView1->RowHeadersDefaultCellStyle->BackColor = Color::PaleGreen;
	dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = Color::PaleGreen;

	//���������
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();
}

// �������� ����������� ������
void COURSEWORK::MyForm::Reset()
{
	actions = 0;
	iterations = 0;

	operations->Text = " ";
	iter_count->Text = " ";
}

// ����� ������� �������
void COURSEWORK::MyForm::ShowResultMatrix()
{
	int size = result_matrix.GetSize();
	//�������� �������
	dataGridView2->RowCount = size;
	dataGridView2->ColumnCount = size;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::LightSteelBlue;
			dataGridView2->Columns[j]->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridView2->TopLeftHeaderCell->Value = "";
			//������ ��������
			dataGridView2->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//������ �����
			dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			// ���� �������
			dataGridView2->Rows[i]->Cells[j]->Value = result_matrix.GetElement(i, j);
		}
	}

	//���������
	dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView2->AutoResizeColumns();
}

//�������� ������� � ����������
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
		MessageBox::Show("�������������, �� ����� ������� ��������� �� ��������� �� ����. �� ������ ������� ����� � ���� ��������. ��� ��������� ��������� ���������� ����������� ����� \"��� ��������\"", "�������");
	return flag;
}

// ��������
System::Void COURSEWORK::MyForm::Clear_btn_Click(System::Object^ sender, System::EventArgs^ e)
{
	int size = work_matrix.GetSize();
	if (size == 0) {
		MessageBox::Show("�������� ������� �������!", "�������");
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

//���������� � �����
System::Void COURSEWORK::MyForm::file_read_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (file_name->Text == "")
	{
		MessageBox::Show("������ ����� ����", "�������");
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
			MessageBox::Show("���! �����, �� �� ������� ����� � ����� ������ �� ����� �������!", "�������");
			return;
		}
		else {
			MessageBox::Show("�� ����, ������ ������ � ����� ���� �� ����������� ���������\n ������ � ���� ������ ���� ������� � ������:\n\n //�����\nA_11 ..... A_1n\n.......          .......\nA_n1 ..... A_nn", "�������");
			return;
		}
	}

	return System::Void();
}

// ������ ��������������
System::Void COURSEWORK::MyForm::Transponation_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("�������� ������� �������!", "�������");
		return;
	}
	else if (ReadMatrixFromInterface()) //����  �� ������� ������� ��� ��������� � �������
	{
		operation.clear();
		operation = "������ �� - ��������������";
		Reset();

		result_matrix.deleteMatrix();
		result_matrix.CreateMatrix(work_matrix.GetSize(),work_matrix.GetSize());
		result_matrix.transpose(work_matrix);
		ShowResultMatrix();			
	}
	return System::Void();
}

// ��������
System::Void COURSEWORK::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string const_mult;
	Convert_String_to_string(���������_��������->Text, const_mult);
	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("�������� ������� �������!", "�������");
		return;
	}
	else if (!is_number_validator(const_mult) || const_mult == "")
	{
		MessageBox::Show("������ �����!", "�������");
		return;
	}
	else if (ReadMatrixFromInterface()){
		Reset();
		operation.clear();
		operation = "������ �� - �������� �� ���������";
		result_matrix.deleteMatrix();
		int size = work_matrix.GetSize();
		double constant = stod(const_mult);
		result_matrix.CreateMatrix(size,size);
		result_matrix.MultiplyByNumber(work_matrix, constant);
		ShowResultMatrix();
	}
	return System::Void();
}

// ������ �������� � ������
System::Void COURSEWORK::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView2->RowCount == 0) // ���� ������
	{
		MessageBox::Show("������� ������� � ���������.", "�������");
		return;
	}
	else {
		int rowCount = dataGridView2->RowCount;
		int columnCount = dataGridView2->ColumnCount;
		Reset();

		// ������� dataGridView1
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();

		// ��������� �������� �� dataGridView1
		for (int i = 0; i < columnCount; ++i) {
			String^ columnName = dataGridView2->Columns[i]->HeaderText;
			dataGridView1->Columns->Add(columnName, columnName);
		}
		// ��������� ����� � dataGridView2 � dataGridView1
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

//����������� ����������
System::Void COURSEWORK::MyForm::find_determinant_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("�������� ������� �������!", "�������");
		return;
	}
	else if (ReadMatrixFromInterface()) {//����  �� ������� ������� ��� ��������� � �������
		Reset();
		operation.clear();
		operation = "������ �� - ����������� ����������";
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
			MessageBox::Show("�� ����, �������� ��������  �� ���� ���������� ��������� ��� ���� ������� ", "���������");
		}
		else {
			std::string text = " ��������� ���� ������� = " + std::to_string(work_matrix.GetDet());
			String^ message = gcnew String(text.c_str());
			MessageBox::Show(message, "���������");
		}
	}
	return System::Void();
}

//��������� LU �������
System::Void COURSEWORK::MyForm::LU_inverse_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("�������� ������� �������!", "�������");
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
			operation = "������ �� - ��������� ������� ������� LU-��������";
			A.LU_inverse(LU.GetAdress());
			result_matrix.deleteMatrix();
			result_matrix.CreateMatrix(size,size);
			result_matrix.copyMatrix(A);

			operations->Text = "��������: " + actions;
			iter_count->Text = "��������: " + iterations;
			ShowResultMatrix();
		}
		else if (!A.GetElement(0, 0))
		{
			MessageBox::Show("��������� ������ �������� ������� ��� �������, ���� ������� � �������� [0][0] ������� ����", "�����");
		}
		else if (isnan(A.GetDet()))
		{
			MessageBox::Show("��������� ������ �������� ������� ��� �������, ���� ���� � ����������� �������� ������� U ����� ����", "�����");
		}
		else {
			MessageBox::Show("������� ��������� ���� ������� = 0, �� �������� ������� �� ����", "�����");
		}
		LU.deleteMatrix();
		A.deleteMatrix();
	}
	return System::Void();
}

// ������ ���������� 
System::Void COURSEWORK::MyForm::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!operation.empty())
	{
		std::string fileName = "Matrix Calculator file";
		std::ofstream file(fileName, std::ios::out | std::ios::trunc);

		if (file.is_open()) {
			processFile(file, work_matrix,0,0);
			file << std::endl << operation << std::endl << std::endl;
			if (operation == "������ �� - ����������� ����������")
			{
				file << "��������� ������� = " << work_matrix.GetDet() << std::endl;
			}
			else {
				processFile(file, result_matrix, actions,iterations);
			}
			MessageBox::Show("��� ������ ������� � ���� \"Matrix Calculator file\" ", "���������");
			file.close();
		}
		else {
			MessageBox::Show("��������� �������� ����", "�������");
		}
	}
	else {
		MessageBox::Show("�� �� ���� �������� ����� ��������", "�������");
	}
	return System::Void();
}

// ��������� ��������� �� �����
System::Void COURSEWORK::MyForm::squares_inverse_Click(System::Object^ sender, System::EventArgs^ e)
{
	actions = 0;
	iterations = 0;

	if (work_matrix.GetSize() == 0)
	{
		MessageBox::Show("�������� ������� �������!", "�������");
		return;
	}
	else if (ReadMatrixFromInterface()) {
		operation.clear();
		operation = "������ �� - ��������� ������� ������� �������� �� �����";
		Reset();
		Matrix mtr;
		mtr.copyMatrix(work_matrix);
		try {
			mtr = BlockWiseInversion(mtr);
			result_matrix.deleteMatrix();
			result_matrix.copyMatrix(mtr);
			operations->Text = "��������: " + actions;
			iter_count->Text = "��������: " + iterations;
			ShowResultMatrix();
		}
		catch (const std::runtime_error& e) {
			
			MessageBox::Show("���� � �������, ��������� ��� �������, � ����������. ��������� ������ �������� ��� �������", "�������");
		}
		mtr.deleteMatrix();
	}
	return System::Void();
}

// �������������� �-� ��������
void incrementIter() {
	iterations++;
}

// �������������� �-� ��������
void incrementActions() {
	actions++;
}