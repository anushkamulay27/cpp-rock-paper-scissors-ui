#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    
    cout << "Initializing graphics..." << endl;
    initgraph(&gd, &gm, NULL);
    
    if (graphresult() != grOk) {
        cout << "Graphics error: " << grapherrormsg(graphresult()) << endl;
        return 1;
    }
    
    cout << "Graphics initialized successfully!" << endl;
    
    setcolor(WHITE);
    outtextxy(100, 100, (char*)"Test");
    
    delay(3000);
    closegraph();
    return 0;
}