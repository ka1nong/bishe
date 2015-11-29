object Form1: TForm1
  Left = 380
  Top = 256
  Width = 974
  Height = 670
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 16
    Top = 16
    Width = 257
    Height = 537
    Caption = #31383#21475#26639
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 504
      Width = 137
      Height = 25
      AutoSize = False
      Caption = #32467#26463#24555#25463#38190#65306
    end
    object list_progress: TListBox
      Left = 8
      Top = 48
      Width = 241
      Height = 441
      ItemHeight = 20
      TabOrder = 0
    end
    object btn_refreshProgress: TButton
      Left = 160
      Top = 16
      Width = 89
      Height = 25
      Caption = #21047#26032
      TabOrder = 1
      OnClick = btn_refreshProgressClick
    end
    object Edit1: TEdit
      Left = 144
      Top = 496
      Width = 97
      Height = 28
      TabOrder = 2
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 568
    Width = 929
    Height = 49
    Caption = #24037#20855#26639
    TabOrder = 1
    object Label6: TLabel
      Left = 16
      Top = 16
      Width = 89
      Height = 16
      AutoSize = False
      Caption = #25171#24320#25991#20214#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Button1: TButton
      Left = 792
      Top = 16
      Width = 121
      Height = 25
      Caption = #36816#34892
      TabOrder = 0
    end
    object OpenFile_Text: TEdit
      Left = 104
      Top = 16
      Width = 225
      Height = 21
      TabOrder = 1
    end
    object Button2: TButton
      Left = 336
      Top = 16
      Width = 89
      Height = 25
      Caption = #25353#38062
      TabOrder = 2
      OnClick = Button2Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 296
    Top = 24
    Width = 97
    Height = 529
    Caption = #25805#20316#26639
    TabOrder = 2
    object Label2: TLabel
      Left = 8
      Top = 24
      Width = 73
      Height = 25
      AutoSize = False
      Caption = #40736#26631#35774#32622
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 8
      Top = 104
      Width = 73
      Height = 16
      AutoSize = False
      Caption = #38190#30424#35774#32622
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 8
      Top = 176
      Width = 73
      Height = 25
      AutoSize = False
      Caption = #24310#26102#35774#32622
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 72
      Top = 208
      Width = 17
      Height = 25
      AutoSize = False
      Caption = #31186
    end
    object mouseEventFilter: TComboBox
      Left = 8
      Top = 48
      Width = 81
      Height = 21
      ItemHeight = 13
      TabOrder = 0
    end
    object TComboBox
      Left = 8
      Top = 128
      Width = 81
      Height = 21
      ItemHeight = 13
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 8
      Top = 200
      Width = 57
      Height = 33
      TabOrder = 2
    end
  end
  object GroupBox4: TGroupBox
    Left = 408
    Top = 24
    Width = 537
    Height = 529
    Caption = #37197#32622#26639
    TabOrder = 3
    object Label7: TLabel
      Left = 16
      Top = 488
      Width = 108
      Height = 13
      Caption = #31383#21475#19981#23384#22312#26102#25191#34892#65306
    end
    object ListBox1: TListBox
      Left = 8
      Top = 16
      Width = 513
      Height = 457
      ItemHeight = 13
      TabOrder = 0
    end
    object open_Radiobtn: TRadioButton
      Left = 136
      Top = 488
      Width = 57
      Height = 17
      Caption = #25171#24320
      TabOrder = 1
    end
    object close_Radiobtn: TRadioButton
      Left = 192
      Top = 488
      Width = 73
      Height = 17
      Caption = #32456#27490
      TabOrder = 2
    end
    object Button3: TButton
      Left = 424
      Top = 480
      Width = 97
      Height = 33
      Caption = #19981#21487#32456#27490
      TabOrder = 3
    end
  end
end
