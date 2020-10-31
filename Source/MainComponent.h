#pragma once
#include <JuceHeader.h>
#include "StandartParser.h"
#include "InputFileParser.h"
#include "ZGMLOperatorReturnValue.h"
class MainComponent : public juce::Component
{
private:
	void DrawColurText(juce::TextEditor& output, const juce::String& data, const ZGMLOperatorReturnValue& type, bool isAppend);
public:
	MainComponent();
	~MainComponent() override;
	void paint(juce::Graphics&) override;
	void resized() override;
private:
	const juce::Font defaulthFont;
	InputFileParser inputFileParser;
	std::string inputFileName;
	//
	juce::ToggleButton isAllowWhiteSpaceInQuery;
	//
	juce::TextEditor inputDataTextEditor;
	juce::TextEditor queryTextEditor;
	juce::TextButton getTextButton;
	juce::TextButton loadIputDataFromFileTextButton;
	juce::Label inputDataLabel;
	juce::Label queryLabel;
	juce::Label outputLabel;
	juce::TextEditor outputTextEditor;
	/////////////////////
	juce::TextButton testProgramSelectFileTextButton;
	juce::TextButton testProgramTestTextButton;
	juce::Label testProgramLabelLabel;
	juce::Label testProgramQueryLabel;
	juce::TextEditor testProgramQueryTextEditor;
	juce::Label testProgramOutputLabel;
	juce::TextEditor testProgramOutputTextEditor;//
	juce::Label testProgramInputFileDataLabel;
	juce::TextEditor testProgramInputFileDataTextEditor;
	juce::Label testProgramOutput2Label;
	juce::TextEditor testProgramOutput2TextEditor;
	juce::TextButton testProgramTest2TextButton;
	juce::TextButton testProgramInputFileDataLoadFromFileTextButton;
	//#########################
	juce::Slider swicher;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
