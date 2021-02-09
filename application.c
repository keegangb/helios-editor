#include "application.h"

#include <helios/core.h>
#include <helios/graphics.h>

#include "modules.h"

Window *Application_mainWindow = null;
UiCanvas *Application_mainCanvas = null;

static void InitializeUi(void);

static void MainWindowCloseRequested(Window *window)
{
    Helios_Exit();
}

static void Init(void)
{
    InitializeUi();
    Modules_Init();
}

static void Cleanup(void)
{
    Modules_Cleanup();
}

void Application_Run(void)
{
    HeliosParams p = NEW_HELIOS_PARAMS;
    p.callbacks.init = Init;
    p.callbacks.cleanup = Cleanup;
    Helios_Main(&p);
}

static void InitializeUi(void)
{
    WindowParams pWindow = NEW_WINDOW_PARAMS;
    pWindow.width = 1280;
    pWindow.height = 720;
    pWindow.name = "Application";
    pWindow.visible = true;
    pWindow.position = INT2(300, 200);
    Application_mainWindow = Window_Create(&pWindow);

    Application_mainWindow->closeRequested = MainWindowCloseRequested;

    HObject *canvasObject = HObject_Create("Ui Canvas", null, null);
    Application_mainCanvas = HObject_AddComponent(canvasObject, "UiCanvas");

    UiContainer_SetLayout(Application_mainCanvas->rootContainer, UILAYOUT_VERTICAL);
    UiCanvas_SetWindow(Application_mainCanvas, Application_mainWindow);

    HObject *toolbar = HObject_Create("Toolbar", canvasObject, null);
    HObject_AddComponent(toolbar, "UiToolbar");
}