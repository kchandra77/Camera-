//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RFID.h"
#include "Projet3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket)

{
	//ShowMessage ("Connecté à la RFID ! ");

}
//---------------------------------------------------------------------------
void __fastcall TForm2::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)

{   ifstream fichier;
	ClientSocket1->Socket->ReceiveBuf(BadgeLuAvecEspace,100);
   //	Label1->Caption=BadgeLuAvecEspace;
	int j,i;
	j=0;
	for (i=0; i<=strlen(BadgeLuAvecEspace); i++)
	{
		if( BadgeLuAvecEspace[i]!=0x20)
		{
			BadgeLuSansEspace[j]=BadgeLuAvecEspace[i];
			j=j+1;
		}

	}
	Label1->Caption=BadgeLuSansEspace;

	accesOK=false;
	fichier.open("acces.rfid");
	do
	{
		fichier>>numeroBadge;
		fichier.getline(nomprenom,100);
		if(!strcmp(numeroBadge,BadgeLuSansEspace))
		{
			accesOK=true;
		}
	}while(fichier.eof()==false && accesOK==false);
	if(accesOK==true)
	{
		Button1Click(NULL);
		Timer1->Enabled=1;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
		if(ClientSocket1->Active == false)
	{
		//Indiquer l'adresse IP
		ClientSocket1->Host = Edit1->Text;
		//Indiquer le port
		ClientSocket1->Port = Edit2->Text.ToInt();
		//lancer la connexion au serveur
		ClientSocket1->Active = true;
	}
	else
	{
		ClientSocket1->Active = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	if(accesOK==false)
	{
		Button2Click(NULL);
	}

}
//---------------------------------------------------------------------------
 void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Form1->Show();
	Form2->Visible=0;
}
//---------------------------------------------------------------------------

