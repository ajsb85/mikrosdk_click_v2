
---
# eINK 2.90 inch display

eINK click is an adapter Click board™, used to interface a compatible eINK display with the host MCU. 

<p align="center">
  <img src="https://download.mikroe.com/images/click_for_ide/eink_click_bundle29inch.png">
</p>

[click Product page](https://www.mikroe.com/e-paper-bundle-3)

---


#### Click library 

- **Author**        : MikroE Team
- **Date**          : Feb 2020.
- **Type**          : SPI type


# Software Support

We provide a library for the Eink290Inch Click 
as well as a demo application (example), developed using MikroElektronika 
[compilers](https://shop.mikroe.com/compilers). 
The demo can run on all the main MikroElektronika [development boards](https://shop.mikroe.com/development-boards).

Package can be downloaded/installed directly form compilers IDE(recommended way), or downloaded from our LibStock, or found on mikroE github account. 

## Library Description

> This library contains API for Eink290Inch Click driver.

#### Standard key functions :

- Config Object Initialization function.
> void eink_290inch_cfg_setup ( eink_290inch_cfg_t *cfg ); 
 
- Initialization function.
> EINK290INCH_RETVAL eink_290inch_init ( eink_290inch_t *ctx, eink_290inch_cfg_t *cfg );

#### Example key functions :

- Function that fills the screen
> void eink_290_fill_screen ( eink_290inch_t *ctx, uint8_t color );
 
- Display image function
> void eink_290_display_image ( eink_290inch_t *ctx, const uint8_t* image_buffer );

- Set font function
> void eink_290_set_font ( eink_290inch_t *ctx, eink_290inch_font_t *cfg_font );

## Examples Description

> This application demonstrates the use of eINK click board.

**The demo application is composed of two sections :**

### Application Init 

> Initializes the driver and configures the click board for 2.90 inch eINK display.
> After that, if the TEXT mode is supported, shows a desired text messages on the display.

```c

void application_init ( void )
{
    eink_290inch_cfg_t cfg;
    eink_290inch_font_t cfg_font;
    eink_290inch_set_text_t text_set;

    //  Click initialization.

    eink_290inch_cfg_setup( &cfg );
    EINK290INCH_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    eink_290inch_init( &eink_290inch, &cfg );

    eink_290_start_config( &eink_290inch );
    eink_290_set_lut( &eink_290inch, EINK290_LUT_TABLE_1, 70 );
    Delay_ms( 1000 );
    
#ifndef IMAGE_MODE_ONLY
    cfg_font.p_font = &guiFont_Tahoma_18_Regular[ 0 ];
    cfg_font.color = EINK290_SCREEN_COLOR_WHITE;
    cfg_font.orientation = EINK290_FO_HORIZONTAL;  
    eink_290_set_font( &eink_290inch, &cfg_font );
    text_set.n_char = 4;
    text_set.text_x = 5;
    text_set.text_y = 50;
    eink_290_text( &eink_290inch, &demo_text[ 0 ], &text_set );
    Delay_ms( 1000 );
    
    cfg_font.p_font = &guiFont_Tahoma_10_Regular[ 0 ];
    cfg_font.color = EINK290_SCREEN_COLOR_WHITE;
    cfg_font.orientation = EINK290_FO_HORIZONTAL; 
    eink_290_set_font( &eink_290inch, &cfg_font );
    text_set.n_char = 7;
    text_set.text_x = 5;
    text_set.text_y = 90;
    eink_290_text( &eink_290inch, &demo_text1[ 0 ], &text_set );
    Delay_ms( 1000 );
    
    cfg_font.p_font = &guiFont_Tahoma_8_Regular[ 0 ];
    cfg_font.color = EINK290_SCREEN_COLOR_WHITE;
    cfg_font.orientation = EINK290_FO_HORIZONTAL; 
    eink_290_set_font( &eink_290inch, &cfg_font );
    text_set.n_char = 9;
    text_set.text_x = 5;
    text_set.text_y = 120;
    eink_290_text( &eink_290inch, &demo_text2[ 0 ], &text_set ); 
    Delay_ms( 1000 );
#endif
}
  
```

### Application Task

> Draws four demo images to the display with a one-second delay between each drawing.

```c

void application_task ( void )
{
    eink_290_display_image( &eink_290inch, &demoImage_light[ 0 ] );
    Delay_1sec( );
    eink_290_display_image( &eink_290inch, &demoImage_dark[ 0 ] );
    Delay_1sec( );
    eink_290_display_image( &eink_290inch, &demoImage_light_180[ 0 ] );
    Delay_1sec( );
    eink_290_display_image( &eink_290inch, &demoImage_dark_180[ 0 ] );
    Delay_1sec( );
}

```

## Note

> Due to insuficient RAM memory, only the IMAGE mode is supported with 8-bit PIC microcontrollers.

The full application code, and ready to use projects can be  installed directly form compilers IDE(recommneded) or found on LibStock page or mikroE GitHub accaunt.

**Other mikroE Libraries used in the example:** 

- MikroSDK.Board
- MikroSDK.Log
- Click.Eink290Inch

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](https://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](https://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](https://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](https://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.



---
