#include "main.h"
#include "stm32wbxx_hal.h"

typedef unsigned char byte;

const byte LimitT = 0b00110000;		// Tells the sensor we want an interrupt when the temperature goes above or below (bit2) the following value.
const byte LimitP = 0b00110100;		// Tells the sensor we want an interrupt when the Pressure goes above or below (bit2) the following value.

class MS5849{
	const byte RESET = 0b00010000;		// To trigger sensor reset
	const byte WriteConfig = 0b00100000;// Tells the sensor we want to set it's configuration register. Bits 2 and 3 determine address
	const byte ReadConfig = 0b00101000;	// Tells the sensor to send it's configuration. Bits 2 and 3 determine address
	const byte ReadMemory = 0b11100000;	// Read data from address selected by bits 2-5. Can be used to read conversion coefficients, serial number, CRC
	const byte WriteOperationReg = 0b00010100;	// Tells the sensor we want to set it's operation register. Controls FIFO and automatic mode
	const byte ReadOperationReg = 0b00010110;	// Tells the sensor to send it's operation register.
	const byte WriteIntMask = 0b00011000;		// Tells the sensor we want to set it's interrupt mask. Controls what can trigger a signal on INT pin
	const byte ReadIntMask = 0b00011010;		// Tells the sensor to send it's interrupt mask
	const byte WriteIntReg = 0b00011100;// Tells the sensor we want to set it's interrupt register. Clears interrupts
	const byte ReadIntReg = 0b00011110;	// Tells the sensor to send it's interrupt register. Shows cause of interrupts
	const byte MeasureT = 0b01001000;	// Start ADC of temperature
	const byte MeasureP = 0b01000100;	// Start ADC of pressure
	const byte MeasureTP = MeasureT | MeasureP;// Start ADC of temperature and then pressure (I think)
	const byte ReadT = 0b01001000;		// Read the raw digitized temperature
	const byte ReadP = 0b01000100;		// Read the raw digitized pressure
	const byte ReadTP = ReadT | ReadP;	// Read the temperature and the pressure (Again I think)

	uint16_t coefficients[10]; // The coefficients needed to convert raw readings to temperature and pressure.
	SPI_HandleTypeDef* spi;

public:
	MS5849(SPI_HandleTypeDef* hspi){
		spi = hspi;
	}
	// Reset the sensor
	HAL_StatusTypeDef reset(){
		HAL_StatusTypeDef errorcode = HAL_SPI_Transmit(spi, (uint8_t*)&RESET, 1, 100);
		HAL_Delay(1);// Takes some time to load data after reset
		return errorcode;
	}
	// Read the conversion coefficients from the sensors memory
	HAL_StatusTypeDef readCoefficients(){

		for(byte adr = 4; adr < 14; adr++){
			byte dataIn[2];
			byte readAdr = ReadMemory | (adr<<2);// Shifting left so that the address for the specific constant is in bits 2 to 5
			HAL_StatusTypeDef errorcode = HAL_OK;
			errorcode = HAL_SPI_Transmit(spi, &readAdr, 1, 100);

			if(errorcode != HAL_OK)
				return errorcode;

			errorcode = HAL_SPI_Receive(spi, dataIn, 2, 100);

			if(errorcode != HAL_OK)
				return errorcode;

			// Combining the two bytes into a single 16 bit number and saving to the array of coefficients
			const byte coefAdr = adr - 4;
			coefficients[coefAdr] = dataIn[0];
			coefficients[coefAdr] = coefficients[coefAdr] << 8;
			coefficients[coefAdr] += dataIn[1];
			HAL_Delay(1);


		}
		return HAL_OK;
	}
	// Load the conversion coefficients into an array (for debug)
	void getCoefficients(uint16_t* arr){
		for(byte i = 0; i < 10; i++){
			arr[i] = coefficients[i];
		}
	}
	// Initialize the sensor and get the conversion coefficients
	byte begin(){
		byte errorcode;
		errorcode = reset();
		errorcode += (readCoefficients() << 4);
		return errorcode;
	}

};
