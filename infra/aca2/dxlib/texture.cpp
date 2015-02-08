#include "texture.hpp"
#include <stdexcept>
#include <DxLib.h>

namespace aca2
{
    texture::texture(std::string const& filename)
    {
        if (DxLib_IsInit() == FALSE) {
            throw std::logic_error{"dxlib is not initialized"};
        }
        handle_ = LoadGraph(filename.c_str());
        if (handle_ == -1) {
            throw std::runtime_error{"failed to load a file"};
        }
    }

    texture::texture(handle_type handle)
        : handle_{handle}
    {
    }

    texture derive_texture(texture const& tex, point const& src_point, point const& length)
    {
        auto const new_handle = DerivationGraph(src_point.x(), src_point.y(), length.x(), length.y(), tex.get());
        if (new_handle == -1) {
            throw std::runtime_error{"failed to derive texture"};
        }
        return texture{new_handle};
    }
}
