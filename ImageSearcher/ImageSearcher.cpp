#include "ImageSearcher.h"

using namespace System;
using namespace System::Windows::Forms;

#pragma region "Main"
[STAThread]
void main(array<System::String^>^ args)
{
	// Initiating application.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Initiating search engines.
	ColorEngine* colorEngine = new ColorEngine();
	FormEngine* formEngine = new FormEngine();
	TextureEngine* textureEngine = new TextureEngine();;

	// Initiating main form.
	ImageSearcher::ImageSearcher form(colorEngine, formEngine, textureEngine);
	Application::Run(%form);
}
#pragma endregion

ImageSearcher::ImageSearcher::ImageSearcher(ColorEngine* colorEngine,
											FormEngine* formEngine,
											TextureEngine* textureEngine)
{
	InitializeComponent();

	// Set default database path.
	imageBasePath = L"C:/Users/Marcelo/OneDrive/UEPG/4� Ano/Processamento de Imagens/images";

	this->txtbox_imagePath->Text = "Please wait. Creating database...";
	this->btn_search->Enabled = false;
	this->btn_choose->Enabled = false;
	this->btn_database->Enabled = false;

	this->colorEngine = colorEngine;
	this->backWorkerColorEngine->RunWorkerAsync();

	this->formEngine = formEngine;
	this->backWorkerFormEngine->RunWorkerAsync();

	this->textureEngine = textureEngine;
	this->backWorkerTextureEngine->RunWorkerAsync();

	this->txtbox_imagePath->Text = "";
	this->btn_search->Enabled = true;
	this->btn_choose->Enabled = true;
	this->btn_database->Enabled = true;
}


ImageSearcher::ImageSearcher::~ImageSearcher()
{
	if (components)
	{
		delete components;
	}
}