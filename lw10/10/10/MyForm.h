#pragma once

#include <string>

namespace My10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			/*if (components)
			{
				delete components;
			}*/
		}


	private: int startX = 0;
	private: int startY = 0;
	private: int lastX = 0;
	private: int lastY = 0;
	private: int startW = 0;
	private: int startH = 0;
	private: int lastW = 0;
	private: int lastH = 0;
	private: bool isClicked = false;
	private: bool isChosen = false;



	protected:

	//private: System::Collections::ArrayList^ components;
	//private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ addShapeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ triangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rectangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ellipseToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ rectangle;
	private: System::Windows::Forms::PictureBox^ ellipse;
	private: System::Windows::Forms::PictureBox^ triangle;



	private: int counter = 0;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			
			//this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->addShapeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->triangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ellipseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangle = (gcnew System::Windows::Forms::PictureBox());
			this->ellipse = (gcnew System::Windows::Forms::PictureBox());
			this->triangle = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rectangle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ellipse))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->triangle))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			/*this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->groupBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->groupBox1->Location = System::Drawing::Point(423, 64);
			this->groupBox1->Margin = System::Windows::Forms::Padding(0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->groupBox1->Size = System::Drawing::Size(160, 190);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::groupBox1_MouseDown);
			this->groupBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			this->groupBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->groupBox1->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);
			*/// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(640, 188);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::SizeNWSE;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(121, 149);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(224, 301);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->addShapeToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1319, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// addShapeToolStripMenuItem
			// 
			this->addShapeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->triangleToolStripMenuItem,
					this->rectangleToolStripMenuItem, this->ellipseToolStripMenuItem
			});
			this->addShapeToolStripMenuItem->Name = L"addShapeToolStripMenuItem";
			this->addShapeToolStripMenuItem->Size = System::Drawing::Size(92, 24);
			this->addShapeToolStripMenuItem->Text = L"AddShape";
			// 
			// triangleToolStripMenuItem
			// 
			this->triangleToolStripMenuItem->Name = L"triangleToolStripMenuItem";
			this->triangleToolStripMenuItem->Size = System::Drawing::Size(158, 26);
			this->triangleToolStripMenuItem->Text = L"Triangle";
			this->triangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::triangleToolStripMenuItem_Click);
			// 
			// rectangleToolStripMenuItem
			// 
			this->rectangleToolStripMenuItem->Name = L"rectangleToolStripMenuItem";
			this->rectangleToolStripMenuItem->Size = System::Drawing::Size(158, 26);
			this->rectangleToolStripMenuItem->Text = L"Rectangle";
			this->rectangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rectangleToolStripMenuItem_Click);
			// 
			// ellipseToolStripMenuItem
			// 
			this->ellipseToolStripMenuItem->Name = L"ellipseToolStripMenuItem";
			this->ellipseToolStripMenuItem->Size = System::Drawing::Size(158, 26);
			this->ellipseToolStripMenuItem->Text = L"Ellipse";
			this->ellipseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ellipseToolStripMenuItem_Click);
			// 
			// rectangle
			// 
			this->rectangle->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rectangle.Image")));
			this->rectangle->Location = System::Drawing::Point(840, 72);
			this->rectangle->Name = L"rectangle";
			this->rectangle->Size = System::Drawing::Size(576, 391);
			this->rectangle->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->rectangle->TabIndex = 2;
			this->rectangle->TabStop = false;
			// 
			// ellipse
			// 
			this->ellipse->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ellipse->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ellipse.Image")));
			this->ellipse->Location = System::Drawing::Point(710, 102);
			this->ellipse->Name = L"ellipse";
			this->ellipse->Size = System::Drawing::Size(431, 430);
			this->ellipse->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->ellipse->TabIndex = 3;
			this->ellipse->TabStop = false;
			// 
			// triangle
			// 
			this->triangle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->triangle->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"triangle.Image")));
			this->triangle->Location = System::Drawing::Point(208, 72);
			this->triangle->Name = L"triangle";
			this->triangle->Size = System::Drawing::Size(476, 412);
			this->triangle->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->triangle->TabIndex = 4;
			this->triangle->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1000, 1000);
			this->Size = System::Drawing::Size(1000, 1000);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rectangle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ellipse))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->triangle))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void pictureBox1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (!isClicked)return;

	auto box((GroupBox^)(((PictureBox^)sender)->Parent));

	if (this->MousePosition.X - startX + lastX < this->ClientRectangle.Location.X
		|| this->MousePosition.Y - startY + lastY < this->ClientRectangle.Location.Y
		|| this->MousePosition.X - startX + lastX + box->Size.Width > this->ClientSize.Width
		|| this->MousePosition.Y - startY + lastY + box->Size.Height > this->ClientSize.Height)
	{
		return;
	}

	box->Location = System::Drawing::Point(
		this->MousePosition.X - startX + lastX, 
		this->MousePosition.Y - startY + lastY
	);
	
}
private: System::Void groupBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	auto box = ((GroupBox^)(((PictureBox^)sender)->Parent));

	this->OnMouseDown(e);
	box->Controls->Find("4", false)[0]->BringToFront();
	box->Controls->Find("3", false)[0]->BringToFront();
	box->Controls->Find("2", false)[0]->BringToFront();
	box->Controls->Find("1", false)[0]->BringToFront();

	box->BringToFront();
	
}
private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	isClicked = true;

	lastX = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.X;
	lastY = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.Y;
	startX = this->MousePosition.X;
	startY = this->MousePosition.Y;
	
}
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	isClicked = false;
}
private: System::Void pictureBox1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	
	isClicked = false;
}

