#ifndef PSXF_GUARD_AUDIO_DEF_H
#define PSXF_GUARD_AUDIO_DEF_H

#include "psx/psx.h"
#include "psx/io.h"  // For IO_SECT_SIZE

// Number of unique XA files
#define XA_Max 3

//XA track enumerations
typedef enum
{
	XA_GettinFreaky,
	XA_GameOver,
	XA_StoryMode,
	
	XA_TooSlow,
	XA_TooSlowEncore,
	
	XA_YouCantRun,
	
	XA_TripleTrouble,
	
	XA_EndlessUS,
	XA_EndlessOG,
	
	XA_Cycles,
	XA_Execution,
	
	XA_Sunshine,
	XA_Soulless,
	
	XA_Chaos,
	
	XA_Prey,
	XA_Fight_Or_Flight,
	
	XA_Round_A_Bout,
	
	XA_Milk,
	
	XA_TooFest,
	
	XA_Personel,
    
    XA_TrackMax,
} XA_Track;

#define XA_LENGTH(x) (((u64)(x) * 75) / 100 * IO_SECT_SIZE) //Centiseconds to sectors in bytes (w)

typedef struct
{
    const char* file_path;  // Path to the XA file
    const char* name;       // Track name for identification
    u32 length;             // Track length in sectors
    boolean vocal;          // Whether the track has vocals
} XA_TrackDef;

static const XA_TrackDef xa_tracks[] = {
    // MENU.XA
    [XA_GettinFreaky] = {"\\MUSIC\\MENU.XA;1", "freakymenu", XA_LENGTH(6119), false},
    [XA_GameOver] = {"\\MUSIC\\MENU.XA;1", "gameover", XA_LENGTH(1920), false},
    [XA_StoryMode] = {"\\MUSIC\\MENU.XA;1", "storymode", XA_LENGTH(7540), false},

    // TOOSLOW.XA
    [XA_TooSlow] = {"\\MUSIC\\TOOSLOW.XA;1", "tooslow", XA_LENGTH(18830), true},
    [XA_TooSlowEncore] = {"\\MUSIC\\TOOSLOW.XA;1", "tooslowencore", XA_LENGTH(18216), true},

    // YCR.XA
    [XA_YouCantRun] = {"\\MUSIC\\YCR.XA;1", "youcantrun", XA_LENGTH(15942), true},

    // TRIPLETRO.XA
    [XA_TripleTrouble] = {"\\MUSIC\\TRIPLETRO.XA;1", "tripletrouble", XA_LENGTH(50710), true},

    // ENDLESS.XA
    [XA_EndlessUS] = {"\\MUSIC\\ENDLESS.XA;1", "endless", XA_LENGTH(16954), true},
    [XA_EndlessOG] = {"\\MUSIC\\ENDLESS.XA;1", "endlessencore", XA_LENGTH(17032), true},

    // CYC-EXEC.XA
    [XA_Cycles] = {"\\MUSIC\\CYC-EXEC.XA;1", "cycles", XA_LENGTH(15230), true},
    [XA_Execution] = {"\\MUSIC\\CYC-EXEC.XA;1", "execution", XA_LENGTH(12158), true},

    // SUN-SOUL.XA
    [XA_Sunshine] = {"\\MUSIC\\SUN-SOUL.XA;1", "sunshine", XA_LENGTH(18342), true},
    [XA_Soulless] = {"\\MUSIC\\SUN-SOUL.XA;1", "soulless", XA_LENGTH(4856), true},

    // CHAOS.XA
    [XA_Chaos] = {"\\MUSIC\\CHAOS.XA;1", "chaos", XA_LENGTH(15751), true},

    // PRY-FOF.XA
    [XA_Prey] = {"\\MUSIC\\PRY-FOF.XA;1", "prey", XA_LENGTH(29045), true},
    [XA_Fight_Or_Flight] = {"\\MUSIC\\PRY-FOF.XA;1", "fight or flight", XA_LENGTH(21990), true},

    // RAB.XA
    [XA_Round_A_Bout] = {"\\MUSIC\\RAB.XA;1", "round a bout", XA_LENGTH(16401), true},

    // MILK.XA
    [XA_Milk] = {"\\MUSIC\\MILK.XA;1", "milk", XA_LENGTH(15846), true},

    // TOOFEST.XA
    [XA_TooFest] = {"\\MUSIC\\TOOFEST.XA;1", "toofest", XA_LENGTH(13179), true},

    // PERSONEL.XA
    [XA_Personel] = {"\\MUSIC\\PERSONEL.XA;1", "personel", XA_LENGTH(16115), true},
};


#endif