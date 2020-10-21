#pragma once
#include <JuceHeader.h>
#include"Parser.h"
#include "DotOperator.h"
#include "TildeOperator.h"

class MainComponent  : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::TextButton res;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