private: System::Void changeSizeLeftTopSquare_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	isClicked = true;

	lastX = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.X;
	lastY = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.Y;
	startX = this->MousePosition.X;
	startY = this->MousePosition.Y;

	startW = ((GroupBox^)(((PictureBox^)sender)->Parent))->Size.Width;
	startH = ((GroupBox^)(((PictureBox^)sender)->Parent))->Size.Height;
}
private: System::Void changeSizeLeftTopSquare_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (!isClicked)return;

	auto pictureBox = (PictureBox^)sender;
	auto Parent = ((GroupBox^)(pictureBox->Parent));

	Parent->Location = System::Drawing::Point(
		this->MousePosition.X - startX + lastX,
		this->MousePosition.Y - startY + lastY
	);

	Parent->Size = System::Drawing::Size(
		startW - Parent->Location.X + lastX,
		startH - Parent->Location.Y + lastY
	);

	Parent->Controls[4]->Size = System::Drawing::Size(
		startW - Parent->Location.X + lastX,
		startH - Parent->Location.Y + lastY
	);

	Parent->Controls[0]->Location = System::Drawing::Point(0, 0);
	Parent->Controls[1]->Location = System::Drawing::Point(
		0,
		Parent->Size.Height - Parent->Controls[1]->Size.Height
	);
	Parent->Controls[2]->Location = System::Drawing::Point(
		Parent->Size.Width - Parent->Controls[2]->Size.Width,
		Parent->Size.Height - Parent->Controls[2]->Size.Height
	);
	Parent->Controls[3]->Location = System::Drawing::Point(
		Parent->Size.Width - Parent->Controls[3]->Size.Width,
		0
	);

}
private: System::Void changeSizeLeftTopSquare_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	isClicked = false;
}

private: System::Void changeSizeLeftBottomSquare_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	isClicked = true;

	lastX = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.X;
	lastY = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.Y;
	startX = this->MousePosition.X;
	startY = this->MousePosition.Y;

	startW = ((GroupBox^)(((PictureBox^)sender)->Parent))->Size.Width;
	startH = ((GroupBox^)(((PictureBox^)sender)->Parent))->Size.Height;
}
private: System::Void changeSizeLeftBottomSquare_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (!isClicked)return;

	auto pictureBox = (PictureBox^)sender;
	auto Parent = ((GroupBox^)(pictureBox->Parent));

	Parent->Location = System::Drawing::Point(
		this->MousePosition.X - startX + lastX,
		Parent->Location.Y
	);

	Parent->Size = System::Drawing::Size(
		startW - Parent->Location.X + lastX,
		startH + this->MousePosition.Y - startY 
	);

	Parent->Controls[4]->Size = System::Drawing::Size(
		startW - Parent->Location.X + lastX,
		startH + this->MousePosition.Y - startY
	);

	Parent->Controls[0]->Location = System::Drawing::Point(0, 0);
	Parent->Controls[1]->Location = System::Drawing::Point(
		0,
		Parent->Size.Height - Parent->Controls[1]->Size.Height
	);
	Parent->Controls[2]->Location = System::Drawing::Point(
		Parent->Size.Width - Parent->Controls[2]->Size.Width,
		Parent->Size.Height - Parent->Controls[2]->Size.Height
	);
	Parent->Controls[3]->Location = System::Drawing::Point(
		Parent->Size.Width - Parent->Controls[3]->Size.Width,
		0
	);
}
private: System::Void changeSizeLeftBottomSquare_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	isClicked = false;
}

