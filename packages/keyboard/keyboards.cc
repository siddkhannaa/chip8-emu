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

#include <emojicode/runtime/Runtime.h>

int kbhit(void) {
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

// runtime::Boolean keyToASCII(runtime::Boolean key) {
//     switch ((uint64_t)key) {
//         case 0x0:
//             return 120;
//         case 0x1:
//             return 49;
//         case 0x2:
//             return 50;
//         case 0x3: 
//             return 51;
//         case 0x4:
//             return 113;
//         case 0x5:
//             return 119;
//         case 0x6:
//             return 101;
//         case 0x7:
//             return 97;
//         case 0x8:
//             return 115;
//         case 0x9:
//             return 100;
//         case 0xA:
//             return 122;
//         case 0xB:
//             return 99;
//         case 0xC:
//             return 52;
//         case 0xD:
//             return 114;
//         case 0xE:
//             return 102;
//         case 0xF:
//             return 118;
//     }
// }

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