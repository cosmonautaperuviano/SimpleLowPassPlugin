# 🚀 GitHub Actions Setup for Windows Build

## 📋 **Next Steps to Get Windows VST3:**

### 1. **Create GitHub Repository**
1. Go to [github.com](https://github.com) and log in as `cosmonautaperuviano`
2. Click **"New repository"**
3. Repository name: `SimpleLowPassPlugin`
4. Make it **Public** (required for free GitHub Actions)
5. **Don't** initialize with README (we already have files)
6. Click **"Create repository"**

### 2. **Push Your Code**
Run this command in your terminal:
```bash
git push -u origin main
```

### 3. **GitHub Actions Will Automatically Build**
Once pushed, GitHub will automatically:
- ✅ Build for **Windows** (VST3)
- ✅ Build for **macOS** (AU + VST3) 
- ✅ Build for **Linux** (VST3)

### 4. **Download Windows VST3**
1. Go to your repository: `https://github.com/cosmonautaperuviano/SimpleLowPassPlugin`
2. Click **"Actions"** tab
3. Click on the latest build
4. Scroll down to **"Artifacts"**
5. Download **"SimpleLowPass-Windows-VST3"**

### 5. **Install on Windows**
1. Extract the downloaded `.vst3` file
2. Copy to: `C:\Program Files\Common Files\VST3\`
3. Restart Ableton Live
4. Find plugin under **VST3** → **AI Music Lab** → **SimpleLowPass**

---

## 🔧 **Troubleshooting**

### **If Build Fails:**
- Check the **Actions** tab for error messages
- Most common issue: JUCE submodule not loading properly
- Solution: The workflow should handle this automatically

### **If No Artifacts:**
- Ensure repository is **Public** (private repos have limited free Actions)
- Check that the build completed successfully (green checkmark)

### **If Plugin Doesn't Load in Ableton:**
- Verify file is in correct Windows directory
- Check Ableton's VST3 settings in Preferences
- Try rescanning plugins in Ableton

---

## 🎯 **What Happens Next:**

Every time you:
1. **Push code changes** to GitHub
2. **GitHub Actions automatically rebuilds** all platforms
3. **Download latest Windows VST3** from Artifacts

This gives you a **free Windows build server** without needing a Windows machine!

---

## 📁 **Repository Structure:**
```
SimpleLowPassPlugin/
├── .github/workflows/build.yml    ← GitHub Actions configuration
├── Source/                         ← Your plugin code
├── CMakeLists.txt                  ← Build configuration
├── JUCE/                          ← JUCE framework (submodule)
└── README.md                      ← Documentation
```

## 🌟 **Ready to Push?**
Run: `git push -u origin main` 