private: System::Void changeSizeRightBottomSquare_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	isClicked = true;

	lastX = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.X;
	lastY = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.Y;
	startX = this->MousePosition.X;
	startY = this->MousePosition.Y;

	startW = ((GroupBox^)(((PictureBox^)sender)->Parent))->Size.Width;
	startH = ((GroupBox^)(((PictureBox^)sender)->Parent))->Size.Height;
}
private: System::Void changeSizeRightBottomSquare_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (!isClicked)return;

	auto pictureBox = (PictureBox^)sender;
	auto Parent = ((GroupBox^)(pictureBox->Parent));

	Parent->Size = System::Drawing::Size(
		startW + this->MousePosition.X - startX,
		startH + this->MousePosition.Y - startY
	);

	Parent->Controls[4]->Size = System::Drawing::Size(
		startW + this->MousePosition.X - startX,
		startH + this->MousePosition.Y - startY
	);

	Parent->Controls[0]->Location = System::Drawing::Point(0, 0);
	Parent->Controls[1]->Location = System::Drawing::Point(
		0,
		Parent->Size.Height - Parent->Controls[1]->Size.Height
	);
	Parent->Controls[2]->Location = System::Drawing::Point(
		Parent->Size.Width - Parent->Controls[2]->Size.Width,
		Parent->Size.Height - Parent->Controls[2]->Size.Height
	);
	Parent->Controls[3]->Location = System::Drawing::Point(
		Parent->Size.Width - Parent->Controls[3]->Size.Width,
		0
	);
}
private: System::Void changeSizeRightBottomSquare_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	isClicked = false;
}
private: System::Void changeSizeRightBottomSquare_MouseLeave(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	isClicked = false;
}

