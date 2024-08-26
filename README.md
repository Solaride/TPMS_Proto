# TPMS_Proto

Hetkel on siin täiesti mitte toimiv kood. Idee kohaselt peaks programm lugema SPI kaudu rõhusensorilt sellesse salvestatud teisenduskonstandid, mis on vajalikud, et hilljem teisendada ADC näit temperatuuriks ja rõhuks. ADC lugemise funktsiooni veel ei kirjutanud. Ei SPI ega Printf ei tööta, ostsilloskoobiga ei näinud USART klemmidel üldse mingit signaali, SPI MOSI pin saatis mingit signaali, kuid see ei paistnud SPI andmete moodi.

Seaded:
Valisin projekti alustades seadmeks B-WB1M-WPAN1 arendusplaadi

Lülitasin välja I2C ja ADC, kuna neid pole vaja

SPI sätetes "Prescaler (for Baud Rate) muutsin neljaks

Ülejäänu kõik default
