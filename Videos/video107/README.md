# README - Video 107

17 September 2026

# Scope
This is video 107 on a Home Assistant LVGL embedded solution. This tutorial should help you deploy your own Thread network and add your own Matter devices.  This project demonstrates the integration of Matter over Thread using Home Assistant, Matter devices and ESPHome with LVGL graphics.  The Test Rig consists of an ESP32-C5 N8R8 USB Device and a ST7796 (320x480) touchscreen display.  Additionally, a Xaio ESP32-C6 board was used to host the Open Thread Border Router (OTBR).

In this video:
    • Demonstrate the Matter Smart Plug operating via LVGL graphics
    • We briefly explain Matter and Thread
    • We explain and demonstrate five Setup Steps and OTBR deployment
    • We discuss the technical challenges

Besides the demonstration, there are six hands-on video segments.
The videos cover the Setup and the installation:

Step 1 Initial Configuration    7:55
Step 2 OTBR Deployment         14:00
Step 3 Transition to Thread    18:17
Step 4 Matter Server && Comm.  19:24
Step 5 LVGL Intg. & Final.     25:25
OTBR Firmware Instructions     32:00
 
The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA/tree/main/Videos/video107


# Files

 - YAML
These are copies of the smartc5 YAML at various steps of the Setup as described in the Video. There are four files as some of the configuration occurs within Home Assistant.
You should create your own ESPHome device, and then copy and paste from the files as needed.

 - smartc5-step1.yaml
 - smartc5-step3.yaml
 - smartc5-step5.yaml
 - smartc5-final.yaml