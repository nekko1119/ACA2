#include "stdafx.h"
#include "CppUnitTest.h"
#include <aca2/point.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template <typename T>
            std::wstring ToString(aca2::basic_point<T> const& point)
            {
                std::wostringstream woss;
                woss << L"point(" << point.x() << L", " << point.y() << L")";
                return woss.str();
            }
        }
    }
}

namespace aca2
{
    TEST_CLASS(point_test)
    {
    public:
        TEST_METHOD(point同士で加算代入できる)
        {
            point actual{1, 2};
            point const addend{2, 3};
            point const expected = {3, 5};
            actual += addend;
            Assert::AreEqual(expected, actual, L"(1, 2) + (2, 3)は(3, 5)");
        }

        TEST_METHOD(pointと数値で加算代入できる)
        {
            point actual{1, 2};
            point const expected = {3, 4};
            actual += 2;
            Assert::AreEqual(expected, actual, L"(1, 2) + 2は(3, 4)");
        }

        TEST_METHOD(point同士で加算できる)
        {
            point const expected = {3, 5};
            auto const actual = point{1, 2} + point{2, 3};
            Assert::AreEqual(expected, actual, L"(1, 2) + 2は(3, 4)");
        }

        TEST_METHOD(pointと数値で加算できる)
        {
            point const expected = {3, 4};
            auto const actual = point{1, 2} + 2;
            Assert::AreEqual(expected, actual, L"(1, 2) + 2は(3, 4)");
        }

        TEST_METHOD(数値とpointで加算できる)
        {
            point const expected = {3, 4};
            auto const actual = 2 + point{1, 2};
            Assert::AreEqual(expected, actual, L"(1, 2) + 2は(3, 4)");
        }

        TEST_METHOD(point同士で等値演算できる)
        {
            point const p1{1, 2};
            point const p2{1, 2};
            point const p3{1, 3};
            Assert::AreEqual(p1, p2, L"p1とp2は等しい");
            Assert::AreNotEqual(p1, p3, L"p1とp3は等しくない");
        }
    };
}
