# README.md - Video 80

12 March 2026

# Scope
This is video 80 on a Home Assistant ESPHome/LVGL embedded solution. In this video, we setup ESPHome on the CYD to fetch weather data from Home Assistant. We demonstrate the weather data in Developer Tools. We explain how to prepare the Home Assistant interface by using a Template Sensor and Helpers.  Our Test Rig is the Cheap Yellow Display (ESP32-2432S028 [R]) device.  This device has an integrated ILI9341 display (320x480) and touchscreen. 

You can fetch the firmware and programs from our GitHub site, and begin using them immediately.  

In this video, 
 - Demonstrate how to get weather data to ESPHome.
 - Demonstrate Home Assistant Developer Tools.
 - Explain why we need Hoime Assistant Helpers.
 - Review the ESPHome Sensors and the LVGL screen implementation.

The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA/tree/main/Videos/video80

# Files

 - ESPHOME_YAML
   - cydtemp.yaml   

 - Other_YAML
   - configuration.yaml
   - templates.yaml
   - helperTemplateSensors-information.txt   (This text allows you to copy/paste the query into Helpers)
