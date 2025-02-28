
---
# DC MOTOR  click

DC MOTOR click is a DC motor driver board in mikroBUS form factor. It features the DRV8833RTYH-Bridge motor driver, 74HC4053 multiplexer and two screw terminals >

<p align="center">
  <img src="https://download.mikroe.com/images/click_for_ide/dcmotor_click.png" height=300px>
</p>

[click Product page](https://www.mikroe.com/dc-motor-click)

---


#### Click library 

- **Author**        : MikroE Team
- **Date**          : Jan 2020.
- **Type**          : PWM type


# Software Support

We provide a library for the DcMotor Click 
as well as a demo application (example), developed using MikroElektronika 
[compilers](https://shop.mikroe.com/compilers). 
The demo can run on all the main MikroElektronika [development boards](https://shop.mikroe.com/development-boards).

Package can be downloaded/installed directly form compilers IDE(recommended way), or downloaded from our LibStock, or found on mikroE github account. 

## Library Description

> This library contains API for DcMotor Click driver.

#### Standard key functions :

- Config Object Initialization function.
> void dcmotor_cfg_setup ( dcmotor_cfg_t *cfg ); 
 
- Initialization function.
> DCMOTOR_RETVAL dcmotor_init ( dcmotor_t *ctx, dcmotor_cfg_t *cfg );


#### Example key functions :

- Start PWM module.
> void dcmotor_pwm_start ( dcmotor_t *ctx );
 
- Enable the motor function.
> void dcmotor_enable ( dcmotor_t *ctx );

- Set sleep mode function.
> void dcmotor_sleep_mode ( dcmotor_t *ctx );
## Examples Description

> This application change the speed and direction of DC Motor.

**The demo application is composed of two sections :**

### Application Init 

> Initialization driver enable's - GPIO, PWM initialization, set PWM duty cycle and PWM frequency, enable the motor, start PWM and start write log.

```c

void application_init ( void )
{
    log_cfg_t log_cfg;
    dcmotor_cfg_t cfg;

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

    dcmotor_cfg_setup( &cfg );
    DCMOTOR_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    dcmotor_init( &dcmotor, &cfg );

    log_printf( &logger, " Initialization  PWM \r\n" );
    dcmotor_set_duty_cycle( &dcmotor, duty_cycle );
    dcmotor_enable( &dcmotor );
    dcmotor_pwm_start( &dcmotor );
    Delay_ms( 1000 );
    log_printf( &logger, "---------------------\r\n" );
}
  
```

### Application Task

>  This is a example which demonstrates the use of DC Motor Click board. DC Motor Click communicates with register via PWM interface. It shows moving in the left direction from slow to fast speed and moving in the right direction from fast to slow speed. Results are being sent to the Usart Terminal where you can track their changes.

```c

void application_task ( void )
{
 //  Task implementation.
    
    if ( duty_cycle > dcmotor.pwm_period )
    {
        duty_cycle = 100;
    }
    
    dcmotor_set_duty_cycle ( &dcmotor, duty_cycle );
    duty_cycle += 50;
    Delay_100ms();

    log_printf( &logger, "    Left Direction   \r\n" );
    dcmotor_left_direction_slow( &dcmotor );
    dcmotor_enable( &dcmotor );
    Delay_ms( 1000 );

    for ( duty_cycle = 500; duty_cycle < 3000; duty_cycle += 250 )
    {
        dcmotor_set_duty_cycle( &dcmotor, duty_cycle );
        log_printf( &logger, " <\r\n" );
        Delay_ms( 1000 );
    }

    dcmotor_sleep_mode( &dcmotor );
    Delay_ms( 1000 );
    log_printf( &logger, "---------------------\r\n" );
    log_printf( &logger, "   Right Direction   \r\n" );

    dcmotor_right_direction_fast( &dcmotor );
    dcmotor_enable( &dcmotor );
    Delay_ms( 1000 );

    for ( duty_cycle = 500; duty_cycle < 3000; duty_cycle += 250 )
    {
        dcmotor_set_duty_cycle( &dcmotor, duty_cycle );
        log_printf( &logger, " >\r\n" );
        Delay_ms( 1000 );
    }

  
    log_printf( &logger, "---------------------\r\n" );
    dcmotor_sleep_mode( &dcmotor );
    Delay_ms( 1000 );
}  

```

The full application code, and ready to use projects can be  installed directly form compilers IDE(recommneded) or found on LibStock page or mikroE GitHub accaunt.

**Other mikroE Libraries used in the example:** 

- MikroSDK.Board
- MikroSDK.Log
- Click.DcMotor

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
