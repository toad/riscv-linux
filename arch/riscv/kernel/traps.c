#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/init.h>

#include <asm/processor.h>
#include <asm/ptrace.h>
#include <asm/pcr.h>

extern asmlinkage void handle_exception(void);

void show_stack(struct task_struct *task, unsigned long *sp)
{
}

void dump_stack(void)
{
}
EXPORT_SYMBOL(dump_stack);

void show_regs(struct pt_regs *regs)
{
}

void do_exception(unsigned long cause,
    unsigned long epc, unsigned long badvaddr)
{
	panic("Unhandled exception %ld\n", cause);
}

void __init trap_init(void)
{
	/* This clears the IPI exception that started the processor */
	mtpcr("cr9", 0);

	mtpcr(PCR_EVEC, &handle_exception);
}
