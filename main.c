#include "common.h"
#include "d9menu.h"

#define base_gfx_main "base_bot.png"
#define base_gfx_sub "base_sub.png"
#define entry_active_gfx "entry_active.png"
// #define entry_inactive_gfx "entry_inactive.png"

#define entry_start_x 12
#define entry_start_y 39
#define entry_gfx_start_x (entry_start_x - 2)
#define entry_gfx_start_y (entry_start_y - 1)
#define entry_step_x 0
#define entry_step_y 15

#define entry_font "Roboto-Bold.ttf"
#define entry_font_size 11
#define entry_font_kerning 1
#define entry_font_strokewidth 0
#define entry_active_color "#00B7FF"
#define entry_active_color_stroke "#00B7FF00"
#define entry_inactive_color "#006E99"
#define entry_inactive_color_stroke "#006E9900"

#define menu_dist_x 36
#define menu_start_y 10

#define menu_font "Roboto-Bold.ttf"
#define menu_font_size 11
#define menu_font_kerning 1 
#define menu_font_strokewidth 0
#define menu_active_color "#00B7FF"
#define menu_active_color_stroke "#00B7FF00"
#define menu_inactive_color "#006E99"
#define menu_inactive_color_stroke "#006E9900"

#define desc_dim_x 130
#define desc_dim_y 150
#define desc_start_x 180
#define desc_start_y 50

#define desc_font "Roboto-Bold.ttf"
#define desc_font_size 12
#define desc_font_kerning 1
#define desc_font_strokewidth 0
#define desc_color "#006E99"
#define desc_color_stroke "#006E9900"
#define desc_gravity "SouthWest"

int main()
{
    // batch file start / define output folders
    printf("@echo off\n\n");
    printf("set BUILD=build\n");
    printf("set OUTPUT=output\n");
    printf("if not exist %%BUILD%% md %%BUILD%%\n");
    printf("if not exist %%OUTPUT%% md %%OUTPUT%%\n");

    //create label files
    printf("\n");
    for (u32 idx_m = 0; menu[idx_m].name != NULL; idx_m++) {
        for (u32 idx_s = 0; idx_s < menu[idx_m].n_entries; idx_s++) {
            for (u32 a = 0; a < 2; a++) {
                printf( "convert -background transparent -font %s -pointsize %i ", entry_font, entry_font_size );
                printf( "-fill %s -stroke %s -strokewidth %i -kerning %i \"label:%s\" %%BUILD%%/label%04i_%i.png\n",
                    (a == 1) ? entry_active_color : entry_inactive_color,
                    (a == 1) ? entry_active_color_stroke : entry_inactive_color_stroke,
                    menu_font_strokewidth, menu_font_kerning,
                    menu[idx_m].entries[idx_s].name, (idx_m * 100) + idx_s, a);
            }
            if (menu[idx_m].entries[idx_s].desc != NULL) {
                printf( "convert -background transparent -font %s -pointsize %i ", desc_font, desc_font_size );
                printf( "-fill %s -stroke %s -strokewidth %i -kerning %i -size %ix%i -gravity %s \"caption:%s\" %%BUILD%%/desc%04i.png\n",
                    desc_color, desc_color_stroke, desc_font_strokewidth, desc_font_kerning, 
                    desc_dim_x, desc_dim_y, desc_gravity,
                    menu[idx_m].entries[idx_s].desc, (idx_m * 100) + idx_s);
            }
        }
        
        for (u32 a = 0; a < 2; a++) {
            printf( "convert -background transparent -font %s -pointsize %i ", menu_font, menu_font_size );
            printf( "-fill %s -stroke %s -strokewidth %i -kerning %i \"label:%s\" %%BUILD%%/mlabel%02i_%i.png\n",
                (a == 1) ? menu_active_color : menu_inactive_color,
                (a == 1) ? menu_active_color_stroke : menu_inactive_color_stroke,
                menu_font_strokewidth, menu_font_kerning,
                menu[idx_m].name, idx_m, a);
        }
    }
    printf("\n");

    // create actual menu GFX
    printf("\n");
    for (u32 idx_m = 0; menu[idx_m].name != NULL; idx_m++) {
        for (u32 idx_s = 0; idx_s < menu[idx_m].n_entries; idx_s++) {
            // insert entry texts
            #ifdef base_gfx_sub
            printf( "convert %s ", (idx_m < SUBMENU_START) ? base_gfx_main : base_gfx_sub );
            #else
            printf( "convert %s ", base_gfx_main );
            #endif
            for (u32 i = 0; i < menu[idx_m].n_entries; i++) {
                #ifdef entry_active_gfx
                if (idx_s == i) {
                    printf( "-draw \"image over %i,%i 0,0 %s\" ",
                    entry_gfx_start_x + i * entry_step_x, entry_gfx_start_y + i * entry_step_y,
                    entry_active_gfx);
                }
                #endif
                #ifdef entry_inactive_gfx
                if (idx_s != i) {
                    printf( "-draw \"image over %i,%i 0,0 %s\" ",
                    entry_gfx_start_x + i * entry_step_x, entry_gfx_start_y + i * entry_step_y,
                    entry_inactive_gfx);
                }
                #endif
                printf( "-draw \"image over %i,%i 0,0 %%BUILD%%/label%04i_%i.png\" ",
                    entry_start_x + i * entry_step_x, entry_start_y + i * entry_step_y,
                    (idx_m * 100) + i, (idx_s == i) ? 1 : 0);
            }
            // (if available) insert description text
            if (menu[idx_m].entries[idx_s].desc != NULL) {
                printf( "-draw \"image over %i,%i 0,0 %%BUILD%%/desc%04i.png\" ",
                    desc_start_x, desc_start_y, (idx_m * 100) + idx_s);
            }
            // insert menu nav text
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
            printf( "-flatten %%OUTPUT%%/menu%04i.png\n", (idx_m * 100) + idx_s );
        }
    }
    
    return 0;
}
