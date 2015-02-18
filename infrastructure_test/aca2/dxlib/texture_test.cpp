#include "stdafx.h"
#include "CppUnitTest.h"
#include <aca2/dxlib/texture.hpp>
#include <DxLib.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template <>
            std::wstring ToString(aca2::texture const& texture)
            {
                std::wostringstream woss;
                woss << texture.get();
                return woss.str();
            }
        }
    }
}

namespace aca2
{
    TEST_CLASS(texture_test)
    {
    public:
        TEST_CLASS_INITIALIZE(texture_test_setup)
        {
            SetWindowVisibleFlag(FALSE);
            ChangeWindowMode(TRUE);
            DxLib_Init();
        }

        TEST_CLASS_CLEANUP(texture_test_teardown)
        {
            DxLib_End();
        }

        TEST_METHOD(textureが読み込める)
        {
            texture tex{"..\\infrastructure_test\\resources\\texture.png"};
        }
    };
}
