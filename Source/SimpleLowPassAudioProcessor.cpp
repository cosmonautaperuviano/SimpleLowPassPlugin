#include "SimpleLowPassAudioProcessor.h"
#include "SimpleLowPassAudioProcessorEditor.h"

SimpleLowPassAudioProcessor::SimpleLowPassAudioProcessor()
    : AudioProcessor(BusesProperties()
                     .withInput("Input", juce::AudioChannelSet::stereo(), true)
                     .withOutput("Output", juce::AudioChannelSet::stereo(), true)),
      parameters(*this, nullptr, "Parameters",
                 {
                     std::make_unique<juce::AudioParameterFloat>("cutoff",
                                                                 "Cutoff Frequency",
                                                                 juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.25f),
                                                                 1000.0f)
                 })
{
}

void SimpleLowPassAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    juce::dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();

    lowPassFilter.prepare(spec);
    lowPassFilter.reset();
}

void SimpleLowPassAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear any output channels that don't contain input data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    // Get the cutoff frequency parameter value
    auto cutoffFreq = parameters.getRawParameterValue("cutoff")->load();
    
    // Update filter coefficients
    auto coefficients = juce::dsp::IIR::Coefficients<float>::makeLowPass(getSampleRate(), cutoffFreq);
    *lowPassFilter.state = *coefficients;

    // Create audio block and process
    juce::dsp::AudioBlock<float> block(buffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    lowPassFilter.process(context);
}

bool SimpleLowPassAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* SimpleLowPassAudioProcessor::createEditor()
{
    return new SimpleLowPassAudioProcessorEditor(*this);
}

// This creates new instances of the plugin
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SimpleLowPassAudioProcessor();
} 