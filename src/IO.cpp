#include "IO.hpp"

// this file contains things to communicate with hardware ports.

namespace Sauce{
    namespace IO{
        // 8bit
        void outb(uint16_t port,uint8_t val,bool slow){
            if(slow){
                asm volatile ("outb %0, %1\njmp 1f\n1: jmp 1f\n1:": : "a"(val), "Nd"(port));
            }else{
                asm volatile ("outb %0, %1": : "a"(val), "Nd"(port));
            }
        }
        uint8_t inb(uint16_t port){
            uint8_t Result=NULL;
            asm volatile("inb %1, %0": "=a"(Result): "Nd"(port));
            return Result;
        }
        // 16bit
        void outw(uint16_t port,uint16_t val){
            asm volatile ("outw %0, %1": : "a"(val), "Nd"(port));
        }
        uint16_t inw(uint16_t port){
            uint16_t Result=NULL;
            asm volatile("inw %1, %0": "=a"(Result): "Nd"(port));
            return Result;
        }
        // 32bit
        void outl(uint16_t port,uint32_t val){
                asm volatile ("outl %0, %1": : "a"(val), "Nd"(port));

        }
        uint32_t inl(uint16_t port){
            uint32_t Result=NULL;
            asm volatile("inl %1, %0": "=a"(Result): "Nd"(port));
            return Result;
        }
        void RemapPic(){
            uint8_t a1,a2;
            a1 = inb(PIC1_DATA);
            a2 = inb(PIC2_DATA);
            outb(PIC1_COMMAND,ICW1_INIT|ICW1_ICW4);
            outb(PIC2_COMMAND,ICW1_INIT|ICW1_ICW4);
            outb(PIC1_DATA,0);
            outb(PIC2_DATA,8);
            outb(PIC1_DATA,4);
            outb(PIC2_DATA,2);
            outb(PIC1_DATA,ICW4_8086);
            outb(PIC2_DATA,ICW4_8086);

            outb(PIC1_DATA,a1);
            outb(PIC2_DATA,a2);
        }
        int init_serial(){
            outb(COMn + 1, 0x00);    // Disable all interrupts
            outb(COMn + 3, 0x80);    // Enable DLAB (set baud rate divisor)
            outb(COMn + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
            outb(COMn + 1, 0x00);    //                  (hi byte)
            outb(COMn + 3, 0x03);    // 8 bits, no parity, one stop bit
            outb(COMn + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
            outb(COMn + 4, 0x0B);    // IRQs enabled, RTS/DSR set
            outb(COMn + 4, 0x1E);    // Set in loopback mode, test the serial chip
            outb(COMn + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)

            // Check if serial is faulty (i.e: not same byte as sent)
            if(inb(COMn + 0) != 0xAE) {
               return 1;
            }
            // If serial is not faulty set it in normal operation mode
            // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
            outb(COMn + 4, 0x0F);
            return 0;
        }
        int serial_received(){
            return inb(COMn + 5) & 1;
        }
        char read_serial(){
            while (serial_received() == 0);
 
            return inb(COMn);
        }
        int is_transmit_empty(){
            return inb(COMn + 5) & 0x20;
        }
        void write_serial(char a){
            while (is_transmit_empty() == 0);
            outb(COMn,a);
        }
    };
};

namespace External{
    namespace IO{
        _Port::_Port(uint16_t port_number){
            this->port_number=port_number;
        }
        _Port::~_Port(){}

        _8Bit_Port::_8Bit_Port(uint16_t port_number):_Port(port_number){}
        _8Bit_Port::~_8Bit_Port(){}
        void _8Bit_Port::operator<<(uint8_t Data){
            Sauce::IO::outb(port_number,Data);
        }
		void _8Bit_Port::operator>>(uint8_t &Data){
            Data = Sauce::IO::inb(port_number);
        }

        _8BitSlow_Port::_8BitSlow_Port(uint16_t port_number):_8Bit_Port(port_number){}
        _8BitSlow_Port::~_8BitSlow_Port(){}
        void _8BitSlow_Port::operator<<(uint8_t Data){
            Sauce::IO::outb(port_number,Data,true);
        }

        _16Bit_Port::_16Bit_Port(uint16_t port_number):_Port(port_number){}
        _16Bit_Port::~_16Bit_Port(){}
        void _16Bit_Port::operator<<(uint16_t Data){
            Sauce::IO::outw(port_number,Data);
        }
		void _16Bit_Port::operator>>(uint16_t &Data){
            Data = Sauce::IO::inw(port_number);
        }

        _32Bit_Port::_32Bit_Port(uint16_t port_number):_Port(port_number){}
        _32Bit_Port::~_32Bit_Port(){}
        void _32Bit_Port::operator<<(uint32_t Data){
            Sauce::IO::outl(port_number,Data);
        }
		void _32Bit_Port::operator>>(uint32_t &Data){
            Data = Sauce::IO::inl(port_number);
        }
    };
};

