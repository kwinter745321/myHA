# README.md - video 49 

13 August 2025

# Scope
This is video 49 on Home Assistant and LVGL.  We learn about the default Weather information in Home Assistant.  This video provides an approach to configure an ESPHome device to fetch this data and display on a LVGL Display using LVGL.  The Test Rig uses Raspberry Pi Pico W USB board connected to an ILI9341 display.  This functionality is applicable to an ESP32-S3 USB board.

In this video, 
    • Discuss Home Assistant (HA) weather forecast
    • Present HA Template Sensors
    • Demonstrate some of the Developer Tools
    • Discuss LVGL Flex flow for the display
    • Walk through the setup

ESPHome automated and manual first-install instructions:  https://www.home-assistant.io/integrations/esphome/#required-manual-input

The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA

Repo:
https://github.com/kwinter745321/myHA/tree/main/Videos/video49

# Files

YAML

configuration.yaml - an example of my file showing the include for template.yaml
templates.yaml -  setup a template sensor
helperTemplateSensors-information.txt  - create helper functions using the jinja2 template "state"
picotemp(video).yaml - my final yaml for the esphome device.

font

materialdisignicons-webfont.ttf  - use your File Editor to copy this to a directory under esphome

