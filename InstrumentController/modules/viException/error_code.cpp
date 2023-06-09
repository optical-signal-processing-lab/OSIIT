#include"error_code.h"

std::map<uint32_t, std::string> ErrorCode = {
    {0xBFFF0000,"VI_ERROR_SYSTEM_ERROR"},
    {0xBFFF000E,"VI_ERROR_INV_OBJECT"},
    {0xBFFF000F,"VI_ERROR_RSRC_LOCKED"},
    {0xBFFF0010,"VI_ERROR_INV_EXPR"},
    {0xBFFF0011,"VI_ERROR_RSRC_NFOUND"},
    {0xBFFF0012,"VI_ERROR_INV_RSRC_NAME"},
    {0xBFFF0013,"VI_ERROR_INV_ACC_MODE"},
    {0xBFFF0015,"VI_ERROR_TMO"},
    {0xBFFF0016,"VI_ERROR_CLOSING_FAILED"},
    {0xBFFF001B,"VI_ERROR_INV_DEGREE"},
    {0xBFFF001C,"VI_ERROR_INV_JOB_ID"},
    {0xBFFF001D,"VI_ERROR_NSUP_ATTR"},
    {0xBFFF001E,"VI_ERROR_NSUP_ATTR_STATE"},
    {0xBFFF001F,"VI_ERROR_ATTR_READONLY"},
    {0xBFFF0020,"VI_ERROR_INV_LOCK_TYPE"},
    {0xBFFF0021,"VI_ERROR_INV_ACCESS_KEY"},
    {0xBFFF0026,"VI_ERROR_INV_EVENT"},
    {0xBFFF0027,"VI_ERROR_INV_MECH"},
    {0xBFFF0028,"VI_ERROR_HNDLR_NINSTALLED"},
    {0xBFFF0029,"VI_ERROR_INV_HNDLR_REF"},
    {0xBFFF002A,"VI_ERROR_INV_CONTEXT"},
    {0xBFFF002D,"VI_ERROR_QUEUE_OVERFLOW"},
    {0xBFFF002F,"VI_ERROR_NENABLED"},
    {0xBFFF0030,"VI_ERROR_ABORT"},
    {0xBFFF0034,"VI_ERROR_RAW_WR_PROT_VIOL"},
    {0xBFFF0035,"VI_ERROR_RAW_RD_PROT_VIOL"},
    {0xBFFF0036,"VI_ERROR_OUTP_PROT_VIOL"},
    {0xBFFF0037,"VI_ERROR_INP_PROT_VIOL"},
    {0xBFFF0038,"VI_ERROR_BERR"},
    {0xBFFF0039,"VI_ERROR_IN_PROGRESS"},
    {0xBFFF003A,"VI_ERROR_INV_SETUP"},
    {0xBFFF003B,"VI_ERROR_QUEUE_ERROR"},
    {0xBFFF003C,"VI_ERROR_ALLOC"},
    {0xBFFF003D,"VI_ERROR_INV_MASK"},
    {0xBFFF003E,"VI_ERROR_IO"},
    {0xBFFF003F,"VI_ERROR_INV_FMT"},
    {0xBFFF0041,"VI_ERROR_NSUP_FMT"},
    {0xBFFF0042,"VI_ERROR_LINE_IN_USE"},
    {0xBFFF0046,"VI_ERROR_NSUP_MODE"},
    {0xBFFF004A,"VI_ERROR_SRQ_NOCCURRED"},
    {0xBFFF004E,"VI_ERROR_INV_SPACE"},
    {0xBFFF0051,"VI_ERROR_INV_OFFSET"},
    {0xBFFF0052,"VI_ERROR_INV_WIDTH"},
    {0xBFFF0054,"VI_ERROR_NSUP_OFFSET"},
    {0xBFFF0055,"VI_ERROR_NSUP_VAR_WIDTH"},
    {0xBFFF0057,"VI_ERROR_WINDOW_NMAPPED"},
    {0xBFFF0059,"VI_ERROR_RESP_PENDING"},
    {0xBFFF005F,"VI_ERROR_NLISTENERS"},
    {0xBFFF0060,"VI_ERROR_NCIC"},
    {0xBFFF0061,"VI_ERROR_NSYS_CNTLR"},
    {0xBFFF0067,"VI_ERROR_NSUP_OPER"},
    {0xBFFF0068,"VI_ERROR_INTR_PENDING"},
    {0xBFFF006A,"VI_ERROR_ASRL_PARITY"},
    {0xBFFF006B,"VI_ERROR_ASRL_FRAMING"},
    {0xBFFF006C,"VI_ERROR_ASRL_OVERRUN"},
    {0xBFFF006E,"VI_ERROR_TRIG_NMAPPED"},
    {0xBFFF0070,"VI_ERROR_NSUP_ALIGN_OFFSET"},
    {0xBFFF0071,"VI_ERROR_USER_BUF"},
    {0xBFFF0072,"VI_ERROR_RSRC_BUSY"},
    {0xBFFF0076,"VI_ERROR_NSUP_WIDTH"},
    {0xBFFF0078,"VI_ERROR_INV_PARAMETER"},
    {0xBFFF0079,"VI_ERROR_INV_PROT"},
    {0xBFFF007B,"VI_ERROR_INV_SIZE"},
    {0xBFFF0080,"VI_ERROR_WINDOW_MAPPED"},
    {0xBFFF0081,"VI_ERROR_NIMPL_OPER"},
    {0xBFFF0083,"VI_ERROR_INV_LENGTH"},
    {0xBFFF0091,"VI_ERROR_INV_MODE"},
    {0xBFFF009C,"VI_ERROR_SESN_NLOCKED"},
    {0xBFFF009D,"VI_ERROR_MEM_NSHARED"},
    {0xBFFF009E,"VI_ERROR_LIBRARY_NFOUND"},
    {0xBFFF009F,"VI_ERROR_NSUP_INTR"},
    {0xBFFF00A0,"VI_ERROR_INV_LINE"},
    {0xBFFF00A1,"VI_ERROR_FILE_ACCESS"},
    {0xBFFF00A2,"VI_ERROR_FILE_IO"},
    {0xBFFF00A3,"VI_ERROR_NSUP_LINE"},
    {0xBFFF00A4,"VI_ERROR_NSUP_MECH"},
    {0xBFFF00A5,"VI_ERROR_INTF_NUM_NCONFIG"},
    {0xBFFF00A6,"VI_ERROR_CONN_LOST"},
    {0xBFFF00A7,"VI_ERROR_MACHINE_NAVAIL"},
    {0xBFFF00A8,"VI_ERROR_NPERMISSION"}
};

