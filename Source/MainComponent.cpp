#include "MainComponent.h"
void MainComponent::DrawColurText(juce::TextEditor& output, const juce::String& data, const ZGMLOperatorReturnValue& type, bool isAppend = false)
{
	if (!isAppend)
		output.clear();
	if (type == ZGMLOperatorReturnValue::CorrectExit) {
		output.insertTextAtCaret(data);
		return;
	}
	switch (type)
	{
	case ZGMLOperatorReturnValue::Error:
		output.setFont(juce::Font(defaulthFont.getHeightInPoints(), juce::Font::bold));
		output.setColour(juce::TextEditor::ColourIds::textColourId, juce::Colours::red);
		break;
	case  ZGMLOperatorReturnValue::Warning:
		output.setFont(juce::Font(defaulthFont.getHeightInPoints(), juce::Font::bold));
		output.setColour(juce::TextEditor::ColourIds::textColourId, juce::Colours::yellow);
		break;
	}
	output.insertTextAtCaret(data);
	output.setFont(defaulthFont);
	output.setColour(juce::TextEditor::ColourIds::textColourId, juce::Colours::white);
}
MainComponent::MainComponent() :
	testProgramLabelLabel("testProgramLabelLabel", "Test program with file"),
	testProgramQueryLabel("testProgramQueryLabel", "Queries:"),
	testProgramOutputLabel("testProgramOutputLabel", "Output:"),
	inputDataLabel("inputDataLabel", "Input data:"),
	getTextButton("Get"),
	loadIputDataFromFileTextButton("Load input data from file"),
	testProgramTestTextButton("Test"),
	testProgramSelectFileTextButton("SelectFile"),
	queryLabel("queryLabel", "Query:"),
	outputLabel("outputLabel", "Output data:"),
	isAllowWhiteSpaceInQuery("is allow white space in query"),
	testProgramInputFileDataLabel("testProgramInputFileDataLabel", "InputFileData"),
	testProgramOutput2Label("testProgramOutput2Label", "Output:"),
	testProgramTest2TextButton("Test"),
	testProgramInputFileDataLoadFromFileTextButton("Load from file"),
	inputFileName(""),
	defaulthFont(juce::Font(20.f))
{
	size_t windowW = 1280;
	size_t windowH = 720;
	setSize(windowW, windowH);
	inputDataLabel.setTopLeftPosition(15, 5);
	inputDataLabel.setSize(300, 40);
	inputDataLabel.setFont(defaulthFont);
	addAndMakeVisible(inputDataLabel);
	//
	loadIputDataFromFileTextButton.setTopLeftPosition(150, 8);
	loadIputDataFromFileTextButton.setSize(200, 30);
	loadIputDataFromFileTextButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::green);
	loadIputDataFromFileTextButton.onClick = [this]()->void {
		juce::FileChooser fileExplorer("Select file");
		fileExplorer.browseForFileToOpen();
		auto inputFile = fileExplorer.getResult().getFullPathName().toStdString();
		if (inputFileName.size() == 0)
		{
			inputDataTextEditor.setText("Please, select file");
		}
		inputDataTextEditor.setText(inputFileParser.ParseFromFileGetInputData(inputFile));
	};
	addAndMakeVisible(loadIputDataFromFileTextButton);
	//
	inputDataTextEditor.setTopLeftPosition(10, 40);
	inputDataTextEditor.setSize(800, 400);
	inputDataTextEditor.setMultiLine(true);
	inputDataTextEditor.setReturnKeyStartsNewLine(true);
	inputDataTextEditor.setTabKeyUsedAsCharacter(true);
	inputDataTextEditor.setFont(defaulthFont);
	addAndMakeVisible(inputDataTextEditor);
	//
	queryLabel.setTopLeftPosition(15, 450);
	queryLabel.setSize(300, 40);
	queryLabel.setFont(defaulthFont);
	addAndMakeVisible(queryLabel);
	//
	queryTextEditor.setTopLeftPosition(10, 490);
	queryTextEditor.setSize(600, 40);
	queryTextEditor.setTabKeyUsedAsCharacter(true);
	queryTextEditor.setFont(defaulthFont);
	queryTextEditor.setJustification(juce::Justification::centredLeft);
	addAndMakeVisible(queryTextEditor);
	//
	getTextButton.setTopLeftPosition(615, 490);
	getTextButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);
	getTextButton.setSize(185, 40);
	getTextButton.onClick = [this]()->void {
		StandartParser parser;
		ZGMLOperatorReturnValue resultIdentificator;
		std::string result = parser.parse(inputDataTextEditor.getText().toStdString(), queryTextEditor.getText().toStdString(), resultIdentificator, isAllowWhiteSpaceInQuery.getToggleState());
		DrawColurText(outputTextEditor, result, resultIdentificator);
	};
	addAndMakeVisible(getTextButton);
	//
	outputLabel.setTopLeftPosition(15, 540);
	outputLabel.setSize(300, 40);
	outputLabel.setFont(defaulthFont);
	addAndMakeVisible(outputLabel);
	//
	outputTextEditor.setTopLeftPosition(10, 580);
	outputTextEditor.setSize(800, 40);
	outputTextEditor.setTabKeyUsedAsCharacter(true);
	outputTextEditor.setFont(defaulthFont);
	outputTextEditor.setJustification(juce::Justification::centredLeft);
	outputTextEditor.setMultiLine(true);
	outputTextEditor.setReturnKeyStartsNewLine(true);
	outputTextEditor.setEnabled(false);
	addAndMakeVisible(outputTextEditor);
	//
	isAllowWhiteSpaceInQuery.setTopLeftPosition(10, 680);
	isAllowWhiteSpaceInQuery.setSize(200, 40);
	isAllowWhiteSpaceInQuery.setColour(juce::ToggleButton::ColourIds::textColourId, juce::Colours::orange);
	addAndMakeVisible(isAllowWhiteSpaceInQuery);
	//////////////#########################
	testProgramLabelLabel.setTopLeftPosition(windowW - 370, 30);
	testProgramLabelLabel.setSize(330, 40);
	testProgramLabelLabel.setFont(juce::Font(32.f));
	testProgramLabelLabel.setColour(juce::Label::ColourIds::backgroundColourId, juce::Colours::red);
	addAndMakeVisible(testProgramLabelLabel);
	//
	testProgramSelectFileTextButton.setTopLeftPosition(windowW - 270, 90);
	testProgramSelectFileTextButton.setSize(130, 50);
	testProgramSelectFileTextButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::yellow);
	testProgramSelectFileTextButton.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
	testProgramSelectFileTextButton.onClick = [this]()->void {
		juce::FileChooser fileExplorer("Select file");
		fileExplorer.browseForFileToOpen();
		inputFileName = fileExplorer.getResult().getFullPathName().toStdString();
		if (inputFileName.size() == 0)
		{
			testProgramOutputTextEditor.setText("Please, select file");
		}
		std::vector<std::string> queries;
		std::string error;
		if (inputFileParser.ParseFromFileGetQueries(inputFileName, queries, error))
		{
			std::string queriesList;
			for (auto item : queries)
			{
				queriesList += item + "\n";
			}
			testProgramQueryTextEditor.setText(queriesList);
		}
		else {
			testProgramQueryTextEditor.setText(error);
		}
	};
	addAndMakeVisible(testProgramSelectFileTextButton);
	//
	testProgramQueryLabel.setTopLeftPosition(windowW - 380, 140);
	testProgramQueryLabel.setSize(200, 40);
	testProgramQueryLabel.setFont(defaulthFont);
	addAndMakeVisible(testProgramQueryLabel);
	//
	testProgramQueryTextEditor.setTopLeftPosition(windowW - 380, 180);
	testProgramQueryTextEditor.setSize(360, 140);
	testProgramQueryTextEditor.setMultiLine(true);
	testProgramQueryTextEditor.setReturnKeyStartsNewLine(true);
	testProgramQueryTextEditor.setTabKeyUsedAsCharacter(true);
	testProgramQueryTextEditor.setFont(defaulthFont);
	testProgramQueryTextEditor.setEnabled(false);
	addAndMakeVisible(testProgramQueryTextEditor);
	//
	testProgramOutputLabel.setTopLeftPosition(windowW - 380, 330);
	testProgramOutputLabel.setSize(200, 40);
	testProgramOutputLabel.setFont(defaulthFont);
	addAndMakeVisible(testProgramOutputLabel);
	//
	testProgramOutputTextEditor.setTopLeftPosition(windowW - 380, 380);
	testProgramOutputTextEditor.setSize(360, 240);
	testProgramOutputTextEditor.setMultiLine(true);
	testProgramOutputTextEditor.setReturnKeyStartsNewLine(true);
	testProgramOutputTextEditor.setTabKeyUsedAsCharacter(true);
	testProgramOutputTextEditor.setFont(defaulthFont);
	testProgramOutputTextEditor.setEnabled(false);
	addAndMakeVisible(testProgramOutputTextEditor);
	//
	testProgramTestTextButton.setTopLeftPosition(windowW - 270, 630);
	testProgramTestTextButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);
	testProgramTestTextButton.setSize(130, 50);
	testProgramTestTextButton.onClick = [this]()->void {
		if (inputFileName.size() == 0) {
			testProgramOutputTextEditor.setText("Please, select file");
		}
		testProgramOutputTextEditor.setText("");
		std::vector<std::string> queries;
		std::string error;
		std::string input = inputFileParser.ParseFromFileGetInputData(inputFileName);
		if (inputFileParser.ParseFromFileGetQueries(inputFileName, queries, error))
		{
			StandartParser parser;
			ZGMLOperatorReturnValue resultIdentificator;
			std::string result;
			for (size_t i = 0; i < queries.size(); i++)
			{
				result = parser.parse(input, queries[i], resultIdentificator, isAllowWhiteSpaceInQuery.getToggleState());
				DrawColurText(testProgramOutputTextEditor, result, resultIdentificator, true);
				if (i < queries.size() - 1)
					testProgramOutputTextEditor.insertTextAtCaret("\n");
			}
		}
		else {
			testProgramQueryTextEditor.setText(error);
		}
	};
	addAndMakeVisible(testProgramTestTextButton);
	//
	testProgramInputFileDataLabel.setTopLeftPosition(15, 5);
	testProgramInputFileDataLabel.setSize(300, 40);
	testProgramInputFileDataLabel.setFont(defaulthFont);
	addAndMakeVisible(testProgramInputFileDataLabel);
	//
	testProgramInputFileDataLoadFromFileTextButton.setTopLeftPosition(150, 8);
	testProgramInputFileDataLoadFromFileTextButton.setSize(200, 30);
	testProgramInputFileDataLoadFromFileTextButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::green);
	testProgramInputFileDataLoadFromFileTextButton.onClick = [this]()->void {
		juce::FileChooser fileExplorer("Select file");
		fileExplorer.browseForFileToOpen();
		auto inputFile = fileExplorer.getResult().getFullPathName().toStdString();
		if (inputFileName.size() == 0)
		{
			testProgramInputFileDataTextEditor.setText("Please, select file");
		}
		testProgramInputFileDataTextEditor.setText(inputFileParser.ParseFromFileGetInputData(inputFile));
	};
	addAndMakeVisible(testProgramInputFileDataLoadFromFileTextButton);
	//
	testProgramInputFileDataTextEditor.setTopLeftPosition(10, 40);
	testProgramInputFileDataTextEditor.setSize(800, 250);
	testProgramInputFileDataTextEditor.setMultiLine(true);
	testProgramInputFileDataTextEditor.setReturnKeyStartsNewLine(true);
	testProgramInputFileDataTextEditor.setTabKeyUsedAsCharacter(true);
	testProgramInputFileDataTextEditor.setFont(defaulthFont);
	addAndMakeVisible(testProgramInputFileDataTextEditor);
	//
	testProgramTest2TextButton.setTopLeftPosition(600, 630);
	testProgramTest2TextButton.setSize(200, 30);
	testProgramTest2TextButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::orange);
	testProgramTest2TextButton.onClick = [this]()->void {
		if (inputFileName.size() == 0) {
			testProgramOutputTextEditor.setText("Please, select file");
		}
		testProgramOutputTextEditor.setText("");
		std::vector<std::string> queries;
		std::string error;
		std::string input = inputFileParser.ParseFromFileGetInputData(inputFileName);
		if (inputFileParser.ParseFromFileGetQueries(inputFileName, queries, error))
		{
			StandartParser parser;
			ZGMLOperatorReturnValue resultIdentificator;
			std::string result;
			for (size_t i = 0; i < queries.size(); i++)
			{
				result = parser.parse(input, queries[i], resultIdentificator, isAllowWhiteSpaceInQuery.getToggleState());
				DrawColurText(testProgramOutputTextEditor, result, resultIdentificator, true);
				if (i < queries.size() - 1)
					testProgramOutputTextEditor.insertTextAtCaret("\n");
			}
		}
		else {
			testProgramQueryTextEditor.setText(error);
		}
	};
	addAndMakeVisible(testProgramTest2TextButton);
	//
	testProgramOutput2Label.setTopLeftPosition(15, 280);
	testProgramOutput2Label.setSize(300, 40);
	testProgramOutput2Label.setFont(defaulthFont);
	addAndMakeVisible(testProgramOutput2Label);
	//
	testProgramOutput2TextEditor.setTopLeftPosition(10, 320);
	testProgramOutput2TextEditor.setSize(800, 280);
	testProgramOutput2TextEditor.setMultiLine(true);
	testProgramOutput2TextEditor.setReturnKeyStartsNewLine(true);
	testProgramOutput2TextEditor.setTabKeyUsedAsCharacter(true);
	testProgramOutput2TextEditor.setFont(defaulthFont);
	testProgramOutput2TextEditor.setEnabled(false);
	addAndMakeVisible(testProgramOutput2TextEditor);
	//
	swicher.setTopLeftPosition(300, 630);
	swicher.setSize(100, 40);
	swicher.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
	swicher.setRange(1.f, 2.f, 1.f);
	swicher.setValue(1.f);
	swicher.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 30);
	swicher.onValueChange = [this]() {
		if (swicher.getValue() == 1) {
			testProgramInputFileDataLabel.setVisible(false);
			testProgramInputFileDataTextEditor.setVisible(false);
			testProgramOutput2Label.setVisible(false);
			testProgramOutput2TextEditor.setVisible(false);
			testProgramTest2TextButton.setVisible(false);
			testProgramInputFileDataLoadFromFileTextButton.setVisible(false);
			//
			inputDataTextEditor.setVisible(true);
			queryTextEditor.setVisible(true);
			getTextButton.setVisible(true);
			loadIputDataFromFileTextButton.setVisible(true);
			inputDataLabel.setVisible(true);
			queryLabel.setVisible(true);
			outputLabel.setVisible(true);
			outputTextEditor.setVisible(true);
		}
		else {
			testProgramInputFileDataLabel.setVisible(true);
			testProgramInputFileDataTextEditor.setVisible(true);
			testProgramOutput2Label.setVisible(true);
			testProgramOutput2TextEditor.setVisible(true);
			testProgramTest2TextButton.setVisible(true);
			testProgramInputFileDataLoadFromFileTextButton.setVisible(true);
			//
			inputDataTextEditor.setVisible(false);
			queryTextEditor.setVisible(false);
			getTextButton.setVisible(false);
			loadIputDataFromFileTextButton.setVisible(false);
			inputDataLabel.setVisible(false);
			queryLabel.setVisible(false);
			outputLabel.setVisible(false);
			outputTextEditor.setVisible(false);
		}
	};
	addAndMakeVisible(swicher);
	//
	testProgramInputFileDataLabel.setVisible(false);
	testProgramInputFileDataTextEditor.setVisible(false);
	testProgramOutput2Label.setVisible(false);
	testProgramOutput2TextEditor.setVisible(false);
	testProgramTest2TextButton.setVisible(false);
	testProgramInputFileDataLoadFromFileTextButton.setVisible(false);
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
