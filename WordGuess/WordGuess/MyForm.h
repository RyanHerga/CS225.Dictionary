#include "WordEngine.h"
#include <msclr\marshal_cppstd.h>

#pragma once

namespace WordGuess {

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
	private: System::Windows::Forms::Button^  btnSkip;
	private: System::Windows::Forms::Label^  lblDefinition;
	protected:

	protected:


	private: System::Windows::Forms::TextBox^  inputGuess;

	private: System::Windows::Forms::Button^  btnGuess;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  btnLoadLibrary;
	private: System::Windows::Forms::Label^  labelLibary;


	private: System::Windows::Forms::DialogResult^  dialogResults;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
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
			this->btnSkip = (gcnew System::Windows::Forms::Button());
			this->lblDefinition = (gcnew System::Windows::Forms::Label());
			this->inputGuess = (gcnew System::Windows::Forms::TextBox());
			this->btnGuess = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnLoadLibrary = (gcnew System::Windows::Forms::Button());
			this->labelLibary = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnSkip
			// 
			this->btnSkip->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->btnSkip->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSkip->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSkip->Location = System::Drawing::Point(156, 198);
			this->btnSkip->Name = L"btnSkip";
			this->btnSkip->Size = System::Drawing::Size(150, 30);
			this->btnSkip->TabIndex = 0;
			this->btnSkip->Text = L"Skip Word ->";
			this->btnSkip->UseVisualStyleBackColor = false;
			// 
			// lblDefinition
			// 
			this->lblDefinition->AutoSize = true;
			this->lblDefinition->Location = System::Drawing::Point(15, 13);
			this->lblDefinition->Name = L"lblDefinition";
			this->lblDefinition->Size = System::Drawing::Size(35, 13);
			this->lblDefinition->TabIndex = 2;
			this->lblDefinition->Text = L"label1";
			// 
			// inputGuess
			// 
			this->inputGuess->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->inputGuess->Location = System::Drawing::Point(12, 172);
			this->inputGuess->Name = L"inputGuess";
			this->inputGuess->Size = System::Drawing::Size(294, 20);
			this->inputGuess->TabIndex = 3;
			// 
			// btnGuess
			// 
			this->btnGuess->BackColor = System::Drawing::Color::DarkCyan;
			this->btnGuess->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGuess->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnGuess->Location = System::Drawing::Point(12, 198);
			this->btnGuess->Name = L"btnGuess";
			this->btnGuess->Size = System::Drawing::Size(138, 30);
			this->btnGuess->TabIndex = 4;
			this->btnGuess->Text = L"Guess";
			this->btnGuess->UseVisualStyleBackColor = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel1->Controls->Add(this->lblDefinition);
			this->panel1->Location = System::Drawing::Point(12, 53);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(294, 113);
			this->panel1->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Silver;
			this->panel2->Controls->Add(this->btnLoadLibrary);
			this->panel2->Controls->Add(this->labelLibary);
			this->panel2->Location = System::Drawing::Point(12, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(294, 35);
			this->panel2->TabIndex = 6;
			// 
			// btnLoadLibrary
			// 
			this->btnLoadLibrary->BackColor = System::Drawing::Color::Gold;
			this->btnLoadLibrary->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLoadLibrary->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnLoadLibrary->Location = System::Drawing::Point(153, 5);
			this->btnLoadLibrary->Name = L"btnLoadLibrary";
			this->btnLoadLibrary->Size = System::Drawing::Size(138, 24);
			this->btnLoadLibrary->TabIndex = 7;
			this->btnLoadLibrary->Text = L"Load Library...";
			this->btnLoadLibrary->UseVisualStyleBackColor = false;
			this->btnLoadLibrary->Click += gcnew System::EventHandler(this, &MyForm::btnLoadLibrary_Click);
			// 
			// labelLibary
			// 
			this->labelLibary->AutoSize = true;
			this->labelLibary->Location = System::Drawing::Point(15, 11);
			this->labelLibary->Name = L"labelLibary";
			this->labelLibary->Size = System::Drawing::Size(128, 13);
			this->labelLibary->TabIndex = 2;
			this->labelLibary->Text = L"Load a Word Library, First";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Word Library File (*.wordlib) | *.wordlib";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(320, 232);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnGuess);
			this->Controls->Add(this->inputGuess);
			this->Controls->Add(this->btnSkip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"Word Guessing";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	

	private: System::Void btnLoadLibrary_Click(System::Object^  sender, System::EventArgs^  e) {

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			WordLibrary myGameEngine;
			string thePath = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
			myGameEngine.init(thePath, &(this->labelLibary));
		}

	}
};
}
