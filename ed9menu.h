#pragma once

#define MENU_MAX_ENTRIES 12
#define SUBMENU_START 1

typedef struct {
    char* name;
    char* desc;
    u32 param;
} MenuEntry;

typedef struct {
    char* name;
    u32 n_entries;
    MenuEntry entries[MENU_MAX_ENTRIES];
} MenuInfo;

MenuInfo menu[] =
{
    {
        #ifndef BUILD_NAME
        "EmuNAND9 Main Menu", 3,
        #else
        BUILD_NAME, 3,
        #endif
        {
            { "Complete EmuNAND Setup", NULL, 0 },
            { "SD Format Options...", NULL, SUBMENU_START + 0 },
            { "EmuNAND Manager Options...", NULL, SUBMENU_START + 1 }
        }
    },
    {
        "SD Format Options", 4,
        {
            { "Format SD (EmuNAND)", NULL, 0 },
            { "Format SD (EmuNAND/auto)", NULL, 0 },
            { "Format SD (standard)", NULL, 0 },
            { "Format SD (standard/auto)", NULL, 0 }
        }
    },
    {
        "EmuNAND Manager Options", 5,
        {
            { "Clone SysNAND to EmuNAND", NULL, 0 },
            { "Clone NAND.bin to EmuNAND", NULL, 0 },
            { "Clone EmuNAND.bin to EmuNAND", NULL, 0 },
            { "Dump SysNAND to NAND.bin", NULL, 0 },
            { "Dump EmuNAND to EmuNAND.bin", NULL, 0 }
        }
    },
    {
        NULL, 0, {}, // empty menu to signal end
    }
};
