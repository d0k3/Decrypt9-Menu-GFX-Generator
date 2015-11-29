#pragma once

#define MENU_MAX_ENTRIES    12
#define SUBMENU_START 5

typedef struct {
    char* name;
    char* desc;
    u32 dangerous;
    u32 emunand;
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
        "XORpad Generator", 4,
        {
            { "NCCH Padgen", "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua.", 0, 0, 0 },
            { "SD Padgen", NULL, 0, 0, 0 },
            { "CTRNAND Padgen", NULL, 0, 0, 0 },
            { "TWLNAND Padgen", NULL, 0, 0, 0 }
        }
    },
    {
        "Titlekey Decrypt", 3,
        {
            { "Titlekey Decrypt (file)", NULL, 0, 0, 0 },
            { "Titlekey Decrypt (NAND)", NULL, 0, 0, 0 },
            { "Titlekey Decrypt (EMU)", NULL, 0, 1, 0 }
        }
    },
    {
        "SysNAND Options", 8,
        {
            { "NAND Backup", NULL, 0, 0, 0 },
            { "NAND Restore", NULL, 1, 0, 0 },
            { "Partition Dump...", NULL, 0, 0, 0 },
            { "Partition Inject...", NULL, 1, 0, 0 },
            { "File Dump...", NULL, 0, 0, 0 },
            { "File Inject...", NULL, 1, 0, 0 },
            { "Health&Safety Dump", NULL, 0, 0, 0 },
            { "Health&Safety Inject", NULL, 1, 0, 0 }
        }
    },
    {
        "EmuNAND Options", 9,
        {
            { "EmuNAND Backup", NULL, 0, 1, 0 },
            { "EmuNAND Restore", NULL, 1, 1, 0 },
            { "Partition Dump...", NULL, 0, 1, 0 },
            { "Partition Inject...", NULL, 1, 1, 0 },
            { "File Dump...", NULL, 0, 1, 0 },
            { "File Inject...", NULL, 1, 1, 0 },
            { "Health&Safety Dump", NULL, 0, 1, 0 },
            { "Health&Safety Inject", NULL, 1, 1, 0 },
            { "Update SeedDB", NULL, 0, 1, 0 }
        }
    },
    {
        "Game Decryptor", 6,
        {
            { "NCCH/NCSD Decryptor", NULL, 0, 0, 0 },
            { "NCCH/NCSD Encryptor", NULL, 0, 0, 0 },
            { "CIA Decryptor (shallow)", NULL, 0, 0, 0 },
            { "CIA Decryptor (deep)", NULL, 0, 0, 0 },
            { "CIA Decryptor (for GW)", NULL, 0, 0, 0 },
            { "SD Decryptor/Encryptor", NULL, 0, 0, 0 }
        }
    },
    // everything below is not contained in the main menu
    {
        "Partition Dump... (SysNAND)", 6, // ID 0
        {
            { "Dump TWLN Partition", NULL, 0, 0, 0 },
            { "Dump TWLP Partition", NULL, 0, 0, 0 },
            { "Dump AGBSAVE Partition", NULL, 0, 0, 0 },
            { "Dump FIRM0 Partition", NULL, 0, 0, 0 },
            { "Dump FIRM1 Partition", NULL, 0, 0, 0 },
            { "Dump CTRNAND Partition", NULL, 0, 0, 0 }
        }
    },
    {
        "Partition Dump...(EmuNAND)", 6, // ID 1
        {
            { "Dump TWLN Partition", NULL, 0, 1, 0 },
            { "Dump TWLP Partition", NULL, 0, 1, 0 },
            { "Dump AGBSAVE Partition", NULL, 0, 1, 0 },
            { "Dump FIRM0 Partition", NULL, 0, 1, 0 },
            { "Dump FIRM1 Partition", NULL, 0, 1, 0 },
            { "Dump CTRNAND Partition", NULL, 0, 1, 0 }
        }
    },
    {
        "Partition Inject... (SysNAND)", 6, // ID 2
        {
            { "Inject TWLN Partition", NULL, 1, 0, 0 },
            { "Inject TWLP Partition", NULL, 1, 0, 0 },
            { "Inject AGBSAVE Partition", NULL, 1, 0, 0 },
            { "Inject FIRM0 Partition", NULL, 1, 0, 0 },
            { "Inject FIRM1 Partition", NULL, 1, 0, 0 },
            { "Inject CTRNAND Partition", NULL, 1, 0, 0 }
        }
    },
    {
        "Partition Inject... (EmuNAND)", 6, // ID 3
        {
            { "Inject TWLN Partition", NULL, 1, 1, 0 },
            { "Inject TWLP Partition", NULL, 1, 1, 0 },
            { "Inject AGBSAVE Partition", NULL, 1, 1, 0 },
            { "Inject FIRM0 Partition", NULL, 1, 1, 0 },
            { "Inject FIRM1 Partition", NULL, 1, 1, 0 },
            { "Inject CTRNAND Partition", NULL, 1, 1, 0 }
        }
    },
    {
        "File Dump... (SysNAND)", 8, // ID 4
        {
            { "Dump ticket.db", NULL, 0, 0, 0 },
            { "Dump title.db", NULL, 0, 0, 0 },
            { "Dump import.db", NULL, 0, 0, 0 },
            { "Dump certs.db", NULL, 0, 0, 0 },
            { "Dump SecureInfo_A", NULL, 0, 0, 0 },
            { "Dump LocalFriendCodeSeed_B", NULL, 0, 0, 0 },
            { "Dump rand_seed", NULL, 0, 0, 0 },
            { "Dump movable.sed", NULL, 0, 0, 0 }
        }
    },
    {
        "File Dump... (EmuNAND)", 9, // ID 5
        {
            { "Dump ticket.db", NULL, 0, 1, 0 },
            { "Dump title.db", NULL, 0, 1, 0 },
            { "Dump import.db", NULL, 0, 1, 0 },
            { "Dump certs.db", NULL, 0, 1, 0 },
            { "Dump SecureInfo_A", NULL, 0, 1, 0 },
            { "Dump LocalFriendCodeSeed_B", NULL, 0, 1, 0 },
            { "Dump rand_seed", NULL, 0, 1, 0 },
            { "Dump movable.sed", NULL, 0, 1, 0 },
            { "Dump seedsave.bin", NULL, 0, 1, 0 }
        }
    },
    {
        "File Inject... (SysNAND)", 8, // ID 6
        {
            { "Inject ticket.db", NULL, 1, 0, 0 },
            { "Inject title.db", NULL, 1, 0, 0 },
            { "Inject import.db", NULL, 1, 0, 0 },
            { "Inject certs.db", NULL, 1, 0, 0 },
            { "Inject SecureInfo_A", NULL, 1, 0, 0 },
            { "Inject LocalFriendCodeSeed_B", NULL, 1, 0, 0 },
            { "Inject rand_seed", NULL, 1, 0, 0 },
            { "Inject movable.sed", NULL, 1, 0, 0 }
        }
    },
    {
        "File Inject... (EmuNAND)", 9, // ID 7
        {
            { "Inject ticket.db", NULL, 1, 1, 0 },
            { "Inject title.db", NULL, 1, 1, 0 },
            { "Inject import.db", NULL, 1, 1, 0 },
            { "Inject certs.db", NULL, 1, 1, 0 },
            { "Inject SecureInfo_A", NULL, 1, 1, 0 },
            { "Inject LocalFriendCodeSeed_B", NULL, 1, 1, 0 },
            { "Inject rand_seed", NULL, 1, 1, 0 },
            { "Inject movable.sed", NULL, 1, 1, 0 },
            { "Inject seedsave.bin", NULL, 1, 1, 0 }
        }
    },
    {
        NULL, 0, {}, // empty menu to signal end
    }
};
