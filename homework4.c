#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework4.h"

int main(void)
{
    char rChar;
    char *response = "\n\n\r2534 is the best course in the curriculum!\r\n\n";

    // TODO: Declare the variables that main uses to interact with your state machine.
    bool finished = false


    // Stops the Watchdog timer.
    initBoard();
    // TODO: Declare a UART config struct as defined in uart.h.
    //       To begin, configure the UART for 9600 baud, 8-bit payload (LSB first), no parity, 1 stop bit.
    struct eUSCI_UART_Config uartConfig =
    {
             EUSCI_A_UART_CLOCKSOURCE_SMCLK,
             65,
             1,
             0xD6,
             EUSCI_A_UART_NO_PARITY,                       // No Parity
             EUSCI_A_UART_LSB_FIRST,                       // LSB First
             EUSCI_A_UART_ONE_STOP_BIT,                    // One stop bit
             EUSCI_A_UART_MODE,                            // UART mode
             EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION // Oversampling
        };


    // TODO: Make sure Tx AND Rx pins of EUSCI_A0 work for UART and not as regular GPIO pins.
    extern void GPIO_setAsPeripheralModuleFunctionInputPin(uint_fast8_t GPIO_PORT_P1,
    uint_fast16_t GPIO_PIN2, uint_fast8_t GPIO_PRIMARY_MODULE_FUNCTION);

    extern void GPIO_setAsPeripheralModuleFunctionOutputPin(uint_fast8_t GPIO_PORT_P1,
    uint_fast16_t GPIO_PIN3, uint_fast8_t GPIO_PRIMARY_MODULE_FUNCTION );


    // TODO: Initialize EUSCI_A0
void initUART(uint32_t moduleInstance, const eUSCI_UART_Config *config);
{
    UART_initmodule(rChar, *config);
    UART_enableModule(rChar);
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PIN2);
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PIN3);

}

    // TODO: Enable EUSCI_A0
extern void UART_enableModule(uint32_t rChar);


    while(1)
    {
        // TODO: Check the receive interrupt flag to see if a received character is available.
        //       Return 0xFF if no character is available.
        if (UART_getInterruptStatus (EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
                        == EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG);
        else
            rChar = 0xFF;

        // TODO: If an actual character was received, echo the character to the terminal AND use it to update the FSM.
        //       Check the transmit interrupt flag prior to transmitting the character.
        if (UART_getInterruptStatus (EUSCI_A0_BASE, EUSCI_A_UART_TRANSMIT_INTERRUPT_FLAG)
                            == EUSCI_A_UART_TRANSMIT_INTERRUPT_FLAG)
        {
            charFSM(rChar);

        }


        // TODO: If the FSM indicates a successful string entry, transmit the response string.
        //       Check the transmit interrupt flag prior to transmitting each character and moving on to the next one.
        //       Make sure to reset the success variable after transmission.
if (finished)
{
    extern void UART_transmitData(uint32_t moduleInstance,
            uint_fast8_t *response);
    finished = false
}

    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: FSM for detecting character sequence.
bool charFSM(char rChar)
{
    typedef enum {SX, S2, S25, S253, S2534} passcode_state_t;
    static passcode_state_t currentState = SX;
    bool finished = false;

    switch (currentState) {
        case SX:
            if (rChar == 2)
                currentState = S2;
            else
                currentState = SX;
            break;
        case S2:
            if (rChar) == 5)
                currentState = S25;
            else
                currentState = SX;
            break;
        case S25:
            if (rChar == 3 )
                currentState = S253;
            else
                currentState = SX;
            break;
        case S253:
            if (rChar == 4)
                currentState = S2534
                finished = true;
            else
                currentState = SX;
            break;
        case S2534:
            currentState = SX;
            break;

    }

    return finished;//Ideally, this makes sure that the last 4 digits in a desired string are 2534, and once that is reached,
    //the FSM goes back to the initial state, however, the response string will be sent/echoed before this happens

}
