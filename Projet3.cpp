//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Projet3.h"
#include "RFID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}

void __fastcall TForm1::Button1Click(TObject *Sender)
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

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket)

{
	//ShowMessage ("Connecté à la caméra ! ");  	  //affcihe un msg
	Button1->Caption= "Déconnexion";              //permet de se connecter à la camera
	if(deplace==0)
	{
		UnicodeString login = Edit3->Text+":"+ Edit4->Text;
		char crypte[30];
		codage64(AnsiString(login).c_str(), crypte);
		UnicodeString requete = "GET /snapshot.cgi HTTP/1.1\r\nHost: 172.20.182.32\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:43.0) Gecko/20100101 Firefox/43.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;q=0.3\r\nAccept-Encoding: gzip, deflate\r\nReferer: http://172.20.182.32/content.htm\r\nAuthorization: Basic "+UnicodeString(crypte)+"\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\n\r\n";
		ClientSocket1->Socket->SendBuf(AnsiString(requete).c_str(),1000);
		fichier.open("image1.jpg",ios_base::binary);
	}
	else if(deplace == 1)
	{
         //deplacement haut

	UnicodeString haut = "GET /decoder_control.cgi?command=2 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
	ClientSocket1->Socket->SendBuf(AnsiString(haut).c_str(),1000);
	UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
   ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
	}
	else if(deplace == 2)
	{
	//deplacement droite
	UnicodeString droite = "GET /decoder_control.cgi?command=4 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
	ClientSocket1->Socket->SendBuf(AnsiString(droite).c_str(),1000);
	UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
   ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
    }
	else if(deplace == 3)
	{
    	 //deplacememnt gauche

	UnicodeString gauche = "GET /decoder_control.cgi?command=0 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
	ClientSocket1->Socket->SendBuf(AnsiString(gauche).c_str(),1000);
  UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
   ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
	}
	else if(deplace == 4)
	{
		//deplacement bas

	UnicodeString bas = "GET /decoder_control.cgi?command=6 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
	ClientSocket1->Socket->SendBuf(AnsiString(bas).c_str(),1000);
	UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
   ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{

	 if(deplace==0)
	 {
		fichier.close();
	  //	ShowMessage ("Déconnecté à la caméra ! ");
		Button1->Caption="Connexion";
		fichier1.open("image1.jpg",ios_base::binary);
		fichier2.open("image2.jpg",ios_base::binary);
		int compteur=0;
		do
		{
			char c;
			compteur++;
			c=fichier1.get();
			if(compteur>225)
			{
				fichier2.put(c);
			}

		}
		while(fichier1.eof()==0);

		fichier1.close();
		fichier1.clear();
		fichier2.close();
		fichier2.clear();
		Image1->Picture->LoadFromFile("image2.jpg");
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	deplace = 0;
	//fichier.open("image1.jpg",ios_base::binary);
	//ClientSocket1->Socket->SendBuf((char*)"GET /snapshot.cgi HTTP/1.1\r\nHost: 172.20.182.32\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:43.0) Gecko/20100101 Firefox/43.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;q=0.3\r\nAccept-Encoding: gzip, deflate\r\nReferer: http://172.20.182.32/content.htm\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\n\r\n",1000);
   //	UnicodeString login = Edit3->Text+":"+ Edit4->Text;
	//char crypte[30];
   //	codage64(AnsiString(login).c_str(), crypte);
   //	UnicodeString requete = "GET /snapshot.cgi HTTP/1.1\r\nHost: 172.20.182.32\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:43.0) Gecko/20100101 Firefox/43.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;q=0.3\r\nAccept-Encoding: gzip, deflate\r\nReferer: http://172.20.182.32/content.htm\r\nAuthorization: Basic "+UnicodeString(crypte)+"\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\n\r\n";
  //	ClientSocket1->Socket->SendBuf(AnsiString(requete).c_str(),1000);
	//Label1->Caption= UnicodeString(crypte);
	Button1Click(NULL);
	deplace=0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)
{
	if(deplace==0)
	{
   	AnsiString in= Socket->ReceiveText();
	fichier.write(in.c_str(),in.Length());
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{     //deplacement haut
	//deplace = 1;
   //	UnicodeString haut = "GET /decoder_control.cgi?command=2 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
   //	ClientSocket1->Socket->SendBuf(AnsiString(haut).c_str(),1000);
  //	UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
  // ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
   Button1Click(NULL);
   deplace=1;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{     //deplacement droite
	//deplace = 1;
//	UnicodeString droite = "GET /decoder_control.cgi?command=4 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
  //	ClientSocket1->Socket->SendBuf(AnsiString(droite).c_str(),1000);
	//UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
//   ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
	Button1Click(NULL);
	deplace=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{      //deplacememnt gauche
//	deplace = 1;
  //	UnicodeString gauche = "GET /decoder_control.cgi?command=6 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
	//ClientSocket1->Socket->SendBuf(AnsiString(gauche).c_str(),1000);
//  UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
//   ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
	Button1Click(NULL);
	deplace=4;}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{     //deplacement bas
	//deplace = 1;
//	UnicodeString bas = "GET /decoder_control.cgi?command=0 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
  //	ClientSocket1->Socket->SendBuf(AnsiString(bas).c_str(),1000);
	//UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
//   ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
Button1Click(NULL);
	deplace=3;}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
	//deplacement haute droite
	//deplace = 1;
  //	UnicodeString haut droite = "GET /decoder_control.cgi?command=92 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
  //	ClientSocket1->Socket->SendBuf(AnsiString(haut droite).c_str(),1000);
  //	UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
  // ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
	//déplacement bas droite
  //	deplace = 1;
  //	UnicodeString bas droite = "GET /decoder_control.cgi?command=90 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n";
  //	ClientSocket1->Socket->SendBuf(AnsiString(bas droite).c_str(),1000);
  //	UnicodeString stop = "GET /decoder_control.cgi?command=1 HTTP/1.1\r\nHost: 172.20.182.32\r\nConnection: keep-alive\r\nAuthorization: Basic YWRtaW46YWRtaW4=\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\nReferer: http://172.20.182.32/camera.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
  // ClientSocket1->Socket->SendBuf(AnsiString(stop).c_str(),1000);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	if(ClientSocket1->Active==true)
	{
		Button1Click(NULL);
		deplace=0;
	}
	else
	{
		Button1Click(NULL);
		deplace=0;
    }
}
//---------------------------------------------------------------------------

