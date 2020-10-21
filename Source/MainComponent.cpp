#include "MainComponent.h"


MainComponent::MainComponent()
{
	setSize(600, 400);



	/*std::string inputData("<tag><tag2></tag2><tag1><tag1 arg = \"is work\"></tag1></tag1></tag>");
	std::string query("tag.tag1.tag1~arg");
	std::vector<std::shared_ptr<BaseZGMLOperator>> useSymbols;
	useSymbols.push_back(std::make_shared<DotOperator>());
	useSymbols.push_back(std::make_shared<TildeOperator>());
	std::shared_ptr<BaseZGMLOperator> baseSymbol = std::make_shared<DotOperator>();
	Parser p;
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::string re =p.parse(inputData, query, useSymbols, baseSymbol);*/
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

	g.setFont(juce::Font(16.0f));
	g.setColour(juce::Colours::white);
	g.drawText("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
}
