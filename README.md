# Simple Low-Pass Guitar Filter Plugin

A real-time audio plugin that applies a low-pass filter to guitar input with a GUI knob to control the cutoff frequency. Built using the JUCE framework for macOS (Apple Silicon).

## Features

- **Low-pass filter** with adjustable cutoff frequency (20 Hz - 20 kHz)
- **Real-time parameter control** via rotary knob GUI
- **Modern, intuitive interface** with gradient background
- **Multiple plugin formats**: AudioUnit (AU) and VST3
- **Optimized for guitar processing** with logarithmic frequency scaling

## Built Plugin Formats

- **AudioUnit (AU)**: `SimpleLowPass.component`
- **VST3**: `SimpleLowPass.vst3`

## Installation

### Plugin Installation Locations

After building, copy the plugins to the appropriate system directories:

#### AudioUnit (AU)
```bash
cp -r build/SimpleLowPassPlugin_artefacts/AU/SimpleLowPass.component ~/Library/Audio/Plug-Ins/Components/
```

#### VST3
```bash
cp -r build/SimpleLowPassPlugin_artefacts/VST3/SimpleLowPass.vst3 ~/Library/Audio/Plug-Ins/VST3/
```

## Usage

1. **Load the plugin** in your DAW (Logic Pro, GarageBand, Reaper, etc.)
2. **Connect your guitar** to your audio interface
3. **Insert the plugin** on the guitar track
4. **Adjust the cutoff frequency** using the orange rotary knob:
   - **Lower values** (20-500 Hz): Remove high frequencies for a muffled, warm tone
   - **Mid values** (500-2000 Hz): Reduce harshness while maintaining clarity
   - **Higher values** (2000-20000 Hz): Subtle high-frequency roll-off

## Technical Specifications

- **Sample Rate**: Supports all standard rates (44.1 kHz, 48 kHz, 96 kHz, etc.)
- **Bit Depth**: 32-bit floating point processing
- **Channels**: Stereo input/output
- **Latency**: Zero latency (real-time processing)
- **Filter Type**: IIR Low-pass filter with smooth frequency response

## Build Requirements

- macOS (Apple Silicon recommended)
- Xcode (latest version)
- CMake 3.15 or higher
- JUCE framework (included as submodule)

## Building from Source

1. **Clone and setup**:
   ```bash
   git clone <repository-url>
   cd SimpleLowPassPlugin
   ```

2. **Build the plugin**:
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build . --config Release
   ```

3. **Install plugins** (optional):
   ```bash
   # Install AU
   cp -r SimpleLowPassPlugin_artefacts/AU/SimpleLowPass.component ~/Library/Audio/Plug-Ins/Components/
   
   # Install VST3
   cp -r SimpleLowPassPlugin_artefacts/VST3/SimpleLowPass.vst3 ~/Library/Audio/Plug-Ins/VST3/
   ```

## Project Structure

```
SimpleLowPassPlugin/
├── CMakeLists.txt                          # Build configuration
├── README.md                               # This file
├── JUCE/                                   # JUCE framework (submodule)
├── Source/
│   ├── SimpleLowPassAudioProcessor.h       # Plugin processor header
│   ├── SimpleLowPassAudioProcessor.cpp     # Plugin processor implementation
│   ├── SimpleLowPassAudioProcessorEditor.h # GUI editor header
│   └── SimpleLowPassAudioProcessorEditor.cpp # GUI editor implementation
└── build/
    └── SimpleLowPassPlugin_artefacts/
        ├── AU/SimpleLowPass.component       # AudioUnit plugin
        └── VST3/SimpleLowPass.vst3         # VST3 plugin
```

## Plugin Parameters

| Parameter | Range | Default | Description |
|-----------|-------|---------|-------------|
| Cutoff Frequency | 20 Hz - 20 kHz | 1000 Hz | Low-pass filter cutoff frequency |

## Compatibility

- **macOS**: 10.15 (Catalina) or later
- **Architecture**: Universal (Intel x64 + Apple Silicon ARM64)
- **DAWs**: Logic Pro, GarageBand, Reaper, Pro Tools, Ableton Live, and more

## License

This project is built using the JUCE framework. Please refer to JUCE licensing terms for commercial use.

## Troubleshooting

### Plugin Not Appearing in DAW
1. Ensure plugins are copied to the correct directories
2. Restart your DAW after installation
3. Check DAW plugin scan/validation settings

### Audio Issues
1. Verify audio interface is properly configured
2. Check sample rate compatibility
3. Ensure plugin is inserted on the correct track

## Development Notes

- Uses JUCE 8.x framework with modern C++17 features
- Implements real-time safe audio processing
- GUI built with JUCE's native components
- Parameter automation supported via AudioProcessorValueTreeState 