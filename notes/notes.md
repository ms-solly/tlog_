#DAY1

- `tlog_logger` is opaque to prevent external modification, opaque means the struct exists can be seen but not its contents 
- `tlog_create` owns the file resource 
- `filepath == NULL` means log to stdout as msg. 
- `tlog_log` requires a valid logger pointer(otherwise undefined behaviour).

#DAY2

test.c -> tlog.c -> tlog.h



`tlog_create`    - tlog.c(defined) - tlog.h(declare) 
`tlog_destroy`   - tlog.c(defined) - tlog.h(declare)
`level_to_string`- tlog.c(defined & declared) 
`tlog_log`       - tlog.c(defined) - tlog.h(declare))


- API and internal helpers should be kept separately 
- translation unit != part of API core
- headers are promises not implementations
- if a struct is opaque,its full definition must exist in one file only 
- only log msg with level >= logger -> level


