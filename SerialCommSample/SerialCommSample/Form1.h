#pragma once

//===============================================================================
//Copyright(C) altemasoft.com
//<SOFTWARE_INFORMATION>
// <SOFTWARE_NAME> Visual C++ 2008 用 シリアル通信サンプル </SOFTWARE_NAME>
// <SOFTWARE_VERSION> 0.10 </SOFTWARE_VERSION>
//</SOFTWARE_INFORMATION>
//
//<AUTHOR_INFORMATION>
// <AUTHOUR_NAME> ベイガー </AUTHOUR_NAME>
// <WEBSITE_URL>http://www.altemasoft.com/</WEBSITE_URL>
// <EMAIL_ADDRESS>koichi_hasegawa@altemasoft.com</EMAIL_ADDRESS>
//</AUTHOR_INFORMATION>
//===============================================================================


#include "formSerialConfiguration.h"

namespace SerialCommSample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textTransmit;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonConnect;
	private: System::Windows::Forms::Button^  buttonDisconnect;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labelConnectionStatus;
	private: System::Windows::Forms::TextBox^  textRecieved;
	private: System::IO::Ports::SerialPort^  serialPort;
	private: System::ComponentModel::IContainer^  components;

	private: String^	COMRevieveBuffer;	//シリアル受信バッファ


	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textTransmit = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->buttonDisconnect = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelConnectionStatus = (gcnew System::Windows::Forms::Label());
			this->textRecieved = (gcnew System::Windows::Forms::TextBox());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 137);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"受信文字列：";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(253, 108);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"送信する";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textTransmit
			// 
			this->textTransmit->Location = System::Drawing::Point(12, 83);
			this->textTransmit->Name = L"textTransmit";
			this->textTransmit->Size = System::Drawing::Size(319, 19);
			this->textTransmit->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L"送信文字列：";
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(12, 12);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(75, 23);
			this->buttonConnect->TabIndex = 1;
			this->buttonConnect->Text = L"接続";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &Form1::buttonConnect_Click);
			// 
			// buttonDisconnect
			// 
			this->buttonDisconnect->Location = System::Drawing::Point(256, 12);
			this->buttonDisconnect->Name = L"buttonDisconnect";
			this->buttonDisconnect->Size = System::Drawing::Size(75, 23);
			this->buttonDisconnect->TabIndex = 2;
			this->buttonDisconnect->Text = L"切断";
			this->buttonDisconnect->UseVisualStyleBackColor = true;
			this->buttonDisconnect->Click += gcnew System::EventHandler(this, &Form1::buttonDisconnect_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(148, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 12);
			this->label3->TabIndex = 7;
			this->label3->Text = L"接続ステータス：";
			// 
			// labelConnectionStatus
			// 
			this->labelConnectionStatus->AutoSize = true;
			this->labelConnectionStatus->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->labelConnectionStatus->Location = System::Drawing::Point(249, 39);
			this->labelConnectionStatus->Name = L"labelConnectionStatus";
			this->labelConnectionStatus->Size = System::Drawing::Size(82, 24);
			this->labelConnectionStatus->TabIndex = 8;
			this->labelConnectionStatus->Text = L"切断中";
			// 
			// textRecieved
			// 
			this->textRecieved->Location = System::Drawing::Point(8, 155);
			this->textRecieved->Name = L"textRecieved";
			this->textRecieved->Size = System::Drawing::Size(320, 19);
			this->textRecieved->TabIndex = 5;
			// 
			// serialPort
			// 
			this->serialPort->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::serialPort_DataReceived);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(343, 186);
			this->Controls->Add(this->textRecieved);
			this->Controls->Add(this->labelConnectionStatus);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->buttonDisconnect);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textTransmit);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"SerialCommunicationSample";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonConnect_Click(System::Object^  sender, System::EventArgs^  e) {
				 formSerialConfiguration^	SerialConfiguration	= gcnew	formSerialConfiguration();
				 if(serialPort->IsOpen == false) { // ポートが閉じてることを確認
					 SerialConfiguration->ShowDialog();	//フォームを表示する
				

					 //フォームがキャンセルされたかどうかの確認
					 if( SerialConfiguration->IsConfigurationEnabled == true){
						 try {
							 //設定されたデータの取得
							 serialPort->PortName = SerialConfiguration->GetSelectedPortName();
							 serialPort->BaudRate = SerialConfiguration->GetSelectedBaudRate();
							 serialPort->DataBits = SerialConfiguration->GetSelectedDataBits();
							 serialPort->Parity = SerialConfiguration->GetSelectedParity();
							 serialPort->StopBits = SerialConfiguration->GetSelectedStopBits();
							 serialPort->Handshake = SerialConfiguration->GetSelectedHandShake();

							 serialPort->Open();
						 } catch(Exception^ ex) {
							 System::Windows::Forms::MessageBox::Show(ex->Message);

						 }

						 if(serialPort->IsOpen == true) {	//ほんとに開かれたか確認
							labelConnectionStatus->Text = "接続中";

						 }


					 }
				 }


			 }

private: System::Void buttonDisconnect_Click(System::Object^  sender, System::EventArgs^  e) {
		if(serialPort->IsOpen == true) {	//ほんとに開かれたか確認
			serialPort->Close();

		}

		if(serialPort->IsOpen == false) {	//ほんとに閉じたれたか確認
				labelConnectionStatus->Text = "切断中";

		}
	}
		 

//
delegate void SerialDataRecievedDelegate(String^ recvData);
private: void SerialDataRecieved(String^ recvData){
			//別スレッドで起動される関数。
			textRecieved->Text =  recvData;


		 }

private: System::Void serialPort_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
			SerialDataRecievedDelegate^ dlgte = gcnew SerialDataRecievedDelegate( this, &SerialCommSample::Form1::SerialDataRecieved );
			String^ RecievedData = serialPort->ReadExisting();

			//1バイトずつ受信することを前提
			if(serialPort->IsOpen == true) {	//シリアルポートが開いていることを確認してから。

			COMRevieveBuffer = COMRevieveBuffer + RecievedData; //受信バッファに追加


			//改行コードを検出する
			if(RecievedData == "\r" ) {			
				RecievedData = RecievedData + "\n";
				COMRevieveBuffer = COMRevieveBuffer + RecievedData;

				//受信した一行をテキストボックスに転送する。テキストボックスの操作は別スレッドの関数にする。
				this->Invoke(dlgte, COMRevieveBuffer);

				COMRevieveBuffer = "";
			}
			if(RecievedData == "\n" ) {
				RecievedData = RecievedData + "\n";
				COMRevieveBuffer = COMRevieveBuffer + RecievedData;

				//受信した一行をテキストボックスに転送する。テキストボックスの操作は別スレッドの関数にする。
				this->Invoke(dlgte, COMRevieveBuffer);
				COMRevieveBuffer = "";
			}
				


			//エコーを返す
			serialPort->Write(RecievedData);


		 }
	}
		 
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		 if(serialPort->IsOpen == true) {
			 //シリアルポートが開いていることを確認してから。
			 serialPort->Write( textTransmit->Text + "\r\n" );
		 }

		 }
};
}

