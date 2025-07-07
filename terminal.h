#ifndef TERMINAL_H
#define TERMINAL_H

#define CTRL_KEY(k) ((k) & 0x1f)

void die();
void enter_raw_mode();
void exit_raw_mode();
char read_key();
void process_key();
void refresh_display();

#endif
