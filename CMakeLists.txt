cmake_minimum_required(VERSION 3.15)
project(SimpleLowPassPlugin VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(JUCE)

juce_add_plugin(SimpleLowPassPlugin
    COMPANY_NAME "AI Music Lab"
    BUNDLE_ID "com.aimusiclab.simplelowpass"
    PLUGIN_MANUFACTURER_CODE AILB
    PLUGIN_CODE LPF1
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "SimpleLowPass"
)

target_sources(SimpleLowPassPlugin PRIVATE
    Source/SimpleLowPassAudioProcessor.cpp
    Source/SimpleLowPassAudioProcessor.h
    Source/SimpleLowPassAudioProcessorEditor.cpp
    Source/SimpleLowPassAudioProcessorEditor.h
)

target_link_libraries(SimpleLowPassPlugin PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
    juce::juce_gui_basics
) 