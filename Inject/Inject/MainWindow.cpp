#include "MainWindow.h"
#include <Windows.h>
#include <iostream>
using namespace Inject;


[STAThreadAttribute]
int ShowMainWindow(){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainWindow()); 
	return 0;
}
