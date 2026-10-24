# Uploaded SDK layout evidence

SDK SHA256:09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a.
Analysis image base0x180000000. Live addresses are obtained via external process reads; these analysis code addresses are not invoked in HD-Player.

- VMR3GetVM107CD0: page-aligned UVM, magic19700823, VM pointer atUVM+8.
- VMR3GetUVM107C20: VM->UVM at+18; validation uses VM state.<30.
- VMMGetCpuById200C30: count atVM+3C, CPU pointer table atVM+11FE00.
- PGMGstGetPage1DF890: paging mode byte atCPU+1101C. GuestCR3 getter123620 readsCPU+19170.
- RAM-range lookup1EB900/1EB790: cached ranges atVM+106050; tree rootVM+106098, left/right links at50/58, base0,size8; descriptors at70,16bytes per4KiB page.
- Existing contiguous/map translation1EBA20: contiguous flagVM+106019; range host base+30. Existing chunk-cache slotsVM+106860,16bytes each; map pointer+8, node host mapping+28.
- Chunk-map creationDA070 proves its AVL key is atnode+10; links0/8. No remote map allocation is attempted.
- Existing physical TLB entries atVM+106C80,32bytes each, indexed byphysical page&255; physical tag0, host-page pointer18.

Offsets above are hexadecimal. These references establish layout/selected paths, not all SDK semantics. The external backend implements architectural x8632/PAE/AMD64 page walking and only consumes already-mapped normal RAM. Device/MMIO handling, page promotion/COW, nested-translation mode2, every reserved-bit case and live target races are not fully implemented or verified.
