#include "SimpleLowPassAudioProcessorEditor.h"

SimpleLowPassAudioProcessorEditor::SimpleLowPassAudioProcessorEditor(SimpleLowPassAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Set up the cutoff frequency slider
    cutoffSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    cutoffSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    cutoffSlider.setRange(20.0, 20000.0, 1.0);
    cutoffSlider.setValue(1000.0);
    cutoffSlider.setSkewFactorFromMidPoint(1000.0);
    cutoffSlider.setColour(juce::Slider::thumbColourId, juce::Colours::orange);
    cutoffSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::orange.withAlpha(0.7f));
    cutoffSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkgrey);
    addAndMakeVisible(cutoffSlider);

    // Set up the label
    cutoffLabel.setText("Cutoff Frequency", juce::dontSendNotification);
    cutoffLabel.setJustificationType(juce::Justification::centred);
    cutoffLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    cutoffLabel.setFont(juce::FontOptions(16.0f, juce::Font::bold));
    addAndMakeVisible(cutoffLabel);

    // Attach the slider to the parameter
    cutoffAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.parameters, "cutoff", cutoffSlider);

    // Set the plugin window size
    setSize(300, 200);
}

SimpleLowPassAudioProcessorEditor::~SimpleLowPassAudioProcessorEditor()
{
}

void SimpleLowPassAudioProcessorEditor::paint(juce::Graphics& g)
{
    // Create a modern gradient background
    juce::ColourGradient gradient(juce::Colours::darkslategrey, 0, 0,
                                  juce::Colours::black, 0, getHeight(), false);
    g.setGradientFill(gradient);
    g.fillAll();

    // Draw the plugin title
    g.setColour(juce::Colours::white);
    g.setFont(juce::FontOptions(24.0f, juce::Font::bold));
    g.drawFittedText("Simple Low-Pass Filter", getLocalBounds().removeFromTop(50),
                     juce::Justification::centred, 1);

    // Draw a subtle border
    g.setColour(juce::Colours::lightgrey.withAlpha(0.3f));
    g.drawRect(getLocalBounds(), 2);
}

void SimpleLowPassAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    
    // Reserve space for title
    bounds.removeFromTop(50);
    
    // Position the label
    cutoffLabel.setBounds(bounds.removeFromTop(30));
    
    // Position the slider in the remaining space
    auto sliderBounds = bounds.reduced(20);
    cutoffSlider.setBounds(sliderBounds);
} 