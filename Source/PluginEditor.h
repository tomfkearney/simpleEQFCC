/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

struct CustomRotarySlider : juce::Slider
{
    CustomRotarySlider() : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox)
    {
    }
};

//==============================================================================
/**
*/
class SimpleEQFCCAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleEQFCCAudioProcessorEditor (SimpleEQFCCAudioProcessor&);
    ~SimpleEQFCCAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleEQFCCAudioProcessor& audioProcessor;
    
    std::vector<juce::Component*> getComps();
    
    CustomRotarySlider peakFreqSlider,
    peakGainSlider,
    peakQualitySlider,
    lowCutFreqSlider,
    highCutFreqSlider;
    
    CustomRotarySlider lowCutSlopeSlider, highCutSlopeSlider;
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleEQFCCAudioProcessorEditor)
};
