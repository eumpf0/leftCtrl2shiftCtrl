// -------------------------------------------------------+
//    leftCtrl2shiftCtrl - an interception-tools plugin   |
//        Elias Rumpf (github.com/eumpf0), 2022           |
// -------------------------------------------------------+

#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>

#define TRIGGER_KEY KEY_LEFTCTRL

int read_event(struct input_event* event) {
    return fread(event, sizeof(struct input_event), 1, stdin) == 1;
}

void write_event(const struct input_event* event) {
    if (fwrite(event, sizeof(struct input_event), 1, stdout) != 1) {
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    setbuf(stdin, NULL), setbuf(stdout, NULL);

    struct input_event input;

    while (read_event(&input)) {
        if (input.type == EV_KEY && input.code == TRIGGER_KEY) {
            struct input_event lctrl  = {.type = EV_KEY, .code = KEY_LEFTCTRL,  .value = input.value};
            struct input_event lshift = {.type = EV_KEY, .code = KEY_LEFTSHIFT, .value = input.value};
            write_event(&lctrl);
            write_event(&lshift);
        } else {
            write_event(&input);
        }
    }
}
