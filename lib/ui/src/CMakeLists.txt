SET(SOURCES screens/ui_Screen1.c
    screens/ui_ScreenSetting.c
    screens/ui_SceenFinger.c
    # screens/ui_screenFingerAdd.c
    screens/ui_screenFingerDelete.c
    screens/ui_screenFingerShow.c
    screens/ui_SceenCard.c
    # screens/ui_screenCardAdd.c
    screens/ui_screenCardDelete.c
    screens/ui_screenCardShow.c
    screens/ui_SceenPassword.c
    screens/ui_ScreenHistory.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_iconunlock_png.c
    images/ui_img_iconsetting_png.c
    images/ui_img_iconhome_png.c
    images/ui_img_iconpassword_png.c
    images/ui_img_iconfinger_png.c
    images/ui_img_iconcard_png.c)

add_library(ui ${SOURCES})
