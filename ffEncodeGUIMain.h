#ifndef HEADER_9F960D988AE37DCB
#define HEADER_9F960D988AE37DCB

/***************************************************************
 * Name:      ffEncodeGUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    KJ ()
 * Created:   2021-07-03
 * Copyright: KJ ()
 * License:
 **************************************************************/

#ifndef ffEncodeGUIMAIN_H
#define ffEncodeGUIMAIN_H

//(*Headers(ffEncodeGUIFrame)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class ffEncodeGUIFrame: public wxFrame
{
    public:

        ffEncodeGUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ffEncodeGUIFrame();

    private:

        //(*Handlers(ffEncodeGUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void onDocs(wxCommandEvent& event);
        void onEncode(wxCommandEvent& event);
        void OnCheckUpdateSelected(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void OnEncoderSliderUpdated(wxScrollEvent& event);
        void OnVideoCodecChoiceSelect(wxCommandEvent& event);
        void OnAudioInclueCheckBoxClick(wxCommandEvent& event);
        void OnAudioQualityModeChange(wxCommandEvent& event);
        void OnAudioQualityChoiceSelect(wxCommandEvent& event);
        void OnAudioCodecChoiceSelect(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnDimensionsSelected(wxCommandEvent& event);
        void OnCropVideoSelected(wxCommandEvent& event);
        void OnOutputFilePickerFileChanged(wxFileDirPickerEvent& event);
        void OnClearConsoleButtonClick(wxCommandEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);
        void OnWEBMVideoCodecChoiceSelect(wxCommandEvent& event);
        void OnDimensionsTabPaint(wxPaintEvent& event);
        //*)

        //(*Identifiers(ffEncodeGUIFrame)
        static const long ID_FILEPICKERCTRL1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT15;
        static const long ID_PANEL1;
        static const long ID_STATICTEXT17;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON2;
        static const long ID_PANEL8;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT20;
        static const long ID_SPINCTRL1;
        static const long ID_SPINCTRL2;
        static const long ID_CHECKBOX4;
        static const long ID_CHECKBOX2;
        static const long ID_STATICTEXT21;
        static const long ID_STATICTEXT23;
        static const long ID_STATICTEXT25;
        static const long ID_STATICTEXT24;
        static const long ID_STATICTEXT22;
        static const long ID_SPINCTRL6;
        static const long ID_SPINCTRL7;
        static const long ID_SPINCTRL9;
        static const long ID_SPINCTRL3;
        static const long ID_PANEL5;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT3;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_SLIDER1;
        static const long ID_SLIDER2;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_CHOICE3;
        static const long ID_STATICTEXT10;
        static const long ID_CHOICE4;
        static const long ID_STATICTEXT11;
        static const long ID_CHOICE12;
        static const long ID_CHOICE13;
        static const long ID_PANEL9;
        static const long ID_CHOICE10;
        static const long ID_PANEL2;
        static const long ID_CHOICE8;
        static const long ID_CHOICE6;
        static const long ID_CHOICE7;
        static const long ID_CHOICE9;
        static const long ID_STATICTEXT14;
        static const long ID_PANEL4;
        static const long ID_CHECKBOX1;
        static const long ID_STATICTEXT12;
        static const long ID_CHOICE5;
        static const long ID_STATICTEXT13;
        static const long ID_CHOICE11;
        static const long ID_PANEL3;
        static const long ID_NOTEBOOK1;
        static const long ID_STATICTEXT16;
        static const long ID_FILEPICKERCTRL2;
        static const long ID_PANEL6;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long idMenuDoc;
        static const long checkUpdate;
        static const long ID_STATUSBAR1;
        static const long ID_MESSAGEDIALOG1;
        //*)

        //(*Declarations(ffEncodeGUIFrame)
        wxButton* ClearConsoleButton;
        wxButton* EncodeButton;
        wxCheckBox* AudioIncludeCheckBox;
        wxCheckBox* CheckCroppingChange;
        wxCheckBox* CheckSizeChange;
        wxChoice* AudioBitrateChoice;
        wxChoice* AudioCodecChoice;
        wxChoice* AudioMixdownSelection;
        wxChoice* AudioModeChoice;
        wxChoice* AudioQualityChoice;
        wxChoice* EncoderProfile265;
        wxChoice* EncoderProfile;
        wxChoice* EncoderTune265;
        wxChoice* EncoderTune;
        wxChoice* FPSChoice;
        wxChoice* VideoCodecChoice;
        wxChoice* WEBMAudioCodecChoice;
        wxChoice* WEBMVideoCodecChoice;
        wxFilePickerCtrl* FilePickerCtrl1;
        wxFilePickerCtrl* OutputFilePicker;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMessageDialog* SuccessDialog;
        wxNotebook* MainTabsNotebook;
        wxPanel* AudioTab;
        wxPanel* DimensionsTab;
        wxPanel* EncoderTuneProfile;
        wxPanel* InteriorAudioPanel;
        wxPanel* SaveAsPanel;
        wxPanel* SourceFilePanel;
        wxPanel* SummaryTab;
        wxPanel* VideoTab;
        wxSlider* EncoderPresetSlider;
        wxSlider* crfSlider;
        wxSpinCtrl* CropBottom;
        wxSpinCtrl* CropLeft;
        wxSpinCtrl* CropRight;
        wxSpinCtrl* CropTop;
        wxSpinCtrl* VideoHeightChange;
        wxSpinCtrl* VideoWidthChange;
        wxStaticLine* StaticLine1;
        wxStaticText* AudioCodecText;
        wxStaticText* AudioMixdownText;
        wxStaticText* ChooseSourceText;
        wxStaticText* CropBottomText;
        wxStaticText* CropLeftText;
        wxStaticText* CropRightText;
        wxStaticText* CropTopText;
        wxStaticText* FPSText;
        wxStaticText* PresetLabel;
        wxStaticText* SaveAsText;
        wxStaticText* SourceFileText;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText1;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStaticText* TextCropping;
        wxStaticText* TextHeight;
        wxStaticText* TextSize;
        wxStaticText* TextWidth;
        wxStaticText* VideoCodecText;
        wxStatusBar* StatusBar1;
        wxTextCtrl* consoleLog;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ffEncodeGUIMAIN_H
#endif // header guard

