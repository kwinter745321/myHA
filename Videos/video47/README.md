# Video 47 README.md

31 July 2025

# Scope
This is video 47 on Home Assistant and LVGL. Two example displays are shown that are based on the ESPHome Cookbook examples.  This video introduces LVGL on ESPHome. The video explains how to setup the display and touchscreen in ESPHome for an ILI9341 Integrated display.  The Test Rig uses an ESP32-S3-DevKitC-1 USB board connected to an ILI9341 display.
Although similar to Video 46 this video covers the setup items needed for ESP32 and additional features are discussed that are applicable to both the ESP32 and the Pico W.

To see the controls in a Dashboard.  You may need to add your new ESPHome Device (for example Central) to Integrations.  To do this, click Settings (near bottom of Side pane), then click "Devices & services".  Then click "Add Integration" at bottom-right corner of the page.  Now enter "esphome", then the Host name (in my case "Central") and click Submit.  Back at the Integration page, look for ESPHome under the Configured items. Click the device.  Now you can see info on the device.  One of the items is Controls. It should have a link to add the controls to a Dashboard.

In this video, 
    • Demonstrates a few ESPHome cookbook LVGL examples.
    • Present the Test Rig wiring
    • Walk through a simple LVGL configuration 

ESPHome automated and manual first-install instructions:  https://www.home-assistant.io/integrations/esphome/#required-manual-input

The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA

Repo:
https://github.com/kwinter745321/myHA/tree/main/Videos/video47


# Files

These are YAML files for an ESPHome device called Central.
There are two examples (based on ESPHome Cookbook):

 - central-internal-temperature.yaml
 - central-flex.yaml

This file contains the "hello-world" simple LVGL script that was used in the configuration review

 - central-hello.yaml

This file contains the "hello-world" simple LVGL script that was modified in the configuration review.

 - central-hello-final.yaml

 