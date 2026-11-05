// chart4.h
//
// Created: 02 November 2026
//
// Author: KW Services
// License: MIT
//
// ESPHome 2026.10.2
//
// Custom LVGL Charting routines for ESPHome.
// Parent display area: 300 x 260 pixels

#include <lvgl.h>
#include <cmath>
#include <vector>


// Configuration constatntd
static lv_obj_t *chart_1 = nullptr;
static lv_chart_series_t *ser1 = nullptr;
static lv_chart_series_t *ser2 = nullptr;
static lv_chart_series_t *ser3 = nullptr;
static lv_chart_series_t *ser4 = nullptr;
static lv_obj_t *y_axis_container = nullptr;
static lv_obj_t *x_axis_container = nullptr;

static constexpr float Y_MIN = 0.0f;
static constexpr float Y_MAX = 100.0f;
static constexpr int Y_TICKS = 5;
static constexpr int X_TICKS = 10;

// Leave room on the left for Y labels and on the bottom for the last X label.
static constexpr int LEFT_MARGIN = 42;
static constexpr int TOP_MARGIN = 4;
static constexpr int WIDTH = 245;
static constexpr int HEIGHT = 210;
static constexpr int Y_AXIS_WIDTH= 38;
static constexpr int X_AXIS_HEIGHT  = 28;

// Series data dot and line colors
static lv_color_t BLUE =   lv_color_hex(0x6366f1);
static lv_color_t RED =    lv_color_hex(0xf16366);
static lv_color_t GREEN =  lv_color_hex(0x66f163);
static lv_color_t VIOLET = lv_color_hex(0xa763f1);

static void cleanup_chart() {
    if (chart_1 != nullptr) {
        lv_obj_del(chart_1);
        chart_1 = nullptr;
        ser1 = nullptr;
    }
    if (y_axis_container != nullptr) {
        lv_obj_del(y_axis_container);
        y_axis_container = nullptr;
    }
    if (x_axis_container != nullptr) {
        lv_obj_del(x_axis_container);
        x_axis_container = nullptr;
    }
}

