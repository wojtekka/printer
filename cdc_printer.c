#include "src/system.h"
#include "src/delay.h"
#include "src/usb_cdc.h"
#include "src/gpio.h"

void USB_interrupt(void);

void USB_ISR(void) __interrupt(INT_NO_USB)
{
    USB_interrupt();
}

void main(void)
{
    CLK_config();
    DLY_ms(5);
    CDC_init();
    
    PIN_output(P11);
    PIN_low(P11);
    DLY_us(1);
    PIN_high(P11);

    PIN_input_PU(P34);

    PIN_input_PU(P14);
    PIN_input_PU(P15);
    PIN_input_PU(P16);
    PIN_input_PU(P17);
    PIN_input_PU(P30);
    PIN_input_PU(P31);
    PIN_input_PU(P32);
    PIN_input_PU(P33);

    for (;;)
    {
        if (PIN_read(P34))
        {
            unsigned char value = 0;
            if (PIN_read(P30)) value |= 0x01;
            if (PIN_read(P31)) value |= 0x02;
            if (PIN_read(P32)) value |= 0x04;
            if (PIN_read(P33)) value |= 0x08;
            if (PIN_read(P14)) value |= 0x10;
            if (PIN_read(P15)) value |= 0x20;
            if (PIN_read(P16)) value |= 0x40;
            if (PIN_read(P17)) value |= 0x80;
            PIN_low(P11);
            DLY_us(1);
            PIN_high(P11);
            CDC_write(value);
            TR0 = 1;
        }

        if (TF0)
        {
            TR0 = 0;
            CDC_flush();
        }
    }
}
