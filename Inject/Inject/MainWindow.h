#pragma once
#include <Windows.h>
namespace Inject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	DWORD dwProciD;
	HWND hStartGame;
	HANDLE hProcess;
	DWORD dSize;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(359, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(422, 20);
			this->textBox1->TabIndex = 1;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(446, 252);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		/*DWORD addr = (int)(GetModuleHandle(L"Step 2") + 0x245300 + 0x480);
		float value = 1.121038771E-43;
		WriteFloat((LPVOID)addr, value ,L"Step 2");*/

		float value = 2.101947696E-44; // 15
		HANDLE sGame = GetCurrentProcess();
		WriteProcessMemory(sGame, (void*)(0x245300 + 0x480), &value, 4, 0);


	}
	private: System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {
		
		
	}

			 void WriteFloat(LPVOID address, float data ,LPCWSTR window){
				 unsigned long protect;
				 hStartGame = FindWindow(NULL, window);
				 GetWindowThreadProcessId(hStartGame, &dwProciD);
				 hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProciD);

				 VirtualProtectEx(hProcess, (void*)address, 4, PAGE_EXECUTE_READWRITE, &protect);
				 if (!WriteProcessMemory(hProcess, (LPVOID)address, &data, sizeof(float), &dSize)){

					 Console::WriteLine("Falha");
				 }
				 VirtualProtectEx(hProcess, (void*)address, 4, protect, &protect);
				 float r;
				 ReadProcessMemory(hStartGame, (LPVOID)address, &r, sizeof(r), 0);
				 Console::WriteLine(r);
			 }
	};
}
