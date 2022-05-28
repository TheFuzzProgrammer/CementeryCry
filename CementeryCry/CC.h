#pragma once
#include "Game.h"

namespace CementeryCry {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class CC : public System::Windows::Forms::Form
	{
	public:
		CC(void)
		{
			InitializeComponent();
			game = new Game(5);

		}

	protected:

		~CC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ soul;
	private: Game* game;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;

	protected:
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:



#pragma region

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CC::typeid));
			this->soul = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// soul
			// 
			this->soul->Enabled = true;
			this->soul->Interval = 33;
			this->soul->Tick += gcnew System::EventHandler(this, &CC::soul_Tick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 76);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1008, 653);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1008, 77);
			this->panel2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(479, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 29);
			this->label1->TabIndex = 0;
			// 
			// CC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"CC";
			this->Opacity = 0.99;
			this->Text = L"CD";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CC::CC_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &CC::CC_KeyUp);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	Void soul_Tick(Object^ sender, EventArgs^ e) {
		Graphics^ g = this->panel1->CreateGraphics();
		g->Clear(Color::White);
		game->Move(g);
		game->Show(g);
		this->label1->Text = game->GetPlayer()->GetArea().X.ToString() + ";" + game->GetPlayer()->GetArea().Y.ToString();
	}
	Void CC_KeyDown(Object^ sender, KeyEventArgs^ e) {
		game->PlayerMovement(true, e->KeyCode, 10);
	}
	Void CC_KeyUp(Object^ sender, KeyEventArgs^ e) {
		game->PlayerMovement(false, e->KeyCode, 10);
	}
	};
}
