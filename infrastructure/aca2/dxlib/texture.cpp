﻿#include "texture.hpp"
#include <aca2/utility/precondition.hpp>
#include <stdexcept>
#include <boost/filesystem.hpp>
#include <DxLib.h>

namespace aca2
{
    texture::texture(std::string const& filename)
    {
        boost::filesystem::path const path{filename};
        precondition::validate_argument(boost::filesystem::exists(path), "file is not found");
        precondition::validate_state(DxLib_IsInit() == TRUE, "dxlib is not initialized");
        handle_ = LoadGraph(filename.c_str());
        validator::validate<std::runtime_error>(handle_ != -1, "failed to load a file");
    }

    texture::texture(handle_type handle)
        : handle_{handle}
    {
    }

    texture derive_texture(texture const& tex, point const& src_point, point const& length)
    {
        auto const new_handle = DerivationGraph(src_point.x(), src_point.y(), length.x(), length.y(), tex.get());
        validator::validate<std::runtime_error>(new_handle == -1, "failed to derive texture");
        return texture{new_handle};
    }
}
