# README.md - Video116

13 November 2026

# Scope
This is video 116 on a Home Assistant ESPHome/LVGL embedded solution. In today’s video we configure ESPHome and Home Assistant to provide a portable solution to managing a shareable Grocery List for a group of people.  It features a high-resolution 410x502 pixel capacitive touch display and an integrated lithium battery.  Furthermore, the inclusion of a built-in speaker and dual microphones allows for sophisticated voice-command processing, making it an ideal candidate for testing the Local AI capabilities of Home Assistant.  

Our hardware is the Waveshare ESP32-S3 Touch-AMOLED-2.06 device. 
 
In this video, 
 - Demonstrate the Smart Watch and notifications.
 - Review the steps to deploy the software.
 - Discuss technical aspects of the I2S Audio.
 - Review the screen design and actions across the screens.

The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA/tree/main/Videos/video116

# Files
We suggest several steps:

- Create the ESPHome device to ensure Wifi is working, and you enabled Home Assistant actions. Please use parts from the file initial_mywatch.yaml.  This has no GUI screens, so ESPHome autmatically gives you a test LVGL screen.  You are ready, when you have a working test LVGL screen.
- Now use insert parts from mywatch.yaml into your device.  This has the full configuration of sensors, scripts, animations, images, and LVGL screens.  You are ready, when you have a working main screen and the four information screens.
- Now, use the automations.txt to create four Automation objects in Home Assistant.


# Source
This is a source json to be opened by LCD Wizard.  It presents the original GUI screens.  Please keep identities (id:) as-is.  The simpliest case is to replace all text values and labels with your local language or wording.  When ready, perform an Export.

The export will contain three items: (1) an example YAML, (2) a folder of images, and (3) a README.md.
Within the YAML you may have general ESPHome statements, display and touchscreen setup, scripts, images, and a LVGL section.  Unless you changed a script or image you should not need to change them.  We show a simple LVGL section below.
You can carefully replace everything below 'pages:'.  

<H2>LVGL Section</H2>

```
lvgl:
  displays:
    - panel
  touchscreens:
    - touch
  default_font: montserrat_24
  buffer_size: 25%
  pages:
```