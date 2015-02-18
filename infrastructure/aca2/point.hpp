#ifndef ACA2_POINT_HPP
#define ACA2_POINT_HPP

#include <type_traits>

namespace aca2
{
    template <typename T>
    class basic_point
    {
        static_assert(std::is_arithmetic<T>::value, "basic_point<T> : T must be arithmetic type");

        T x_;
        T y_;

    public:
        using value_type = T;

        explicit basic_point(T value)
            : basic_point(value, value)
        {
        }

        basic_point(T x, T y)
            : x_{x}, y_{y}
        {
        }

        T const& x() const noexcept
        {
            return x_;
        }

        void x(T value)
        {
            x_ = value;
        }

        T const& y() const noexcept
        {
            return y_;
        }

        void y(T value)
        {
            y_ = value;
        }

        basic_point& operator+=(basic_point const& that)
        {
            x_ += that.x_;
            y_ += that.y_;
            return *this;
        }

        basic_point& operator+=(T value)
        {
            return *this += basic_point{value};
        }

        basic_point& operator-=(basic_point const& that)
        {
            x_ -= that.x_;
            y_ -= that.y_;
            return *this;
        }

        basic_point& operator*=(basic_point const& that)
        {
            x_ *= that.x_;
            y_ *= that.y_;
            return *this;
        }
    };

    template <typename T>
    basic_point<T> operator+(basic_point<T> lhs, basic_point<T> const& rhs)
    {
        return lhs += rhs;
    }

    template <typename T>
    basic_point<T> operator+(basic_point<T> point, T value)
    {
        return point += basic_point<T>{value};
    }

    template <typename T>
    basic_point<T> operator+(T value, basic_point<T> point)
    {
        return point + value;
    }

    template <typename T>
    inline bool operator==(basic_point<T> const& lhs, basic_point<T> const& rhs) noexcept
    {
        return lhs.x() == rhs.x() && lhs.y() == rhs.y();
    }

    template <typename T>
    inline bool operator!=(basic_point<T> const& lhs, basic_point<T> const& rhs) noexcept
    {
        return !(lhs == rhs);
    }

    using point = basic_point<int>;
}

#endif
