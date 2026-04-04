# README.md - video 49 

13 August 2025
 - 08 March 2026 - Add a Details page with README
 - 04 April 2026 - How to add additional Helpers

# Scope
This is video 49 on Home Assistant and LVGL.  We learn about the default Weather information in Home Assistant.  This video provides an approach to configure an ESPHome device to fetch this data and display on a LVGL Display using LVGL.  The Test Rig uses Raspberry Pi Pico W USB board connected to an ILI9341 display.  This functionality is applicable to an ESP32-S3 USB board.

In this video, 
 - Discuss Home Assistant (HA) weather forecast
 - Present HA Template Sensors
 - Demonstrate some of the Developer Tools
 - Discuss LVGL Flex flow for the display
 - Walk through the setup

ESPHome automated and manual first-install instructions:  https://www.home-assistant.io/integrations/esphome/#required-manual-input

The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA

Repo:
https://github.com/kwinter745321/myHA/tree/main/Videos/video49

# Files

YAML

 - configuration.yaml - an example of my file showing the include for template.yaml
 - templates.yaml -  setup a template sensor
 - helperTemplateSensors-information.txt  - create helper functions using the jinja2 template "state"
 - picotemp(video).yaml - my final yaml for the esphome device.

font

materialdisignicons-webfont.ttf  - use your File Editor to copy this to a directory under esphome

# Adding additional helpers

- suggested by anymules6532  (thanks)

Hopefully these quick steps will help:

1. Go to Settings > Devices & Services > Helpers
2. Click the Create Helper button
3. From the dropdown box, select Template
4. From the next dropdown box, select Sensor
5. Put the name of the sensor in the Name field, ie temperature_high_forecast_1 
6. Put the state string in to the State field, ie {{ state_attr('sensor.forecast','forecast')[1].temperature  }}
7. Click the submit button at the bottom

Repeat to create all the helpers shown in the helperTemplateSensors-Information.txt file.