std::map<uint32_t, std::string> ErrorDesp = {
    {0xBFFF0000,"Unknown system error (miscellaneous error)."},
    {0xBFFF000E,"The given session or object reference is invalid."},
    {0xBFFF000F,"Specified type of lock cannot be obtained or specified operation cannot be performed, because the resource is locked."},
    {0xBFFF0010,"Invalid expression specified for search."},
    {0xBFFF0011,"Insufficient location information or the device or resource is not present in the system."},
    {0xBFFF0012,"Invalid resource reference specified. Parsing error."},
    {0xBFFF0013,"Invalid access mode."},
    {0xBFFF0015,"Timeout expired before operation completed."},
    {0xBFFF0016,"Unable to deallocate the previously allocated data structures corresponding to this session or object reference."},
    {0xBFFF001B,"Specified degree is invalid."},
    {0xBFFF001C,"Specified job identifier is invalid."},
    {0xBFFF001D,"The specified attribute is not defined or supported by the referenced session, event, or find list."},
    {0xBFFF001E,"The specified state of the attribute is not valid, or is not supported as defined by the session, event, or find list."},
    {0xBFFF001F,"The specified attribute is Read Only."},
    {0xBFFF0020,"The specified type of lock is not supported by this resource."},
    {0xBFFF0021,"The access key to the resource associated with this session is invalid."},
    {0xBFFF0026,"Specified event type is not supported by the resource."},
    {0xBFFF0027,"Invalid mechanism specified."},
    {0xBFFF0028,"A handler is not currently installed for the specified event."},
    {0xBFFF0029,"The given handler reference is invalid."},
    {0xBFFF002A,"Specified event context is invalid."},
    {0xBFFF002D,"The event queue for the specified type has overflowed (usually due to previous events not having been closed)."},
    {0xBFFF002F,"The session must be enabled for events of the specified type in order to receive them."},
    {0xBFFF0030,"The operation was aborted."},
    {0xBFFF0034,"Violation of raw write protocol occurred during transfer."},
    {0xBFFF0035,"Violation of raw read protocol occurred during transfer."},
    {0xBFFF0036,"Device reported an output protocol error during transfer."},
    {0xBFFF0037,"Device reported an input protocol error during transfer."},
    {0xBFFF0038,"Bus error occurred during transfer."},
    {0xBFFF0039,"Unable to queue the asynchronous operation because there is already an operation in progress."},
    {0xBFFF003A,"Unable to start operation because setup is invalid (due to attributes being set to an inconsistent state)."},
    {0xBFFF003B,"Unable to queue asynchronous operation (usually due to the I/O completion event not being enabled or insufficient space in the session's queue)."},
    {0xBFFF003C,"Insufficient system resources to perform necessary memory allocation."},
    {0xBFFF003D,"Invalid buffer mask specified."},
    {0xBFFF003E,"Could not perform operation because of I/O error."},
    {0xBFFF003F,"A format specifier in the format string is invalid."},
    {0xBFFF0041,"A format specifier in the format string is not supported."},
    {0xBFFF0042,"The specified trigger line is currently in use."},
    {0xBFFF0046,"The specified mode is not supported by this VISA implementation."},
    {0xBFFF004A,"Service request has not been received for the session."},
    {0xBFFF004E,"Invalid address space specified."},
    {0xBFFF0051,"Invalid offset specified."},
    {0xBFFF0052,"Invalid source or destination width specified."},
    {0xBFFF0054,"Specified offset is not accessible from this hardware."},
    {0xBFFF0055,"Cannot support source and destination widths that are different."},
    {0xBFFF0057,"The specified session is not currently mapped."},
    {0xBFFF0059,"A previous response is still pending, causing a multiple query error."},
    {0xBFFF005F,"No Listeners condition is detected (both NRFD and NDAC are deasserted)."},
    {0xBFFF0060,"The interface associated with this session is not currently the controller in charge."},
    {0xBFFF0061,"The interface associated with this session is not the system controller."},
    {0xBFFF0067,"The given session or object reference does not support this operation."},
    {0xBFFF0068,"An interrupt is still pending from a previous call."},
    {0xBFFF006A,"A parity error occurred during transfer."},
    {0xBFFF006B,"A framing error occurred during transfer."},
    {0xBFFF006C,"An overrun error occurred during transfer. A character was not read from the hardware before the next character arrived."},
    {0xBFFF006E,"The path from trigSrc to trigDest is not currently mapped."},
    {0xBFFF0070,"The specified offset is not properly aligned for the access width of the operation."},
    {0xBFFF0071,"A specified user buffer is not valid or cannot be accessed for the required size."},
    {0xBFFF0072,"The resource is valid, but VISA cannot currently access it."},
    {0xBFFF0076,"Specified width is not supported by this hardware."},
    {0xBFFF0078,"The value of some parameter��which parameter is not known��is invalid."},
    {0xBFFF0079,"The protocol specified is invalid."},
    {0xBFFF007B,"Invalid size of window specified."},
    {0xBFFF0080,"The specified session currently contains a mapped window."},
    {0xBFFF0081,"The given operation is not implemented."},
    {0xBFFF0083,"Invalid length specified."},
    {0xBFFF0091,"The specified mode is invalid."},
    {0xBFFF009C,"The current session did not have any lock on the resource."},
    {0xBFFF009D,"The device does not export any memory."},
    {0xBFFF009E,"A code library required by VISA could not be located or loaded."},
    {0xBFFF009F,"The interface cannot generate an interrupt on the requested level or with the requested statusID value."},
    {0xBFFF00A0,"The value specified by the line parameter is invalid."},
    {0xBFFF00A1,"An error occurred while trying to open the specified file. Possible reasons include an invalid path or lack of access rights."},
    {0xBFFF00A2,"An error occurred while performing I/O on the specified file."},
    {0xBFFF00A3,"One of the specified lines (trigSrc or trigDest) is not supported by this VISA implementation, or the combination of lines is not a valid mapping."},
    {0xBFFF00A4,"The specified mechanism is not supported for the given event type."},
    {0xBFFF00A5,"The interface type is valid but the specified interface number is not configured."},
    {0xBFFF00A6,"The connection for the given session has been lost."},
    {0xBFFF00A7,"The remote machine does not exist or is not accepting any connections."},
    {0xBFFF00A8,"Access to the resource or remote machine is denied. This is due to lack of sufficient privileges for the current user or machine."},
};