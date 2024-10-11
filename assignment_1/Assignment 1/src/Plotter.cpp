#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    PenStyle style = {1, "black"};
    bool penUp = true;
    double x0 = 0, y0 = 0;
    for (string line; getline(input, line); ) {
        line = toLowerCase(line);
        if (startsWith(line, "pendown")) {
            penUp = false;
        }

        if (startsWith(line, "penup")) {
            penUp = true;
        }

        if (startsWith(line, "moveabs")) {
            Vector<string> command = stringSplit(line, " ");
            double x1 = stringToReal(command[1]);
            double y1 = stringToReal(command[2]);
            if (!penUp) drawLine(x0, y0, x1, y1, style);
            x0 = x1;
            y0 = y1;
        }

        if (startsWith(line, "moverel")) {
            Vector<string> command = stringSplit(line, " ");
            double dx = stringToReal(command[1]);
            double dy = stringToReal(command[2]);
            if (!penUp) drawLine(x0, y0, x0 + dx, y0 + dy, style);
            x0 += dx;
            y0 += dy;
        }

        if (startsWith(line, "pencolor")) {
            Vector<string> command = stringSplit(line, " ");
            style.color = command[1];
        }

        if (startsWith(line, "penwidth")) {
            Vector<string> command = stringSplit(line, " ");
            double penWidth = stringToReal(command[1]);
            style.width = penWidth;
        }
    }
}
