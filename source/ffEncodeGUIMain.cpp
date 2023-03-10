/***************************************************************
 * Name:      ffEncodeGUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    KJ ()
 * Created:   2021-07-03
 * Copyright: KJ ()
 * License:
 **************************************************************/
#define CURRENT_VER 1
#include "ffEncodeGUIMain.h"
#include <wx/msgdlg.h>
#include <wx/xml/xml.h>
#include <wx/filesys.h>
#include <wx/log.h>
#include <wx/stdpaths.h>
#include <wx/utils.h>
#include <wx/process.h>
#include <wx/stopwatch.h>
#include <wx/aboutdlg.h>
//(*InternalHeaders(ffEncodeGUIFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ffEncodeGUIFrame)
const long ffEncodeGUIFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICLINE1 = wxNewId();
const long ffEncodeGUIFrame::ID_BUTTON1 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT15 = wxNewId();
const long ffEncodeGUIFrame::ID_PANEL1 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT17 = wxNewId();
const long ffEncodeGUIFrame::ID_TEXTCTRL1 = wxNewId();
const long ffEncodeGUIFrame::ID_BUTTON2 = wxNewId();
const long ffEncodeGUIFrame::ID_PANEL8 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT18 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT19 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT20 = wxNewId();
const long ffEncodeGUIFrame::ID_SPINCTRL1 = wxNewId();
const long ffEncodeGUIFrame::ID_SPINCTRL2 = wxNewId();
const long ffEncodeGUIFrame::ID_CHECKBOX4 = wxNewId();
const long ffEncodeGUIFrame::ID_CHECKBOX2 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT21 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT23 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT25 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT24 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT22 = wxNewId();
const long ffEncodeGUIFrame::ID_SPINCTRL6 = wxNewId();
const long ffEncodeGUIFrame::ID_SPINCTRL7 = wxNewId();
const long ffEncodeGUIFrame::ID_SPINCTRL9 = wxNewId();
const long ffEncodeGUIFrame::ID_SPINCTRL3 = wxNewId();
const long ffEncodeGUIFrame::ID_PANEL5 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT1 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT2 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE1 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT3 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE2 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT4 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT5 = wxNewId();
const long ffEncodeGUIFrame::ID_SLIDER1 = wxNewId();
const long ffEncodeGUIFrame::ID_SLIDER2 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT6 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT7 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT8 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT9 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE3 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT10 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE4 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT11 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE12 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE13 = wxNewId();
const long ffEncodeGUIFrame::ID_PANEL9 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE10 = wxNewId();
const long ffEncodeGUIFrame::ID_PANEL2 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE8 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE6 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE7 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE9 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT14 = wxNewId();
const long ffEncodeGUIFrame::ID_PANEL4 = wxNewId();
const long ffEncodeGUIFrame::ID_CHECKBOX1 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT12 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE5 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT13 = wxNewId();
const long ffEncodeGUIFrame::ID_CHOICE11 = wxNewId();
const long ffEncodeGUIFrame::ID_PANEL3 = wxNewId();
const long ffEncodeGUIFrame::ID_NOTEBOOK1 = wxNewId();
const long ffEncodeGUIFrame::ID_STATICTEXT16 = wxNewId();
const long ffEncodeGUIFrame::ID_FILEPICKERCTRL2 = wxNewId();
const long ffEncodeGUIFrame::ID_PANEL6 = wxNewId();
const long ffEncodeGUIFrame::ID_MENUITEM1 = wxNewId();
const long ffEncodeGUIFrame::idMenuAbout = wxNewId();
const long ffEncodeGUIFrame::idMenuDoc = wxNewId();
const long ffEncodeGUIFrame::checkUpdate = wxNewId();
const long ffEncodeGUIFrame::ID_STATUSBAR1 = wxNewId();
const long ffEncodeGUIFrame::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ffEncodeGUIFrame,wxFrame)
    //(*EventTable(ffEncodeGUIFrame)
    //*)
END_EVENT_TABLE()

