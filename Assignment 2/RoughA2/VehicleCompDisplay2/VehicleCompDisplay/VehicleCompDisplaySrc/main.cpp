
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

// You can use this code to cause your display to sleep
#include "DisplaySleep.h"

using namespace std;



int main() {
	// This is the code from page 441
	Window win1(Point(100, 100), 600, 400, "two lines");
	Line horizontal(Point(100, 100), Point(200, 100));
	Line vertical(Point(150, 50), Point(150, 150));
	win1.show();

	// The following is a rough processing loop design for A2.
	// This code just turns the cross on or off

	// Cause the cross to blink 10 times
	int i; 
	for (i = 0 ; i < 10; i++) {
		win1.attach(horizontal);
		win1.attach(vertical);
		win1.redraw();
		Fl::check();
		DisplaySleep(200);
		win1.detach(horizontal);
		win1.detach(vertical);
		win1.redraw();
		Fl::check();
		DisplaySleep(200);
		cout << "sleeping" << endl;
	}

	// Now tick a digital clock - sort of 
	win1.detach(vertical);
	win1.detach(horizontal);

	for (i = 0; i < 10 ; i++) {
		ostringstream oss;
		oss << i;
		Text timer(Point(200, 200), oss.str());
		timer.set_font(Font::times_bold);
		timer.set_font_size(40);

			timer.set_color(Color::red);

		win1.attach(timer);
		win1.redraw();
		Fl::check();
		DisplaySleep(1000);
	}



}