\mainpage Main Page
 
---
# IR Beacon click

IR Beacon click is a mikroBUS™ add-on board with an array of nine high speed infrared emitting diodes.

<p align="center">
  <img src="https://download.mikroe.com/images/click_for_ide/irbeacon_click.png" height=300px>
</p>

[click Product page](https://www.mikroe.com/ir-beacon-click)

---


#### Click library 

- **Author**        : MikroE Team
- **Date**          : Jan 2020.
- **Type**          : PWM type


# Software Support

We provide a library for the IrBeacon Click 
as well as a demo application (example), developed using MikroElektronika 
[compilers](https://shop.mikroe.com/compilers). 
The demo can run on all the main MikroElektronika [development boards](https://shop.mikroe.com/development-boards).

Package can be downloaded/installed directly form compilers IDE(recommended way), or downloaded from our LibStock, or found on mikroE github account. 

## Library Description

> This library contains API for IrBeacon Click driver.

#### Standard key functions :

- Config Object Initialization function.
> void irbeacon_cfg_setup ( irbeacon_cfg_t *cfg ); 
 
- Initialization function.
> IRBEACON_RETVAL irbeacon_init ( irbeacon_t *ctx, irbeacon_cfg_t *cfg );

#### Example key functions :

- Enable MOD function
> void irbeacon_enable_mod ( irbeacon_t *ctx );
 
- Disable MOD function
> void irbeacon_disable_mod ( irbeacon_t *ctx );

- Reset MOD function
> void irbeacon_reset_mod ( irbeacon_t *ctx );

## Examples Description

> This application sets the brightness on Leds.

**The demo application is composed of two sections :**

### Application Init 

> Enables GPIO and PWM, sets the frequency and duty cycle and enables PWM.

```c

void application_init ( void )
{
    log_cfg_t log_cfg;
    irbeacon_cfg_t cfg;

    /** 
     * Logger initialization.
     * Default baud rate: 115200
     * Default log level: LOG_LEVEL_DEBUG
     * @note If USB_UART_RX and USB_UART_TX 
     * are defined as HAL_PIN_NC, you will 
     * need to define them manually for log to work. 
     * See @b LOG_MAP_USB_UART macro definition for detailed explanation.
     */
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info( &logger, "---- Application Init ----" );

    //  Click initialization.

    irbeacon_cfg_setup( &cfg );
    IRBEACON_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    irbeacon_init( &irbeacon, &cfg );

    irbeacon_set_duty_cycle( &irbeacon, duty_cycle );
    irbeacon_pwm_start( &irbeacon );
    Delay_ms( 1000 );
}
  
```

### Application Task

> This is a example which demonstrates the use of IR Beacon Click board.
> It shows how to enable the device and gradualy increase the duty cycle.

```c

void application_task ( void )
{
    irbeacon_enable_mod( &irbeacon );
    
    for ( duty_cycle = 250; duty_cycle < 3000; duty_cycle += 250 )
    {
        irbeacon_set_duty_cycle( &irbeacon, duty_cycle );
        Delay_ms( 500 );
    }
    
    irbeacon_disable_mod( );
    Delay_ms( 1000 );
}

```

The full application code, and ready to use projects can be  installed directly form compilers IDE(recommneded) or found on LibStock page or mikroE GitHub accaunt.

**Other mikroE Libraries used in the example:** 

- MikroSDK.Board
- MikroSDK.Log
- Click.IrBeacon

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