bool CheckForFFMPEG();
ffEncodeGUIFrame::ffEncodeGUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ffEncodeGUIFrame)
    wxFlexGridSizer* FlexGridSizerMain;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("ffEncodeGUI"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("C:\\msys\\programs\\ffEncodeGUI\\programICO_blue.ico"))));
    SetIcon(FrameIcon);
    }
    FlexGridSizerMain = new wxFlexGridSizer(4, 0, 0, 0);
    FlexGridSizerMain->AddGrowableCol(0);
    FlexGridSizerMain->AddGrowableRow(2);
    SourceFilePanel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(512,50), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    SourceFilePanel->SetMaxSize(wxSize(-1,50));
    FilePickerCtrl1 = new wxFilePickerCtrl(SourceFilePanel, ID_FILEPICKERCTRL1, wxEmptyString, _("Select source media file"), _T("Media files|*.mp4;*.mkv;*.webm;*.mov;*.wmv;*.flv;*.avi|All files|*.*"), wxPoint(104,16), wxSize(288,23), wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    FilePickerCtrl1->SetToolTip(_("Select the source file"));
    StaticLine1 = new wxStaticLine(SourceFilePanel, ID_STATICLINE1, wxPoint(408,8), wxSize(1,34), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    EncodeButton = new wxButton(SourceFilePanel, ID_BUTTON1, _("Encode!"), wxPoint(416,8), wxSize(88,31), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    EncodeButton->Disable();
    EncodeButton->SetToolTip(_("Press to encode selected source file, using chosen settings."));
    SourceFileText = new wxStaticText(SourceFilePanel, ID_STATICTEXT15, _("Source file:"), wxPoint(8,18), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    wxFont SourceFileTextFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    SourceFileText->SetFont(SourceFileTextFont);
    FlexGridSizerMain->Add(SourceFilePanel, 1, wxEXPAND, 5);
    MainTabsNotebook = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(499,331), 0, _T("ID_NOTEBOOK1"));
    MainTabsNotebook->Disable();
    SummaryTab = new wxPanel(MainTabsNotebook, ID_PANEL8, wxPoint(310,23), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    ChooseSourceText = new wxStaticText(SummaryTab, ID_STATICTEXT17, _("Choose the source media file to start!"), wxPoint(56,16), wxSize(360,23), wxALIGN_CENTRE, _T("ID_STATICTEXT17"));
    wxFont ChooseSourceTextFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    ChooseSourceText->SetFont(ChooseSourceTextFont);
    consoleLog = new wxTextCtrl(SummaryTab, ID_TEXTCTRL1, wxEmptyString, wxPoint(16,48), wxSize(480,248), wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2|wxTE_CHARWRAP|wxTE_WORDWRAP|wxVSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    consoleLog->SetMaxSize(wxSize(-1,-1));
    ClearConsoleButton = new wxButton(SummaryTab, ID_BUTTON2, _("Clear Log"), wxPoint(416,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    ClearConsoleButton->SetToolTip(_("Press to clear the console log"));
    DimensionsTab = new wxPanel(MainTabsNotebook, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    TextSize = new wxStaticText(DimensionsTab, ID_STATICTEXT18, _("Size"), wxPoint(16,8), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    wxFont TextSizeFont(9,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextSize->SetFont(TextSizeFont);
    TextWidth = new wxStaticText(DimensionsTab, ID_STATICTEXT19, _("Width:"), wxPoint(16,88), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    TextHeight = new wxStaticText(DimensionsTab, ID_STATICTEXT20, _("Height:"), wxPoint(16,124), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    VideoWidthChange = new wxSpinCtrl(DimensionsTab, ID_SPINCTRL1, _T("1280"), wxPoint(80,88), wxSize(66,23), 0, -1, 1920, 1280, _T("ID_SPINCTRL1"));
    VideoWidthChange->SetValue(_T("1280"));
    VideoWidthChange->Disable();
    VideoWidthChange->SetToolTip(_("Dimension width of the video in pixels. Use \'-1\' to keep aspect ratio"));
    VideoHeightChange = new wxSpinCtrl(DimensionsTab, ID_SPINCTRL2, _T("720"), wxPoint(80,124), wxSize(66,23), 0, -1, 1080, 720, _T("ID_SPINCTRL2"));
    VideoHeightChange->SetValue(_T("720"));
    VideoHeightChange->Disable();
    VideoHeightChange->SetToolTip(_("Dimension height of the video in pixels. Use \'-1\' to keep aspect ratio"));
    CheckSizeChange = new wxCheckBox(DimensionsTab, ID_CHECKBOX4, _("Change video dimensions"), wxPoint(16,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    CheckSizeChange->SetValue(false);
    CheckSizeChange->SetToolTip(_("Check to unlock video dimensions controls."));
    CheckCroppingChange = new wxCheckBox(DimensionsTab, ID_CHECKBOX2, _("Crop video"), wxPoint(248,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckCroppingChange->SetValue(false);
    CheckCroppingChange->SetToolTip(_("Check to unlock video crop controls"));
    TextCropping = new wxStaticText(DimensionsTab, ID_STATICTEXT21, _("Cropping"), wxPoint(240,8), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    wxFont TextCroppingFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
    TextCropping->SetFont(TextCroppingFont);
    CropLeftText = new wxStaticText(DimensionsTab, ID_STATICTEXT23, _("Left"), wxPoint(216,112), wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    CropRightText = new wxStaticText(DimensionsTab, ID_STATICTEXT25, _("Right"), wxPoint(456,112), wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    CropBottomText = new wxStaticText(DimensionsTab, ID_STATICTEXT24, _("Bottom"), wxPoint(328,160), wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    CropTopText = new wxStaticText(DimensionsTab, ID_STATICTEXT22, _("Top"), wxPoint(336,72), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    CropRight = new wxSpinCtrl(DimensionsTab, ID_SPINCTRL6, _T("0"), wxPoint(392,112), wxSize(58,23), 0, 0, 8192, 0, _T("ID_SPINCTRL6"));
    CropRight->SetValue(_T("0"));
    CropRight->Disable();
    CropRight->SetToolTip(_("Crop video starting from the right by x amount of pixels."));
    CropBottom = new wxSpinCtrl(DimensionsTab, ID_SPINCTRL7, _T("0"), wxPoint(320,136), wxSize(66,23), 0, 0, 8192, 0, _T("ID_SPINCTRL7"));
    CropBottom->SetValue(_T("0"));
    CropBottom->Disable();
    CropBottom->SetToolTip(_("Crop video starting from the bottom by x amount of pixels."));
    CropLeft = new wxSpinCtrl(DimensionsTab, ID_SPINCTRL9, _T("0"), wxPoint(248,112), wxSize(64,23), 0, 0, 8192, 0, _T("ID_SPINCTRL9"));
    CropLeft->SetValue(_T("0"));
    CropLeft->Disable();
    CropLeft->SetToolTip(_("Crop video starting from the left by x amount of pixels."));
    CropTop = new wxSpinCtrl(DimensionsTab, ID_SPINCTRL3, _T("0"), wxPoint(320,88), wxSize(66,23), 0, 0, 8192, 0, _T("ID_SPINCTRL3"));
    CropTop->SetValue(_T("0"));
    CropTop->Disable();
    CropTop->SetToolTip(_("Crop video starting from the top by x amount of pixels."));
    VideoTab = new wxPanel(MainTabsNotebook, ID_PANEL2, wxPoint(190,163), wxSize(507,303), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticText1 = new wxStaticText(VideoTab, ID_STATICTEXT1, _("Video"), wxPoint(16,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    VideoCodecText = new wxStaticText(VideoTab, ID_STATICTEXT2, _("Video codec:"), wxPoint(16,48), wxSize(88,16), 0, _T("ID_STATICTEXT2"));
    VideoCodecChoice = new wxChoice(VideoTab, ID_CHOICE1, wxPoint(112,48), wxSize(96,24), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    VideoCodecChoice->SetSelection( VideoCodecChoice->Append(_("H.264")) );
    VideoCodecChoice->Append(_("H.265"));
    FPSText = new wxStaticText(VideoTab, ID_STATICTEXT3, _("Framerate (FPS):"), wxPoint(16,88), wxSize(96,24), 0, _T("ID_STATICTEXT3"));
    FPSChoice = new wxChoice(VideoTab, ID_CHOICE2, wxPoint(112,88), wxSize(96,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    FPSChoice->SetSelection( FPSChoice->Append(_("Source")) );
    FPSChoice->Append(_("1"));
    FPSChoice->Append(_("2"));
    FPSChoice->Append(_("5"));
    FPSChoice->Append(_("10"));
    FPSChoice->Append(_("15"));
    FPSChoice->Append(_("20"));
    FPSChoice->Append(_("25"));
    FPSChoice->Append(_("29.976"));
    FPSChoice->Append(_("30"));
    FPSChoice->Append(_("35"));
    FPSChoice->Append(_("40"));
    FPSChoice->Append(_("45"));
    FPSChoice->Append(_("55"));
    FPSChoice->Append(_("60"));
    FPSChoice->SetToolTip(_("Output framerate.\n\nIf source has variable framerate, then option \"Source\" will preserve it. "));
    StaticText4 = new wxStaticText(VideoTab, ID_STATICTEXT4, _("Optimize video"), wxPoint(16,136), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText4Font(9,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    StaticText5 = new wxStaticText(VideoTab, ID_STATICTEXT5, _("Encoder Preset:"), wxPoint(16,168), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    EncoderPresetSlider = new wxSlider(VideoTab, ID_SLIDER1, 5, 0, 9, wxPoint(112,168), wxSize(108,32), wxSL_AUTOTICKS, wxDefaultValidator, _T("ID_SLIDER1"));
    EncoderPresetSlider->SetTickFreq(1);
    EncoderPresetSlider->SetToolTip(_("Adjusts encoder settings to trade off compression efficiency against encoding speed.\n\nFaster speed = worse compression. Set this to the slowest you can bear.\n\nAvoid using placebo:\nIt helps at most ~1% in terms of quality (vs. veryslow) at the cost of a much higher encoding time."));
    crfSlider = new wxSlider(VideoTab, ID_SLIDER2, 20, 0, 51, wxPoint(232,48), wxSize(256,45), wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER2"));
    crfSlider->SetToolTip(_("Sets the desired quality factor (CRF).\n\nLower values correspond to higher quality. Small decreases in value will result in progressively larger increases in the resulting file size.\nA value of 0 means lossless and will result in a file size that is larger than the original source.\n\nA change of 6 should result in about half/double the file size, although your results might vary and it depends on the codec"));
    StaticText6 = new wxStaticText(VideoTab, ID_STATICTEXT6, _("Constant Rate Factor:"), wxPoint(232,48), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText7 = new wxStaticText(VideoTab, ID_STATICTEXT7, _("Better quality"), wxPoint(248,96), wxSize(76,16), 0, _T("ID_STATICTEXT7"));
    StaticText8 = new wxStaticText(VideoTab, ID_STATICTEXT8, _("Lower quality"), wxPoint(392,96), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    PresetLabel = new wxStaticText(VideoTab, ID_STATICTEXT9, _("Medium"), wxPoint(232,176), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    EncoderTuneProfile = new wxPanel(VideoTab, ID_PANEL9, wxPoint(8,200), wxSize(232,88), wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    EncoderTune = new wxChoice(EncoderTuneProfile, ID_CHOICE3, wxPoint(104,8), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    EncoderTune->SetSelection( EncoderTune->Append(_("None")) );
    EncoderTune->Append(_("Film"));
    EncoderTune->Append(_("Animation"));
    EncoderTune->Append(_("Grain"));
    EncoderTune->Append(_("Still Image"));
    EncoderTune->Append(_("PSNR"));
    EncoderTune->Append(_("SSIM"));
    EncoderTune->Append(_("Zero Latency"));
    EncoderTune->SetToolTip(_("Tune settings to optimize for common scenarios."));
    StaticText9 = new wxStaticText(EncoderTuneProfile, ID_STATICTEXT10, _("Encoder Tune:"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    EncoderProfile = new wxChoice(EncoderTuneProfile, ID_CHOICE4, wxPoint(104,48), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    EncoderProfile->SetSelection( EncoderProfile->Append(_("High")) );
    EncoderProfile->Append(_("Main"));
    EncoderProfile->Append(_("Baseline"));
    EncoderProfile->SetToolTip(_("Sets specified profile."));
    StaticText10 = new wxStaticText(EncoderTuneProfile, ID_STATICTEXT11, _("Encoder Profile:"), wxPoint(8,48), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    EncoderProfile265 = new wxChoice(EncoderTuneProfile, ID_CHOICE12, wxPoint(104,48), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE12"));
    EncoderProfile265->SetSelection( EncoderProfile265->Append(_("Main")) );
    EncoderProfile265->Append(_("Main Still Picture"));
    EncoderProfile265->Hide();
    EncoderProfile265->SetToolTip(_("Sets specified profile."));
    EncoderTune265 = new wxChoice(EncoderTuneProfile, ID_CHOICE13, wxPoint(104,8), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE13"));
    EncoderTune265->SetSelection( EncoderTune265->Append(_("None")) );
    EncoderTune265->Append(_("Animation"));
    EncoderTune265->Append(_("Grain"));
    EncoderTune265->Append(_("Fast Decode"));
    EncoderTune265->Append(_("PSNR"));
    EncoderTune265->Append(_("SSIM"));
    EncoderTune265->Append(_("Zero Latency"));
    EncoderTune265->Hide();
    EncoderTune265->SetToolTip(_("Tune settings to optimize for common scenarios."));
    WEBMVideoCodecChoice = new wxChoice(VideoTab, ID_CHOICE10, wxPoint(112,48), wxSize(96,24), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE10"));
    WEBMVideoCodecChoice->SetSelection( WEBMVideoCodecChoice->Append(_("VP8")) );
    WEBMVideoCodecChoice->Append(_("VP9"));
    WEBMVideoCodecChoice->Hide();
    WEBMVideoCodecChoice->SetToolTip(_("Available video encoders.\n\nNote that for .webm container there are available only VP8 and VP9, whereas for .mp4 and .mkv there\'s H.264 and H.265."));
    AudioTab = new wxPanel(MainTabsNotebook, ID_PANEL3, wxPoint(87,7), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    InteriorAudioPanel = new wxPanel(AudioTab, ID_PANEL4, wxPoint(8,112), wxSize(240,112), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    AudioQualityChoice = new wxChoice(InteriorAudioPanel, ID_CHOICE8, wxPoint(96,24), wxSize(96,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE8"));
    AudioQualityChoice->Append(_("1"));
    AudioQualityChoice->Append(_("2"));
    AudioQualityChoice->Append(_("3"));
    AudioQualityChoice->Append(_("4"));
    AudioQualityChoice->SetSelection( AudioQualityChoice->Append(_("5")) );
    AudioQualityChoice->Append(_("6"));
    AudioQualityChoice->Append(_("7"));
    AudioQualityChoice->Append(_("8"));
    AudioQualityChoice->Append(_("9"));
    AudioQualityChoice->Append(_("10"));
    AudioQualityChoice->Hide();
    AudioQualityChoice->SetToolTip(_("Available quality levels"));
    AudioModeChoice = new wxChoice(InteriorAudioPanel, ID_CHOICE6, wxPoint(8,24), wxSize(72,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
    AudioModeChoice->SetSelection( AudioModeChoice->Append(_("Bitrate:")) );
    AudioModeChoice->Append(_("Quality:"));
    AudioModeChoice->SetToolTip(_("Available modes for quality target.\n\nBitrate option will target specified bitrate in kbps.\nQuality option has values, which are encoder specific, so for libmp3lame the range is 0-9 where a lower value is a higher quality. "));
    AudioBitrateChoice = new wxChoice(InteriorAudioPanel, ID_CHOICE7, wxPoint(96,24), wxSize(96,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE7"));
    AudioBitrateChoice->Append(_("96"));
    AudioBitrateChoice->Append(_("100"));
    AudioBitrateChoice->Append(_("112"));
    AudioBitrateChoice->Append(_("128"));
    AudioBitrateChoice->SetSelection( AudioBitrateChoice->Append(_("160")) );
    AudioBitrateChoice->Append(_("192"));
    AudioBitrateChoice->Append(_("224"));
    AudioBitrateChoice->Append(_("256"));
    AudioBitrateChoice->Append(_("320"));
    AudioBitrateChoice->Append(_("384"));
    AudioBitrateChoice->Append(_("448"));
    AudioBitrateChoice->Append(_("512"));
    AudioBitrateChoice->SetToolTip(_("Available bitrate levels."));
    AudioMixdownSelection = new wxChoice(InteriorAudioPanel, ID_CHOICE9, wxPoint(96,64), wxSize(96,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE9"));
    AudioMixdownSelection->SetSelection( AudioMixdownSelection->Append(_("Stereo")) );
    AudioMixdownSelection->Append(_("Mono"));
    AudioMixdownSelection->SetToolTip(_("Available mixdown levels."));
    AudioMixdownText = new wxStaticText(InteriorAudioPanel, ID_STATICTEXT14, _("Mixdown:"), wxPoint(8,64), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    AudioIncludeCheckBox = new wxCheckBox(AudioTab, ID_CHECKBOX1, _("Include Audio"), wxPoint(16,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    AudioIncludeCheckBox->SetValue(true);
    AudioIncludeCheckBox->SetToolTip(_("Check this if you want to include the audio (or not)"));
    StaticText11 = new wxStaticText(AudioTab, ID_STATICTEXT12, _("Audio"), wxPoint(16,8), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    wxFont StaticText11Font(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText11->SetFont(StaticText11Font);
    AudioCodecChoice = new wxChoice(AudioTab, ID_CHOICE5, wxPoint(104,88), wxSize(96,24), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    AudioCodecChoice->SetSelection( AudioCodecChoice->Append(_("AAC")) );
    AudioCodecChoice->Append(_("MP3"));
    AudioCodecChoice->Append(_("Vorbis"));
    AudioCodecChoice->Append(_("Passthrough"));
    AudioCodecChoice->Append(_("Opus"));
    AudioCodecChoice->Append(_("FLAC"));
    AudioCodecChoice->SetToolTip(_("Available audio codecs.\n\nBased on quality produced from high to low:\nFLAC (lossless) > Opus > Vorbis >= AAC > MP3 > Vorbis \n\nNote that for .webm container ony Vorbis is available"));
    AudioCodecText = new wxStaticText(AudioTab, ID_STATICTEXT13, _("Audio Codec:"), wxPoint(16,88), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    WEBMAudioCodecChoice = new wxChoice(AudioTab, ID_CHOICE11, wxPoint(104,88), wxSize(96,24), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE11"));
    WEBMAudioCodecChoice->SetSelection( WEBMAudioCodecChoice->Append(_("Vorbis")) );
    WEBMAudioCodecChoice->Append(_("Opus"));
    WEBMAudioCodecChoice->SetToolTip(_("Available audio codecs.\n\nBased on quality produced from high to low:\nFLAC (lossless) > Opus > Vorbis >= AAC > MP3 > Vorbis \n\nNote that for .webm container ony Vorbis and Opus are available"));
    MainTabsNotebook->AddPage(SummaryTab, _("Console"), false);
    MainTabsNotebook->AddPage(DimensionsTab, _("Dimensions"), false);
    MainTabsNotebook->AddPage(VideoTab, _("Video"), false);
    MainTabsNotebook->AddPage(AudioTab, _("Audio"), false);
    FlexGridSizerMain->Add(MainTabsNotebook, 0, wxEXPAND, 5);
    SaveAsPanel = new wxPanel(this, ID_PANEL6, wxDefaultPosition, wxSize(513,50), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    SaveAsText = new wxStaticText(SaveAsPanel, ID_STATICTEXT16, _("Save as:"), wxPoint(8,18), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    wxFont SaveAsTextFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    SaveAsText->SetFont(SaveAsTextFont);
    OutputFilePicker = new wxFilePickerCtrl(SaveAsPanel, ID_FILEPICKERCTRL2, wxEmptyString, wxEmptyString, _T("mp4|*.mp4|mkv|*.mkv|webm|*.webm"), wxPoint(80,16), wxSize(424,23), wxFLP_SAVE|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL2"));
    OutputFilePicker->Disable();
    OutputFilePicker->SetToolTip(_("Select the output media save directory."));
    FlexGridSizerMain->Add(SaveAsPanel, 1, wxEXPAND, 5);
    SetSizer(FlexGridSizerMain);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuItem3 = new wxMenuItem(Menu2, idMenuDoc, _("Open ffmpeg docs"), _("Opens webpage of ffmpeg documentation"), wxITEM_NORMAL);
    Menu2->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu2, checkUpdate, _("Check for Updates"), _("Checks if there\'s an update available"), wxITEM_NORMAL);
    Menu2->Append(MenuItem4);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SuccessDialog = new wxMessageDialog(this, _("File encoded successfully"), _("Information"), wxYES_NO|wxICON_INFORMATION, wxDefaultPosition);
    FlexGridSizerMain->SetSizeHints(this);
    Center();

    Connect(ID_FILEPICKERCTRL1,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnFilePickerCtrl1FileChanged);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ffEncodeGUIFrame::onEncode);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnClearConsoleButtonClick);
    Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnDimensionsSelected);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnCropVideoSelected);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnVideoCodecChoiceSelect);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnEncoderSliderUpdated);
    Connect(ID_CHOICE10,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnWEBMVideoCodecChoiceSelect);
    Connect(ID_CHOICE8,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnAudioQualityChoiceSelect);
    Connect(ID_CHOICE6,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnAudioQualityModeChange);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnAudioInclueCheckBoxClick);
    Connect(ID_CHOICE5,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnAudioCodecChoiceSelect);
    Connect(ID_CHOICE11,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnAudioCodecChoiceSelect);
    Connect(ID_FILEPICKERCTRL2,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnOutputFilePickerFileChanged);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnAbout);
    Connect(idMenuDoc,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::onDocs);
    Connect(checkUpdate,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ffEncodeGUIFrame::OnCheckUpdateSelected);
    //*)
    SuccessDialog->SetYesNoLabels(wxID_OK, _("&Open encoded media file"));
    CheckForFFMPEG();
}


wxString FFmpegPath;
//wxString FFprobePath;
wxString sourceFilename;
wxString SourceMediaFilepath;
wxString OutputMediaFilepath;
bool webmOnly = false;

bool CheckForFFMPEG() {
    FFmpegPath = ::wxStandardPaths::Get().GetDataDir();
//    FFprobePath = FFmpegPath;
    FFmpegPath.append("\\resources\\ffmpeg.exe");
//    FFprobePath.append("\\resources\\ffprobe.exe");
//  if(!wxFileExists(FFmpegPath) || !wxFileExists(FFprobePath)) {
    if(!wxFileExists(FFmpegPath)) {
        wxMessageBox("Couldn't find FFmpeg binaries!\nThe program will not work!", _("Error"),wxICON_ERROR);
        return false;
    }
    else {
        wxLogStatus("Select media to start.");
        return true;
    }
}

ffEncodeGUIFrame::~ffEncodeGUIFrame()
{
    //(*Destroy(ffEncodeGUIFrame)
    SuccessDialog->Destroy();
    //*)
}

void ffEncodeGUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}


void ffEncodeGUIFrame::OnAbout(wxCommandEvent& event)
{
    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("C:\\msys\\programs\\ffEncodeGUI\\programICO_blue.ico"))));
    wxAboutDialogInfo info;
    info.SetIcon(FrameIcon);
    info.SetName(_("ffEncodeGUI"));
    info.SetVersion(_("v0.9"));
    info.SetDescription(_("Program na zaliczenie przedmiotu Zaawansowane Jezyki Programowania.\nSluzy do enkodowania plikow multimedialnych"));
    info.SetCopyright(wxT("(C) 2021 Krystian Jackowski <kryjac@st.amu.edu.pl>"));
    wxAboutBox(info);
}

void ffEncodeGUIFrame::OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event)
{
    ChooseSourceText->Hide();
    SourceMediaFilepath = event.GetPath();
    consoleLog->AppendText("Source path set: "+ SourceMediaFilepath+"\n");
    wxLogStatus("Select output file.");
    sourceFilename = FilePickerCtrl1->GetFileName().GetName();
    //wxExecute(FFprobePath + " -v quiet -hide_banner -i \"" + SourceMediaFilepath+"\"");
    MainTabsNotebook->Enable();
    OutputFilePicker->Enable();
}

void ffEncodeGUIFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void ffEncodeGUIFrame::onDocs(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("https://ffmpeg.org/documentation.html");
}

void ffEncodeGUIFrame::onEncode(wxCommandEvent& event)
{
    //Initial command build
    wxString executeCommand = "";
    wxString executeFilters = " -vf null";
    executeCommand.append(FFmpegPath + " -v error -loglevel error -hide_banner -y -i \"" + SourceMediaFilepath + "\"");
    //Dimensions tab - Size
    if(CheckSizeChange->IsChecked()) {
        wxString videoSize="";
        wxString newWidth, newHeight;
        newWidth << VideoWidthChange->GetValue();
        newHeight << VideoHeightChange->GetValue();
        videoSize=",scale=\""+newWidth+":"+newHeight+"\"";
        executeFilters.append(videoSize);
    }
    //Dimensions tab - Cropping
    if(CheckCroppingChange->IsChecked()) {
        wxString videoCrop="";
        wxString cTop, cLeft, cBottom, cRight;
        cTop<<CropTop->GetValue();
        cLeft<<CropLeft->GetValue();
        cBottom<<CropBottom->GetValue();
        cRight<<CropRight->GetValue();
        videoCrop=",crop=\"w=in_w-"+cLeft+"-"+cRight+":h=in_h-"+cTop+"-"+cBottom+":x="+cLeft+":y="+cTop+"\"";
        executeFilters.append(videoCrop);
    }
    //Videos tab - codecs
    wxString videoCodec="";
    if (!webmOnly) {
        switch(VideoCodecChoice->GetCurrentSelection()) {
            case 0:
                videoCodec="libx264";
                break;
            case 1:
                videoCodec="libx265";
                break;
        }
    }
    else {
        switch(WEBMVideoCodecChoice->GetCurrentSelection()) {
            case 0:
                videoCodec="libvpx";
                break;
            case 1:
                videoCodec="libvpx-vp9";
                break;
        }
    }
    //Videos tab - FPS
    wxString videoFPS="";
    switch(FPSChoice->GetCurrentSelection()) {
        case 0:
            videoFPS="source_fps";
            break;
        case 1:
            videoFPS="1";
            break;
        case 2:
            videoFPS="2";
            break;
        case 3:
            videoFPS="5";
            break;
        case 4:
            videoFPS="10";
            break;
        case 5:
            videoFPS="15";
            break;
        case 6:
            videoFPS="20";
            break;
        case 7:
            videoFPS="25";
            break;
        case 8:
            videoFPS="29.976";
            break;
        case 9:
            videoFPS="30";
            break;
        case 10:
            videoFPS="35";
            break;
        case 11:
            videoFPS="40";
            break;
        case 12:
            videoFPS="45";
            break;
        case 13:
            videoFPS="55";
            break;
        case 14:
            videoFPS="60";
            break;
    }
    executeFilters.append(",fps="+videoFPS);
    //Videos tab - encoder preset
    wxString videoEncoderPreset="";
    switch(EncoderPresetSlider->GetValue()) {
        case 0:
            videoEncoderPreset="ultrafast";
            break;
        case 1:
            videoEncoderPreset="superfast";
            break;
        case 2:
            videoEncoderPreset="veryfast";
            break;
        case 3:
            videoEncoderPreset="faster";
            break;
        case 4:
            videoEncoderPreset="fast";
            break;
        case 5:
            videoEncoderPreset="medium";
            break;
        case 6:
            videoEncoderPreset="slow";
            break;
        case 7:
            videoEncoderPreset="slower";
            break;
        case 8:
            videoEncoderPreset="veryslow";
            break;
        case 9:
            videoEncoderPreset="placebo";
            break;
    }
    //Videos tab - encoder tune
    wxString videoEncoderTune="";
    if (!webmOnly) {
        if(VideoCodecChoice->GetCurrentSelection()==0) {
            switch(EncoderTune->GetCurrentSelection()) {
                case 0:
                    videoEncoderTune="";
                    break;
                case 1:
                    videoEncoderTune="-tune film";
                    break;
                case 2:
                    videoEncoderTune="-tune animation";
                    break;
                case 3:
                    videoEncoderTune="-tune grain";
                    break;
                case 4:
                    videoEncoderTune="-tune stillimage";
                    break;
                case 5:
                    videoEncoderTune="-tune psnr";
                    break;
                case 6:
                    videoEncoderTune="-tune ssim";
                    break;
                case 7:
                    videoEncoderTune="-tune zerolatency";
                    break;
            }
        }
        else {
            switch(EncoderTune265->GetCurrentSelection()) {
                case 0:
                    videoEncoderTune="";
                    break;
                case 1:
                    videoEncoderTune="-tune animation";
                    break;
                case 2:
                    videoEncoderTune="-tune grain";
                    break;
                case 3:
                    videoEncoderTune="-tune fastdecode";
                    break;
                case 4:
                    videoEncoderTune="-tune psnr";
                    break;
                case 5:
                    videoEncoderTune="-tune ssim";
                    break;
                case 6:
                    videoEncoderTune="-tune zerolatency";
                    break;
            }
        }
    }
    //Video tab - encoder profile
    wxString videoEncoderProfile="";
    if (!webmOnly) {
        if(VideoCodecChoice->GetCurrentSelection()==0) {
            switch(EncoderProfile->GetCurrentSelection()) {
                case 0:
                    videoEncoderProfile="-profile:v high";
                    break;
                case 1:
                    videoEncoderProfile="-profile:v main";
                    break;
                case 2:
                    videoEncoderProfile="-profile:v baseline";
                    break;
            }
        }
        else {
            switch(EncoderProfile265->GetCurrentSelection()) {
                case 0:
                    videoEncoderProfile="-profile:v main";
                    break;
                case 1:
                    videoEncoderProfile="-profile:v mainstillpicture";
                    break;
            }
        }
    }
    //Video tab - CRF
    wxString videoCRF="-crf ";
    videoCRF<<crfSlider->GetValue();
    //Audio tab  - codec
    wxString audioCodec="";
    if(!AudioIncludeCheckBox->IsChecked()) {
        audioCodec=" -an ";
    }
    else {
        if (!webmOnly) {
            switch(AudioCodecChoice->GetCurrentSelection()) {
                case 0:
                    audioCodec="-c:a aac";
                    break;
                case 1:
                    audioCodec="-c:a libmp3lame";
                    break;
                case 2:
                    audioCodec="-c:a libvorbis";
                    break;
                case 3:
                    audioCodec="-c:a copy";
                    break;
                case 4:
                    audioCodec="-c:a libopus";
                    break;
                case 5:
                    audioCodec="-c:a flac";
                    break;
                }
            }
            else {
                switch(WEBMAudioCodecChoice->GetCurrentSelection()) {
                    case 0:
                        audioCodec="-c:a libvorbis";
                        break;
                    case 1:
                        audioCodec="-c:a libopus";
                        break;
                }
            }
    }
    //Audio tab - quality
    wxString audioQuality = "";
    if(AudioModeChoice->GetCurrentSelection()==0) {
        audioQuality.append("-b:a "+AudioBitrateChoice->GetString(AudioBitrateChoice->GetCurrentSelection())+"k");
    }
    else {
        audioQuality.append("-q:a "+AudioQualityChoice->GetString(AudioQualityChoice->GetCurrentSelection()));
    }
    //Finishing command build
    executeCommand.append(" -x265-params log-level=error -strict -2 -c:v "+videoCodec+" "+videoCRF+" "+videoEncoderProfile+" "+videoEncoderTune+" -preset:v "+videoEncoderPreset+" "+audioCodec+" "+audioQuality+" "+executeFilters+" \"" + OutputMediaFilepath + "\"");
    consoleLog->AppendText("\nExecuting command: "+executeCommand);
    wxStopWatch sw;
    wxArrayString exOut, exErr;
    int pid = wxExecute(executeCommand,exOut,exErr,wxEXEC_SYNC);
    if (pid==0) {   // on return code 0 i.e on successful encode
        wxLogStatus("Encode finished after %ldms", sw.Time());
        if (!exErr.IsEmpty()) {
            for (size_t i=0;i<exErr.GetCount();i++) {
                consoleLog->AppendText("\n"+exErr[i]);
            }
        }
        consoleLog->AppendText("\nEncode finished successfully");
        int successChoice = 5105;
        successChoice = SuccessDialog->ShowModal();
        switch(successChoice) {
        case 5103:  // equals to wxYES
            break;
        case 5104: { // equals to wxNO
            wxString launchDefault = "explorer ";
            launchDefault<<OutputMediaFilepath;
            wxExecute( launchDefault, wxEXEC_ASYNC, NULL);
            break; }
        default:
            wxLogError("Wrong choice!");
            break;
        }
    }
    else {      // if encode failed, return code not 0
        if (!exErr.IsEmpty()) {
            for (size_t i=0;i<exErr.GetCount();i++) {
                consoleLog->AppendText("\n"+exErr[i]);
            }
        }
        wxLogError("Encoding failed!");
    }

//    wxArrayString errors, output;
//    wxExecute(executeCommand, errors, output,9);
//    if(output.IsEmpty()) {
//            wxMessageBox("empty", _("empty"));
//    }
//    else {
//        for (int i=0;i<output.GetCount();i++) {
//            consoleLog->AppendText(output[i]<<"\n");
//        }
//    }
}


void ffEncodeGUIFrame::OnCheckUpdateSelected(wxCommandEvent& event)
{
    wxString noUpdateAvailable = "No updates available at the moment";
    wxString yesUpdateAvailable =  "New version available: v";
    wxFileSystem fs;
    wxFSFile *file=fs.OpenFile(wxT("http://127.0.0.1/zaliczenieProgramVer.xml"));
    if(file!=NULL) {
        wxInputStream *in = file->GetStream();
        if(in!=NULL) {
            wxXmlDocument programVer;
            programVer.Load(*in);
            if(programVer.IsOk()) {
                wxXmlNode *child = programVer.GetRoot()->GetChildren();
                while (child) {
                if (child->GetName() == "version") {
                    wxString content = child->GetNodeContent();
                    int vernum = wxAtoi(content);
                    if (vernum>CURRENT_VER) {
                        yesUpdateAvailable<<vernum<<"\nVisit our website to download the update.";
                        wxMessageBox(yesUpdateAvailable, _("Information"));}
                    else
                        wxMessageBox(noUpdateAvailable, _("Information"));
                    }
                child = child->GetNext();
                }
            }
            delete in;
            programVer.~wxXmlDocument();
            }
        }
        else {
            wxMessageBox("Couldn't check for updates.", _("Information"));
        }
}

void ffEncodeGUIFrame::OnEncoderSliderUpdated(wxScrollEvent& event)
{
    switch(event.GetPosition()) {
    case 0:
        PresetLabel->SetLabel("Ultrafast");
        break;
    case 1:
        PresetLabel->SetLabel("Superfast");
        break;
    case 2:
        PresetLabel->SetLabel("Veryfast");
        break;
    case 3:
        PresetLabel->SetLabel("Faster");
        break;
    case 4:
        PresetLabel->SetLabel("Fast");
        break;
    case 5:
        PresetLabel->SetLabel("Medium");
        break;
    case 6:
        PresetLabel->SetLabel("Slow");
        break;
    case 7:
        PresetLabel->SetLabel("Slower");
        break;
    case 8:
        PresetLabel->SetLabel("Veryslow");
        break;
    case 9:
        PresetLabel->SetLabel("Placebo");
        break;
    default:
        break;
    }
}

void ffEncodeGUIFrame::OnWEBMVideoCodecChoiceSelect(wxCommandEvent& event)
{
    if (webmOnly) {
        switch(event.GetSelection()) {
        case 0:
            crfSlider->SetMin(4);
            crfSlider->SetMax(63);
            break;
        case 1:
            crfSlider->SetMin(0);
            crfSlider->SetMax(63);
            break;
        }
    }
}

void ffEncodeGUIFrame::OnVideoCodecChoiceSelect(wxCommandEvent& event)
{
    if (!webmOnly) {
        crfSlider->SetMin(0);
        crfSlider->SetMax(51);
    }
    if (event.GetSelection()==1) {
        EncoderProfile->Show(0);
        EncoderTune->Show(0);
        EncoderProfile265->Show(1);
        EncoderTune265->Show(1);
    }
    else {
        EncoderProfile->Show(1);
        EncoderTune->Show(1);
        EncoderProfile265->Show(0);
        EncoderTune265->Show(0);
    }
}

void ffEncodeGUIFrame::OnAudioInclueCheckBoxClick(wxCommandEvent& event)
{
    if (!event.IsChecked()) {
        AudioCodecChoice->Disable();
        WEBMAudioCodecChoice->Disable();
        InteriorAudioPanel->Disable();
    }
    else {
        AudioCodecChoice->Enable();
        WEBMAudioCodecChoice->Enable();
        InteriorAudioPanel->Enable();
    }
}

void ffEncodeGUIFrame::OnAudioQualityModeChange(wxCommandEvent& event)
{
    switch(event.GetSelection()) {
    case 0:
        AudioBitrateChoice->Show(1);
        AudioQualityChoice->Show(0);
        break;
    case 1:
        AudioBitrateChoice->Show(0);
        AudioQualityChoice->Show(1);
        break;
    }
}

void ffEncodeGUIFrame::OnAudioQualityChoiceSelect(wxCommandEvent& event)
{
}

void ffEncodeGUIFrame::OnAudioCodecChoiceSelect(wxCommandEvent& event)
{
    if (event.GetSelection()==3 || WEBMAudioCodecChoice->GetSelection()==2)
        InteriorAudioPanel->Show(0);
    else
        InteriorAudioPanel->Show(1);
    if(event.GetSelection()==4 || event.GetSelection()==5 || WEBMAudioCodecChoice->GetSelection()==1) {
        AudioModeChoice->SetSelection(0);
        AudioModeChoice->Disable();
        AudioBitrateChoice->Show(1);
        AudioQualityChoice->Show(0);
    }
    else {

        AudioModeChoice->Enable();
    }
}

void ffEncodeGUIFrame::OnDimensionsSelected(wxCommandEvent& event)
{
    if (!event.IsChecked()) {
            VideoWidthChange->Disable();
            VideoHeightChange->Disable();
    }
    else {
            VideoWidthChange->Enable();
            VideoHeightChange->Enable();
    }
}

void ffEncodeGUIFrame::OnCropVideoSelected(wxCommandEvent& event)
{
    if (!event.IsChecked()) {
            CropTop->Disable();
            CropLeft->Disable();
            CropBottom->Disable();
            CropRight->Disable();
    }
    else {
            CropTop->Enable();
            CropLeft->Enable();
            CropBottom->Enable();
            CropRight->Enable();
    }
}

void ffEncodeGUIFrame::OnOutputFilePickerFileChanged(wxFileDirPickerEvent& event)
{
    EncodeButton->Enable();
    OutputMediaFilepath = OutputFilePicker->GetPath();
    if(OutputMediaFilepath.EndsWith(".webm")) {
        webmOnly = true;
        EncoderTuneProfile->Show(0);
        WEBMVideoCodecChoice->Show(1);
        VideoCodecChoice->Show(0);
        AudioCodecChoice->Show(0);
        WEBMAudioCodecChoice->Show(1);
        WEBMVideoCodecChoice->SetSelection(0);
        crfSlider->SetMin(4);
        crfSlider->SetMax(63);
    }
    else {
        webmOnly = false;
        EncoderTuneProfile->Show(1);
        WEBMVideoCodecChoice->Show(0);
        VideoCodecChoice->Show(1);
        AudioCodecChoice->Show(1);
        WEBMAudioCodecChoice->Show(0);
        crfSlider->SetMin(0);
        crfSlider->SetMax(51);
    }
    consoleLog->AppendText("Output path set: "+OutputMediaFilepath+"\n");
    wxLogStatus("Ready to encode.");

}

void ffEncodeGUIFrame::OnClearConsoleButtonClick(wxCommandEvent& event)
{
    consoleLog->Clear();
}
