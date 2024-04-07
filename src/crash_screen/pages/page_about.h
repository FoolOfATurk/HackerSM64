#pragma once

#include <ultra64.h>

#include "types.h"

#include "crash_screen/cs_settings.h"

#include "game/emutest.h"


enum CSSettingsGroup_page_about {
    CS_OPT_HEADER_PAGE_ABOUT,
    CS_OPT_END_ABOUT,
};


enum CSAboutEntryTypes {
    CS_ABOUT_ENTRY_TYPE_NULL = -1,
    CS_ABOUT_ENTRY_TYPE_NONE,
    CS_ABOUT_ENTRY_TYPE_HEADER,
    CS_ABOUT_ENTRY_TYPE_BUTTON,
    CS_ABOUT_ENTRY_TYPE_TITLE,
    CS_ABOUT_ENTRY_TYPE_SINGLE,
    CS_ABOUT_ENTRY_TYPE_SINGLE_LPL,
    CS_ABOUT_ENTRY_TYPE_LONG,
    CS_ABOUT_ENTRY_TYPE_LONG_N,
};

enum PACKED CSAboutGroups {
    CS_ABOUT_GROUP_TITLE,
    CS_ABOUT_GROUP_BUTTONS,
    CS_ABOUT_GROUP_COMPILER,
    CS_ABOUT_GROUP_ROM,
    CS_ABOUT_GROUP_COLLISION,
    CS_ABOUT_GROUP_MISC,
    CS_ABOUT_GROUP_EMULATOR,
    CS_NUM_ABOUT_GROUPS,
};

enum CSAboutEntries_Title {
    CS_ABOUT_ENTRY_TITLE_HACKERSM64,
    CS_ABOUT_ENTRY_TITLE_CRASH_SCREEN,
    CS_ABOUT_ENTRY_TITLE_END,
    CS_NUM_ABOUT_ENTRIES_TITLE,
};
enum CSAboutEntries_Buttons {
    CS_ABOUT_ENTRY_BUTTONS_EXPAND_ALL,
    CS_ABOUT_ENTRY_BUTTONS_COLLAPSE_ALL,
    CS_ABOUT_ENTRY_BUTTONS_END,
    CS_NUM_ABOUT_ENTRIES_BUTTONS,
};
enum CSAboutEntries_Compiler {
    CS_ABOUT_GROUP_HEADER_COMPILER,
    CS_ABOUT_ENTRY_COMPILER_COMPILER_1,
    CS_ABOUT_ENTRY_COMPILER_COMPILER_2,
    CS_ABOUT_ENTRY_COMPILER_LINKER_1,
    CS_ABOUT_ENTRY_COMPILER_LINKER_2,
    CS_ABOUT_ENTRY_COMPILER_END,
    CS_NUM_ABOUT_ENTRIES_COMPILER,
};
enum CSAboutEntries_Rom {
    CS_ABOUT_GROUP_HEADER_ROM,
    CS_ABOUT_ENTRY_ROM_ROM_NAME,
    CS_ABOUT_ENTRY_ROM_LIBULTRA,
    CS_ABOUT_ENTRY_ROM_MICROCODE,
    CS_ABOUT_ENTRY_ROM_REGION,
    CS_ABOUT_ENTRY_ROM_SAVE_TYPE,
    CS_ABOUT_ENTRY_ROM_COMPRESSION,
    CS_ABOUT_ENTRY_ROM_CRASH_SCREEN,
    CS_ABOUT_ENTRY_ROM_SYMBOLS,
    CS_ABOUT_ENTRY_ROM_ROM_SIZE,
    CS_ABOUT_ENTRY_ROM_RAM_SIZE,
    CS_ABOUT_ENTRY_ROM_END,
    CS_NUM_ABOUT_ENTRIES_ROM,
};
enum CSAboutEntries_Collision {
    CS_ABOUT_GROUP_HEADER_COLLISION,
    CS_ABOUT_ENTRY_COLLISION_LEVEL_BOUNDS,
    CS_ABOUT_ENTRY_COLLISION_CELL_SIZE,
    CS_ABOUT_ENTRY_COLLISION_WORLD_SCALE,
    CS_ABOUT_ENTRY_COLLISION_ST_SURF_POOL,
    CS_ABOUT_ENTRY_COLLISION_DYN_SURF_POOL,
    CS_ABOUT_ENTRY_COLLISION_END,
    CS_NUM_ABOUT_ENTRIES_COLLISION,
};
enum CSAboutEntries_Misc {
    CS_ABOUT_GROUP_HEADER_MISC,
    CS_ABOUT_ENTRY_MISC_GFX_POOL,
    CS_ABOUT_ENTRY_MISC_GODDARD,
    CS_ABOUT_ENTRY_MISC_RCVI_HACK,
    CS_ABOUT_ENTRY_MISC_SILHOUETTE,
    CS_ABOUT_ENTRY_MISC_RUMBLE,
    CS_ABOUT_ENTRY_MISC_DEBUG_MODE,
    CS_ABOUT_ENTRY_MISC_END,
    CS_NUM_ABOUT_ENTRIES_MISC,
};
enum CSAboutEntries_Emulator {
    CS_ABOUT_GROUP_HEADER_EMULATOR,
    CS_ABOUT_ENTRY_EMULATOR_EMULATOR,
#ifdef LIBPL
    CS_ABOUT_ENTRY_EMULATOR_GFX_PLUGIN,
    CS_ABOUT_ENTRY_EMULATOR_LAUNCHER,
    CS_ABOUT_ENTRY_EMULATOR_LIBPL_VERSION,
    CS_ABOUT_ENTRY_EMULATOR_CHEAT_FLAGS,
    CS_ABOUT_ENTRY_EMULATOR_RHDC,
#endif // LIBPL
    CS_ABOUT_ENTRY_EMULATOR_END,
    CS_NUM_ABOUT_ENTRIES_EMULATOR,
};


typedef struct PACKED {
    /*0x00*/ const char* desc;          // Entry description.
    /*0x04*/ void (*func)(char* buf);   // Funxtion that writes the info string to a buffer.
    union {
        /*0x08*/ char info[27];             // Buffer for the info data. If type == CS_ABOUT_ENTRY_TYPE_LONG, uses a different, longer buffer.
        struct PACKED {
            u8 pad[26];
            _Bool expanded;                 // CS_ABOUT_ENTRY_TYPE_HEADER doesn't use the 'info' buffer, so repurpose it.
        } flags;
    };
    /*0x23*/ s8 type;                   // enum CSAboutEntryTypes.
} CSAboutEntry; /*0x24*/

typedef struct CSAboutEntryDisplay {
    /*0x00*/ enum CSAboutGroups groupID;
    /*0x01*/ u8 entryID;
} CSAboutEntryDisplay; /*0x02*/


#define NUM_LONG_INFO_BUFFERS 2
#define LONG_INFO_BUFFER_SIZE 40

#define ABOUT_PAGE_NUM_SCROLLABLE_ENTRIES 21


extern struct CSSetting cs_settings_group_page_about[];
extern struct CSPage gCSPage_about;
