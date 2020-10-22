#include "MainComponent.h"
MainComponent::MainComponent() :
	testProgramLabelLabel("testProgramLabelLabel", "Test program with file"),
	testProgramQueryLabel("testProgramQueryLabel", "Query list:"),
	testProgramOutputLabel("testProgramOutputLabel", "Output:"),
	inputDataLabel("inputDataLabel", "Input data:"),
	getTextButton("Get"),
	testProgramTestTextButton("Test"),
	testProgramSelectFileTextButton("SelectFile"),
	queryLabel("queryLabel", "Query:"),
	outputLabel("outputLabel", "Output data:")
{
	size_t windowW = 1280;
	size_t windowH = 720;
	setSize(windowW, windowH);
	inputDataLabel.setTopLeftPosition(15, 5);
	inputDataLabel.setSize(300, 40);
	inputDataLabel.setFont(juce::Font(24.f));
	addAndMakeVisible(inputDataLabel);
	//
	inputDataTextEditor.setTopLeftPosition(10, 40);
	inputDataTextEditor.setSize(800, 400);
	inputDataTextEditor.setMultiLine(true);
	inputDataTextEditor.setReturnKeyStartsNewLine(true);
	inputDataTextEditor.setTabKeyUsedAsCharacter(true);
	inputDataTextEditor.setFont(juce::Font(18.f));
	addAndMakeVisible(inputDataTextEditor);
	//
	queryLabel.setTopLeftPosition(15, 450);
	queryLabel.setSize(300, 40);
	queryLabel.setFont(juce::Font(24.f));
	addAndMakeVisible(queryLabel);
	//
	queryTextEditor.setTopLeftPosition(10, 490);
	queryTextEditor.setSize(600, 40);
	queryTextEditor.setTabKeyUsedAsCharacter(true);
	queryTextEditor.setFont(juce::Font(18.f));
	queryTextEditor.setJustification(juce::Justification::centredLeft);
	addAndMakeVisible(queryTextEditor);
	//
	getTextButton.setTopLeftPosition(615, 490);
	getTextButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);
	getTextButton.setSize(185, 40);
	getTextButton.onClick = [&]() {
		StandartParser parser;
		outputTextEditor.setText(parser.parse(inputDataTextEditor.getText().toStdString(), queryTextEditor.getText().toStdString()));
	};
	addAndMakeVisible(getTextButton);
	//
	outputLabel.setTopLeftPosition(15, 540);
	outputLabel.setSize(300, 40);
	outputLabel.setFont(juce::Font(24.f));
	addAndMakeVisible(outputLabel);
	//
	outputTextEditor.setTopLeftPosition(10, 580);
	outputTextEditor.setSize(800, 40);
	outputTextEditor.setTabKeyUsedAsCharacter(true);
	outputTextEditor.setFont(juce::Font(18.f));
	outputTextEditor.setJustification(juce::Justification::centredLeft);
	outputTextEditor.setMultiLine(true);
	outputTextEditor.setReturnKeyStartsNewLine(true);
	outputTextEditor.setTabKeyUsedAsCharacter(true);
	outputTextEditor.setEnabled(false);
	addAndMakeVisible(outputTextEditor);
	//////////////#########################
	testProgramLabelLabel.setTopLeftPosition(windowW - 340, 30);
	testProgramLabelLabel.setSize(300, 40);
	testProgramLabelLabel.setFont(juce::Font(32.f));
	testProgramLabelLabel.setColour(juce::Label::ColourIds::backgroundColourId, juce::Colours::red);
	addAndMakeVisible(testProgramLabelLabel);
	//
	testProgramSelectFileTextButton.setTopLeftPosition(windowW - 250, 90);
	testProgramSelectFileTextButton.setSize(130, 50);
	testProgramSelectFileTextButton.onClick = [&]() {
		/*fileExplorer.browseForFileToOpen();
		juce::String name = fileExplorer.getResult().getFullPathName();*/
	};
	addAndMakeVisible(testProgramSelectFileTextButton);
	//
	testProgramQueryLabel.setTopLeftPosition(windowW - 340, 140);
	testProgramQueryLabel.setSize(200, 40);
	testProgramQueryLabel.setFont(juce::Font(24.f));
	addAndMakeVisible(testProgramQueryLabel);
	//
	testProgramQueryTextEditor.setTopLeftPosition(windowW - 340, 180);
	testProgramQueryTextEditor.setSize(330, 140);
	testProgramQueryTextEditor.setMultiLine(true);
	testProgramQueryTextEditor.setReturnKeyStartsNewLine(true);
	testProgramQueryTextEditor.setTabKeyUsedAsCharacter(true);
	testProgramQueryTextEditor.setFont(juce::Font(18.f));
	testProgramQueryTextEditor.setEnabled(false);
	addAndMakeVisible(testProgramQueryTextEditor);
	//
	testProgramOutputLabel.setTopLeftPosition(windowW - 340, 330);
	testProgramOutputLabel.setSize(200, 40);
	testProgramOutputLabel.setFont(juce::Font(24.f));
	addAndMakeVisible(testProgramOutputLabel);
	//
	testProgramOutputTextEditor.setTopLeftPosition(windowW - 340, 380);
	testProgramOutputTextEditor.setSize(330, 140);
	testProgramOutputTextEditor.setMultiLine(true);
	testProgramOutputTextEditor.setReturnKeyStartsNewLine(true);
	testProgramOutputTextEditor.setTabKeyUsedAsCharacter(true);
	testProgramOutputTextEditor.setFont(juce::Font(18.f));
	testProgramOutputTextEditor.setEnabled(false);
	addAndMakeVisible(testProgramOutputTextEditor);
	//
	testProgramTestTextButton.setTopLeftPosition(windowW - 250, 530);
	testProgramTestTextButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);
	testProgramTestTextButton.setSize(130, 50);
	testProgramTestTextButton.onClick = [&]() {
		/*fileExplorer.browseForFileToOpen();
		juce::String name = fileExplorer.getResult().getFullPathName();*/
	};
	addAndMakeVisible(testProgramTestTextButton);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

	g.setFont(juce::Font(26.f));
	g.setColour(juce::Colours::grey);
	g.drawText("Zagrava test task", getLocalBounds(), juce::Justification::centredTop, true);
}

void MainComponent::resized()
{

}
