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


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace	System::IO::Ports;



namespace SerialCommSample {

	/// <summary>
	/// formSerialConfiguration の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class formSerialConfiguration : public System::Windows::Forms::Form
	{
	public:
		formSerialConfiguration(void)
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
		~formSerialConfiguration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  cmdOK;
	private: System::Windows::Forms::Button^  cmdCancel;
	private: System::Windows::Forms::ComboBox^  listCOMPortName;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  listBitRate;
	private: System::Windows::Forms::ComboBox^  listDataBitLength;
	private: System::Windows::Forms::ComboBox^  listParity;
	private: System::Windows::Forms::ComboBox^  listStopBit;
	private: System::Windows::Forms::ComboBox^  listFlowControl;

	//設定を内部的に保存
	private: int		SelectedBaudRate;						//ボーレート
	private: String^	SelectedPortName;						//ポート名
	private: int		SelectedDataBits;						//データビット
	private: System::IO::Ports::Parity		SelectedParity;		//パリティ
	private: System::IO::Ports::StopBits	SelectedStopBits;	//ストップビット
	private: System::IO::Ports::Handshake	SelectedHandShake;	//ハンドシェイク（フロー制御）

	//外部へデータを橋渡し
	//外部へデータを橋渡し
	public: int		GetSelectedBaudRate(){
			//ボーレート	
			return(SelectedBaudRate);	
				
			}
	public: String^	GetSelectedPortName(){
			return(SelectedPortName);	
			}						//ポート名
	public: int		GetSelectedDataBits(){
			return(SelectedDataBits);	//データビット
			}
			
	public: System::IO::Ports::Parity		GetSelectedParity(){
			return(SelectedParity);	//パリティ
			}
	public: System::IO::Ports::StopBits		GetSelectedStopBits(){
			return(SelectedStopBits);	//ストップビット
			}	
	public: System::IO::Ports::Handshake	GetSelectedHandShake(){
			return(SelectedHandShake);	//ハンドシェイク（フロー制御）
			}	

	public: bool		IsConfigurationEnabled;					//キャンセルで閉じたかOKで閉じたか


	protected: 


	protected: 

	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->cmdOK = (gcnew System::Windows::Forms::Button());
			this->cmdCancel = (gcnew System::Windows::Forms::Button());
			this->listCOMPortName = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->listBitRate = (gcnew System::Windows::Forms::ComboBox());
			this->listDataBitLength = (gcnew System::Windows::Forms::ComboBox());
			this->listParity = (gcnew System::Windows::Forms::ComboBox());
			this->listStopBit = (gcnew System::Windows::Forms::ComboBox());
			this->listFlowControl = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// cmdOK
			// 
			this->cmdOK->Location = System::Drawing::Point(12, 231);
			this->cmdOK->Name = L"cmdOK";
			this->cmdOK->Size = System::Drawing::Size(75, 23);
			this->cmdOK->TabIndex = 0;
			this->cmdOK->Text = L"OK";
			this->cmdOK->UseVisualStyleBackColor = true;
			this->cmdOK->Click += gcnew System::EventHandler(this, &formSerialConfiguration::cmdOK_Click);
			// 
			// cmdCancel
			// 
			this->cmdCancel->Location = System::Drawing::Point(205, 231);
			this->cmdCancel->Name = L"cmdCancel";
			this->cmdCancel->Size = System::Drawing::Size(75, 23);
			this->cmdCancel->TabIndex = 1;
			this->cmdCancel->Text = L"キャンセル";
			this->cmdCancel->UseVisualStyleBackColor = true;
			this->cmdCancel->Click += gcnew System::EventHandler(this, &formSerialConfiguration::cmdCancel_Click);
			// 
			// listCOMPortName
			// 
			this->listCOMPortName->FormattingEnabled = true;
			this->listCOMPortName->Location = System::Drawing::Point(135, 14);
			this->listCOMPortName->Name = L"listCOMPortName";
			this->listCOMPortName->Size = System::Drawing::Size(145, 20);
			this->listCOMPortName->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"ポート名：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L"ビットレート(bit/sec)：";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 12);
			this->label3->TabIndex = 5;
			this->label3->Text = L"データビット長：";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 131);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 12);
			this->label4->TabIndex = 6;
			this->label4->Text = L"パリティ：";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 165);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 12);
			this->label5->TabIndex = 7;
			this->label5->Text = L"ストップビット：";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(19, 201);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 12);
			this->label6->TabIndex = 8;
			this->label6->Text = L"フロー制御：";
			// 
			// listBitRate
			// 
			this->listBitRate->FormattingEnabled = true;
			this->listBitRate->Items->AddRange(gcnew cli::array< System::Object^  >(13) {L"110", L"300", L"1200", L"2400", L"4800", L"9600", 
				L"19200", L"38400", L"57600", L"115200", L"230400", L"460800", L"921600"});
			this->listBitRate->Location = System::Drawing::Point(135, 50);
			this->listBitRate->Name = L"listBitRate";
			this->listBitRate->Size = System::Drawing::Size(145, 20);
			this->listBitRate->TabIndex = 9;
			// 
			// listDataBitLength
			// 
			this->listDataBitLength->FormattingEnabled = true;
			this->listDataBitLength->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"5", L"6", L"7", L"8"});
			this->listDataBitLength->Location = System::Drawing::Point(135, 84);
			this->listDataBitLength->Name = L"listDataBitLength";
			this->listDataBitLength->Size = System::Drawing::Size(145, 20);
			this->listDataBitLength->TabIndex = 10;
			// 
			// listParity
			// 
			this->listParity->FormattingEnabled = true;
			this->listParity->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"なし", L"奇数", L"偶数", L"マーク", L"スペース"});
			this->listParity->Location = System::Drawing::Point(135, 123);
			this->listParity->Name = L"listParity";
			this->listParity->Size = System::Drawing::Size(145, 20);
			this->listParity->TabIndex = 11;
			// 
			// listStopBit
			// 
			this->listStopBit->FormattingEnabled = true;
			this->listStopBit->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"1", L"1.5", L"2"});
			this->listStopBit->Location = System::Drawing::Point(135, 157);
			this->listStopBit->Name = L"listStopBit";
			this->listStopBit->Size = System::Drawing::Size(145, 20);
			this->listStopBit->TabIndex = 12;
			// 
			// listFlowControl
			// 
			this->listFlowControl->FormattingEnabled = true;
			this->listFlowControl->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"なし", L"Xon/Xoff", L"ハードウェア", L"Xon/Xoff + ハードウェア"});
			this->listFlowControl->Location = System::Drawing::Point(135, 193);
			this->listFlowControl->Name = L"listFlowControl";
			this->listFlowControl->Size = System::Drawing::Size(145, 20);
			this->listFlowControl->TabIndex = 13;
			// 
			// formSerialConfiguration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->Controls->Add(this->listFlowControl);
			this->Controls->Add(this->listStopBit);
			this->Controls->Add(this->listParity);
			this->Controls->Add(this->listDataBitLength);
			this->Controls->Add(this->listBitRate);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listCOMPortName);
			this->Controls->Add(this->cmdCancel);
			this->Controls->Add(this->cmdOK);
			this->Name = L"formSerialConfiguration";
			this->Text = L"シリアルポート設定";
			this->Load += gcnew System::EventHandler(this, &formSerialConfiguration::formSerialConfiguration_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void formSerialConfiguration_Load(System::Object^  sender, System::EventArgs^  e) {
			array<String^>^ portnames = nullptr;

			 listCOMPortName->Items->Clear();	//リストをクリア
			
			 portnames = System::IO::Ports::SerialPort::GetPortNames();	//使えるポート名をGET
				for each(String^ port in portnames)
				{
					listCOMPortName->Items->Add(port);
				}
			
			 if( listCOMPortName->Items->Count >= 0){
				//リストに何かあったら、一番最初を選択しておく。
				listCOMPortName->SelectedIndex=0;
				}

				listBitRate->SelectedIndex=5;

				listDataBitLength->SelectedIndex=3;

				listParity->SelectedIndex=0;
				listStopBit->SelectedIndex=0;
				listFlowControl->SelectedIndex=0;


			 }





private: System::Void cmdOK_Click(System::Object^  sender, System::EventArgs^  e) {

		SelectedPortName = listCOMPortName->SelectedItem->ToString();	//COMポート名
		SelectedBaudRate= System::Convert::ToInt32( listBitRate->SelectedItem->ToString() ); //ボーレート
		SelectedDataBits = System::Convert::ToInt32( listDataBitLength->SelectedItem->ToString() );


		switch( listParity->SelectedIndex ){
			case	0:	//なし
				SelectedParity = Parity::None;
				break;
			case	1:	//奇数
				SelectedParity = Parity::Odd;
				break;
			case	2:	//偶数
				SelectedParity = Parity::Even;
				break;
			case	3:	//マーク
				SelectedParity = Parity::Mark;
				break;	
			case	4:	//スペース
				SelectedParity = Parity::Space;
				break;

			default:
				SelectedParity = Parity::None;
				break;

		}

		switch( listStopBit->SelectedIndex ){
			case	0:	//1
				SelectedStopBits = StopBits::One;
				break;
			case	1:	//1.5
				SelectedStopBits = StopBits::OnePointFive;
				break;
			case	2:	//2
				SelectedStopBits = StopBits::Two;
				break;

			default:
				SelectedStopBits = StopBits::One;
				break;

		}




		switch( listFlowControl->SelectedIndex ){
			case	0:
				SelectedHandShake = Handshake::None;	//なし
				break;
			case	1:
				SelectedHandShake = Handshake::XOnXOff;	//Xon/Xoff
				break;
			case	2:
				SelectedHandShake = Handshake::RequestToSend;	//ハードウェア
				break;
			case	3:
				SelectedHandShake = Handshake::RequestToSendXOnXOff;	//Xon/Xoff + ハードウェア
				break;

			default:
				SelectedHandShake = Handshake::None;	//なし
				break;

		}

		IsConfigurationEnabled = true;	//OKボタンで閉じられた

		this->Close();	//ばいばい



		 }
private: System::Void cmdCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		IsConfigurationEnabled = false;	//Cancelボタンで閉じられた

		this->Close();	//ばいばい

		 }
};
}
