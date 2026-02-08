#include "bus.h"
#include "cpu.h"

ZynNes::Core::Bus::Bus() {
}

template<typename T>
void ZynNes::Core::Bus::attachDevice(T* device, std::size_t idx) {
    static_assert(!std::is_void_v<T>, "Device type cannot be void");
    m_devices[idx] = device;
}

template<typename T>
T* ZynNes::Core::Bus::getDevice(std::size_t idx) {
    auto it = m_devices.find(idx);
    if (it == m_devices.end())
        return nullptr;

    if (it->second.type() != typeid(T*)) {
        throw std::bad_any_cast{};
    }

    return std::any_cast<T*>(it->second);
}

// explicit instantiation of cpu case
template void ZynNes::Core::Bus::attachDevice<ZynNes::Core::Cpu>(Cpu*, std::size_t);
template ZynNes::Core::Cpu* ZynNes::Core::Bus::getDevice<ZynNes::Core::Cpu>(std::size_t);

ZynNes::Core::u8 ZynNes::Core::Bus::read(u16 addr) {
    return m_ram[addr];
}

void ZynNes::Core::Bus::write(u16 addr, u8 data) {
    m_ram[addr] = data;
}
