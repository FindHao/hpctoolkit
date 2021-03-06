#ifndef _HPCTOOLKIT_CUPTI_ANALYSIS_H_
#define _HPCTOOLKIT_CUPTI_ANALYSIS_H_

#include <cupti_activity.h>

extern void
cupti_occupancy_analyze
(
 CUpti_ActivityKernel4 *activity,
 uint32_t *active_warps_per_sm,
 uint32_t *max_active_warps_per_sm
); 


extern void
cupti_sm_efficiency_analyze
(
 CUpti_ActivityPCSamplingRecordInfo *pc_sampling_record_info,
 uint64_t *total_samples,
 uint64_t *full_sm_samples
);

#endif

