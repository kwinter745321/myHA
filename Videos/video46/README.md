# Video 46 README.md

23 July 2025

# Scope
This is video 46 on Home Assistant and LVGL. Three example displays are shown that are based on the ESPHome Cookbook examples.  This video introduces LVGL on ESPHome. The video explains how to setup the display and touchscreen in ESPHome for an ILI9341 Integrated display.  The Test Rig uses an Raspberry Pi Pico W USB board connected to an ILI9341 display.

To see the controls in a Dashboard.  You may need to add your new ESPHome Device (for example picow) to Integrations.  To do this, click Settings (near bottom of Side pane), then click "Devices & services".  Then click "Add Integration" at bottom-right corner of the page.  Now enter "esphome", then the Host name (in my case "picow") and click Submit.  Back at the Integration page, look for ESPHome under the Configured items. Click the device.  Now you can see info on the device.  One of the items is Controls. It should have a link to add the controls to a Dashboard.

In this video, 
 - Demonstrates a few ESPHome cookbook LVGL examples.
 - Present the Test Rig wiring
 - Walk through a simple LVGL configuration 

The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA

Repo:
https://github.com/kwinter745321/myHA/tree/main/Videos/video46

# Files

These are YAML files for an ESPHome device called picow.
There are three examples (based on ESPHome Cookbook):

 - picow-core-temp.yaml
 - picow-elock.yaml
 - picow-flex.yaml

This file contains the "hello-world" simple LVGL script that was used in the configuration review

 - picow-hello.yaml

