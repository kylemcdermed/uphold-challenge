#include <cctype>
#include <string>
#include <string_view>
#include <cstring>   

std::string padDigitGroups(std::string_view input, int width) {
    if (width <= 0) {
        return std::string(input);
    }

    std::size_t extraZeros = 0;
    std::size_t i = 0;
    const std::size_t N = input.size();

    while (i < N) {
        if (input[i] < '0' || input[i] > '9') {
            ++i;
            continue;
        }

        std::size_t start = i;
        while (i < N && input[i] >= '0' && input[i] <= '9') {
            ++i;
        }

        std::size_t digitCount = i - start;
        if (digitCount < static_cast<std::size_t>(width)) {
            extraZeros += static_cast<std::size_t>(width) - digitCount;
        }
    }

    if (extraZeros == 0) {
        return std::string(input);
    }

    std::string output;
    output.resize(N + extraZeros);

    char* dst = output.data();
    std::size_t pos = 0;
    i = 0;

    while (i < N) {
        if (input[i] < '0' || input[i] > '9') {
            dst[pos++] = input[i++];
            continue;
        }

        std::size_t start = i;
        while (i < N && input[i] >= '0' && input[i] <= '9') {
            ++i;
        }

        std::size_t digitCount = i - start;

        if (digitCount < static_cast<std::size_t>(width)) {
            std::memset(dst + pos, '0', static_cast<std::size_t>(width) - digitCount);
            pos += static_cast<std::size_t>(width) - digitCount;
        }

        std::memcpy(dst + pos, input.data() + start, digitCount);
        pos += digitCount;
    }

    return output;
}
