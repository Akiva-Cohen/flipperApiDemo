#include <furi.h>

/* generated by fbt from .png files in images folder */
#include <api_demo_icons.h>

#include <storage/storage.h>

#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/text_box.h>
#include <gui/modules/submenu.h>

#include <gui/modules/button_menu.h>
#include <gui/modules/button_panel.h>
#include <gui/modules/byte_input.h>
#include <gui/modules/dialog_ex.h>
#include <gui/modules/empty_screen.h>
#include <gui/modules/file_browser.h>
#include <gui/modules/loading.h>
#include <gui/modules/menu.h>
#include <gui/modules/number_input.h>
#include <gui/modules/popup.h>

#define BUTTON_MENU_TEXT  "Placeholder button menu text"
#define BUTTON_PANEL_TEXT "Placeholder button panel text"
#define BYTE_INPUT_TEXT   "Placeholder byte input text"
#define DIALOG_EX_TEXT    "Placeholder dialog ex text"
#define EMPTY_SCREEN_TEXT "Placeholder empty screen text"
#define FILE_BROWSER_TEXT "Placeholder file browser text"
#define LOADING_TEXT \
    "Suppresses all navigation events, making it impossible for the user to use the back button"
#define MENU_TEXT         "Placeholder menu text"
#define NUMBER_INPUT_TEXT "Placeholder number input text"
#define POPUP_TEXT        "Placeholder popup text"

typedef enum {
    Scene_MainMenu,
    Scene_ButtonMenuMenu,
    Scene_ButtonMenuText,
    Scene_ButtonMenuDemo,
    Scene_ButtonPanelMenu,
    Scene_ButtonPanelText,
    Scene_ButtonPanelDemo,
    Scene_ByteInputMenu,
    Scene_ByteInputText,
    Scene_ByteInputDemo,
    Scene_DialogExMenu,
    Scene_DialogExText,
    Scene_DialogExDemo,
    Scene_EmptyScreenMenu,
    Scene_EmptyScreenText,
    Scene_EmptyScreenDemo,
    Scene_FileBrowserMenu,
    Scene_FileBrowserText,
    Scene_FileBrowserDemo,
    Scene_LoadingMenu,
    Scene_LoadingText,
    Scene_LoadingDemo,
    Scene_MenuMenu,
    Scene_MenuText,
    Scene_MenuDemo,
    Scene_NumberInputMenu,
    Scene_NumberInputText,
    Scene_NumberInputDemo,
    Scene_PopupMenu,
    Scene_PopupText,
    Scene_PopupDemo,
    Scene_count
} Scene;
typedef enum {
    Views_Submenu,
    Views_TextBox,
    Views_ButtonMenu,
    Views_ButtonPanel,
    Views_ByteInput,
    Views_DialogEx,
    Views_EmptyScreen,
    Views_FileBrowser,
    Views_Loading,
    Views_Menu,
    Views_NumberInput,
    Views_Popup
} Views;
typedef struct {
    uint8_t* bytes;
    FuriString* furiString;
    FuriString* fileBrowserResultPath;
} Resources;
typedef struct {
    Resources* Resources;
    SceneManager* scene_manager;
    ViewDispatcher* view_dispatcher;
    Submenu* submenu;
    TextBox* textbox;

    ButtonMenu* buttonmenu;
    ButtonPanel* buttonpanel;
    ByteInput* byteinput;
    DialogEx* dialogex;
    EmptyScreen* emptyscreen;
    FileBrowser* filebrowser;
    Loading* loading;
    Menu* menu;
    NumberInput* numberinput;
    Popup* popup;
} ApiDemo;

