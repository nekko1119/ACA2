#include "stdafx.h"
#include "CppUnitTest.h"
#include <aca2/rgb.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace aca2
{
    TEST_CLASS(rgb_test)
    {
    public:
        TEST_METHOD(符号なし整数値へ変換できる)
        {
            rgb const rgb{255, 0, 128};
            auto const num = to_uint(rgb);
            Assert::AreEqual(0xFF0080U, num, L"(255, 0, 128)は整数値で0xFF0080になる");
        }

    };
}