void interrupt(){
     if (CCP1IF_bit == 1){
        TMR1H = 0;
        TMR1L = 0;
        //TMR1 must be cleared manually
        if (CCP1CON == 8){
           CCP1CON = 9;
           CCPR1H = 0x92;
           CCPR1L = 0x7C;
           //CCPR1 = 37500 --> 100ms
        }
        else{
             CCP1CON = 8;
             CCPR1H = 0x30;
             CCPR1L = 0xD4;
             //CCPR1 = 12500 --> 100ms
        }
        CCP1IF_bit = 0;
     }
}

void main() {
     TRISC = 0;
     PORTC = 4;
     CCP1CON = 9; //Clear RC2 on match
     CCPR1H = 0x92;
     CCPR1L = 0x7C;
     //CCPR1 = 37500 --> 100ms
     CCP1IE_bit = 1;
     GIE_bit = 1;
     PEIE_bit = 1;
     T1CON = 0x11; //Prescaler 1:2, start Timer 1
     while(1){
     //Do whatever else is required
     }
}
