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
            gauge(1) | color(Color::RGB(255, 0, 0)),
            gauge(1) | color(Color::RGB(255, 140, 0)),
            gauge(1) | color(Color::RGB(255, 255, 0)),
            gauge(1) | color(Color::RGB(0, 255, 0)),
            gauge(1) | color(Color::RGB(0, 128, 255)),
            gauge(1) | color(Color::RGB(128, 0, 128)),
       });

    document = document | size(WIDTH, LESS_THAN, 80);

    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);

    std::cout << screen.ToString() << '\0' << std::endl;

    return EXIT_SUCCESS;
}