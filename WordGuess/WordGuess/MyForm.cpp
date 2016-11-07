#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	WordGuess::MyForm form;
	Application::Run(%form);
}
