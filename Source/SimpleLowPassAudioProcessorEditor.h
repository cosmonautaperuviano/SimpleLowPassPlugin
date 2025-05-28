#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include "SimpleLowPassAudioProcessor.h"

class SimpleLowPassAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    SimpleLowPassAudioProcessorEditor(SimpleLowPassAudioProcessor&);
    ~SimpleLowPassAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    SimpleLowPassAudioProcessor& audioProcessor;

    juce::Slider cutoffSlider;
    juce::Label cutoffLabel;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cutoffAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleLowPassAudioProcessorEditor)
}; 