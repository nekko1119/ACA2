#ifndef ACA2_DXLIB_TEXTURE_HPP
#define ACA2_DXLIB_TEXTURE_HPP

#include <string>
#include <aca2/point.hpp>

namespace aca2
{
    class texture
    {
    public:
        using handle_type = int;

    private:
        handle_type handle_;

    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="filename">画像ファイルのパス</param>
        /// <exception cref="logic_error">DirectXのデバイスの初期化前に使用された場合投げられる</exception>
        /// <exception cref="runtime_error">
        /// ファイルのパスが存在しないなど、ファイルを読み込めなかった場合投げられる
        /// </exception>
        explicit texture(std::string const& filename);

        explicit texture(handle_type handle);

        handle_type get() const noexcept
        {
            return handle_;
        }
    };

    texture derive_texture(texture const& texture, point const& src_point, point const& length);
}

#endif
