#ifndef happyFace_included
#define happyFace_included

extern char face_done;

void happyFace();
void drawOpenEyes();
void drawClosedEyes();
void update_face_eyes();
void drawSleepSymbols();
void restoreMain();
void clearMain();
void drawBoat();
void drawPiano();
void drawTriangle();
void twinkle();
void drawRunaway();
void drawMc();


extern int eyes_state;
extern int eyes_open;
extern int boat;
extern int piano;
extern int album;
extern int christmas;
extern int run;
extern int mc;
#endif // included
