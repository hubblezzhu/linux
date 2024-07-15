// SPDX-License-Identifier: GPL-2.0
/*
 * Tracepoints for RISC-V exceptions
 *
 * Copyright (C) 2024 ISCAS. All rights reserved
 *
 */

#undef TRACE_SYSTEM
#define TRACE_SYSTEM exceptions

#if !defined(_TRACE_PAGE_FAULT_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_PAGE_FAULT_H

#include <linux/tracepoint.h>

TRACE_EVENT(page_fault,
	TP_PROTO(struct pt_regs *regs),
	TP_ARGS(regs),

	TP_STRUCT__entry(
		__field(unsigned long, address)
		__field(unsigned long, cause)
	),

	TP_fast_assign(
		__entry->address	= regs->addr;
		__entry->cause		= regs->scause;
	),

	TP_printk("address=%ps cause=0x%lx",
		  (void *)__entry->address, (void *)__entry->cause)
);

#endif /* _TRACE_PAGE_FAULT_H */

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE trace

/* This part must be outside protection */
#include <trace/define_trace.h>
