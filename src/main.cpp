#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/terminal.hpp>
#include <ftxui/screen/color.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath> // für std::sin

int main() {
    using namespace ftxui;

    std::vector<Color> colors = {
        Color::RGB(255, 0, 0),      // Rot
        Color::RGB(255, 140, 0),    // Orange
        Color::RGB(255, 255, 0),    // Gelb
        Color::RGB(0, 255, 0),      // Grün
        Color::RGB(0, 128, 255),    // Blau
        Color::RGB(128, 0, 128),    // Lila
    };

    int frame = 0;
    bool running = true;
    int max_frames = 300;

    while (running) {
        std::vector<Element> flag;
        for (size_t i = 0; i < colors.size(); ++i) {
            // "Wellen"-Effekt mit Sinus: Phase variiert mit Zeile & Frame
            double progress = 0.6 + 0.4 * std::sin(frame * 0.15 + i * 0.7);
            flag.push_back(gauge(progress) | color(colors[i]) | flex);
        }

        auto document =
            vbox({
                hbox({
                    text("Happy") | border | flex,
                    text("Pride") | border | flex,
                    text("Month") | border | flex,
                }),
                separator(),
                vbox(flag) | flex,
            });

        auto screen = Screen::Create(Dimension::Full(), Dimension::Full());
        Render(screen, document);

        // Clear Terminal & Ausgabe
        std::cout << "\033[H\033[J" << screen.ToString() << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ++frame;
        if (frame > max_frames) running = false;
    }

    return EXIT_SUCCESS;
}