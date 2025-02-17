#pragma once

#include <ctrpf.hpp>

namespace base
{
    class rainbow_service
    {
    public:
        struct component
        {
            float v;

            u8 as_u8();
        };

        struct rgb
        {
            component r, g, b;

            u32 as_u32();
        };

        struct hsv
        {
            component h, s, v;

            rgb to_rgb();
        };

        explicit rainbow_service();
        ~rainbow_service();

        void run();

        rgb get_color();
        CTRPluginFramework::Color get_ctrpf_color();

    private:
        float m_hue;
    };

    inline rainbow_service *g_rainbow_service{};
}