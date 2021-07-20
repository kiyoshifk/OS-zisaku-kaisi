OUTPUT_FORMAT(pei-i386)
SECTIONS
{
	.text_start 0x8000:
	{
		.text.start = .;
		*(.text-os_start)
		. = .text.start + 0x00278000;
	}
	. = ALIGN(4);
	
	.text :
	{
		*(.text)
	}
	. = ALIGN(4);
	
	.data :
	{
		*(.data)
	}
	. = ALIGN(4);
	
	.reloc :
	{
		*(.reloc);
	}
	. = ALIGN(4);
	
	.rdata :
	{
		*(.rdata)
		*(.rdata$*)
	}
	. = ALIGN(4);
	
	.buildid :
	{
		*(.buildid)
	}
	. = ALIGN(4);
	
	.eh_frame :
	{
		*(.eh_frame*)
	}
	. = ALIGN(4);
	
	.bss :
	{
		*(.bss)
	}
	. = ALIGN(4);
}