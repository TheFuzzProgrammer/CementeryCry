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
	protected:
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:



#pragma region

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->soul = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// soul
			// 
			this->soul->Enabled = true;
			this->soul->Interval = 33;
			this->soul->Tick += gcnew System::EventHandler(this, &CC::soul_Tick);
			// 
			// CD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(859, 613);
			this->Name = L"CD";
			this->Text = L"CD";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CC::CC_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &CC::CC_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	Void soul_Tick(Object^ sender, EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		g->Clear(Color::White);
		game->Move(g);
		game->Show(g);
	}
	Void CC_KeyDown(Object^ sender, KeyEventArgs^ e) {
		game->PlayerMovement(true, e->KeyCode, 5);
	}
	Void CC_KeyUp(Object^ sender, KeyEventArgs^ e) {
		game->PlayerMovement(false, e->KeyCode, 5);
	}
	};
}