void api_demo_submenu_callback(void* context, uint32_t index) {
    ApiDemo* app = context;
    scene_manager_next_scene(app->scene_manager, index);
}
void api_demo_submenu_add_item(ApiDemo* app, const char* label, uint32_t index) {
    submenu_add_item(app->submenu, label, index, api_demo_submenu_callback, app);
}
bool unusedOnEvent(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void api_demo_scene_on_enter_MainMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    //add here
    api_demo_submenu_add_item(app, "Button Menu", Scene_ButtonMenuMenu);
    api_demo_submenu_add_item(app, "Button Panel", Scene_ButtonPanelMenu);
    api_demo_submenu_add_item(app, "Byte Input", Scene_ByteInputMenu);
    api_demo_submenu_add_item(app, "Dialog Ex", Scene_DialogExMenu);
    api_demo_submenu_add_item(app, "Empty Screen", Scene_EmptyScreenMenu);
    api_demo_submenu_add_item(app, "File Browser", Scene_FileBrowserMenu);
    api_demo_submenu_add_item(app, "Loading", Scene_LoadingMenu);
    api_demo_submenu_add_item(app, "Menu", Scene_MenuMenu);
    api_demo_submenu_add_item(app, "Number Input", Scene_NumberInputMenu);
    api_demo_submenu_add_item(app, "Popup", Scene_PopupMenu);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_MainMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_MainMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_ButtonMenuMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "Button Menu Info", Scene_ButtonMenuText);
    api_demo_submenu_add_item(app, "Button Menu Demo", Scene_ButtonMenuDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_ButtonMenuMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_ButtonMenuMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_ButtonMenuText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, BUTTON_MENU_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_TextBox);
}
bool api_demo_scene_on_event_ButtonMenuText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_ButtonMenuText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void blankButtonMenuCallback(void* context, long index, InputType input) {
    UNUSED(context);
    UNUSED(index);
    UNUSED(input);
}

void api_demo_scene_on_enter_ButtonMenuDemo(void* context) {
    ApiDemo* app = context;
    button_menu_reset(app->buttonmenu);
    button_menu_add_item(
        app->buttonmenu,
        "Common Button",
        0,
        blankButtonMenuCallback,
        ButtonMenuItemTypeCommon,
        app);
    button_menu_add_item(
        app->buttonmenu,
        "Control Button",
        0,
        blankButtonMenuCallback,
        ButtonMenuItemTypeControl,
        app);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_ButtonMenu);
}
bool api_demo_scene_on_event_ButtonMenuDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_ButtonMenuDemo(void* context) {
    ApiDemo* app = context;
    button_menu_reset(app->buttonmenu);
}

void api_demo_scene_on_enter_ButtonPanelMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "Button Panel Info", Scene_ButtonPanelText);
    api_demo_submenu_add_item(app, "Button Panel Demo", Scene_ButtonPanelDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_ButtonPanelMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_ButtonPanelMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_ButtonPanelText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, BUTTON_PANEL_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_TextBox);
}
bool api_demo_scene_on_event_ButtonPanelText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_ButtonPanelText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void blankButtonPanel(void* context, uint32_t index) {
    UNUSED(context);
    UNUSED(index);
}
void addNavigation(void* context, int Vx, int Vy, int x, int y) {
    ApiDemo* app = context;
    button_panel_add_item(
        app->buttonpanel,
        0,
        Vx,
        Vy - 1,
        x + 18,
        y,
        &I_navup_24x18,
        &I_navup_hover_24x18,
        *blankButtonPanel,
        context);
    button_panel_add_item(
        app->buttonpanel,
        1,
        Vx - 1,
        Vy,
        x,
        y + 18,
        &I_navleft_18x24,
        &I_navleft_hover_18x24,
        *blankButtonPanel,
        context);
    button_panel_add_item(
        app->buttonpanel,
        0,
        Vx,
        Vy + 1,
        x + 18,
        y + 42,
        &I_navdown_24x18,
        &I_navdown_hover_24x18,
        *blankButtonPanel,
        context);
    button_panel_add_item(
        app->buttonpanel,
        0,
        Vx + 1,
        Vy,
        x + 42,
        y + 18,
        &I_navright_18x24,
        &I_navright_hover_18x24,
        *blankButtonPanel,
        context);
    button_panel_add_item(
        app->buttonpanel,
        0,
        Vx,
        Vy,
        x + 18,
        y + 18,
        &I_navok_24x24,
        &I_navok_hover_24x24,
        *blankButtonPanel,
        context);
}
void api_demo_scene_on_enter_ButtonPanelDemo(void* context) {
    ApiDemo* app = context;
    button_panel_reset(app->buttonpanel);

    button_panel_reserve(app->buttonpanel, 3, 3);
    addNavigation(context, 1, 1, 2, 23);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_ButtonPanel);
}
bool api_demo_scene_on_event_ButtonPanelDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_ButtonPanelDemo(void* context) {
    ApiDemo* app = context;
    button_panel_reset(app->buttonpanel);
}

