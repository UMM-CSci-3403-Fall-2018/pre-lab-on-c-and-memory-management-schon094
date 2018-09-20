# Leak report

==17338== 46 bytes in 6 blocks are definitely lost in loss record 1 of 1
==17338==    at 0x4C2FA50: calloc (vg_replace_malloc.c:711)
==17338==    by 0x400678: strip (check_whitespace.c:41)
==17338==    by 0x4006E3: is_clean (check_whitespace.c:62)
==17338==    by 0x40076B: main (check_whitespace.c:87)

the memory errors happen because the variable result is allocated inside the
strip function and never freed.

the error was fixed when free(result) was used at the end of strip
