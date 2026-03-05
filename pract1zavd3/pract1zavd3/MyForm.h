#pragma once

namespace pract1zavd3 {

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
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"Томат", L"Огірок", L"Кабачок", L"Баклажан", L"Картопля",
					L"Морква", L"Гарбуз", L"Редиска"
			});
			this->listBox1->Location = System::Drawing::Point(670, 70);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(299, 276);
			this->listBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(584, 419);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(205, 66);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(75, 66);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(527, 347);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1023, 553);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
			// Перевірка вибору користувача
			if (listBox1->SelectedIndex == -1) {
				MessageBox::Show("Виберіть слово зі списку!");
				return;
			}
			String^ path = "";
			// Вибір файлу по індексу
			switch (listBox1->SelectedIndex) {
			case 0: path = "томат.wav"; break;
			case 1: path = "огірок.wav"; break;
			case 2: path = "кабачок.wav"; break;
			case 3: path = "баклажан.wav"; break;
			case 4: path = "картопля.wav"; break;
			case 5: path = "морква.wav"; break;
			case 6: path = "гарбуз.wav"; break;
			case 7: path = "редиска.wav"; break;
			default:
				MessageBox::Show("Немає відповідного файлу!");
				return;
			}
			// Відтворення звуку
			System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer(path);
			player->Load();
			player->Play();
		}
	
	};
}
