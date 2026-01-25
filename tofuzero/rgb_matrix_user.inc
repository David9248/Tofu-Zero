// RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Efeito personalizado: Layer Mode
RGB_MATRIX_EFFECT(LAYER_MODE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Cores para cada layer
#define COLOR_LAYER_0  128, 255, 255  // Ciano (DEFAULT)
#define COLOR_LAYER_1  0, 255, 255    // Vermelho (CONTROL)
#define COLOR_LAYER_2  170, 255, 255  // Azul (CENAS)

static bool LAYER_MODE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    
    uint8_t layer = get_highest_layer(layer_state);
    HSV hsv = {0, 0, 0};
    
    // Define a cor baseada no layer
    switch (layer) {
        case 0:  // _DEFAULT
            hsv = (HSV){COLOR_LAYER_0};
            break;
        case 1:  // _CONTROL
            hsv = (HSV){COLOR_LAYER_1};
            break;
        case 2:  // _CENAS
            hsv = (HSV){COLOR_LAYER_2};
            break;
        default:
            hsv = (HSV){0, 0, 255};  // Branco para outros layers
            break;
    }
    
    RGB rgb = hsv_to_rgb(hsv);
    
    // Aplica a cor a todos os LEDs
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS