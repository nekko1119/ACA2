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

        /// <summary>
        /// 赤の値を返す
        /// </summary>
        /// <returns>赤の値</returns>
        std::uint8_t red() const noexcept
        {
            return red_;
        }
        
        /// <summary>
        /// 緑の値を返す
        /// </summary>
        /// <returns>緑の値</returns>
        std::uint8_t green() const noexcept
        {
            return green_;
        }
        
        /// <summary>
        /// 青の値を返す
        /// </summary>
        /// <returns>青の値</returns>
        std::uint8_t blue() const noexcept
        {
            return blue_;
        }
    };
    
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
