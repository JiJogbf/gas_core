#pragma once

#include <cstdint>
#include <vector>

namespace gas{
    // TODO: add compiler define for unicode mode
    using char_t = char;
    using char_p = char_t*;
    using char_cp = const char_t*;
    
    using u8  = uint8_t;    
    using u16 = uint16_t;    
    using u32 = uint32_t;    
    using u64 = uint64_t;
    using i8  = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;

    using f64 = double;
    using f32 = float;

    // @todo: replace stl containers with own implementation's
    using ByteArray = std::vector<u8>;
}