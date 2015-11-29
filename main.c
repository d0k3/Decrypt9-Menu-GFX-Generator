#include "common.h"
#include "d9menu.h"

#define base_gfx "base_bot.png"

#define entry_active_gfx "entry_active_gfx.png"
#define entry_gfx_start_x 10
#define entry_gfx_start_y 38
#define entry_gfx_step_x 0
#define entry_gfx_step_y 15
#define entry_gfx_opacity 80

#define entry_start_x 12
#define entry_start_y 39
#define entry_step_x 0
#define entry_step_y 15

#define menu_dist_x 26
#define menu_start_y 10

#define entry_font "Roboto-Bold.ttf"
#define entry_font_size 11
#define entry_active_color "White"
#define entry_inactive_color "Blue"

#define menu_font "Roboto-Bold.ttf"
#define menu_font_size 12
#define menu_active_color "White"
#define menu_inactive_color "Blue"

int main()
{
    // batch file start / define output folders
    printf("@echo off\n\n");
    printf("set BUILD=build\n");
    printf("set OUTPUT=output\n");
    printf("if not exist %%BUILD%% md %%BUILD%%\n");
    printf("if not exist %%OUTPUT%% md %%OUTPUT%%\n");
    
    // create base GFX
    #ifdef entry_active_gfx
    printf("\n");
    for (u32 i = 0; i < MENU_MAX_ENTRIES; i++) {
        printf("convert -page 320x240+0+0 %s -page +%i+%i %s -flatten %%BUILD%%/base%02i.png\n",
            base_gfx, entry_gfx_start_x + i * entry_gfx_step_x, entry_gfx_start_y + i * entry_gfx_step_y, entry_active_gfx, i);
    }
    #endif

    //create label files
    printf("\n");
    for (u32 idx_m = 0; menu[idx_m].name != NULL; idx_m++) {
        for (u32 idx_s = 0; idx_s < menu[idx_m].n_entries; idx_s++) {
            for (u32 a = 0; a < 2; a++) {
                printf( "convert -background transparent -font %s -pointsize %i ", entry_font, entry_font_size );
                printf( "-fill %s \"label:%s\" %%BUILD%%/label%04i_%i.png\n",
                    (a == 1) ? entry_active_color : entry_inactive_color,
                    menu[idx_m].entries[idx_s].name, (idx_m * 100) + idx_s, a);
            }
        }
        for (u32 a = 0; a < 2; a++) {
            printf( "convert -background transparent -font %s -pointsize %i ", menu_font, menu_font_size );
            printf( "-fill %s \"label:%s\" %%BUILD%%/mlabel%02i_%i.png\n",
                (a == 1) ? menu_active_color : menu_inactive_color, menu[idx_m].name, idx_m, a);
        }
    }
    printf("\n");

    // create actual menu GFX
    printf("\n");
    for (u32 idx_m = 0; menu[idx_m].name != NULL; idx_m++) {
        for (u32 idx_s = 0; idx_s < menu[idx_m].n_entries; idx_s++) {
            printf( "convert %%BUILD%%/base%02i.png ", idx_s );
            for (u32 i = 0; i < menu[idx_m].n_entries; i++) {
                printf( "-draw \"image over %i,%i 0,0 %%BUILD%%/label%04i_%i.png\" ",
                    entry_start_x + i * entry_step_x, entry_start_y + i * entry_step_y,
                    (idx_m * 100) + i, (idx_s == i) ? 1 : 0);
            }
            // create menu nav text
            if (idx_m < SUBMENU_START) {
                u32 idx_m_l = (idx_m > 0) ? idx_m - 1 : SUBMENU_START - 1;
                u32 idx_m_r = (idx_m < SUBMENU_START - 1) ? idx_m + 1 : 0;
                printf( "-gravity NorthWest -draw \"image over %i,%i 0,0 %%BUILD%%/mlabel%02i_0.png\" ",
                    menu_dist_x, menu_start_y, idx_m_l );
                printf( "-gravity NorthEast -draw \"image over %i,%i 0,0 %%BUILD%%/mlabel%02i_0.png\" ",
                    menu_dist_x, menu_start_y, idx_m_r );
            }
            printf( "-gravity North -draw \"image over 0,%i 0,0 %%BUILD%%/mlabel%02i_1.png\" ",
                menu_start_y, idx_m );
            printf( "%%OUTPUT%%/menu%04i.png\n", (idx_m * 100) + idx_s );
        }
    }
    
    return 0;
}
