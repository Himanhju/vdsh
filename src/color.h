#ifndef COLORS_H
#define COLORS_H

// Basic Text Colors
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

// Bold Text Colors
#define BD_BLACK       "\033[1;30m"
#define BD_RED         "\033[1;31m"
#define BD_GREEN       "\033[1;32m"
#define BD_YELLOW      "\033[1;33m"
#define BD_BLUE        "\033[1;34m"
#define BD_MAGENTA     "\033[1;35m"
#define BD_CYAN        "\033[1;36m"
#define BD_WHITE       "\033[1;37m"

// Background Colors
#define BG_BLACK         "\033[48;5;0m"
#define BG_RED           "\033[48;5;1m"
#define BG_GREEN         "\033[48;5;2m"
#define BG_YELLOW        "\033[48;5;3m"
#define BG_BLUE          "\033[48;5;4m"
#define BG_MAGENTA       "\033[48;5;5m"
#define BG_CYAN          "\033[48;5;6m"
#define BG_WHITE         "\033[48;5;7m"

// Extended 256 Colors
#define EXT_COLOR(c)     "\033[38;5;" #c "m"
#define BG_EXT_COLOR(c)  "\033[48;5;" #c "m"

// True Color (24-bit colors) - RGB format
#define RGB_COLOR(r, g, b)    "\033[38;2;" #r ";" #g ";" #b "m"
#define BG_RGB_COLOR(r, g, b) "\033[48;2;" #r ";" #g ";" #b "m"

#endif // COLORS_H