void api_demo_scene_on_enter_ByteInputMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "Byte Input Text", Scene_ByteInputText);
    api_demo_submenu_add_item(app, "Byte Input Demo", Scene_ByteInputDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_ByteInputMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_ByteInputMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_ByteInputText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, BYTE_INPUT_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_TextBox);
}
bool api_demo_scene_on_event_ByteInputText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_ByteInputText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void emptySingleCallback(void* context) {
    UNUSED(context);
}
void api_demo_scene_on_enter_ByteInputDemo(void* context) {
    ApiDemo* app = context;
    byte_input_set_header_text(app->byteinput, "Your Header Here");
    app->Resources->bytes = malloc(sizeof(uint8_t) * 8);
    byte_input_set_result_callback(
        app->byteinput,
        emptySingleCallback,
        emptySingleCallback,
        context,
        app->Resources->bytes,
        8);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_ByteInput);
}
bool api_demo_scene_on_event_ByteInputDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_ByteInputDemo(void* context) {
    ApiDemo* app = context;
    free(app->Resources->bytes);
}

void api_demo_scene_on_enter_DialogExMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "Dialog Ex Text", Scene_DialogExText);
    api_demo_submenu_add_item(app, "Dialog Ex Demo", Scene_DialogExDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_DialogExMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_DialogExMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_DialogExText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, DIALOG_EX_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_TextBox);
}
bool api_demo_scene_on_event_DialogExText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_DialogExText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void blankExCallback(DialogExResult result, void* context) {
    UNUSED(result);
    UNUSED(context);
}
void api_demo_scene_on_enter_DialogExDemo(void* context) {
    ApiDemo* app = context;
    dialog_ex_reset(app->dialogex);
    dialog_ex_set_context(app->dialogex, app);
    dialog_ex_disable_extended_events(app->dialogex);
    dialog_ex_set_center_button_text(app->dialogex, "center");
    dialog_ex_set_left_button_text(app->dialogex, "left");
    dialog_ex_set_right_button_text(app->dialogex, "right");
    dialog_ex_set_header(app->dialogex, "Dialog Ex Interface", 5, 5, AlignLeft, AlignTop);
    dialog_ex_set_result_callback(app->dialogex, blankExCallback);
    dialog_ex_set_text(
        app->dialogex, "this is what text looks like\non two lines", 20, 20, AlignLeft, AlignTop);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_DialogEx);
}
bool api_demo_scene_on_event_DialogExDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_DialogExDemo(void* context) {
    ApiDemo* app = context;
    dialog_ex_reset(app->dialogex);
}

void api_demo_scene_on_enter_EmptyScreenMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "Empty Screen Text", Scene_EmptyScreenText);
    api_demo_submenu_add_item(app, "Empty Screen Demo", Scene_EmptyScreenDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_EmptyScreen);
}
bool api_demo_scene_on_event_EmptyScreenMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_EmptyScreenMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_EmptyScreenText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, EMPTY_SCREEN_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_TextBox);
}
bool api_demo_scene_on_event_EmptyScreenText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_EmptyScreenText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void api_demo_scene_on_enter_EmptyScreenDemo(void* context) {
    ApiDemo* app = context;
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_EmptyScreen);
}
bool api_demo_scene_on_event_EmptyScreenDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_EmptyScreenDemo(void* context) {
    UNUSED(context);
}

