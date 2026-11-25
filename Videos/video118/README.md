# README.md - Video118

25 November 2026

# Scope
This is video 118 on a Home Assistant ESPHome/LVGL embedded solution.. In today’s video we try a Xiao ESP32-C5 mini board to replace the C6 device we used in Video 107. This tutorial can help you deploy your own Thread network and add your own Matter devices.  This project demonstrates the integration of Matter over Thread using Home Assistant, Matter devices and ESPHome with LVGL graphics.  The Test Rig consists of an ESP32-C5 N8R8 USB Device and a ST7796 (320x480) touchscreen display. In this session, we used a Xiao ESP32-C5 board was used to host the Open Thread Border Router (OTBR).

Video 107 can be found at https://github.com/kwinter745321/myHA/tree/main/Videos/video107

In this video:
 - Compare the Xaio ESP32-C5 board to the Xaio ESP32-C6 board
 - Briefly explain the Thread network 
 - Review the Espressif menuconfig and the firmware Build
 - Discuss the technical challenges

There are three video segments.
 - The C5/C6 comparison, a quick thread overview, and the challenges.  	Start
 - Review the Espressif menuconfig and Firmware Build.			08:52
 - Review the Home Assistant Apps						17:12


The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA/tree/main/Videos/video118


# Files

 - Firmware
     - There is an info_xxx.txt file that provides the final statements from the build.  It provides the syntax for the esptool command to use the various bin files to flash the Xiao ESP32-C5 device.

  - YAML
      - smartc5.yaml   rebuilt the ESPHome device (used in Video107) to verify it still builds with the latest home Assistant and its APPs.
      