# README  - Detail


(STEP 1)
update the configuration file using File Editor (or via the Terminal)

```
configuration.yaml
template: !include templates.yaml
```

Add this file, which I called template.yaml.
```
template.yaml
  - triggers:
      - trigger: time_pattern
        hours: /1
    action:
      - service: weather.get_forecasts
        data:
          type: daily
        target:
          entity_id: weather.forecast_home
        response_variable: daily
    sensor:
      - name: "Forecast"
        unique_id: forecast
        state: "{{ daily['weather.forecast_home'].forecast[1].condition }}"
        attributes:
          forecast: "{{ daily['weather.forecast_home']['forecast'] }}"
```

(Step 2)
From Settings --> Devices & Services  --> Helpers

```
Helper
temperature_high_forecast_1

State
{{ state_attr('sensor.forecast','forecast')[1].temperature  }}

becomes 
sensor.temperature_high_forecast_1
```

(Step 3)
finally in your ESP32 YAML add a sensor.  The entity_id points to the Helper,
and local id can be used by your LVGL widget.

```sensor:
  - platform: homeassistant
    name: "Forecast Temp Hi 1"
    id: temphi1
    entity_id: sensor.temperature_high_forecast_1
    internal: True
    unit_of_measurement: "°F"
    on_value: 
      then:
        - lvgl.label.update: 
            id: label_temphi1
            text: 
              format: "%.0f °F"
              args: ['id(temphi1).state']
```


LVGL Widget
```
              - label:
                  id: label_temphi1
                  width: 70
                  height: 25
                  text_font: both_font
                  text_color:  0xFFFFFF
                  bg_color: 0x0
```
