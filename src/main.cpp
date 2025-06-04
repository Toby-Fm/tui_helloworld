#include <iostream>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

int main() {
    using namespace ftxui;

    auto document =
        vbox({
            hbox({
                text("Happy") | border | flex,
                text("Pride") | border | flex,
                text("Month") | border | flex,
            }),
            gauge(1) | color(Color::Palette256(9)),
            gauge(1) | color(Color::Palette256(208)),
            gauge(1) | color(Color::Palette256(11)),
            gauge(1) | color(Color::Palette256(10)),
            gauge(1) | color(Color::Palette256(12)),
            gauge(1) | color(Color::Palette256(91)),
        });

    document = document | size(WIDTH, LESS_THAN, 80);

    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);

    std::cout << screen.ToString() << '\0' << std::endl;

    return EXIT_SUCCESS;
}