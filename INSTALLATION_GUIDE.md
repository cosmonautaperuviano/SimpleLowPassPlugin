# 🎵 SimpleLowPass Plugin Installation & Usage Guide

## ✅ Installation Status
- **AudioUnit (Logic Pro)**: ✅ Installed at `~/Library/Audio/Plug-Ins/Components/SimpleLowPass.component`
- **VST3 (Ableton Live)**: ✅ Installed at `~/Library/Audio/Plug-Ins/VST3/SimpleLowPass.vst3`

---

## 🎹 Using in Logic Pro

### 1. **Launch Logic Pro**
   - Open Logic Pro (restart if it was already running)
   - Logic will automatically scan for new AudioUnit plugins

### 2. **Load the Plugin**
   - Create or open a project
   - Add an audio track or select an existing one
   - Click the **Insert** slot on the channel strip
   - Navigate to: **Audio FX** → **AI Music Lab** → **SimpleLowPass**

### 3. **Alternative Method**
   - In the mixer, click an empty insert slot
   - Type "SimpleLowPass" in the search box
   - Select the plugin from the results

### 4. **Using the Plugin**
   - The GUI will open showing the orange rotary knob
   - **Rotate the knob** to adjust cutoff frequency (20 Hz - 20 kHz)
   - **Default setting**: 1000 Hz
   - **Lower values**: Warmer, more muffled guitar tone
   - **Higher values**: Brighter tone with subtle high-frequency roll-off

---

## 🎛️ Using in Ableton Live

### 1. **Launch Ableton Live**
   - Open Ableton Live (restart if it was already running)
   - Ableton will scan for new VST3 plugins on startup

### 2. **Rescan Plugins (if needed)**
   - Go to **Live** → **Preferences** → **Plug-Ins**
   - Click **Rescan** to force a plugin scan
   - Ensure **VST3 Plug-In System Folder** is enabled

### 3. **Load the Plugin**
   - Create or open a Live Set
   - Add an audio track or select an existing one
   - In the **Browser**, expand **Plug-ins** → **VST3**
   - Look for **AI Music Lab** → **SimpleLowPass**
   - Drag it onto your audio track

### 4. **Alternative Method**
   - Click on an empty **Audio Effects** slot on your track
   - In the device browser, navigate to **Audio Effects** → **VST3**
   - Find and double-click **SimpleLowPass**

### 5. **Using the Plugin**
   - The plugin window will open with the GUI
   - **Click and drag** the orange knob to adjust cutoff frequency
   - **Automation**: Right-click the knob → **Configure** to automate the parameter

---

## 🎸 Guitar Processing Tips

### **Frequency Ranges & Effects:**

| Frequency Range | Effect on Guitar |
|----------------|------------------|
| **20-100 Hz** | Removes all highs, very muffled, vintage radio effect |
| **100-300 Hz** | Warm, thick tone, removes pick attack |
| **300-800 Hz** | Smooth, creamy lead tone |
| **800-2000 Hz** | Balanced tone, slight warmth |
| **2000-5000 Hz** | Natural tone with gentle high-end taming |
| **5000+ Hz** | Subtle effect, removes harsh frequencies |

### **Musical Applications:**
- **Clean Guitar**: 2-8 kHz for smooth, warm cleans
- **Distorted Guitar**: 1-3 kHz to tame harshness
- **Lead Guitar**: 800 Hz - 2 kHz for creamy sustain
- **Rhythm Guitar**: 1-4 kHz to sit better in mix
- **Vintage Tones**: 300-800 Hz for classic warmth

---

## 🔧 Troubleshooting

### **Plugin Not Appearing in Logic Pro:**
1. Check that the AU is in: `~/Library/Audio/Plug-Ins/Components/`
2. Restart Logic Pro completely
3. Go to **Logic Pro** → **Preferences** → **Audio** → **Plug-in Manager**
4. Look for "SimpleLowPass" and ensure it's enabled
5. If not listed, click **Reset & Rescan Selection**

### **Plugin Not Appearing in Ableton Live:**
1. Check that the VST3 is in: `~/Library/Audio/Plug-Ins/VST3/`
2. Restart Ableton Live completely
3. Go to **Live** → **Preferences** → **Plug-Ins**
4. Ensure **Use VST3 Plug-In System Folder** is checked
5. Click **Rescan** button
6. Check **VST3 Plug-In Custom Folder** if using custom locations

### **GUI Not Opening:**
1. Try right-clicking the plugin and selecting "Open Plug-in Window"
2. Check if the plugin is processing audio (meters should show activity)
3. Try removing and re-adding the plugin

### **No Audio Processing:**
1. Ensure the plugin is inserted on the correct track
2. Check that audio is passing through the track
3. Verify the cutoff frequency isn't set too low (try 2000 Hz)
4. Check track input monitoring and record enable status

---

## 🎯 Quick Start Checklist

- [ ] Plugin installed in correct directory
- [ ] DAW restarted after installation
- [ ] Plugin appears in DAW's plugin list
- [ ] Plugin loads without errors
- [ ] GUI opens and displays correctly
- [ ] Knob responds to mouse input
- [ ] Audio processing works as expected
- [ ] Parameter automation works (if needed)

---

## 📞 Support

If you encounter issues:
1. Check the troubleshooting section above
2. Verify your macOS version is 10.15 (Catalina) or later
3. Ensure your DAW supports AU (Logic) or VST3 (Ableton) formats
4. Try the standalone version first to test basic functionality

**Standalone App Location**: `build/SimpleLowPassPlugin_artefacts/Standalone/SimpleLowPass.app` 