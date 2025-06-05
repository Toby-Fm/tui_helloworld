#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/terminal.hpp>
#include <ftxui/screen/color.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

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


    // ===========================================
    // Alles in eine While schleife, damit man
    // "im" Programm bleibt bzw. nicht sofort
    // beendet wird
    // ===========================================
    bool running = true;
    while (running) {
        std::vector<Element> flag;
        for (size_t i = 0; i < colors.size(); ++i) {
            // "Wellen"-Effekt mit Sinus: Phase variiert mit Zeile & Frame
            flag.push_back(gauge(1) | color(colors[i]));
        }
        // ===========================================
        // Content
        // ===========================================
        auto document =
            vbox({
                hbox({
                    text("Happy") | border | flex,
                    text("Pride") | border | flex,
                    text("Month") | border | flex,
                }),
                vbox(flag),
            });

        // ===========================================
        // Setzt windows Size
        // ===========================================
        auto screen = Screen::Create(
            Dimension::Full(),
            Dimension::Full()
        );
        Render(screen, document);

        // Clear Terminal & Ausgabe
        std::cout << screen.ToString() << std::flush;
        // ===========================================
        // cleane Aktualisierungsrate, damit das Bild
        // flüssig ist und nicht bugt
        // ===========================================
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
   }

    return EXIT_SUCCESS;
}