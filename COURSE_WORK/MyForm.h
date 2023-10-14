#pragma once

namespace COURSEWORK {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ зберегтиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ проПрограмуToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ Розмірність;

	public: System::Windows::Forms::Button^ Create;
	private:
	public: System::Windows::Forms::Button^ generate;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ LU_inverse;
	private: System::Windows::Forms::Button^ squares_inverse;
	private: System::Windows::Forms::Button^ Transponation;



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ find_determinant;
	private: System::Windows::Forms::Button^ file_read;
	private: System::Windows::Forms::TextBox^ file_name;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ File_text;

	private: System::Windows::Forms::Label^ ТекстКонстанти;
	public: System::Windows::Forms::Button^ Clear_btn;
	private: System::Windows::Forms::TextBox^ константа_множення;
	private: System::Windows::Forms::DataGridView^ dataGridView2;



	private: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ operation_count;
	public:
	private: System::Windows::Forms::Label^ iteration_count;
	private: System::Windows::Forms::Label^ operations;
	private: System::Windows::Forms::Label^ iter_count;
	private: System::Windows::Forms::Label^ label4;
	private:
	public:

	public:
	private:

	private:

	public:



	private:

	private:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->зберегтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->проПрограмуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Розмірність = (gcnew System::Windows::Forms::NumericUpDown());
			this->Create = (gcnew System::Windows::Forms::Button());
			this->generate = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Clear_btn = (gcnew System::Windows::Forms::Button());
			this->LU_inverse = (gcnew System::Windows::Forms::Button());
			this->squares_inverse = (gcnew System::Windows::Forms::Button());
			this->Transponation = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->find_determinant = (gcnew System::Windows::Forms::Button());
			this->file_read = (gcnew System::Windows::Forms::Button());
			this->file_name = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->константа_множення = (gcnew System::Windows::Forms::TextBox());
			this->File_text = (gcnew System::Windows::Forms::Label());
			this->ТекстКонстанти = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->operation_count = (gcnew System::Windows::Forms::Label());
			this->iteration_count = (gcnew System::Windows::Forms::Label());
			this->operations = (gcnew System::Windows::Forms::Label());
			this->iter_count = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Розмірність))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::LightSkyBlue;
			this->menuStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Visible;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->зберегтиToolStripMenuItem,
					this->проПрограмуToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1211, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// зберегтиToolStripMenuItem
			// 
			this->зберегтиToolStripMenuItem->Name = L"зберегтиToolStripMenuItem";
			this->зберегтиToolStripMenuItem->Size = System::Drawing::Size(86, 24);
			this->зберегтиToolStripMenuItem->Text = L"Зберегти";
			this->зберегтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::зберегтиToolStripMenuItem_Click);
			// 
			// проПрограмуToolStripMenuItem
			// 
			this->проПрограмуToolStripMenuItem->Name = L"проПрограмуToolStripMenuItem";
			this->проПрограмуToolStripMenuItem->Size = System::Drawing::Size(124, 24);
			this->проПрограмуToolStripMenuItem->Text = L"Про програму";
			this->проПрограмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::проПрограмуToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowDrop = true;
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->BackgroundColor = System::Drawing::Color::SteelBlue;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(255, 64);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 50;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(469, 399);
			this->dataGridView1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(413, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Вхідна матриця";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(48, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Задати розмір";
			// 
			// Розмірність
			// 
			this->Розмірність->Location = System::Drawing::Point(71, 11);
			this->Розмірність->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->Розмірність->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Розмірність->Name = L"Розмірність";
			this->Розмірність->Size = System::Drawing::Size(145, 22);
			this->Розмірність->TabIndex = 3;
			this->Розмірність->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// Create
			// 
			this->Create->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->Create->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Create->Location = System::Drawing::Point(0, 43);
			this->Create->Name = L"Create";
			this->Create->Size = System::Drawing::Size(100, 44);
			this->Create->TabIndex = 5;
			this->Create->Text = L"Створити";
			this->Create->UseVisualStyleBackColor = false;
			this->Create->Click += gcnew System::EventHandler(this, &MyForm::Create_Click);
			// 
			// generate
			// 
			this->generate->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->generate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->generate->Location = System::Drawing::Point(115, 43);
			this->generate->Name = L"generate";
			this->generate->Size = System::Drawing::Size(101, 44);
			this->generate->TabIndex = 6;
			this->generate->Text = L"Згенерувати";
			this->generate->UseVisualStyleBackColor = false;
			this->generate->Click += gcnew System::EventHandler(this, &MyForm::generate_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->generate);
			this->groupBox1->Controls->Add(this->Create);
			this->groupBox1->Controls->Add(this->Розмірність);
			this->groupBox1->Location = System::Drawing::Point(12, 55);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(218, 93);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1, 11);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 16);
			this->label4->TabIndex = 23;
			this->label4->Text = L"(max - 20)";
			// 
			// Clear_btn
			// 
			this->Clear_btn->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->Clear_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Clear_btn->Location = System::Drawing::Point(445, 469);
			this->Clear_btn->Name = L"Clear_btn";
			this->Clear_btn->Size = System::Drawing::Size(101, 44);
			this->Clear_btn->TabIndex = 7;
			this->Clear_btn->Text = L"Очистити";
			this->Clear_btn->UseVisualStyleBackColor = false;
			this->Clear_btn->Click += gcnew System::EventHandler(this, &MyForm::Clear_btn_Click);
			// 
			// LU_inverse
			// 
			this->LU_inverse->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->LU_inverse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LU_inverse->Location = System::Drawing::Point(1, 8);
			this->LU_inverse->Name = L"LU_inverse";
			this->LU_inverse->Size = System::Drawing::Size(98, 78);
			this->LU_inverse->TabIndex = 8;
			this->LU_inverse->Text = L"Обернення методом LU- розкладу";
			this->LU_inverse->UseVisualStyleBackColor = false;
			this->LU_inverse->Click += gcnew System::EventHandler(this, &MyForm::LU_inverse_Click);
			// 
			// squares_inverse
			// 
			this->squares_inverse->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->squares_inverse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->squares_inverse->Location = System::Drawing::Point(111, 8);
			this->squares_inverse->Name = L"squares_inverse";
			this->squares_inverse->Size = System::Drawing::Size(100, 78);
			this->squares_inverse->TabIndex = 9;
			this->squares_inverse->Text = L"Обернення методом розбиття на клітки";
			this->squares_inverse->UseVisualStyleBackColor = false;
			this->squares_inverse->Click += gcnew System::EventHandler(this, &MyForm::squares_inverse_Click);
			// 
			// Transponation
			// 
			this->Transponation->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->Transponation->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Transponation->Location = System::Drawing::Point(0, 101);
			this->Transponation->Name = L"Transponation";
			this->Transponation->Size = System::Drawing::Size(99, 75);
			this->Transponation->TabIndex = 10;
			this->Transponation->Text = L"Транспонувати";
			this->Transponation->UseVisualStyleBackColor = false;
			this->Transponation->Click += gcnew System::EventHandler(this, &MyForm::Transponation_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(1, 204);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 69);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Помножити матрицю на константу";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// find_determinant
			// 
			this->find_determinant->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->find_determinant->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->find_determinant->Location = System::Drawing::Point(110, 101);
			this->find_determinant->Name = L"find_determinant";
			this->find_determinant->Size = System::Drawing::Size(101, 75);
			this->find_determinant->TabIndex = 12;
			this->find_determinant->Text = L"Знайти визначник";
			this->find_determinant->UseVisualStyleBackColor = false;
			this->find_determinant->Click += gcnew System::EventHandler(this, &MyForm::find_determinant_Click);
			// 
			// file_read
			// 
			this->file_read->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->file_read->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->file_read->Location = System::Drawing::Point(1, 289);
			this->file_read->Name = L"file_read";
			this->file_read->Size = System::Drawing::Size(96, 74);
			this->file_read->TabIndex = 13;
			this->file_read->Text = L"Зчитати з файлу";
			this->file_read->UseVisualStyleBackColor = false;
			this->file_read->Click += gcnew System::EventHandler(this, &MyForm::file_read_Click);
			// 
			// file_name
			// 
			this->file_name->Location = System::Drawing::Point(111, 312);
			this->file_name->Name = L"file_name";
			this->file_name->Size = System::Drawing::Size(100, 22);
			this->file_name->TabIndex = 14;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::LightSkyBlue;
			this->groupBox2->Controls->Add(this->константа_множення);
			this->groupBox2->Controls->Add(this->File_text);
			this->groupBox2->Controls->Add(this->ТекстКонстанти);
			this->groupBox2->Controls->Add(this->file_name);
			this->groupBox2->Controls->Add(this->file_read);
			this->groupBox2->Controls->Add(this->find_determinant);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->Transponation);
			this->groupBox2->Controls->Add(this->squares_inverse);
			this->groupBox2->Controls->Add(this->LU_inverse);
			this->groupBox2->Location = System::Drawing::Point(13, 154);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(215, 374);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			// 
			// константа_множення
			// 
			this->константа_множення->Location = System::Drawing::Point(111, 223);
			this->константа_множення->Name = L"константа_множення";
			this->константа_множення->Size = System::Drawing::Size(100, 22);
			this->константа_множення->TabIndex = 17;
			// 
			// File_text
			// 
			this->File_text->AutoSize = true;
			this->File_text->Location = System::Drawing::Point(124, 293);
			this->File_text->Name = L"File_text";
			this->File_text->Size = System::Drawing::Size(75, 16);
			this->File_text->TabIndex = 16;
			this->File_text->Text = L"Ім\'я файлу";
			// 
			// ТекстКонстанти
			// 
			this->ТекстКонстанти->AutoSize = true;
			this->ТекстКонстанти->Location = System::Drawing::Point(110, 204);
			this->ТекстКонстанти->Name = L"ТекстКонстанти";
			this->ТекстКонстанти->Size = System::Drawing::Size(99, 16);
			this->ТекстКонстанти->TabIndex = 15;
			this->ТекстКонстанти->Text = L"Уведіть число";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToOrderColumns = true;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::SteelBlue;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(744, 64);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(454, 399);
			this->dataGridView2->TabIndex = 16;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(896, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(171, 25);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Вихідна матриця";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(929, 469);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 44);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Вставити у вхідну";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// operation_count
			// 
			this->operation_count->AutoSize = true;
			this->operation_count->Location = System::Drawing::Point(1054, 469);
			this->operation_count->Name = L"operation_count";
			this->operation_count->Size = System::Drawing::Size(0, 16);
			this->operation_count->TabIndex = 19;
			// 
			// iteration_count
			// 
			this->iteration_count->AutoSize = true;
			this->iteration_count->BackColor = System::Drawing::Color::SkyBlue;
			this->iteration_count->Location = System::Drawing::Point(1074, 503);
			this->iteration_count->Name = L"iteration_count";
			this->iteration_count->Size = System::Drawing::Size(0, 16);
			this->iteration_count->TabIndex = 20;
			// 
			// operations
			// 
			this->operations->AutoSize = true;
			this->operations->Location = System::Drawing::Point(1074, 472);
			this->operations->Name = L"operations";
			this->operations->Size = System::Drawing::Size(0, 16);
			this->operations->TabIndex = 21;
			// 
			// iter_count
			// 
			this->iter_count->AutoSize = true;
			this->iter_count->Location = System::Drawing::Point(1074, 497);
			this->iter_count->Name = L"iter_count";
			this->iter_count->Size = System::Drawing::Size(0, 16);
			this->iter_count->TabIndex = 22;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSkyBlue;
			this->ClientSize = System::Drawing::Size(1211, 525);
			this->Controls->Add(this->iter_count);
			this->Controls->Add(this->operations);
			this->Controls->Add(this->iteration_count);
			this->Controls->Add(this->operation_count);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->Clear_btn);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Matrix calculator";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Розмірність))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Create_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void generate_Click(System::Object^ sender, System::EventArgs^ e);

		private: void MyForm::ShowMatrix();
		private: void MyForm::ShowResultMatrix();
		private: int MyForm::ReadMatrixFromInterface();
		private: void MyForm::Reset();

private: System::Void Clear_btn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void file_read_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Transponation_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void find_determinant_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void LU_inverse_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void зберегтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void squares_inverse_Click(System::Object^ sender, System::EventArgs^ e);
};
}
