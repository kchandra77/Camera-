object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 290
  ClientWidth = 554
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 264
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Button1: TButton
    Left = 232
    Top = 257
    Width = 75
    Height = 25
    Caption = 'Connexion'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 152
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '172.20.101.204'
  end
  object Edit2: TEdit
    Left = 328
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '4213'
  end
  object Button2: TButton
    Left = 344
    Top = 257
    Width = 75
    Height = 25
    Caption = 'Test'
    TabOrder = 3
    OnClick = Button2Click
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnect = ClientSocket1Connect
    OnRead = ClientSocket1Read
    Left = 504
    Top = 16
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 504
    Top = 248
  end
end
