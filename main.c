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

#define menu_start_x 20
#define menu_start_y 20
#define menu_step_x 100
#define menu_step_y 0

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
    // batch file start
    printf("@echo off\n\n");
    
    // create base GFX
    #ifdef entry_active_gfx
    for (u32 i = 0; i < MENU_MAX_ENTRIES; i++) {
        printf("convert -page 320x240+0+0 %s -page +%i+%i %s -flatten Images/base%02i.png\n",
            base_gfx, entry_gfx_start_x + i * entry_gfx_step_x, entry_gfx_start_y + i * entry_gfx_step_y, entry_active_gfx, i);
    }
    #endif

    //create font files
    for (u32 idx_m = 0; menu[idx_m].name != NULL; idx_m++) {
        for (u32 idx_s = 0; idx_s < menu[idx_m].n_entries; idx_s++) {
            for (u32 i = 0; i < menu[idx_m].n_entries; i++) {
                printf( "convert -background transparent -font %s -pointsize %i ", entry_font, entry_font_size );
                printf( "-fill %s label:'%s' \"Images/%s_%s.png\" \n",
                (idx_s == i) ? entry_active_color : entry_inactive_color,
                menu[idx_m].entries[i].name, menu[idx_m].entries[i].name, (idx_s == i) ? entry_active_color : entry_inactive_color);
                if (idx_m < SUBMENU_START) {
                    char* menu_nav[3];
                    menu_nav[0] = menu[(idx_m > 0) ? idx_m - 1 : SUBMENU_START - 1].name;
                    menu_nav[1] = menu[idx_m].name;
                    menu_nav[2] = menu[(idx_m < SUBMENU_START - 1) ? idx_m + 1 : 0].name;
                    for (u32 i = 0; i < 3; i++) {
                        printf( "convert -background transparent -font %s -pointsize %i ", entry_font, entry_font_size );
                        printf( "-fill %s label:'%s' \"Images/%s_%s.png\"\n",
                            (i == 1) ? menu_active_color : menu_inactive_color,
                            menu_nav[i], 
                            (i == 1) ? menu_active_color : menu_inactive_color, 
                            menu_nav[i]);
                    }
                }
            }
        }
    }

    // create actual menu GFX
    printf("\n");
    for (u32 idx_m = 0; menu[idx_m].name != NULL; idx_m++) {
            for (u32 idx_s = 0; idx_s < menu[idx_m].n_entries; idx_s++) {
                    printf( "convert Images/base%02i.png ", idx_s );
                    for (u32 i = 0; i < menu[idx_m].n_entries; i++) {
                        printf( " -draw \"image over %i,%i 0,0 'Images/%s_%s.png'\" ",
                        entry_start_x + i * entry_step_x, entry_start_y + i * entry_step_y,
                        menu[idx_m].entries[i].name,
                        (idx_s == i) ? entry_active_color : entry_inactive_color);
                }
            // create menu nav text
            if (idx_m < SUBMENU_START) {
                char* menu_nav[3];
                menu_nav[0] = menu[(idx_m > 0) ? idx_m - 1 : SUBMENU_START - 1].name;
                menu_nav[1] = menu[idx_m].name;
                menu_nav[2] = menu[(idx_m < SUBMENU_START - 1) ? idx_m + 1 : 0].name;
                for (u32 i = 0; i < 3; i++) {
                    printf( "-draw \"image over %i,%i 0,0 'Images/%s_%s.png'\" ",
                        menu_start_x + i * menu_step_x, menu_start_y + i * menu_step_y,
                        (i == 1) ? menu_active_color : menu_inactive_color, 
                        menu_nav[i] );
                }
            }
            printf( "Images/menu%04i.png\n", (idx_m * 100) + idx_s );
        }
    }
    
    return 0;
}
