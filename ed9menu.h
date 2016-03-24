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
        "SD Format Options", 2,
        {
            { "Format SD...", NULL, SUBMENU_START + 2 },
            { "Format SD & setup starter...", NULL, SUBMENU_START + 3 }
        }
    },
    {
        "EmuNAND Manager Options", 6,
        {
            { "Clone SysNAND to EmuNAND", NULL, 0 },
            { "Clone SysNAND to RedNAND", NULL, 0 },
            { "Clone file to EmuNAND", NULL, 0 },
            { "Clone file to RedNAND", NULL, 0 },
            { "Dump SysNAND to file", NULL, 0 },
            { "Dump EmuNAND to file", NULL, 0 }
        }
    },
    {
        "Format SD...", 3,
        {
            { "... without EmuNAND", NULL, 0 },
            { "... for EmuNAND (default)", NULL, 0 },
            { "... for EmuNAND (legacy)", NULL, 0 }
        }
    },
    {
        "Format SD & setup starter...", 3,
        {
            { "... without EmuNAND", NULL, 0 },
            { "... for EmuNAND (default)", NULL, 0 },
            { "... for EmuNAND (legacy)", NULL, 0 }
        }
    },
    {
        NULL, 0, { { 0 } }, // empty menu to signal end
    }
};
