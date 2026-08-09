ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x00002800, LENGTH = 0x89F8
}

SECTIONS
{
    .firmware ORIGIN(FLASH) :
    {
        KEEP(*(.firmware))
    } > FLASH

    /DISCARD/ :
    {
        *(.comment)
        *(.ARM.attributes)
        *(.note*)
    }
}

ASSERT(ADDR(.firmware) == 0x00002800, "secondary image start address changed")
ASSERT(mi5_secondary_image_start == 0x00002800, "secondary start symbol moved")
ASSERT(armcc_runtime_entry == 0x000028C0, "secondary runtime entry moved")
ASSERT(Reset_Handler == 0x00002984, "secondary Reset_Handler moved")
ASSERT(system_init_set_vtor == 0x00008780, "secondary SystemInit moved")
ASSERT(drive_speed_load_patch_site == 0x000087EE, "D speed load patch site moved")
ASSERT(sport_speed_load_patch_site == 0x000087F2, "S speed load patch site moved")
ASSERT(restricted_profile_skip_branch == 0x0000880E, "D/S skip branch moved")
ASSERT(drive_speed_literal_slot == 0x00008810, "D speed literal slot moved")
ASSERT(sport_speed_literal_slot == 0x00008814, "S speed literal slot moved")
ASSERT(SIZEOF(.firmware) == 0x89F8, "secondary image size changed")
ASSERT(mi5_secondary_image_end == 0x0000B1F8, "secondary end symbol moved")