static void draw_chart(lv_obj_t *parent)
{
    // Clean up an earlier chart, if draw_chart() is called again.
    cleanup_chart();

    // Create main chart.
    chart_1 = lv_chart_create(parent);
    lv_obj_set_pos(chart_1, LEFT_MARGIN, TOP_MARGIN);
    lv_obj_set_size(chart_1, WIDTH, HEIGHT);

    lv_chart_set_type(chart_1, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(chart_1, 10);
    lv_chart_set_div_line_count(chart_1, Y_TICKS + 1, X_TICKS);

    lv_chart_set_axis_min_value(chart_1, LV_CHART_AXIS_PRIMARY_Y,static_cast<int>(Y_MIN));
    lv_chart_set_axis_max_value(chart_1, LV_CHART_AXIS_PRIMARY_Y,static_cast<int>(Y_MAX));

    // Chart styles
    lv_obj_set_style_bg_opa(chart_1, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_border_width(chart_1, 1, LV_PART_MAIN);
    lv_obj_set_style_border_color(chart_1, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_radius(chart_1, 0, LV_PART_MAIN);

    // Y-axis labels. 
    y_axis_container = lv_obj_create(parent);
    lv_obj_set_pos(y_axis_container, 0, TOP_MARGIN);
    lv_obj_set_size(y_axis_container, Y_AXIS_WIDTH, HEIGHT);
    lv_obj_set_style_bg_opa(y_axis_container, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_border_width(y_axis_container, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(y_axis_container, 0, LV_PART_MAIN);
    lv_obj_clear_flag(y_axis_container, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_clip_corner(y_axis_container, false, LV_PART_MAIN);

    for (int i = 0; i <= Y_TICKS; ++i) {
        const float value = Y_MIN + (Y_MAX - Y_MIN) * (static_cast<float>(i) / Y_TICKS);
        lv_obj_t *label = lv_label_create(y_axis_container);
        lv_label_set_text_fmt(label, "%.0f", value);
        lv_obj_set_style_text_font(label, &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_color(label, lv_color_black(), 0);
        lv_obj_update_layout(label);
        const int label_h = lv_obj_get_height(label);
        const int ideal_y = HEIGHT - (HEIGHT * i / Y_TICKS) - label_h / 2;

        // Keep the labels inside the container.
        int label_y = ideal_y;
        if (label_y < 0) label_y = 0;
        if (label_y + label_h > HEIGHT)
            label_y = HEIGHT - label_h;
        lv_obj_set_pos(label, Y_AXIS_WIDTH- lv_obj_get_width(label) - 2,
                       label_y);
    }

    // X-axis labels.
    x_axis_container = lv_obj_create(parent);
    lv_obj_set_pos(x_axis_container, LEFT_MARGIN, TOP_MARGIN + HEIGHT + 3);
    lv_obj_set_size(x_axis_container, WIDTH, X_AXIS_HEIGHT );
    lv_obj_set_style_bg_opa(x_axis_container, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_border_width(x_axis_container, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(x_axis_container, 0, LV_PART_MAIN);
    lv_obj_clear_flag(x_axis_container, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_clip_corner(x_axis_container, false, LV_PART_MAIN);

    for (int i = 0; i < X_TICKS; ++i) {
        lv_obj_t *label = lv_label_create(x_axis_container);
        lv_label_set_text_fmt(label, "%d", i);
        lv_obj_set_style_text_font(label, &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_color(label, lv_color_black(), 0);
        lv_obj_update_layout(label);
        const int label_w = lv_obj_get_width(label);
        const int ideal_x = (WIDTH - 1) * i / (X_TICKS - 1) - label_w / 2;

        // Keep the labels inside the container.
        int label_x = ideal_x;
        if (label_x < 0) label_x = 0;
        if (label_x + label_w > WIDTH)
            label_x = WIDTH - label_w;

        lv_obj_set_pos(label, label_x, 2);
    }
}

// updates chart using an array of a sensor
static void update_chart(const std::vector<float> &float_vec)
{
    if (chart_1 == nullptr || float_vec.empty()) return;
    ESP_LOGI("update_chart", "size is %u",
             static_cast<unsigned>(float_vec.size()));

    ser1 = lv_chart_add_series(chart_1, BLUE, LV_CHART_AXIS_PRIMARY_Y);

    for (size_t i = 0; i < float_vec.size(); ++i) {
        const int value = static_cast<int>(std::round(float_vec[i]));
        lv_chart_set_value_by_id(chart_1, ser1, i, value);
        ESP_LOGI("update_chart", "Value is %d, item is %u",
                 value, static_cast<unsigned>(i));
    }

    lv_chart_refresh(chart_1);
}

// updates chart with four different attributes
static void update_chart_all(const std::vector<float> &v1,const std::vector<float> &v2, 
    const std::vector<float> &v3, const std::vector<float> &v4)
{
    if (chart_1 == nullptr || v1.empty()) return;
    ESP_LOGI("update_chart_all", "size is %u",
             static_cast<unsigned>(v1.size()));

    ser1 = lv_chart_add_series(chart_1, BLUE, LV_CHART_AXIS_PRIMARY_Y);
    ser2 = lv_chart_add_series(chart_1, RED, LV_CHART_AXIS_PRIMARY_Y);
    ser3 = lv_chart_add_series(chart_1, GREEN, LV_CHART_AXIS_PRIMARY_Y);
    ser4 = lv_chart_add_series(chart_1, VIOLET, LV_CHART_AXIS_PRIMARY_Y);

    for (size_t i = 0; i < v1.size(); ++i) {
        const int value1 = static_cast<int>(std::round(v1[i]));
        const int value2 = static_cast<int>(std::round(v2[i]));
        const int value3 = static_cast<int>(std::round(v3[i]));
        const int value4 = static_cast<int>(std::round(v4[i]));
       
        lv_chart_set_value_by_id(chart_1, ser1, i, value1);
        lv_chart_set_value_by_id(chart_1, ser2, i, value2);
        lv_chart_set_value_by_id(chart_1, ser3, i, value3);
        lv_chart_set_value_by_id(chart_1, ser4, i, value4);
    }
    lv_chart_refresh(chart_1);
}