private: System::Void changeSizeRightTopSquare_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	isClicked = true;

	lastX = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.X;
	lastY = ((GroupBox^)(((PictureBox^)sender)->Parent))->Location.Y;
	startX = this->MousePosition.X;
	startY = this->MousePosition.Y;

	startW = ((GroupBox^)(((PictureBox^)sender)->Parent))->Size.Width;
	startH = ((GroupBox^)(((PictureBox^)sender)->Parent))->Size.Height;
}
private: System::Void changeSizeRightTopSquare_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (!isClicked)return;

	auto pictureBox = (PictureBox^)sender;
	auto Parent = ((GroupBox^)(pictureBox->Parent));

	Parent->Location = System::Drawing::Point(
		Parent->Location.X,
		this->MousePosition.Y - startY + lastY
	);

	Parent->Size = System::Drawing::Size(
		startW + this->MousePosition.X - startX,
		startH - this->MousePosition.Y + startY 
	);

	Parent->Controls[4]->Size = System::Drawing::Size(
		startW + this->MousePosition.X - startX,
		startH - this->MousePosition.Y + startY 
	);

	Parent->Controls[0]->Location = System::Drawing::Point(0, 0);
	Parent->Controls[1]->Location = System::Drawing::Point(
		0,
		Parent->Size.Height - Parent->Controls[1]->Size.Height
	);
	Parent->Controls[2]->Location = System::Drawing::Point(
		Parent->Size.Width - Parent->Controls[2]->Size.Width,
		Parent->Size.Height - Parent->Controls[2]->Size.Height
	);
	Parent->Controls[3]->Location = System::Drawing::Point(
		Parent->Size.Width - Parent->Controls[3]->Size.Width,
		0
	);
}
private: System::Void changeSizeRightTopSquare_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	isClicked = false;
}
private: System::Void MyForm_Load(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	this->menuStrip1->BringToFront();

	for (int i = 1; i < this->Controls->Count; i++)
	{
		((GroupBox^)this->Controls[i])->Controls->Find("0", false)[0]->BringToFront();
	}
}
private: System::Void rectangleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));


	System::Windows::Forms::GroupBox^ groupBox1 = (gcnew System::Windows::Forms::GroupBox());
	groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top
		| System::Windows::Forms::AnchorStyles::Left));
	groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
	groupBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
	groupBox1->Location = System::Drawing::Point(0, 0);
	groupBox1->Margin = System::Windows::Forms::Padding(0);
	groupBox1->Name = L"groupBox1";
	groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
	groupBox1->TabIndex = 1;
	groupBox1->TabStop = false;
	groupBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::groupBox1_MouseDown);
	groupBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
	groupBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
	groupBox1->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);
	//groupBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Rectangle_Paint);


	System::Windows::Forms::PictureBox^ pictureBox = (gcnew System::Windows::Forms::PictureBox());
	pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rectangle.Image")));
	pictureBox->Location = System::Drawing::Point(0, 0);
	pictureBox->Name = L"0";
	pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
	pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	pictureBox->TabIndex = 0;
	pictureBox->TabStop = false;
	pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
	pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
	pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::groupBox1_MouseDown);
	pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);

	System::Windows::Forms::PictureBox^ changeSizeLeftTopSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeLeftTopSquare);
	changeSizeLeftTopSquare->Cursor = System::Windows::Forms::Cursors::SizeNWSE;
	changeSizeLeftTopSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	changeSizeLeftTopSquare->Location = System::Drawing::Point(0, 0);
	changeSizeLeftTopSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeLeftTopSquare->Name = L"1";
	changeSizeLeftTopSquare->Size = System::Drawing::Size(10, 10);
	changeSizeLeftTopSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeLeftTopSquare->TabIndex = 2;
	changeSizeLeftTopSquare->TabStop = false;
	changeSizeLeftTopSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftTopSquare_MouseDown);
	changeSizeLeftTopSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftTopSquare_MouseMove);
	changeSizeLeftTopSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftTopSquare_MouseUp);
	changeSizeLeftTopSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);

	System::Windows::Forms::PictureBox^ changeSizeLeftBottomSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeLeftBottomSquare);
	changeSizeLeftBottomSquare->Cursor = System::Windows::Forms::Cursors::SizeNESW;
	changeSizeLeftBottomSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	changeSizeLeftBottomSquare->Size = System::Drawing::Size(10, 10);
	changeSizeLeftBottomSquare->Location = System::Drawing::Point(
		0,
		pictureBox->Size.Height - changeSizeLeftBottomSquare->Size.Height);
	changeSizeLeftBottomSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeLeftBottomSquare->Name = L"2";
	changeSizeLeftBottomSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeLeftBottomSquare->TabIndex = 2;
	changeSizeLeftBottomSquare->TabStop = false;
	changeSizeLeftBottomSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftBottomSquare_MouseDown);
	changeSizeLeftBottomSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftBottomSquare_MouseMove);
	changeSizeLeftBottomSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftBottomSquare_MouseUp);
	changeSizeLeftBottomSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);

	System::Windows::Forms::PictureBox^ changeSizeRightBottomSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeRightBottomSquare);
	changeSizeRightBottomSquare->Cursor = System::Windows::Forms::Cursors::SizeNWSE;
	changeSizeRightBottomSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));

	changeSizeRightBottomSquare->Size = System::Drawing::Size(10, 10);
	changeSizeRightBottomSquare->Location = System::Drawing::Point(
		pictureBox->Size.Width - changeSizeRightBottomSquare->Size.Width,
		pictureBox->Size.Height - changeSizeRightBottomSquare->Size.Height);
	changeSizeRightBottomSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeRightBottomSquare->Name = L"3";
	changeSizeRightBottomSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeRightBottomSquare->TabIndex = 2;
	changeSizeRightBottomSquare->TabStop = false;
	changeSizeRightBottomSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightBottomSquare_MouseDown);
	changeSizeRightBottomSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightBottomSquare_MouseMove);
	changeSizeRightBottomSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightBottomSquare_MouseUp);
	changeSizeRightBottomSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);


	System::Windows::Forms::PictureBox^ changeSizeRightTopSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeRightTopSquare);
	changeSizeRightTopSquare->Cursor = System::Windows::Forms::Cursors::SizeNESW;
	changeSizeRightTopSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	changeSizeRightTopSquare->Size = System::Drawing::Size(10, 10);
	changeSizeRightTopSquare->Location = System::Drawing::Point(
		pictureBox->Size.Width - changeSizeRightTopSquare->Size.Width,
		0);
	changeSizeRightTopSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeRightTopSquare->Name = L"4";
	//changeSizeRightTopSquare->Name = L"changeSizeRightTopSquare" + (wchar_t)(std::to_string(counter).c_str());
	changeSizeRightTopSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeRightTopSquare->TabIndex = 2;
	changeSizeRightTopSquare->TabStop = false;
	changeSizeRightTopSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightTopSquare_MouseDown);
	changeSizeRightTopSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightTopSquare_MouseMove);
	changeSizeRightTopSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightTopSquare_MouseUp);
	changeSizeRightTopSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);

	groupBox1->Controls->Add(pictureBox);
	groupBox1->Controls[4]->BringToFront();
	groupBox1->Size = pictureBox->Size;

	this->Controls->Add(groupBox1);
}
private: System::Void triangleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));


	System::Windows::Forms::GroupBox^ groupBox1 = (gcnew System::Windows::Forms::GroupBox());
	groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top
		| System::Windows::Forms::AnchorStyles::Left));
	groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
	groupBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
	groupBox1->Location = System::Drawing::Point(0, 0);
	groupBox1->Margin = System::Windows::Forms::Padding(0);
	groupBox1->Name = L"groupBox1";
	groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
	groupBox1->Size = System::Drawing::Size(160, 190);
	groupBox1->TabIndex = 1;
	groupBox1->TabStop = false;
	groupBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::groupBox1_MouseDown);
	groupBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
	groupBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
	groupBox1->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);


	System::Windows::Forms::PictureBox^ pictureBox = (gcnew System::Windows::Forms::PictureBox());
	pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"triangle.Image")));
	pictureBox->Location = System::Drawing::Point(0, 0);
	pictureBox->Name = L"0";
	//pictureBox->Name = L"pictureBox" + (wchar_t)(std::to_string(counter++).c_str());
	pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
	pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	pictureBox->TabIndex = 0;
	pictureBox->TabStop = false;
	pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
	pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
	pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::groupBox1_MouseDown);
	pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);

	System::Windows::Forms::PictureBox^ changeSizeLeftTopSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeLeftTopSquare);
	changeSizeLeftTopSquare->Cursor = System::Windows::Forms::Cursors::SizeNWSE;
	changeSizeLeftTopSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	changeSizeLeftTopSquare->Location = System::Drawing::Point(0, 0);
	changeSizeLeftTopSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeLeftTopSquare->Name = L"1";
	//changeSizeLeftTopSquare->Name = L"changeSizeLeftTopSquare" + (wchar_t)(std::to_string(counter).c_str());
	changeSizeLeftTopSquare->Size = System::Drawing::Size(10, 10);
	changeSizeLeftTopSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeLeftTopSquare->TabIndex = 2;
	changeSizeLeftTopSquare->TabStop = false;
	changeSizeLeftTopSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftTopSquare_MouseDown);
	changeSizeLeftTopSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftTopSquare_MouseMove);
	changeSizeLeftTopSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftTopSquare_MouseUp);
	changeSizeLeftTopSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);

	System::Windows::Forms::PictureBox^ changeSizeLeftBottomSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeLeftBottomSquare);
	changeSizeLeftBottomSquare->Cursor = System::Windows::Forms::Cursors::SizeNESW;
	changeSizeLeftBottomSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	changeSizeLeftBottomSquare->Size = System::Drawing::Size(10, 10);
	changeSizeLeftBottomSquare->Location = System::Drawing::Point(
		0,
		pictureBox->Size.Height - changeSizeLeftBottomSquare->Size.Height);
	changeSizeLeftBottomSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeLeftBottomSquare->Name = L"2";
	//changeSizeLeftBottomSquare->Name = L"changeSizeLeftBottomSquare" + (wchar_t)(std::to_string(counter).c_str());
	changeSizeLeftBottomSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeLeftBottomSquare->TabIndex = 2;
	changeSizeLeftBottomSquare->TabStop = false;
	changeSizeLeftBottomSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftBottomSquare_MouseDown);
	changeSizeLeftBottomSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftBottomSquare_MouseMove);
	changeSizeLeftBottomSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftBottomSquare_MouseUp);
	changeSizeLeftBottomSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);

	System::Windows::Forms::PictureBox^ changeSizeRightBottomSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeRightBottomSquare);
	changeSizeRightBottomSquare->Cursor = System::Windows::Forms::Cursors::SizeNWSE;
	changeSizeRightBottomSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));

	changeSizeRightBottomSquare->Size = System::Drawing::Size(10, 10);
	changeSizeRightBottomSquare->Location = System::Drawing::Point(
		pictureBox->Size.Width - changeSizeRightBottomSquare->Size.Width,
		pictureBox->Size.Height - changeSizeRightBottomSquare->Size.Height);
	changeSizeRightBottomSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeRightBottomSquare->Name = L"3";
	//changeSizeRightBottomSquare->Name = L"changeSizeRightBottomSquare" + (wchar_t)(std::to_string(counter).c_str());
	changeSizeRightBottomSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeRightBottomSquare->TabIndex = 2;
	changeSizeRightBottomSquare->TabStop = false;
	changeSizeRightBottomSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightBottomSquare_MouseDown);
	changeSizeRightBottomSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightBottomSquare_MouseMove);
	changeSizeRightBottomSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightBottomSquare_MouseUp);
	changeSizeRightBottomSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);


	System::Windows::Forms::PictureBox^ changeSizeRightTopSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeRightTopSquare);
	changeSizeRightTopSquare->Cursor = System::Windows::Forms::Cursors::SizeNESW;
	changeSizeRightTopSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	changeSizeRightTopSquare->Size = System::Drawing::Size(10, 10);
	changeSizeRightTopSquare->Location = System::Drawing::Point(
		pictureBox->Size.Width - changeSizeRightTopSquare->Size.Width,
		0);
	changeSizeRightTopSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeRightTopSquare->Name = L"4";
	//changeSizeRightTopSquare->Name = L"changeSizeRightTopSquare" + (wchar_t)(std::to_string(counter).c_str());
	changeSizeRightTopSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeRightTopSquare->TabIndex = 2;
	changeSizeRightTopSquare->TabStop = false;
	changeSizeRightTopSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightTopSquare_MouseDown);
	changeSizeRightTopSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightTopSquare_MouseMove);
	changeSizeRightTopSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightTopSquare_MouseUp);
	changeSizeRightTopSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);

	groupBox1->Controls->Add(pictureBox);
	groupBox1->Controls[4]->BringToFront();
	groupBox1->Size = pictureBox->Size;

	this->Controls->Add(groupBox1);
}
private: System::Void ellipseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));


	System::Windows::Forms::GroupBox^ groupBox1 = (gcnew System::Windows::Forms::GroupBox());
	groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top
		| System::Windows::Forms::AnchorStyles::Left));
	groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
	groupBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
	groupBox1->Location = System::Drawing::Point(0, 0);
	groupBox1->Margin = System::Windows::Forms::Padding(0);
	groupBox1->Name = L"groupBox1";
	groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
	groupBox1->Size = System::Drawing::Size(160, 190);
	groupBox1->TabIndex = 1;
	groupBox1->TabStop = false;
	groupBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::groupBox1_MouseDown);
	groupBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
	groupBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
	groupBox1->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);


	System::Windows::Forms::PictureBox^ pictureBox = (gcnew System::Windows::Forms::PictureBox());
	pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ellipse.Image")));
	pictureBox->Location = System::Drawing::Point(0, 0);
	pictureBox->Name = L"0";
	//pictureBox->Name = L"pictureBox" + (wchar_t)(std::to_string(counter++).c_str());
	pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
	pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	pictureBox->TabIndex = 0;
	pictureBox->TabStop = false;
	pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
	pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
	pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::groupBox1_MouseDown);
	pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);

	System::Windows::Forms::PictureBox^ changeSizeLeftTopSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeLeftTopSquare);
	changeSizeLeftTopSquare->Cursor = System::Windows::Forms::Cursors::SizeNWSE;
	changeSizeLeftTopSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	changeSizeLeftTopSquare->Location = System::Drawing::Point(0, 0);
	changeSizeLeftTopSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeLeftTopSquare->Name = L"1";
	//changeSizeLeftTopSquare->Name = L"changeSizeLeftTopSquare" + (wchar_t)(std::to_string(counter).c_str());
	changeSizeLeftTopSquare->Size = System::Drawing::Size(10, 10);
	changeSizeLeftTopSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeLeftTopSquare->TabIndex = 2;
	changeSizeLeftTopSquare->TabStop = false;
	changeSizeLeftTopSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftTopSquare_MouseDown);
	changeSizeLeftTopSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftTopSquare_MouseMove);
	changeSizeLeftTopSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftTopSquare_MouseUp);
	changeSizeLeftTopSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);

	System::Windows::Forms::PictureBox^ changeSizeLeftBottomSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeLeftBottomSquare);
	changeSizeLeftBottomSquare->Cursor = System::Windows::Forms::Cursors::SizeNESW;
	changeSizeLeftBottomSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	changeSizeLeftBottomSquare->Size = System::Drawing::Size(10, 10);
	changeSizeLeftBottomSquare->Location = System::Drawing::Point(
		0,
		pictureBox->Size.Height - changeSizeLeftBottomSquare->Size.Height);
	changeSizeLeftBottomSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeLeftBottomSquare->Name = L"2";
	//changeSizeLeftBottomSquare->Name = L"changeSizeLeftBottomSquare" + (wchar_t)(std::to_string(counter).c_str());
	changeSizeLeftBottomSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeLeftBottomSquare->TabIndex = 2;
	changeSizeLeftBottomSquare->TabStop = false;
	changeSizeLeftBottomSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftBottomSquare_MouseDown);
	changeSizeLeftBottomSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftBottomSquare_MouseMove);
	changeSizeLeftBottomSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeLeftBottomSquare_MouseUp);
	changeSizeLeftBottomSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);

	System::Windows::Forms::PictureBox^ changeSizeRightBottomSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeRightBottomSquare);
	changeSizeRightBottomSquare->Cursor = System::Windows::Forms::Cursors::SizeNWSE;
	changeSizeRightBottomSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));

	changeSizeRightBottomSquare->Size = System::Drawing::Size(10, 10);
	changeSizeRightBottomSquare->Location = System::Drawing::Point(
		pictureBox->Size.Width - changeSizeRightBottomSquare->Size.Width,
		pictureBox->Size.Height - changeSizeRightBottomSquare->Size.Height);
	changeSizeRightBottomSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeRightBottomSquare->Name = L"3";
	//changeSizeRightBottomSquare->Name = L"changeSizeRightBottomSquare" + (wchar_t)(std::to_string(counter).c_str());
	changeSizeRightBottomSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeRightBottomSquare->TabIndex = 2;
	changeSizeRightBottomSquare->TabStop = false;
	changeSizeRightBottomSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightBottomSquare_MouseDown);
	changeSizeRightBottomSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightBottomSquare_MouseMove);
	changeSizeRightBottomSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightBottomSquare_MouseUp);
	changeSizeRightBottomSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);


	System::Windows::Forms::PictureBox^ changeSizeRightTopSquare = (gcnew System::Windows::Forms::PictureBox());
	groupBox1->Controls->Add(changeSizeRightTopSquare);
	changeSizeRightTopSquare->Cursor = System::Windows::Forms::Cursors::SizeNESW;
	changeSizeRightTopSquare->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	changeSizeRightTopSquare->Size = System::Drawing::Size(10, 10);
	changeSizeRightTopSquare->Location = System::Drawing::Point(
		pictureBox->Size.Width - changeSizeRightTopSquare->Size.Width,
		0);
	changeSizeRightTopSquare->Margin = System::Windows::Forms::Padding(0);
	changeSizeRightTopSquare->Name = L"4";
	//changeSizeRightTopSquare->Name = L"changeSizeRightTopSquare" + (wchar_t)(std::to_string(counter).c_str());
	changeSizeRightTopSquare->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	changeSizeRightTopSquare->TabIndex = 2;
	changeSizeRightTopSquare->TabStop = false;
	changeSizeRightTopSquare->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightTopSquare_MouseDown);
	changeSizeRightTopSquare->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightTopSquare_MouseMove);
	changeSizeRightTopSquare->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::changeSizeRightTopSquare_MouseUp);
	changeSizeRightTopSquare->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);

	groupBox1->Controls->Add(pictureBox);
	groupBox1->Controls[4]->BringToFront();
	groupBox1->Size = pictureBox->Size;

	this->Controls->Add(groupBox1);
}
private: System::Void Rectangle_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g = ((GroupBox^)sender)->CreateGraphics();
	

	Rectangle r(0, 0, 1000, 1000);

	g->FillEllipse(Brushes::Black, e->ClipRectangle);
}
};
}
