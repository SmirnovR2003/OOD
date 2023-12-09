#include "MyForm.h"



using namespace System::Windows::Forms;
using namespace System;


[STAThreadAttribute]
int main(array<String^>^ argv)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	My10::MyForm form;
	Application::Run(% form);
}