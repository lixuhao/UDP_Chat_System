#include "window.h"

window::window()
{
	initscr(); //COLS, LINES
}

WINDOW *window::get_header()
{
	return header;
}
WINDOW *window::get_output()
{
	return output;
}
WINDOW *window::get_flist()
{
	return flist;
}
WINDOW *window::get_input()
{
	return input;
}
void window::get_string_from_window(WINDOW *w, std::string &out_string)
{
	char buf[SIZE];
	wgetnstr(w, buf, SIZE);
	out_string = buf;
}

void window::put_string_to_window(WINDOW *w, int y, int x, std::string &message)
{
	mvwaddstr(w, y, x, message.c_str());
	wrefresh(w);
}

void window::draw_header()
{
	int y = 0;
	int x = 0;
	int h = LINES/5;
	int w = COLS;

	header = newwin(h, w, y, x);
	box(header, '+', '=');
	wrefresh(header);
}

void window::draw_output()
{
	int y = LINES/5;
	int x = 0;
	int h = LINES*3/5;
	int w = COLS*3/4;

	output = newwin(h, w, y, x);
	box(output, 0, 0);
	wrefresh(output);
}

void window::draw_flist()
{
	int y = LINES/5;
	int x = COLS*3/4;
	int h = LINES*3/5;
	int w = COLS/4;

	flist = newwin(h, w, y, x);
	box(flist, 0, 0);
	wrefresh(flist);
}

void window::draw_input()
{
	int y = LINES*4/5;
	int x = 0;
	int h = LINES/5;
	int w = COLS;

	input = newwin(h, w, y, x);
	box(input, 0, 0);
	wrefresh(input);
}

window::~window()
{
	endwin();
}

//int main()
//{
//	window w;
//	w.draw_header();
//	w.draw_output();
//	w.draw_flist();
//	w.draw_input();
//
//
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

