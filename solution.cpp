#include <cctype>
#include <string>
#include <string_view>

std::string padDigitGroups(std::string_view input, int width) {
    if (width <= 0) {
        return std::string(input);
    }

    std::string output;
    output.reserve(input.size() + 32);

    std::size_t i = 0;
    while (i < input.size()) {
        unsigned char ch = static_cast<unsigned char>(input[i]);

        if (!std::isdigit(ch)) {
            output.push_back(input[i]);
            ++i;
            continue;
        }

        std::size_t start = i;
        while (i < input.size() && std::isdigit(static_cast<unsigned char>(input[i]))) {
            ++i;
        }

        std::size_t digitCount = i - start;

        if (digitCount < static_cast<std::size_t>(width)) {
            output.append(static_cast<std::size_t>(width) - digitCount, '0');
        }

        output.append(input.substr(start, digitCount));
    }

    return output;
}
