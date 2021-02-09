#ifndef EDITORLAYOUT_H
#define EDITORLAYOUT_H

#include <helios/ui.h>

extern UiContainer *Editor_leftPanel;
extern UiViewport *Editor_viewport;
extern UiContainer *Editor_rightPanel;
extern UiContainer *Editor_bottomPanel;

void EditorLayout_Init(void);
void EditorLayout_Cleanup(void);

#endif // EDITORLAYOUT_H