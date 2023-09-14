#pragma once
#include"Header1.h"
namespace My_Namesp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	Train_1 train;
	//Train* train1;
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ drawing;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ speed;



	private: System::Windows::Forms::TextBox^ width;

	private: System::Windows::Forms::TextBox^ hight;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ starting;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ coord_x;
	private: System::Windows::Forms::TextBox^ coord_y;


	private: System::Windows::Forms::Label^ label4;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->drawing = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->speed = (gcnew System::Windows::Forms::TextBox());
			this->width = (gcnew System::Windows::Forms::TextBox());
			this->hight = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->starting = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->coord_x = (gcnew System::Windows::Forms::TextBox());
			this->coord_y = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// drawing
			// 
			this->drawing->Location = System::Drawing::Point(230, 12);
			this->drawing->Name = L"drawing";
			this->drawing->Size = System::Drawing::Size(75, 23);
			this->drawing->TabIndex = 0;
			this->drawing->Text = L"Draw";
			this->drawing->UseVisualStyleBackColor = true;
			this->drawing->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Location = System::Drawing::Point(12, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Hight";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// speed
			// 
			this->speed->Location = System::Drawing::Point(12, 370);
			this->speed->Name = L"speed";
			this->speed->Size = System::Drawing::Size(100, 20);
			this->speed->TabIndex = 4;
			this->speed->Text = L"5";
			// 
			// width
			// 
			this->width->Location = System::Drawing::Point(12, 121);
			this->width->Name = L"width";
			this->width->Size = System::Drawing::Size(100, 20);
			this->width->TabIndex = 5;
			this->width->Text = L"200";
			// 
			// hight
			// 
			this->hight->Location = System::Drawing::Point(12, 44);
			this->hight->Name = L"hight";
			this->hight->Size = System::Drawing::Size(100, 20);
			this->hight->TabIndex = 6;
			this->hight->Text = L"100";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(159, 62);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(773, 386);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// starting
			// 
			this->starting->Location = System::Drawing::Point(356, 12);
			this->starting->Name = L"starting";
			this->starting->Size = System::Drawing::Size(75, 23);
			this->starting->TabIndex = 8;
			this->starting->Text = L"Start";
			this->starting->UseVisualStyleBackColor = true;
			this->starting->Click += gcnew System::EventHandler(this, &MyForm::starting_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Location = System::Drawing::Point(12, 331);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 20);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Speed";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Location = System::Drawing::Point(12, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Width";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Location = System::Drawing::Point(12, 168);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(80, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Coordinate x";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// coord_x
			// 
			this->coord_x->Location = System::Drawing::Point(12, 204);
			this->coord_x->Name = L"coord_x";
			this->coord_x->Size = System::Drawing::Size(100, 20);
			this->coord_x->TabIndex = 13;
			this->coord_x->Text = L"0";
			// 
			// coord_y
			// 
			this->coord_y->Location = System::Drawing::Point(12, 287);
			this->coord_y->Name = L"coord_y";
			this->coord_y->Size = System::Drawing::Size(100, 20);
			this->coord_y->TabIndex = 14;
			this->coord_y->Text = L"100";
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->Location = System::Drawing::Point(12, 253);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 20);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Coordinate y";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(131)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->ClientSize = System::Drawing::Size(970, 467);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->coord_y);
			this->Controls->Add(this->coord_x);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->starting);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->hight);
			this->Controls->Add(this->width);
			this->Controls->Add(this->speed);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->drawing);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int x = int::Parse(coord_x->Text);
		int y = int::Parse(coord_y->Text);
		int h = int::Parse(hight->Text);
		int w = int::Parse(width->Text);
		tRectangle rect(w, h, x, y);
		int w1_x = (rect.get_left_x())+ (w/4);
		int w1_y = (rect.get_down_y());
		int w2_x = (rect.get_right_x() - (w / 4));
		int w2_y = (rect.get_down_y());
		Circle wh1(h/5,w1_x, w1_y), wh2(h/5, w2_x, w2_y);
		train = Train_1(rect, wh1, wh2);
		//train1 = new Train[10];
		Graphics^ gr = this->pictureBox1->CreateGraphics();
		Pen^ pen = gcnew Pen(Color::FromArgb(5, 5, 5));
		gr->DrawLine(pen,0, train.get_down_y(),773, train.get_down_y());
		train.show(gr);
	}
private: System::Void starting_Click(System::Object^ sender, System::EventArgs^ e) {
	Graphics^ gr = this->pictureBox1->CreateGraphics();
	int sp = int::Parse(speed->Text);
	while (train.get_left_x()<773) {
		train.move(gr, sp, 0);
		System::Threading::Thread::Sleep(50);
	}
	Pen^ pen = gcnew Pen(Color::FromArgb(255, 255, 255));
	gr->DrawLine(pen, 0, train.get_down_y(), 773, train.get_down_y());
	}
};
}
