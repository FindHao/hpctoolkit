#ifndef _HPCTOOLKIT_CUPTI_API_H_
#define _HPCTOOLKIT_CUPTI_API_H_

#include <hpcrun/loadmap.h>
#include <cupti.h>
#include "cupti-node.h"

//******************************************************************************
// constants
//******************************************************************************

extern CUpti_ActivityKind
external_correlation_activities[];

extern CUpti_ActivityKind
data_motion_explicit_activities[];

extern CUpti_ActivityKind
data_motion_implicit_activities[];

extern CUpti_ActivityKind
kernel_invocation_activities[];

extern CUpti_ActivityKind
kernel_execution_activities[];

extern CUpti_ActivityKind
driver_activities[];

extern CUpti_ActivityKind
runtime_activities[];

extern CUpti_ActivityKind
overhead_activities[];

typedef enum {
  cupti_set_all = 1,
  cupti_set_some = 2,
  cupti_set_none = 3
} cupti_set_status_t;


//******************************************************************************
// interface functions
//******************************************************************************

extern void
cupti_activity_process
(
 CUpti_Activity *activity
);


extern void 
cupti_buffer_alloc 
(
 uint8_t **buffer, 
 size_t *buffer_size, 
 size_t *maxNumRecords
);


extern void
cupti_callbacks_subscribe
(
);


extern void
cupti_callbacks_unsubscribe
(
);


extern void
cupti_correlation_enable
(
);


extern void
cupti_correlation_disable
(
);


extern void
cupti_pc_sampling_enable
(
);


extern void
cupti_pc_sampling_disable
(
);


extern cupti_set_status_t 
cupti_monitoring_set
(
 const  CUpti_ActivityKind activity_kinds[],
 bool enable
);


extern void
cupti_device_timestamp_get
(
 CUcontext context,
 uint64_t *time
);


extern void 
cupti_trace_init
(
);


extern void 
cupti_trace_start
(
);


extern void 
cupti_trace_pause
(
 CUcontext context,
 bool begin_pause
);


extern void 
cupti_trace_finalize
(
);


extern void
cupti_num_dropped_records_get
(
 CUcontext context,
 uint32_t streamId,
 size_t* dropped 
);


extern bool
cupti_buffer_cursor_advance
(
  uint8_t *buffer,
  size_t size,
  CUpti_Activity **current
);


extern void 
cupti_buffer_completion_callback
(
 CUcontext ctx,
 uint32_t streamId,
 uint8_t *buffer,
 size_t size,
 size_t validSize
);


extern void
cupti_pc_sampling_config
(
  CUcontext context,
  CUpti_ActivityPCSamplingPeriod period
);


extern void
cupti_metrics_init
(
);


extern void
cupti_load_callback_cuda
(
 int module_id, 
 const void *cubin, 
 size_t cubin_size
);


extern void
cupti_unload_callback_cuda
(
 int module_id, 
 const void *cubin, 
 size_t cubin_size
);


extern uint32_t
cupti_context_id_get
(
);

//******************************************************************************
// finalizer
//******************************************************************************

extern void
cupti_activity_flush
(
);


extern void
cupti_device_flush
(
 void *args
);


extern void
cupti_device_shutdown
(
 void *args
);


void
cupti_stop_flag_set
(
);


void
cupti_stop_flag_unset
(
);

//******************************************************************************
// ignores
//******************************************************************************

extern bool
cupti_lm_contains_fn
(
 const char *lm,
 const char *fn
);


extern bool
cupti_modules_ignore
(
 load_module_t *module
);

//******************************************************************************
// notification stack
//******************************************************************************

void
cupti_notification_handle
(
 cupti_node_t *node
);

void
cupti_activity_handle
(
 cupti_node_t *node
);

#endif
