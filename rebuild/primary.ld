ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08003000, LENGTH = 0x18800
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

ASSERT(ADDR(.firmware) == 0x08003000, "primary image start address changed")
ASSERT(mi5_primary_image_start == 0x08003000, "primary start symbol moved")
ASSERT(armcc_runtime_entry == 0x08003148, "primary runtime entry moved")
ASSERT(Reset_Handler == 0x0800315C, "primary Reset_Handler moved")
ASSERT(system_init_enable_fpu == 0x08013CB4, "primary FPU initialization moved")
ASSERT(SIZEOF(.firmware) == 0x18800, "primary image size changed")
ASSERT(mi5_primary_image_end == 0x0801B800, "primary end symbol moved")
