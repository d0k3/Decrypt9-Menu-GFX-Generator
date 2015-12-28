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
            { "NCCH PADGEN", "Generate the xorpads needed to decrypt and encrypt 3ds titles.", 0 },
            { "SD PADGEN", "Generate the xorpads needed to decrypt and encrypt SD card contents.", 0 },
            { "CTRNAND PADGEN", "Generate the xorpads needed to decrypt and encrypt your main nand partition.", 0 },
            { "TWLNAND PADGEN", "Generate the xorpads needed to decrypt and encrypt your TWL nand partition.", 0 }
        }
    },
    {
        "TITLEKEY", 3,
        {
            { "TITLEKEY DECRYPT (FILE)", "Decrypt the title keys stored in encTitleKeys.bin.", 0 },
            { "TITLEKEY DECRYPT (NAND)", "Decrypt the title keys stored in sysnand to decTitleKeys.bin.", 0 },
            { "TITLEKEY DECRYPT (EMU)", "Decrypt the title keys stored in Emunand to decTitleKeys_emu.bin.", 0 }
        }
    },
    {
        "SYSNAND", 8,
        {
            { "NAND BACKUP", "Backup your sysnand. It is highly recommended to backup your sysnand", 0 },
            { "NAND RESTORE", "Restore your sysnand backup. Proceed with caution!!", 0 },
            { "PARTITION DUMP...", "Backup selected partitions from sysnand.", 0 },
            { "PARTITION INJECT...", "Inject selected partitions into sysnand.", 0 },
            { "FILE DUMP...", "Backup selected files from sysnand.", 0 },
            { "FILE INJECT...", "Inject selected files into sysnand.", 0 },
            { "HEALTH&SAFETY DUMP", "Backup the health and safety app from sysnand.", 0 },
            { "HEALTH&SAFETY INJECT", "Inject the health and safety app into sysnand.", 0 }
        }
    },
    {
        "EMUNAND", 9,
        {
            { "EMUNAND BACKUP", "Backup your emunand. It is highly recommended to backup your emunand.", 0 },
            { "EMUNAND RESTORE", "Restore your emunand backup. Proceed with caution!!", 0 },
            { "PARTITION DUMP...", "Backup selected partitions from emunand.", 0 },
            { "PARTITION INJECT...", "Inject selected partitions into emunand.", 0 },
            { "FILE DUMP...", "Backup selected files from emunand.", 0 },
            { "FILE INJECT...", "Inject selected files into emunand.", 0 },
            { "HEALTH&SAFETY DUMP", "Backup the health and safety app from emunand.", 0 },
            { "HEALTH&SAFETY INJECT", "Inject the health and safety app into emunand.", 0 },
            { "UPDATE SEEDDB", "Dump Seeddb.bin from Emunand. OLD 3DS 9.6+ ONLY FOR NOW...", 0 }
        }
    },
    {
        "GAME", 6,
        {
            { "NCCH/NCSD DECRYPTOR", "Fully decrypt all NCCH/NCSD files in work or game folder. Files with .3DS and .APP extension belong into this category.", 0 },
            { "NCCH/NCSD ENCRYPTOR", "(Re-)Encrypt NCCH/NCSD files with standard compression. On some hardware this might be needed for compatibility.", 0 },
            { "CIA DECRYPTOR (SHALLOW)", "Decrypt the first layer of CIA encryption, but leave the internal NCCH encryption untouched. This processes all CIAs in work / game folder.", 0 },
            { "CIA DECRYPTOR (DEEP)", "Fully decrypt all CIA files in work / game folder.", 0 },
            { "CIA DECRYPTOR (CXI only)", "Decrypt all CIA files in work / game folder, but leave everything but the CXI untouched. On some hardware this might be needed for compatibility.", 0 },
            { "SD DECRYPTOR/ENCRYPTOR", "Decrypt or encrypt the SD files inside your work / game folder. You first need to copy the folder structure from /Nintendo 3DS/<id0>/<id1>", 0 }
        }
    },
    // everything below is not contained in the main menu
    {
        "PARTITION DUMP... (SYSNAND)", 6, // ID 0
        {
            { "Dump TWLN Partition", "Backup the TWL main partition.", 0 },
            { "Dump TWLP Partition", "Backup the TWL photo partition.", 0 },
            { "Dump AGBSAVE Partition", "Backup the Agbsave partition.", 0 },
            { "Dump FIRM0 Partition", "Backup the FIRM0 partition.", 0 },
            { "Dump FIRM1 Partition", "Backup the FIRM1 partition.", 0 },
            { "Dump CTRNAND Partition", "Backup the sysnand main partition.", 0 }
        }
    },
    {
        "PARTITION DUMP...(EMUNAND)", 6, // ID 1
        {
            { "Dump TWLN Partition", "Backup the TWL main partition.", 0 },
            { "Dump TWLP Partition", "Backup the TWL photo partition.", 0 },
            { "Dump AGBSAVE Partition", "Backup the Agbsave partition.", 0 },
            { "Dump FIRM0 Partition", "Backup the FIRM0 partition.", 0 },
            { "Dump FIRM1 Partition", "Backup the FIRM1 partition.", 0 },
            { "Dump CTRNAND Partition", "Backup the emunand main partition.", 0 }
        }
    },
    {
        "PARTITION INJECT... (SYSNAND)", 6, // ID 2
        {
            { "Inject TWLN Partition", "Inject the TWL main partition.", 0 },
            { "Inject TWLP Partition", "Inject the TWL photo partition.", 0 },
            { "Inject AGBSAVE Partition", "Inject the Agbsave partition.", 0 },
            { "Inject FIRM0 Partition", "Inject the FIRM0 partition.", 0 },
            { "Inject FIRM1 Partition", "Inject the FIRM1 partition.", 0 },
            { "Inject CTRNAND Partition", "Inject the sysnand main partition.", 0 }
        }
    },
    {
        "PARTITION INJECT... (EMUNAND)", 6, // ID 3
        {
            { "Inject TWLN Partition", "Inject the TWL main partition.", 0 },
            { "Inject TWLP Partition", "Inject the TWL photo partition.", 0 },
            { "Inject AGBSAVE Partition", "Inject the Agbsave partition.", 0 },
            { "Inject FIRM0 Partition", "Inject the FIRM0 partition.", 0 },
            { "Inject FIRM1 Partition", "Inject the FIRM1 partition.", 0 },
            { "Inject CTRNAND Partition", "Inject the emunand main partition.", 0 }
        }
    },
    {
        "FILE DUMP... (SYSNAND)", 9, // ID 4
        {
            { "Dump ticket.db", "Dump ticket.db from sysnand.", 0 },
            { "Dump title.db", "Dump title.db from sysnand.", 0 },
            { "Dump import.db", "Dump import.db from sysnand.", 0 },
            { "Dump certs.db", "Dump certs.db from sysnand.", 0 },
            { "Dump SecureInfo_A", "Dump SecureInfo_A from sysnand.", 0 },
            { "Dump LocalFriendCodeSeed_B", "Dump Local_Friend Code_Seed_B from sysnand.", 0 },
            { "Dump rand_seed", "Dump rand_seed from sysnand.", 0 },
            { "Dump movable.sed", "Dump movable.sed from sysnand.", 0 },
            { "Dump updtsave.bin", "Dump updtsave.bin from sysnand.", 0 }
        }
    },
    {
        "FILE DUMP... (EMUNAND)", 10, // ID 5
        {
            { "Dump ticket.db", "Dump ticket.db from emunand.", 0 },
            { "Dump title.db", "Dump title.db from emunand.", 0 },
            { "Dump import.db", "Dump import.db from emunand.", 0 },
            { "Dump certs.db", "Dump certs.db from emunand.", 0 },
            { "Dump SecureInfo_A", "Dump SecureInfo_A from emunand.", 0 },
            { "Dump LocalFriendCodeSeed_B", "Dump Local_Friend Code_Seed_B from emunand.", 0 },
            { "Dump rand_seed", "Dump rand_seed from emunand.", 0 },
            { "Dump movable.sed", "Dump movable.sed from emunand.", 0 },
            { "Dump seedsave.bin", "Dump seedsave.bin from emunand. OLD 3DS 9.6+ ONLY FOR NOW...", 0 },
            { "Dump updtsave.bin", "Dump updtsave.bin from emunand.", 0 }
        }
    },
    {
        "FILE INJECT... (SYSNAND)", 9, // ID 6
        {
            { "Inject ticket.db", "Inject ticket.db into sysnand.", 0 },
            { "Inject title.db", "Inject title.db into sysnand.", 0 },
            { "Inject import.db", "Inject import.db into sysnand.", 0 },
            { "Inject certs.db", "Inject certs.db into sysnand.", 0 },
            { "Inject SecureInfo_A", "Inject SecureInfo_A into sysnand.", 0 },
            { "Inject LocalFriendCodeSeed_B", "Inject Local_Friend Code_Seed_B into sysnand.", 0 },
            { "Inject rand_seed", "Inject rand_seed into sysnand.", 0 },
            { "Inject movable.sed", "Inject movable.sed into sysnand.", 0 },
            { "Inject updtsave.bin", "Inject updtsave.bin into sysnand.", 0 }
        }
    },
    {
        "FILE INJECT... (EMUNAND)", 10, // ID 7
        {
            { "Inject ticket.db", "Inject ticket.db into sysnand.", 0 },
            { "Inject title.db", "Inject title.db into sysnand.", 0 },
            { "Inject import.db", "Inject import.db into sysnand.", 0 },
            { "Inject certs.db", "Inject certs.db into sysnand.", 0 },
            { "Inject SecureInfo_A", "Inject SecureInfo_A into sysnand.", 0 },
            { "Inject LocalFriendCodeSeed_B", "Inject Local_Friend Code_Seed_B into sysnand.", 0 },
            { "Inject rand_seed", "Inject rand_seed into sysnand.", 0 },
            { "Inject movable.sed", "Inject movable.sed into sysnand.", 0 },
            { "Inject seedsave.bin", "Inject seedsave.bin into emunand. OLD 3DS 9.6+ ONLY FOR NOW...", 0 },
            { "Inject updtsave.bin", "Inject updtsave.bin into sysnand.", 0 }
        }
    },
    {
        NULL, 0, {}, // empty menu to signal end
    }
};
