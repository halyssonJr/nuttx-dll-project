INCLUDE ../nuttx-export/scripts/gnu-elf.ld

SECTIONS
{
  .got ALIGN(8) :
  {
    *(.got)
    *(.got.*)
  }

  .got.plt ALIGN(8) :
  {
    *(.got.plt)
  }
}
