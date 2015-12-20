#pragma once

#define MENU_MAX_ENTRIES 12
#define SUBMENU_START 5

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
        "XORPAD", 4,
        {
            { "NCCH PADGEN", "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua.", 0 },
            { "SD PADGEN", NULL, 0 },
            { "CTRNAND PADGEN", NULL, 0 },
            { "TWLNAND PADGEN", NULL, 0 }
        }
    },
    {
        "TITLEKEY", 3,
        {
            { "TITLEKEY DECRYPT (FILE)", NULL, 0 },
            { "TITLEKEY DECRYPT (NAND)", NULL, 0 },
            { "TITLEKEY DECRYPT (EMU)", NULL, 0 }
        }
    },
    {
        "SYSNAND", 8,
        {
            { "NAND BACKUP", NULL, 0 },
            { "NAND RESTORE", NULL, 0 },
            { "PARTITION DUMP...", NULL, 0 },
            { "PARTITION INJECT...", NULL, 0 },
            { "FILE DUMP...", NULL, 0 },
            { "FILE INJECT...", NULL, 0 },
            { "HEALTH&SAFETY DUMP", NULL, 0 },
            { "HEALTH&SAFETY INJECT", NULL, 0 }
        }
    },
    {
        "EMUNAND", 9,
        {
            { "EMUNAND BACKUP", NULL, 0 },
            { "EMUNAND RESTORE", NULL, 0 },
            { "PARTITION DUMP...", NULL, 0 },
            { "PARTITION INJECT...", NULL, 0 },
            { "FILE DUMP...", NULL, 0 },
            { "FILE INJECT...", NULL, 0 },
            { "HEALTH&SAFETY DUMP", NULL, 0 },
            { "HEALTH&SAFETY INJECT", NULL, 0 },
            { "UPDATE SEEDDB", NULL, 0 }
        }
    },
    {
        "GAME", 6,
        {
            { "NCCH/NCSD DECRYPTOR", NULL, 0 },
            { "NCCH/NCSD ENCRYPTOR", NULL, 0 },
            { "CIA DECRYPTOR (SHALLOW)", NULL, 0 },
            { "CIA DECRYPTOR (DEEP)", NULL, 0 },
            { "CIA DECRYPTOR (FOR GW)", NULL, 0 },
            { "SD DECRYPTOR/ENCRYPTOR", NULL, 0 }
        }
    },
    // everything below is not contained in the main menu
    {
        "PARTITION DUMP... (SYSNAND)", 6, // ID 0
        {
            { "Dump TWLN Partition", NULL, 0 },
            { "Dump TWLP Partition", NULL, 0 },
            { "Dump AGBSAVE Partition", NULL, 0 },
            { "Dump FIRM0 Partition", NULL, 0 },
            { "Dump FIRM1 Partition", NULL, 0 },
            { "Dump CTRNAND Partition", NULL, 0 }
        }
    },
    {
        "PARTITION DUMP...(EMUNAND)", 6, // ID 1
        {
            { "Dump TWLN Partition", NULL, 0 },
            { "Dump TWLP Partition", NULL, 0 },
            { "Dump AGBSAVE Partition", NULL, 0 },
            { "Dump FIRM0 Partition", NULL, 0 },
            { "Dump FIRM1 Partition", NULL, 0 },
            { "Dump CTRNAND Partition", NULL, 0 }
        }
    },
    {
        "PARTITION INJECT... (SYSNAND)", 6, // ID 2
        {
            { "Inject TWLN Partition", NULL, 0 },
            { "Inject TWLP Partition", NULL, 0 },
            { "Inject AGBSAVE Partition", NULL, 0 },
            { "Inject FIRM0 Partition", NULL, 0 },
            { "Inject FIRM1 Partition", NULL, 0 },
            { "Inject CTRNAND Partition", NULL, 0 }
        }
    },
    {
        "PARTITION INJECT... (EMUNAND)", 6, // ID 3
        {
            { "Inject TWLN Partition", NULL, 0 },
            { "Inject TWLP Partition", NULL, 0 },
            { "Inject AGBSAVE Partition", NULL, 0 },
            { "Inject FIRM0 Partition", NULL, 0 },
            { "Inject FIRM1 Partition", NULL, 0 },
            { "Inject CTRNAND Partition", NULL, 0 }
        }
    },
    {
        "FILE DUMP... (SYSNAND)", 9, // ID 4
        {
            { "Dump ticket.db", NULL, 0 },
            { "Dump title.db", NULL, 0 },
            { "Dump import.db", NULL, 0 },
            { "Dump certs.db", NULL, 0 },
            { "Dump SecureInfo_A", NULL, 0 },
            { "Dump LocalFriendCodeSeed_B", NULL, 0 },
            { "Dump rand_seed", NULL, 0 },
            { "Dump movable.sed", NULL, 0 },
            { "Dump updtsave.bin", NULL, 0 }
        }
    },
    {
        "FILE DUMP... (EMUNAND)", 10, // ID 5
        {
            { "Dump ticket.db", NULL, 0 },
            { "Dump title.db", NULL, 0 },
            { "Dump import.db", NULL, 0 },
            { "Dump certs.db", NULL, 0 },
            { "Dump SecureInfo_A", NULL, 0 },
            { "Dump LocalFriendCodeSeed_B", NULL, 0 },
            { "Dump rand_seed", NULL, 0 },
            { "Dump movable.sed", NULL, 0 },
            { "Dump seedsave.bin", NULL, 0 },
            { "Dump updtsave.bin", NULL, 0 }
        }
    },
    {
        "FILE INJECT... (SYSNAND)", 9, // ID 6
        {
            { "Inject ticket.db", NULL, 0 },
            { "Inject title.db", NULL, 0 },
            { "Inject import.db", NULL, 0 },
            { "Inject certs.db", NULL, 0 },
            { "Inject SecureInfo_A", NULL, 0 },
            { "Inject LocalFriendCodeSeed_B", NULL, 0 },
            { "Inject rand_seed", NULL, 0 },
            { "Inject movable.sed", NULL, 0 },
            { "Inject updtsave.bin", NULL, 0 }
        }
    },
    {
        "FILE INJECT... (EMUNAND)", 10, // ID 7
        {
            { "Inject ticket.db", NULL, 0 },
            { "Inject title.db", NULL, 0 },
            { "Inject import.db", NULL, 0 },
            { "Inject certs.db", NULL, 0 },
            { "Inject SecureInfo_A", NULL, 0 },
            { "Inject LocalFriendCodeSeed_B", NULL, 0 },
            { "Inject rand_seed", NULL, 0 },
            { "Inject movable.sed", NULL, 0 },
            { "Inject seedsave.bin", NULL, 0 },
            { "Inject updtsave.bin", NULL, 0 }
        }
    },
    {
        NULL, 0, {}, // empty menu to signal end
    }
};
