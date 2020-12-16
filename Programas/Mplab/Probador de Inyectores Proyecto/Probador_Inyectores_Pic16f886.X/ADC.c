#include "ADC.h"

void Adc_init(void)
{
    //Settings input mode
    TRISAbits.TRISA0 = 1,ANSELbits.ANS0 = 1;
    TRISAbits.TRISA1 = 1;ANSELbits.ANS1 = 1;
    TRISAbits.TRISA2 = 1,ANSELbits.ANS2 = 1;
    TRISAbits.TRISA3 = 1,ANSELbits.ANS3 = 1;
    
    //Settings for Fosc
    ADCON0bits.ADCS = 0b10;
    
    //Settings justified    It's "1" select Right and It's "0" select Left
    ADCON1bits.ADFM = 1;                //Right justified
    //Settings voltaje reference 
    ADCON1bits.VCFG0 = 0;               // Reference to Vss
    ADCON1bits.VCFG1 = 0;               // Reference to Vdd
    
    return;
}

int Adc(unsigned char channel)
{
    int convertion;
    
    convertion = 0;                                                             // Clear adc

    //Settings for the channels
    ADCON0 &= 0xC3;                                                             // Clear to last selected channels and select channel 0
    ADCON0 |= channel<<2;                                                       // Selections the channel
    
    //Settings for enabled ADC
    ADCON0bits.ADON = 1;                                                        // Enabled ADC for convertions analogue to digital
    __delay_us(70);
    /*==========================================================================
                BEGINS CONVERTION ANALOGUE TO DIGITAL
    ==========================================================================*/
    ADCON0bits.GO_nDONE = 1;                                                    // Comienza la conversion
    while(ADCON0bits.GO_nDONE == 1);                                            // Espera que termine
    convertion = ADRESH, convertion = convertion<<8;                            // Toma el valor de adresh
    convertion |= ADRESL;                                                       // Realizar una OR entre el valor anterior y adresl
    /*==========================================================================
                HAS FINALIZED THE CONVERTION
    ==========================================================================*/
    ADCON0bits.ADON = 0;
    __delay_us(70);
    
    return convertion;
}
