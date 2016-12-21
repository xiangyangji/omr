/* Auto-generated private header file */

/* This file should be included by the IMPLEMENTOR of the hook interface
 * It is not required by USERS of the hook interface
 */

#ifndef MMOMRHOOK_INTERNAL_H
#define MMOMRHOOK_INTERNAL_H

#include "mmomrhook.h"

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_GLOBAL_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_globalGCCount, arg_localGCCount, arg_systemGC, arg_aggressive, arg_bytesRequested) \
	do { \
		struct MM_GlobalGCStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.globalGCCount = (arg_globalGCCount); \
		eventData.localGCCount = (arg_localGCCount); \
		eventData.systemGC = (arg_systemGC); \
		eventData.aggressive = (arg_aggressive); \
		eventData.bytesRequested = (arg_bytesRequested); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_GLOBAL_GC_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_GLOBAL_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_globalGCCount, arg_localGCCount, arg_systemGC, arg_aggressive, arg_bytesRequested) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_GLOBAL_GC_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_GLOBAL_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_globalGCCount, arg_localGCCount, arg_systemGC, arg_aggressive, arg_bytesRequested); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_GLOBAL_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_workpacketCount, arg_nurseryFreeBytes, arg_nurseryTotalBytes, arg_tenureFreeBytes, arg_tenureTotalBytes, arg_loaEnabled, arg_tenureLOAFreeBytes, arg_tenureLOATotalBytes, arg_immortalFreeBytes, arg_immortalTotalBytes, arg_fixHeapForWalkReason, arg_fixHeapForWalkTime) \
	do { \
		struct MM_GlobalGCEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.workStackOverflowOccured = (arg_workStackOverflowOccured); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		eventData.workpacketCount = (arg_workpacketCount); \
		eventData.nurseryFreeBytes = (arg_nurseryFreeBytes); \
		eventData.nurseryTotalBytes = (arg_nurseryTotalBytes); \
		eventData.tenureFreeBytes = (arg_tenureFreeBytes); \
		eventData.tenureTotalBytes = (arg_tenureTotalBytes); \
		eventData.loaEnabled = (arg_loaEnabled); \
		eventData.tenureLOAFreeBytes = (arg_tenureLOAFreeBytes); \
		eventData.tenureLOATotalBytes = (arg_tenureLOATotalBytes); \
		eventData.immortalFreeBytes = (arg_immortalFreeBytes); \
		eventData.immortalTotalBytes = (arg_immortalTotalBytes); \
		eventData.fixHeapForWalkReason = (arg_fixHeapForWalkReason); \
		eventData.fixHeapForWalkTime = (arg_fixHeapForWalkTime); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_GLOBAL_GC_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_GLOBAL_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_workpacketCount, arg_nurseryFreeBytes, arg_nurseryTotalBytes, arg_tenureFreeBytes, arg_tenureTotalBytes, arg_loaEnabled, arg_tenureLOAFreeBytes, arg_tenureLOATotalBytes, arg_immortalFreeBytes, arg_immortalTotalBytes, arg_fixHeapForWalkReason, arg_fixHeapForWalkTime) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_GLOBAL_GC_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_GLOBAL_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_workpacketCount, arg_nurseryFreeBytes, arg_nurseryTotalBytes, arg_tenureFreeBytes, arg_tenureTotalBytes, arg_loaEnabled, arg_tenureLOAFreeBytes, arg_tenureLOATotalBytes, arg_immortalFreeBytes, arg_immortalTotalBytes, arg_fixHeapForWalkReason, arg_fixHeapForWalkTime); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_LOCAL_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_globalGCCount, arg_localGCCount) \
	do { \
		struct MM_LocalGCStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.globalGCCount = (arg_globalGCCount); \
		eventData.localGCCount = (arg_localGCCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_LOCAL_GC_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_LOCAL_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_globalGCCount, arg_localGCCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_LOCAL_GC_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_LOCAL_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_globalGCCount, arg_localGCCount); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_LOCAL_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_subSpace, arg_globalGCCount, arg_localGCCount, arg_rememberedSetOverflowed, arg_causedRememberedSetOverflow, arg_scanCacheOverflow, arg_failedFlipCount, arg_failedFlipBytes, arg_failedTenureCount, arg_failedTenureBytes, arg_backout, arg_flipCount, arg_flipBytes, arg_tenureCount, arg_tenureBytes, arg_tilted, arg_nurseryFreeBytes, arg_nurseryTotalBytes, arg_tenureFreeBytes, arg_tenureTotalBytes, arg_loaEnabled, arg_tenureLOAFreeBytes, arg_tenureLOATotalBytes, arg_tenureAge, arg_totalMemorySize) \
	do { \
		struct MM_LocalGCEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.subSpace = (arg_subSpace); \
		eventData.globalGCCount = (arg_globalGCCount); \
		eventData.localGCCount = (arg_localGCCount); \
		eventData.rememberedSetOverflowed = (arg_rememberedSetOverflowed); \
		eventData.causedRememberedSetOverflow = (arg_causedRememberedSetOverflow); \
		eventData.scanCacheOverflow = (arg_scanCacheOverflow); \
		eventData.failedFlipCount = (arg_failedFlipCount); \
		eventData.failedFlipBytes = (arg_failedFlipBytes); \
		eventData.failedTenureCount = (arg_failedTenureCount); \
		eventData.failedTenureBytes = (arg_failedTenureBytes); \
		eventData.backout = (arg_backout); \
		eventData.flipCount = (arg_flipCount); \
		eventData.flipBytes = (arg_flipBytes); \
		eventData.tenureCount = (arg_tenureCount); \
		eventData.tenureBytes = (arg_tenureBytes); \
		eventData.tilted = (arg_tilted); \
		eventData.nurseryFreeBytes = (arg_nurseryFreeBytes); \
		eventData.nurseryTotalBytes = (arg_nurseryTotalBytes); \
		eventData.tenureFreeBytes = (arg_tenureFreeBytes); \
		eventData.tenureTotalBytes = (arg_tenureTotalBytes); \
		eventData.loaEnabled = (arg_loaEnabled); \
		eventData.tenureLOAFreeBytes = (arg_tenureLOAFreeBytes); \
		eventData.tenureLOATotalBytes = (arg_tenureLOATotalBytes); \
		eventData.tenureAge = (arg_tenureAge); \
		eventData.totalMemorySize = (arg_totalMemorySize); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_LOCAL_GC_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_LOCAL_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_subSpace, arg_globalGCCount, arg_localGCCount, arg_rememberedSetOverflowed, arg_causedRememberedSetOverflow, arg_scanCacheOverflow, arg_failedFlipCount, arg_failedFlipBytes, arg_failedTenureCount, arg_failedTenureBytes, arg_backout, arg_flipCount, arg_flipBytes, arg_tenureCount, arg_tenureBytes, arg_tilted, arg_nurseryFreeBytes, arg_nurseryTotalBytes, arg_tenureFreeBytes, arg_tenureTotalBytes, arg_loaEnabled, arg_tenureLOAFreeBytes, arg_tenureLOATotalBytes, arg_tenureAge, arg_totalMemorySize) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_LOCAL_GC_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_LOCAL_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_subSpace, arg_globalGCCount, arg_localGCCount, arg_rememberedSetOverflowed, arg_causedRememberedSetOverflow, arg_scanCacheOverflow, arg_failedFlipCount, arg_failedFlipBytes, arg_failedTenureCount, arg_failedTenureBytes, arg_backout, arg_flipCount, arg_flipBytes, arg_tenureCount, arg_tenureBytes, arg_tilted, arg_nurseryFreeBytes, arg_nurseryTotalBytes, arg_tenureFreeBytes, arg_tenureTotalBytes, arg_loaEnabled, arg_tenureLOAFreeBytes, arg_tenureLOATotalBytes, arg_tenureAge, arg_totalMemorySize); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_OOM_DUE_TO_SOFTMX(hookInterface, arg_currentThread, arg_timestamp, arg_maxHeapSize, arg_currentHeapSize, arg_currentSoftMX, arg_bytesRequired) \
	do { \
		struct MM_SoftmxOOMEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.maxHeapSize = (arg_maxHeapSize); \
		eventData.currentHeapSize = (arg_currentHeapSize); \
		eventData.currentSoftMX = (arg_currentSoftMX); \
		eventData.bytesRequired = (arg_bytesRequired); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_OOM_DUE_TO_SOFTMX, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_OOM_DUE_TO_SOFTMX(hookInterface, arg_currentThread, arg_timestamp, arg_maxHeapSize, arg_currentHeapSize, arg_currentSoftMX, arg_bytesRequired) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_OOM_DUE_TO_SOFTMX)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_OOM_DUE_TO_SOFTMX(hookInterface, arg_currentThread, arg_timestamp, arg_maxHeapSize, arg_currentHeapSize, arg_currentSoftMX, arg_bytesRequired); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_COMPACT_END(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_CompactEndEvent eventData; \
		eventData.omrVMThread = (arg_omrVMThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_COMPACT_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_COMPACT_END(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_COMPACT_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_COMPACT_END(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_GC_CYCLE_START(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData, arg_cycleType) \
	do { \
		struct MM_GCCycleStartEvent eventData; \
		eventData.omrVMThread = (arg_omrVMThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.commonData = (arg_commonData); \
		eventData.cycleType = (arg_cycleType); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_GC_CYCLE_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_GC_CYCLE_START(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData, arg_cycleType) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_GC_CYCLE_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_GC_CYCLE_START(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData, arg_cycleType); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_GC_CYCLE_CONTINUE(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData, arg_oldCycleType, arg_newCycleType) \
	do { \
		struct MM_GCCycleContinueEvent eventData; \
		eventData.omrVMThread = (arg_omrVMThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.commonData = (arg_commonData); \
		eventData.oldCycleType = (arg_oldCycleType); \
		eventData.newCycleType = (arg_newCycleType); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_GC_CYCLE_CONTINUE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_GC_CYCLE_CONTINUE(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData, arg_oldCycleType, arg_newCycleType) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_GC_CYCLE_CONTINUE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_GC_CYCLE_CONTINUE(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData, arg_oldCycleType, arg_newCycleType); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_GC_CYCLE_END(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData, arg_cycleType, arg_condYieldFromGCFunction) \
	do { \
		struct MM_GCCycleEndEvent eventData; \
		eventData.omrVMThread = (arg_omrVMThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.commonData = (arg_commonData); \
		eventData.cycleType = (arg_cycleType); \
		eventData.condYieldFromGCFunction = (arg_condYieldFromGCFunction); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_GC_CYCLE_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_GC_CYCLE_END(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData, arg_cycleType, arg_condYieldFromGCFunction) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_GC_CYCLE_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_GC_CYCLE_END(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData, arg_cycleType, arg_condYieldFromGCFunction); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_INITIALIZED(hookInterface, arg_currentThread, arg_timestamp, arg_gcPolicy, arg_maxHeapSize, arg_initialHeapSize, arg_physicalMemory, arg_numCPUs, arg_gcThreads, arg_architecture, arg_os, arg_osVersion, arg_compressedPointersShift, arg_beat, arg_timeWindow, arg_targetUtilization, arg_gcTrigger, arg_headRoom, arg_heapPageSize, arg_heapPageType, arg_heapRequestedPageSize, arg_heapRequestedPageType, arg_numaNodes, arg_regionSize, arg_regionCount, arg_arrayletLeafSize) \
	do { \
		struct MM_InitializedEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.gcPolicy = (arg_gcPolicy); \
		eventData.maxHeapSize = (arg_maxHeapSize); \
		eventData.initialHeapSize = (arg_initialHeapSize); \
		eventData.physicalMemory = (arg_physicalMemory); \
		eventData.numCPUs = (arg_numCPUs); \
		eventData.gcThreads = (arg_gcThreads); \
		eventData.architecture = (arg_architecture); \
		eventData.os = (arg_os); \
		eventData.osVersion = (arg_osVersion); \
		eventData.compressedPointersShift = (arg_compressedPointersShift); \
		eventData.beat = (arg_beat); \
		eventData.timeWindow = (arg_timeWindow); \
		eventData.targetUtilization = (arg_targetUtilization); \
		eventData.gcTrigger = (arg_gcTrigger); \
		eventData.headRoom = (arg_headRoom); \
		eventData.heapPageSize = (arg_heapPageSize); \
		eventData.heapPageType = (arg_heapPageType); \
		eventData.heapRequestedPageSize = (arg_heapRequestedPageSize); \
		eventData.heapRequestedPageType = (arg_heapRequestedPageType); \
		eventData.numaNodes = (arg_numaNodes); \
		eventData.regionSize = (arg_regionSize); \
		eventData.regionCount = (arg_regionCount); \
		eventData.arrayletLeafSize = (arg_arrayletLeafSize); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_INITIALIZED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_INITIALIZED(hookInterface, arg_currentThread, arg_timestamp, arg_gcPolicy, arg_maxHeapSize, arg_initialHeapSize, arg_physicalMemory, arg_numCPUs, arg_gcThreads, arg_architecture, arg_os, arg_osVersion, arg_compressedPointersShift, arg_beat, arg_timeWindow, arg_targetUtilization, arg_gcTrigger, arg_headRoom, arg_heapPageSize, arg_heapPageType, arg_heapRequestedPageSize, arg_heapRequestedPageType, arg_numaNodes, arg_regionSize, arg_regionCount, arg_arrayletLeafSize) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_INITIALIZED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_INITIALIZED(hookInterface, arg_currentThread, arg_timestamp, arg_gcPolicy, arg_maxHeapSize, arg_initialHeapSize, arg_physicalMemory, arg_numCPUs, arg_gcThreads, arg_architecture, arg_os, arg_osVersion, arg_compressedPointersShift, arg_beat, arg_timeWindow, arg_targetUtilization, arg_gcTrigger, arg_headRoom, arg_heapPageSize, arg_heapPageType, arg_heapRequestedPageSize, arg_heapRequestedPageType, arg_numaNodes, arg_regionSize, arg_regionCount, arg_arrayletLeafSize); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_VERBOSE_GC_OUTPUT(hookInterface, arg_currentThread, arg_timestamp, arg_string) \
	do { \
		struct MM_VerboseGCOutputEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.string = (arg_string); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_VERBOSE_GC_OUTPUT, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_VERBOSE_GC_OUTPUT(hookInterface, arg_currentThread, arg_timestamp, arg_string) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_VERBOSE_GC_OUTPUT)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_VERBOSE_GC_OUTPUT(hookInterface, arg_currentThread, arg_timestamp, arg_string); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_EXCESSIVEGC_RAISED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount, arg_reclaimedPercent, arg_triggerPercent, arg_excessiveLevel) \
	do { \
		struct MM_ExcessiveGCRaisedEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.gcCount = (arg_gcCount); \
		eventData.reclaimedPercent = (arg_reclaimedPercent); \
		eventData.triggerPercent = (arg_triggerPercent); \
		eventData.excessiveLevel = (arg_excessiveLevel); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_EXCESSIVEGC_RAISED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_EXCESSIVEGC_RAISED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount, arg_reclaimedPercent, arg_triggerPercent, arg_excessiveLevel) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_EXCESSIVEGC_RAISED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_EXCESSIVEGC_RAISED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount, arg_reclaimedPercent, arg_triggerPercent, arg_excessiveLevel); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_OBJECT_DELETE(hookInterface, arg_currentThread, arg_object, arg_heap) \
	do { \
		struct MM_ObjectDeleteEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.object = (arg_object); \
		eventData.heap = (arg_heap); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_OBJECT_DELETE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_OBJECT_DELETE(hookInterface, arg_currentThread, arg_object, arg_heap) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_OBJECT_DELETE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_OBJECT_DELETE(hookInterface, arg_currentThread, arg_object, arg_heap); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_OMR_OBJECT_RENAME(hookInterface, arg_currentThread, arg_oldObject, arg_newObject) \
	do { \
		struct MM_ObjectRenameEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.oldObject = (arg_oldObject); \
		eventData.newObject = (arg_newObject); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_OMR_OBJECT_RENAME, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_OMR_OBJECT_RENAME(hookInterface, arg_currentThread, arg_oldObject, arg_newObject) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_OMR_OBJECT_RENAME)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_OMR_OBJECT_RENAME(hookInterface, arg_currentThread, arg_oldObject, arg_newObject); \
		} \
	} while (0)

typedef struct MM_OMRHookInterface {
	struct J9CommonHookInterface common;
	U_8 flags[15];
	J9HookRecord* hooks[15];
} MM_OMRHookInterface;

#endif /* MMOMRHOOK_INTERNAL_H */
