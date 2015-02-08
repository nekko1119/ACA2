#include "stdafx.h"
#include "CppUnitTest.h"
#include <aca2/rgb.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template <>
            std::wstring ToString(aca2::rgb const& value)
            {
                std::wostringstream woss;
                woss << L"rgb(";
                woss << std::to_wstring(value.red()) + L", ";
                woss << std::to_wstring(value.green()) + L", ";
                woss << std::to_wstring(value.blue()) + L")";
                return woss.str();
            }
        }
    }
}

namespace aca2
{
    TEST_CLASS(rgb_test)
    {
    public:
        TEST_METHOD(正しくインスタンス化できる)
        {
            rgb const& rgb{64U, 128U, 255U};
            Assert::AreEqual<std::uint8_t>(64U, rgb.red(), L"赤は64");
            Assert::AreEqual<std::uint8_t>(128U, rgb.green(), L"緑は128");
            Assert::AreEqual<std::uint8_t>(255U, rgb.blue(), L"青は255");
        }

        TEST_METHOD(符号なし整数値へ変換できる)
        {
            rgb const rgb{255, 0, 128};
            auto const num = to_uint(rgb);
            Assert::AreEqual(0xFF0080U, num, L"(255, 0, 128)は整数値で0xFF0080になる");
        }
    };
}