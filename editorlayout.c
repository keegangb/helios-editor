#include "editorlayout.h"

#include <helios/core.h>

#include "application.h"

UiContainer *Editor_leftPanel = null;
UiViewport *Editor_viewport = null;
UiContainer *Editor_rightPanel = null;
UiContainer *Editor_lowerPanel = null;

static UiContainer *upperSplit = null;

static void InitLeftPanel(void)
{
    UiContainer_SetRect(Editor_leftPanel, UIRECT(0, 0, 300, UI_MAX_SIZE));
    UiContainer_SetColor(Editor_leftPanel, COLOR(1.0, 0.0, 0.0, 1.0));
    UiContainer_SetLayout(Editor_leftPanel, UILAYOUT_VERTICAL);
}

static void InitRightPanel(void)
{
    UiContainer_SetRect(Editor_rightPanel, UIRECT(0, 0, 300, UI_MAX_SIZE));
    UiContainer_SetColor(Editor_rightPanel, COLOR(0.0, 1.0, 0.0, 1.0));
    UiContainer_SetLayout(Editor_rightPanel, UILAYOUT_VERTICAL);
}

static void InitLowerPanel(void)
{
    UiContainer_SetRect(Editor_lowerPanel, UIRECT(0, 0, UI_MAX_SIZE, 200));
    UiContainer_SetColor(Editor_lowerPanel, COLOR(0.0, 0.0, 1.0, 1.0));
    UiContainer_SetLayout(Editor_lowerPanel, UILAYOUT_VERTICAL);
}

void EditorLayout_Init(void)
{
    const UiCanvas *canvas = Application_mainCanvas;

    HObject *upperSplitObject = HObject_Create("Upper Split", canvas->object, null);
    upperSplit = HObject_AddComponent(upperSplitObject, "UiContainer");
    UiContainer_SetLayout(upperSplit, UILAYOUT_HORIZONTAL);
    UiContainer_SetRect(upperSplit, UIRECT(0, 0, UI_MAX_SIZE, UI_MAX_SIZE));

    HObject *leftPanelObject = HObject_Create("Left Panel", upperSplitObject, null);
    Editor_leftPanel = HObject_AddComponent(leftPanelObject, "UiContainer");

    HObject *viewportObject = HObject_Create("Viewport", upperSplitObject, null);
    Editor_viewport = HObject_AddComponent(viewportObject, "UiViewport");
    UiContainer_SetRect(Editor_viewport->container, UIRECT(0, 0, UI_MAX_SIZE, UI_MAX_SIZE));

    HObject *rightPanelObject = HObject_Create("Right Panel", upperSplitObject, null);
    Editor_rightPanel = HObject_AddComponent(rightPanelObject, "UiContainer");

    HObject *lowerPanelObject = HObject_Create("Lower Panel", canvas->object, null);
    Editor_lowerPanel = HObject_AddComponent(lowerPanelObject, "UiContainer");

    InitLeftPanel();
    InitRightPanel();
    InitLowerPanel();
}

void EditorLayout_Cleanup(void) { }