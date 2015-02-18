#ifndef ACA2_UTILITY_VALIDATOR_HPP
#define ACA2_UTILITY_VALIDATOR_HPP

#include <string>

namespace aca2
{
    namespace validator
    {
        template <typename Exception>
        void validate(bool expression, std::string const& message)
        {
            if (!expression) {
                throw Exception{message};
            }
        }
    }
}

#endif
