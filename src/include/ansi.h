
#define CSI_BEGIN "\x1b["
#define CSI_END "\x1b[0m"

#define ANSI(code) CSI_BEGIN code CSI_END

#define CURSOR_UP(n) CSI_BEGIN n "A" CSI_END
#define CURSOR_DOWN(n) CSI_BEGIN n "B" CSI_END
#define CURSOR_FORWARD(n) CSI_BEGIN n "C" CSI_END
#define CURSOR_BACK(n) CSI_BEGIN n "D" CSI_END
#define CURSOR_NEXT(n) CSI_BEGIN n "E" CSI_END
#define CURSOR_PREVIOUS(n) CSI_BEGIN n "F" CSI_END
#define CURSOR_ABSOLUTE_HORISONTAL(n) CSI_BEGIN n "G" CSI_END
#define CURSOR_POSITION(n, m) CSI_BEGIN n ";" m "H" CSI_END
#define ERASE_SCREEN(n) CSI_BEGIN n "J" CSI_END
#define ERASE_LINE(n) CSI_BEGIN n "k" CSI_END

// Colors

#define RED "31;1m"
#define GREEN "32;1m"
#define YELLOW "33;1m"
#define BLUE "34;1m"
#define MAGNETA "35;1m"
#define CYAN "36m;1"
#define WHITE "37;1m"

#define COLOR(code, text) CSI_BEGIN code text CSI_END
#define BOLD(text) CSI_BEGIN "1m" text CSI_END
#define ITALIC_MODERN(text) CSI_BEGIN "2m" text CSI_END 
#define UNDERLINE_MODERN(text) CSI_BEGIN "4m" text CSI_END
#define SLOW_BLINK() ANSI("5m")

#define SCROLL_DOWN(n) CSI_BEGIN n "T" CSI_END
#define SCROLL_UP(n) CSI_BEGIN n "S" CSI_END