void api_demo_scene_on_enter_FileBrowserMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "File Browser Text", Scene_FileBrowserText);
    api_demo_submenu_add_item(app, "File Browser Demo", Scene_FileBrowserDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_FileBrowserMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_FileBrowserMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_FileBrowserText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, FILE_BROWSER_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_TextBox);
}
bool api_demo_scene_on_event_FileBrowserText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_FileBrowserText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void api_demo_scene_on_enter_FileBrowserDemo(void* context) {
    ApiDemo* app = context;
    file_browser_set_callback(app->filebrowser, NULL, context);
    file_browser_configure(app->filebrowser, "*", EXT_PATH(), false, false, &I_apidemo, false);
    file_browser_set_item_callback(app->filebrowser, NULL, context);
    app->Resources->furiString = furi_string_alloc_set(EXT_PATH());

    file_browser_start(app->filebrowser, app->Resources->fileBrowserResultPath);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_FileBrowser);
}
bool api_demo_scene_on_event_FileBrowserDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_FileBrowserDemo(void* context) {
    ApiDemo* app = context;

    file_browser_stop(app->filebrowser);
    furi_string_free(app->Resources->furiString);
}

void api_demo_scene_on_enter_LoadingMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "Loading Text", Scene_LoadingText);
    api_demo_submenu_add_item(app, "Loading Demo", Scene_LoadingDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_LoadingMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_LoadingMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_LoadingText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, LOADING_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_TextBox);
}
bool api_demo_scene_on_event_LoadingText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_LoadingText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void api_demo_scene_on_enter_LoadingDemo(void* context) {
    ApiDemo* app = context;
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Loading);
    furi_delay_ms(4000);
    scene_manager_handle_back_event(app->scene_manager);
}
bool api_demo_scene_on_event_LoadingDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_LoadingDemo(void* context) {
    UNUSED(context);
}

void api_demo_scene_on_enter_MenuMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "Menu Text", Scene_MenuText);
    api_demo_submenu_add_item(app, "Menu Demo", Scene_MenuDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_MenuMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_MenuMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_MenuText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, MENU_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_TextBox);
}
bool api_demo_scene_on_event_MenuText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_MenuText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void api_demo_scene_on_enter_MenuDemo(void* context) {
    ApiDemo* app = context;
    menu_reset(app->menu);
    menu_add_item(app->menu, "Option One", &I_apidemo, 0, NULL, NULL);
    menu_add_item(app->menu, "Option Two", &I_apidemo, 0, NULL, NULL);
    menu_add_item(app->menu, "Option Three", &I_apidemo, 0, NULL, NULL);
    menu_add_item(app->menu, "Option Four", &I_apidemo, 0, NULL, NULL);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Menu);
}
bool api_demo_scene_on_event_MenuDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_MenuDemo(void* context) {
    ApiDemo* app = context;
    menu_reset(app->menu);
}

void api_demo_scene_on_enter_NumberInputMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "Number Input Text", Scene_NumberInputText);
    api_demo_submenu_add_item(app, "Number Input Demo", Scene_NumberInputDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_NumberInputMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_NumberInputMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_NumberInputText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, NUMBER_INPUT_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_TextBox);
}
bool api_demo_scene_on_event_NumberInputText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_NumberInputText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void api_demo_scene_on_enter_NumberInputDemo(void* context) {
    ApiDemo* app = context;
    number_input_set_header_text(app->numberinput, "Your Header Here");
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_NumberInput);
}
bool api_demo_scene_on_event_NumberInputDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_NumberInputDemo(void* context) {
    UNUSED(context);
}

