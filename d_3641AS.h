#ifndef d_3641AS_h
#define d_3641AS_h

#include "Arduino.h"
#include "independent_libs/digitalWriteFast.h"

namespace d_3641AS{
    struct ISoft_3641AS {
        virtual void setupPins() = 0;
        virtual void sendOutFull(uint16_t val) = 0;
        virtual void sendOutSingle(uint8_t reg, uint8_t val) = 0;
        virtual ~ISoft_3641AS() {}
    };

    void display1(ISoft_3641AS &d, uint8_t digit, uint8_t value) {
        // turn off all digits
        d.sendOutFull(0b0000111100000000);
        uint16_t res = 0;
        res = res | (uint16_t)value;
        digit += (1 << (digit - 1)) - digit;
        digit = digit ^ 15;
        res = res | digit << 8;
        d.sendOutFull(res);
    }
    void display4(ISoft_3641AS &d, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4) {
        display1(d, 1, d1);
        display1(d, 2, d2);
        display1(d, 3, d3);
        display1(d, 4, d4);
        // turn off all digits 
        d.sendOutFull(0b0000111100000000);
    }

}

namespace DefaultSoftDrivers_3641AS{
    struct DirectPinsSoft_3641AS : public d_3641AS::ISoft_3641AS {
        public:
            uint8_t* registers;


            DirectPinsSoft_3641AS(uint8_t *registers) {
                this->registers = registers;
            }

            void setupPins() override{
                for (uint8_t i = 0; i < 12; i++)
                    pinModeFast(registers[i], OUTPUT);
            }

            void sendOutSingle(uint8_t reg, uint8_t val) override{
                digitalWriteFast(registers[reg], val);
            }

            void sendOutFull(uint16_t val) override {
                for (uint8_t i = 12; i >= 1; i--)
                    digitalWriteFast(this->registers[i - 1], (val & (1 << (i - 1))) >> (i-1));
            }
    };
}

#endif