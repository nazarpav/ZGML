#pragma once
#include <JuceHeader.h>
#include "StandartParser.h"
#include "InputFileParser.h"

class MainComponent  : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;
    void paint (juce::Graphics&) override;
    void resized() override;
private:
    InputFileParser inputFileParser;
    std::string inputFileName;
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
    juce::TextEditor testProgramOutputTextEditor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