void api_demo_scene_on_enter_PopupMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
    api_demo_submenu_add_item(app, "Popup Text", Scene_PopupText);
    api_demo_submenu_add_item(app, "Popup Demo", Scene_PopupDemo);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Submenu);
}
bool api_demo_scene_on_event_PopupMenu(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_PopupMenu(void* context) {
    ApiDemo* app = context;
    submenu_reset(app->submenu);
}

void api_demo_scene_on_enter_PopupText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
    text_box_set_text(app->textbox, POPUP_TEXT);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Popup);
}
bool api_demo_scene_on_event_PopupText(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_PopupText(void* context) {
    ApiDemo* app = context;
    text_box_reset(app->textbox);
}

void api_demo_scene_on_enter_PopupDemo(void* context) {
    ApiDemo* app = context;
    popup_reset(app->popup);
    popup_set_header(app->popup, "header text", 32, 16, AlignLeft, AlignTop);
    popup_set_text(app->popup, "popup text\non two lines", 37, 30, AlignLeft, AlignTop);
    popup_set_icon(app->popup, 4, 18, &I_navok_24x24);
    view_dispatcher_switch_to_view(app->view_dispatcher, Views_Popup);
}
bool api_demo_scene_on_event_PopupDemo(void* context, SceneManagerEvent event) {
    return unusedOnEvent(context, event);
}
void api_demo_scene_on_exit_PopupDemo(void* context) {
    ApiDemo* app = context;
    popup_reset(app->popup);
}

//collection of all on enter, event, and exit methods
//all on enter
void (*const api_demo_scene_on_enter_handlers[])(void*) = {
    api_demo_scene_on_enter_MainMenu,        api_demo_scene_on_enter_ButtonMenuMenu,
    api_demo_scene_on_enter_ButtonMenuText,  api_demo_scene_on_enter_ButtonMenuDemo,
    api_demo_scene_on_enter_ButtonPanelMenu, api_demo_scene_on_enter_ButtonPanelText,
    api_demo_scene_on_enter_ButtonPanelDemo, api_demo_scene_on_enter_ByteInputMenu,
    api_demo_scene_on_enter_ByteInputText,   api_demo_scene_on_enter_ByteInputDemo,
    api_demo_scene_on_enter_DialogExMenu,    api_demo_scene_on_enter_DialogExText,
    api_demo_scene_on_enter_DialogExDemo,    api_demo_scene_on_enter_EmptyScreenMenu,
    api_demo_scene_on_enter_EmptyScreenText, api_demo_scene_on_enter_EmptyScreenDemo,
    api_demo_scene_on_enter_FileBrowserMenu, api_demo_scene_on_enter_FileBrowserText,
    api_demo_scene_on_enter_FileBrowserDemo, api_demo_scene_on_enter_LoadingMenu,
    api_demo_scene_on_enter_LoadingText,     api_demo_scene_on_enter_LoadingDemo,
    api_demo_scene_on_enter_MenuMenu,        api_demo_scene_on_enter_MenuText,
    api_demo_scene_on_enter_MenuDemo,        api_demo_scene_on_enter_NumberInputMenu,
    api_demo_scene_on_enter_NumberInputText, api_demo_scene_on_enter_NumberInputDemo,
    api_demo_scene_on_enter_PopupMenu,       api_demo_scene_on_enter_PopupText,
    api_demo_scene_on_enter_PopupDemo};
//all on event
bool (*const api_demo_scene_on_event_handlers[])(void*, SceneManagerEvent) = {
    api_demo_scene_on_event_MainMenu,        api_demo_scene_on_event_ButtonMenuMenu,
    api_demo_scene_on_event_ButtonMenuText,  api_demo_scene_on_event_ButtonMenuDemo,
    api_demo_scene_on_event_ButtonPanelMenu, api_demo_scene_on_event_ButtonPanelText,
    api_demo_scene_on_event_ButtonPanelDemo, api_demo_scene_on_event_ByteInputMenu,
    api_demo_scene_on_event_ByteInputText,   api_demo_scene_on_event_ByteInputDemo,
    api_demo_scene_on_event_DialogExMenu,    api_demo_scene_on_event_DialogExText,
    api_demo_scene_on_event_DialogExDemo,    api_demo_scene_on_event_EmptyScreenMenu,
    api_demo_scene_on_event_EmptyScreenText, api_demo_scene_on_event_EmptyScreenDemo,
    api_demo_scene_on_event_FileBrowserMenu, api_demo_scene_on_event_FileBrowserText,
    api_demo_scene_on_event_FileBrowserDemo, api_demo_scene_on_event_LoadingMenu,
    api_demo_scene_on_event_LoadingText,     api_demo_scene_on_event_LoadingDemo,
    api_demo_scene_on_event_MenuMenu,        api_demo_scene_on_event_MenuText,
    api_demo_scene_on_event_MenuDemo,        api_demo_scene_on_event_NumberInputMenu,
    api_demo_scene_on_event_NumberInputText, api_demo_scene_on_event_NumberInputDemo,
    api_demo_scene_on_event_PopupMenu,       api_demo_scene_on_event_PopupText,
    api_demo_scene_on_event_PopupDemo};
//all on exit
void (*const api_demo_scene_on_exit_handlers[])(void*) = {
    api_demo_scene_on_exit_MainMenu,        api_demo_scene_on_exit_ButtonMenuMenu,
    api_demo_scene_on_exit_ButtonMenuText,  api_demo_scene_on_exit_ButtonMenuDemo,
    api_demo_scene_on_exit_ButtonPanelMenu, api_demo_scene_on_exit_ButtonPanelText,
    api_demo_scene_on_exit_ButtonPanelDemo, api_demo_scene_on_exit_ByteInputMenu,
    api_demo_scene_on_exit_ByteInputText,   api_demo_scene_on_exit_ByteInputDemo,
    api_demo_scene_on_exit_DialogExMenu,    api_demo_scene_on_exit_DialogExText,
    api_demo_scene_on_exit_DialogExDemo,    api_demo_scene_on_exit_EmptyScreenMenu,
    api_demo_scene_on_exit_EmptyScreenText, api_demo_scene_on_exit_EmptyScreenDemo,
    api_demo_scene_on_exit_FileBrowserMenu, api_demo_scene_on_exit_FileBrowserText,
    api_demo_scene_on_exit_FileBrowserDemo, api_demo_scene_on_exit_LoadingMenu,
    api_demo_scene_on_exit_LoadingText,     api_demo_scene_on_exit_LoadingDemo,
    api_demo_scene_on_exit_MenuMenu,        api_demo_scene_on_exit_MenuText,
    api_demo_scene_on_exit_MenuDemo,        api_demo_scene_on_exit_NumberInputMenu,
    api_demo_scene_on_exit_NumberInputText, api_demo_scene_on_exit_NumberInputDemo,
    api_demo_scene_on_exit_PopupMenu,       api_demo_scene_on_exit_PopupText,
    api_demo_scene_on_exit_PopupDemo};
//combination
const SceneManagerHandlers api_demo_scene_event_handlers = {
    .on_enter_handlers = api_demo_scene_on_enter_handlers,
    .on_event_handlers = api_demo_scene_on_event_handlers,
    .on_exit_handlers = api_demo_scene_on_exit_handlers,
    .scene_num = Scene_count};

void api_demo_scene_manager_init(ApiDemo* app) {
    app->scene_manager = scene_manager_alloc(&api_demo_scene_event_handlers, app);
}
bool api_demo_scene_manager_custom_event_callback(void* context, uint32_t custom_event) {
    ApiDemo* app = context;
    return scene_manager_handle_custom_event(app->scene_manager, custom_event);
}
bool api_demo_scene_manager_navigation_event_callback(void* context) {
    ApiDemo* app = context;
    return scene_manager_handle_back_event(app->scene_manager);
}
//bottom add point
void api_demo_view_dispatcher_init(ApiDemo* app) {
    app->view_dispatcher = view_dispatcher_alloc();

    app->submenu = submenu_alloc();
    app->textbox = text_box_alloc();
    app->buttonmenu = button_menu_alloc();
    app->buttonpanel = button_panel_alloc();
    app->byteinput = byte_input_alloc();
    app->dialogex = dialog_ex_alloc();
    app->emptyscreen = empty_screen_alloc();
    app->filebrowser = file_browser_alloc(app->Resources->fileBrowserResultPath);
    app->loading = loading_alloc();
    app->menu = menu_alloc();
    app->numberinput = number_input_alloc();
    app->popup = popup_alloc();

    view_dispatcher_set_event_callback_context(app->view_dispatcher, app);
    view_dispatcher_set_custom_event_callback(
        app->view_dispatcher, api_demo_scene_manager_custom_event_callback);
    view_dispatcher_set_navigation_event_callback(
        app->view_dispatcher, api_demo_scene_manager_navigation_event_callback);

    view_dispatcher_add_view(app->view_dispatcher, Views_Submenu, submenu_get_view(app->submenu));
    view_dispatcher_add_view(app->view_dispatcher, Views_TextBox, text_box_get_view(app->textbox));
    view_dispatcher_add_view(
        app->view_dispatcher, Views_ButtonMenu, button_menu_get_view(app->buttonmenu));
    view_dispatcher_add_view(
        app->view_dispatcher, Views_ButtonPanel, button_panel_get_view(app->buttonpanel));
    view_dispatcher_add_view(
        app->view_dispatcher, Views_ByteInput, byte_input_get_view(app->byteinput));
    view_dispatcher_add_view(
        app->view_dispatcher, Views_DialogEx, dialog_ex_get_view(app->dialogex));
    view_dispatcher_add_view(
        app->view_dispatcher, Views_EmptyScreen, empty_screen_get_view(app->emptyscreen));
    view_dispatcher_add_view(
        app->view_dispatcher, Views_FileBrowser, file_browser_get_view(app->filebrowser));
    view_dispatcher_add_view(app->view_dispatcher, Views_Loading, loading_get_view(app->loading));
    view_dispatcher_add_view(app->view_dispatcher, Views_Menu, menu_get_view(app->menu));
    view_dispatcher_add_view(
        app->view_dispatcher, Views_NumberInput, number_input_get_view(app->numberinput));
    view_dispatcher_add_view(app->view_dispatcher, Views_Popup, popup_get_view(app->popup));
}
ApiDemo* api_demo_init() {
    ApiDemo* app = malloc(sizeof(ApiDemo));
    app->Resources = malloc(sizeof(Resources));
    app->Resources->fileBrowserResultPath = furi_string_alloc_set(EXT_PATH());
    api_demo_scene_manager_init(app);
    api_demo_view_dispatcher_init(app);
    return app;
}
void api_demo_free(ApiDemo* app) {
    scene_manager_free(app->scene_manager);
    free(app->Resources->fileBrowserResultPath);
    free(app->Resources);

    //dont forget about here
    view_dispatcher_remove_view(app->view_dispatcher, Views_Submenu);
    view_dispatcher_remove_view(app->view_dispatcher, Views_TextBox);
    view_dispatcher_remove_view(app->view_dispatcher, Views_ButtonMenu);
    view_dispatcher_remove_view(app->view_dispatcher, Views_ButtonPanel);
    view_dispatcher_remove_view(app->view_dispatcher, Views_ByteInput);
    view_dispatcher_remove_view(app->view_dispatcher, Views_DialogEx);
    view_dispatcher_remove_view(app->view_dispatcher, Views_EmptyScreen);
    view_dispatcher_remove_view(app->view_dispatcher, Views_FileBrowser);
    view_dispatcher_remove_view(app->view_dispatcher, Views_Loading);
    view_dispatcher_remove_view(app->view_dispatcher, Views_Menu);
    view_dispatcher_remove_view(app->view_dispatcher, Views_NumberInput);
    view_dispatcher_remove_view(app->view_dispatcher, Views_Popup);
    view_dispatcher_free(app->view_dispatcher);

    submenu_free(app->submenu);
    text_box_free(app->textbox);
    button_menu_free(app->buttonmenu);
    byte_input_free(app->byteinput);
    dialog_ex_free(app->dialogex);
    button_panel_free(app->buttonpanel);
    empty_screen_free(app->emptyscreen);
    file_browser_free(app->filebrowser);
    loading_free(app->loading);
    menu_free(app->menu);
    number_input_free(app->numberinput);
    popup_free(app->popup);
    free(app);
}
int32_t api_demo_app() {
    ApiDemo* app = api_demo_init();
    Gui* gui = furi_record_open(RECORD_GUI);
    view_dispatcher_attach_to_gui(app->view_dispatcher, gui, ViewDispatcherTypeFullscreen);
    scene_manager_next_scene(app->scene_manager, Scene_MainMenu);

    view_dispatcher_run(app->view_dispatcher);

    api_demo_free(app);
    return 0;
}
