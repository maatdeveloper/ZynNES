#include "nes.h"
#include "bus.h"
#include "cpu.h"

ZynNes::Core::Nes::Nes() {
    m_bus = std::make_unique<Bus>();
    // pass bus instance pointer to cpu can attach onto
    m_cpu = std::make_unique<Cpu>(m_bus.get());
};

ZynNes::Core::Nes::~Nes() {

}

void ZynNes::Core::Nes::run() {

}

