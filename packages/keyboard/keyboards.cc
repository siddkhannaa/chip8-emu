// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <cstdint>

// #include<ncurses.h>


// extern "C" void doit(runtime::ClassInfo*) {

//     initscr();
//     printw("Hello world\n");
//     refresh();
//     getch();
//     endwin();
//     // return 0;
// }

#include <ncurses.h>
#include <unistd.h>  /* only for sleep() */
#include <string>

#include <emojicode/runtime/Runtime.h>
#include <emojicode/s/String.h>

int kbhit(void) {
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

runtime::Integer ASCIIToKey(runtime::Integer ASCII) {
    switch ((uint64_t)ASCII) {
        case 120:
			return 0x0;
        case 49:
			return 0x1;
        case 50:
			return 0x2;
        case 0x3: 
            return 51;
        case 113:
			return 0x4;
        case 119:
			return 0x5;
        case 101:
			return 0x6;
        case 97:
			return 0x7;
        case 115:
			return 0x8;
        case 100:
			return 0x9;
        case 122:
			return 0xA;
        case 99:
			return 0xB;
        case 52:
			return 0xC;
        case 114:
			return 0xD;
        case 102:
			return 0xE;
        case 118:
			return 0xF;
    }
}

extern "C" void kbSetup(runtime::ClassInfo*) {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
}

extern "C" void kbEnd(runtime::ClassInfo*) {
    endwin();
}

extern "C" runtime::Boolean checkPressed(runtime::ClassInfo*, runtime::Integer target) {
    if (kbhit()) {
        runtime::Integer key = ASCIIToKey((runtime::Integer)getch());
        refresh();

        if (key == target) {
            return (runtime::Boolean)true;
        }
    }

    return (runtime::Boolean)false;
}

extern "C" runtime::Integer waitForKey(runtime::ClassInfo*) {
    while (1) {
        if (kbhit()) {
            runtime::Integer key = ASCIIToKey((runtime::Integer)getch());
            refresh();

            return key;
        }
        else {
            refresh();
            sleep(1);
        }
    }
}

extern "C" void writeToBuffer(runtime::ClassInfo*, s::String *chars) {
    std::string cppString = chars->stdString();
    printw(cppString.c_str());
}

extern "C" void newline(runtime::ClassInfo*) {
    printw("\n");
}

extern "C" void displayBuffer(runtime::ClassInfo*) {
    refresh();
}

extern "C" void clearDisplay(runtime::ClassInfo*) {
    clear();
}