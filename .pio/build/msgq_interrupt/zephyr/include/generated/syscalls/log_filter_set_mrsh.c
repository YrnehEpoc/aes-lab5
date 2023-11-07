/* auto-generated by gen_syscalls.py, don't edit */
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
#include <syscalls/log_ctrl.h>

extern uint32_t z_vrfy_log_filter_set(struct log_backend const *const backend, uint32_t domain_id, int16_t source_id, uint32_t level);
uintptr_t z_mrsh_log_filter_set(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	uint32_t ret = z_vrfy_log_filter_set(*(struct log_backend const *const*)&arg0, *(uint32_t*)&arg1, *(int16_t*)&arg2, *(uint32_t*)&arg3)
;
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif
