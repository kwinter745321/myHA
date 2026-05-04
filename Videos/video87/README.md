# README - Video 87

04 May 2026

# Scope
This is video 87 on a Home Assistant ESPHome/LVGL embedded solution. In this video, we look at the 2026.4 Release and update to LVGL 9.5.  The release is briefly discussed.  We demonstrate a simple LVGL 9.5 screen on two Test Rigs.  The demo shows buttons performing a rapid screen rotation. All four orientations are shown and the slider is tested at each orientation. 

There are two Test Rigs: (1) a Raspberry Pi Pico-W with ILI9341 Display, and (2) an ESP32-S3 with ILI9488 Display. The wiring for each is provided.  You can fetch the firmware and programs from our GitHub site, and begin using them immediately.  

In this video, 
 - Look at the 2026.4 Release.
 - Demonstrate a simple screen with a slider and buttons; there is runtime rotation.
 - Review the Knob specifications and how we created the Test Rig.
 - Discuss the Test Rigs and wiring.
 - Explain the release in a little more detail.
 - Review the the display and rotation configuration.

The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA/tree/main/Videos/video87

# Files

- YAML
  - infodash.yaml  (ESP32-S3 Test Rig ESPHome YAML Configuration)
  - picodash.yaml  (RPI Pico-W Test Rig ESPHome YAML Configuration)
