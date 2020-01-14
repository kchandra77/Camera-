//---------------------------------------------------------------------------

#ifndef RFIDH
#define RFIDH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <fstream>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *Button1;
	TEdit *Edit1;
	TClientSocket *ClientSocket1;
	TEdit *Edit2;
	TButton *Button2;
	TLabel *Label1;
	TTimer *Timer1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);

private:	// Déclarations utilisateur
public:     // Déclarations utilisateur
bool accesOK;

char BadgeLuSansEspace [100];
char BadgeLuAvecEspace [100];
char numeroBadge [15];
char nomprenom [100];

	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
