#ifndef ACA2_RGB_HPP
#define ACA2_RGB_HPP

#include <cstdint>

namespace aca2
{
    class rgb
    {
        std::uint8_t red_;
        std::uint8_t green_;
        std::uint8_t blue_;

    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="red">赤</param>
        /// <param name="green">緑</param>
        /// <param name="blue">青</param>
        rgb(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
            : red_{red}, green_{green}, blue_{blue}
        {
        }

        std::uint8_t red() const noexcept
        {
            return red_;
        }

        std::uint8_t green() const noexcept
        {
            return green_;
        }

        std::uint8_t blue() const noexcept
        {
            return blue_;
        }
    };

    inline bool operator==(rgb const& l, rgb const& r) noexcept
    {
        return l.red() == r.red() && l.green() == r.green() && l.blue() == r.blue();
    }

    inline bool operator!=(rgb const& l, rgb const& r) noexcept
    {
        return !(l == r);
    }
    
    /// <summary>
    /// <see cref="rgb">rgb</see>を符号なし整数値に変換する
    /// </summary>
    /// <param name="rgb">rgbインスタンス</param>
    /// <returns>rgbの符号なし整数値</returns>
    inline std::uint32_t to_uint(rgb const& rgb) noexcept
    {
        return (rgb.red() << 16) | (rgb.green() << 8) | rgb.blue();
    }
}

#endif
