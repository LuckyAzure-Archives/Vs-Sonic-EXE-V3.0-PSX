#include "playerdef.h"
#include "../player.h"
#include "../stage.h"
#include "chardef.h"

void Player_Generic_Tick(Character *character)
{
    if (((character->pad_held & (stage.prefs.control_keys[0] | stage.prefs.control_keys[1] | stage.prefs.control_keys[2] | stage.prefs.control_keys[3])) == 0) ||
        (character->animatable.anim != CharAnim_Left &&
         character->animatable.anim != CharAnim_LeftAlt &&
         character->animatable.anim != CharAnim_Down &&
         character->animatable.anim != CharAnim_DownAlt &&
         character->animatable.anim != CharAnim_Up &&
         character->animatable.anim != CharAnim_UpAlt &&
         character->animatable.anim != CharAnim_Right &&
         character->animatable.anim != CharAnim_RightAlt))
        Character_CheckEndSing(character);
     
    if (stage.flag & STAGE_FLAG_JUST_STEP)
    {
        //Perform idle dance
        if (Animatable_Ended(&character->animatable) &&
            (character->animatable.anim != CharAnim_Left &&
             character->animatable.anim != CharAnim_LeftAlt &&
             character->animatable.anim != PlayerAnim_LeftMiss &&
             character->animatable.anim != CharAnim_Down &&
             character->animatable.anim != CharAnim_DownAlt &&
             character->animatable.anim != PlayerAnim_DownMiss &&
             character->animatable.anim != CharAnim_Up &&
             character->animatable.anim != CharAnim_UpAlt &&
             character->animatable.anim != PlayerAnim_UpMiss &&
             character->animatable.anim != CharAnim_Right &&
             character->animatable.anim != CharAnim_RightAlt &&
             character->animatable.anim != PlayerAnim_RightMiss) &&
            (stage.song_step & 0x7) == 0)
             character->set_anim(character, CharAnim_Idle);
            
        //Stage specific animations
        if (stage.note_scroll >= 0)
        {
            switch (stage.stage_id)
            {
                default:
                    break;
            }
        }
    }
    
    
    //Animate and draw
    Animatable_Animate(&character->animatable, (void*)character, Char_SetFrame);
    Character_Draw(character, &character->tex, &character->frames[character->frame]);
}

void Player_Generic_SetAnim(Character *character, u8 anim) {
    Char_Generic_SetAnim(character, anim);
}
