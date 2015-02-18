#ifndef ACA2_UTILITY_PRECONDITION_HPP
#define ACA2_UTILITY_PRECONDITION_HPP

#include <stdexcept>
#include <aca2/utility/validator.h>

namespace aca2
{
    namespace precondition
    {
        /// <summary>
        /// 関数に渡される引数が有効か検証する
        /// </summary>
        /// <param name="expression">引数が有効か判定する条件式</param>
        /// <param name="message">条件式が偽の場合に投げられる<see chef=std::invalid_argumentの引数文字列</param>
        void validate_argument(bool expression, std::string const& message)
        {
            validator::validate<std::invalid_argument>(expression, message);
        }

        void validate_state(bool expression, std::string const& message)
        {
            validator::validate<std::runtime_error>(expression, message);
        }
    }
}

#endif
