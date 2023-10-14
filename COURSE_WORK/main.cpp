#include "MyForm.h"
#include"Functions.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	COURSEWORK::MyForm form;
	Application::Run(% form);
}