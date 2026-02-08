#include "cpu.h"
#include "bus.h"

ZynNes::Core::Cpu::Cpu(Bus* bus) {
    // before u read or write in a addr use a evaluate_address<>() from Bus class with address u wanna access to avoid index of bounds exception like this

    // valid ->
    evaluate_address<0xFFFF>();

    // not valid ->
    // evaluate_address<0x1FFFF>();

    // seems pointless but is an extra security!!!

    // connect cpu to the bus
    bus->attachDevice(this, 0);
}
