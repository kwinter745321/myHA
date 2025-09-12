# READMe.md - Video 53

# 12 September 2025

# Scope

This is video 53 on configuring a Home Assistant ESPHome Device to display RSS News Feeds.  We are using a Waveshare ESP32-S3-LCD-4.3 device with a 800x480 display. Its a wholly integrated device; so no wiring is needed.

In this video, 
 - Demonstrated the News Feed on the display and a dashboard in Home Assistant
 - Discuss RSS News Feeds and the Home Assistant Feedreader
 - Discuss parsing the data and screen design
 - Discuss test rig configuration
 - Walk-through the lab dashboard, configuration.yaml and esphome device yaml

The code for this video is available at the GitHub site:
https://github.com/kwinter745321/myHA/tree/main/Videos/video53

Thanks to youtuber Smart Home Junkie for Feedreader approach,
and to @clydebarrow at community.home-assistant.io for esphome device configuration

# Files

Script
 lab-rssfeed.txt    Conmfiguration for a dashboard in Home Assistant

 We created an area called Lab, and then added a dashboard.  In the middle of the screen we clicked the "pencil" icon to enter edit mode.
 Here we place the jinja2 code from thje file.

YAML

 - configuration.yaml - an example of my file showing the include for template.yaml
 - templates.yaml -  setup a template sensor.  Here I configured two sensors: rss_feed_items and list_news
 - esp32news.yaml - my final yaml for the esphome device.

 We found that esphome yaml should be created in stages:

 - First, create a new esphome device and watch the LOGs to see the IOP address it gets.
 - Second, Modify the esphome yaml to use this specific IP address.
 - Thirdly, go to Settings -> Devices & Services -> click Integration button and search for esphome.
 - The integration will prompt for a host, enter the ip address.
 - Re-install and ensure it still works.
 - Now hide your keys and passwords in the Secrets area of Home Assistant
