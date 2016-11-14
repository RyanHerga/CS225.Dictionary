#include "WordEngine.h"
#include <msclr\marshal_cppstd.h>

#pragma once

WordLibrary myGameEngine;
Word myWord;

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
	private: System::Windows::Forms::Label^  lblresult;
	private: System::Windows::Forms::Label^  label1;

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
			this->lblresult = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnSkip
			// 
			this->btnSkip->BackColor = System::Drawing::Color::DarkCyan;
			this->btnSkip->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnSkip->Enabled = false;
			this->btnSkip->FlatAppearance->BorderSize = 0;
			this->btnSkip->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSkip->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSkip->Location = System::Drawing::Point(196, 264);
			this->btnSkip->Name = L"btnSkip";
			this->btnSkip->Size = System::Drawing::Size(112, 30);
			this->btnSkip->TabIndex = 0;
			this->btnSkip->Text = L"Next Word ->";
			this->btnSkip->UseVisualStyleBackColor = false;
			this->btnSkip->Click += gcnew System::EventHandler(this, &MyForm::btnSkip_Click);
			// 
			// lblDefinition
			// 
			this->lblDefinition->BackColor = System::Drawing::Color::Transparent;
			this->lblDefinition->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDefinition->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblDefinition->Location = System::Drawing::Point(14, 10);
			this->lblDefinition->Name = L"lblDefinition";
			this->lblDefinition->Size = System::Drawing::Size(265, 112);
			this->lblDefinition->TabIndex = 2;
			this->lblDefinition->Text = L"How this works:\r\n\r\nA definition will show up on this box. If you can guess the wo"
				L"rd, simply type it on the box below.";
			// 
			// inputGuess
			// 
			this->inputGuess->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->inputGuess->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputGuess->ForeColor = System::Drawing::Color::White;
			this->inputGuess->Location = System::Drawing::Point(14, 234);
			this->inputGuess->Margin = System::Windows::Forms::Padding(10);
			this->inputGuess->Name = L"inputGuess";
			this->inputGuess->Size = System::Drawing::Size(294, 24);
			this->inputGuess->TabIndex = 3;
			// 
			// btnGuess
			// 
			this->btnGuess->BackColor = System::Drawing::Color::DarkCyan;
			this->btnGuess->Enabled = false;
			this->btnGuess->FlatAppearance->BorderColor = System::Drawing::Color::DarkCyan;
			this->btnGuess->FlatAppearance->BorderSize = 0;
			this->btnGuess->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGuess->ForeColor = System::Drawing::Color::Transparent;
			this->btnGuess->Location = System::Drawing::Point(14, 264);
			this->btnGuess->Name = L"btnGuess";
			this->btnGuess->Size = System::Drawing::Size(176, 30);
			this->btnGuess->TabIndex = 4;
			this->btnGuess->Text = L"Guess";
			this->btnGuess->UseVisualStyleBackColor = false;
			this->btnGuess->Click += gcnew System::EventHandler(this, &MyForm::btnGuess_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::DimGray;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->lblDefinition);
			this->panel1->Location = System::Drawing::Point(14, 93);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(294, 135);
			this->panel1->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Gray;
			this->panel2->Controls->Add(this->btnLoadLibrary);
			this->panel2->Controls->Add(this->labelLibary);
			this->panel2->Location = System::Drawing::Point(12, 52);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(294, 35);
			this->panel2->TabIndex = 6;
			// 
			// btnLoadLibrary
			// 
			this->btnLoadLibrary->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->btnLoadLibrary->FlatAppearance->BorderSize = 0;
			this->btnLoadLibrary->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLoadLibrary->ForeColor = System::Drawing::Color::White;
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
			this->labelLibary->ForeColor = System::Drawing::Color::White;
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
			// lblresult
			// 
			this->lblresult->AutoSize = true;
			this->lblresult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblresult->ForeColor = System::Drawing::Color::White;
			this->lblresult->Location = System::Drawing::Point(12, 19);
			this->lblresult->Name = L"lblresult";
			this->lblresult->Size = System::Drawing::Size(0, 20);
			this->lblresult->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(184, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"VocabBuilder";
			// 
			// MyForm
			// 
			this->AcceptButton = this->btnGuess;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->CancelButton = this->btnSkip;
			this->ClientSize = System::Drawing::Size(316, 302);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblresult);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnGuess);
			this->Controls->Add(this->inputGuess);
			this->Controls->Add(this->btnSkip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"VocabBuilder v1.2.6";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void showWord() {
		myWord = myGameEngine.getRandomWord();
		string msgToPrint = "\n Random Word: " + myWord.getWord();
		OutputDebugStringA(msgToPrint.c_str());
		String^ myDef = gcnew String(myWord.getDef().c_str());
		this->lblDefinition->Text = myDef;
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	

	private: System::Void btnLoadLibrary_Click(System::Object^  sender, System::EventArgs^  e) {

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			string thePath = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
			myGameEngine.init(thePath, &(this->labelLibary));
			showWord();
			this->btnSkip->Enabled = true;
			this->btnGuess->Enabled = true;
		}

	}

	
private: System::Void btnSkip_Click(System::Object^  sender, System::EventArgs^  e) {
		showWord();
		this->inputGuess->Text = "";
		this->lblresult->Text = "";
}
private: System::Void btnGuess_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^ theAnswer = gcnew String(myWord.getWord().c_str());
	if (this->inputGuess->Text == theAnswer) {
		this->lblresult->ForeColor = System::Drawing::Color::LightGreen;
		this->lblresult->Text = "Correct!";
	}
	else {
		this->lblresult->ForeColor = System::Drawing::Color::Red;
		this->lblresult->Text = "Incorrect!";
	}
}
};
}
