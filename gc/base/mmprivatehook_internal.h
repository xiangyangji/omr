/* Auto-generated private header file */

/* This file should be included by the IMPLEMENTOR of the hook interface
 * It is not required by USERS of the hook interface
 */

#ifndef MMPRIVATEHOOK_INTERNAL_H
#define MMPRIVATEHOOK_INTERNAL_H

#include "mmprivatehook.h"

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_globalGCCount, arg_localGCCount, arg_bytesRequested) \
	do { \
		struct MM_GlobalGCIncrementStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.globalGCCount = (arg_globalGCCount); \
		eventData.localGCCount = (arg_localGCCount); \
		eventData.bytesRequested = (arg_bytesRequested); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_globalGCCount, arg_localGCCount, arg_bytesRequested) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_globalGCCount, arg_localGCCount, arg_bytesRequested); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GC_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_stats) \
	do { \
		struct MM_GCIncrementStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.stats = (arg_stats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_GC_INCREMENT_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_GC_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_stats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_GC_INCREMENT_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GC_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_stats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GLOBAL_GC_COLLECT_COMPLETE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_GlobalGCCollectCompleteEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_GLOBAL_GC_COLLECT_COMPLETE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_GLOBAL_GC_COLLECT_COMPLETE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_GLOBAL_GC_COLLECT_COMPLETE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GLOBAL_GC_COLLECT_COMPLETE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_END(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData) \
	do { \
		struct MM_GlobalGCIncrementEndEvent eventData; \
		eventData.omrVMThread = (arg_omrVMThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.commonData = (arg_commonData); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_END(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_END(hookInterface, arg_omrVMThread, arg_timestamp, arg_eventid, arg_commonData); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GC_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_stats) \
	do { \
		struct MM_GCIncrementEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.stats = (arg_stats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_GC_INCREMENT_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_GC_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_stats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_GC_INCREMENT_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GC_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_stats); \
		} \
	} while (0)

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_TAROK_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_incrementid, arg_gcStartData, arg_taxationThreshold) \
	do { \
		struct MM_TarokIncrementStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.incrementid = (arg_incrementid); \
		eventData.gcStartData = (arg_gcStartData); \
		eventData.taxationThreshold = (arg_taxationThreshold); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_TAROK_INCREMENT_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_TAROK_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_incrementid, arg_gcStartData, arg_taxationThreshold) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_TAROK_INCREMENT_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_TAROK_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_incrementid, arg_gcStartData, arg_taxationThreshold); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_TAROK_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_incrementid, arg_gcStartData, arg_taxationThreshold)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_TAROK_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData) \
	do { \
		struct MM_TarokIncrementEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.exclusiveAccessTime = (arg_exclusiveAccessTime); \
		eventData.gcEndData = (arg_gcEndData); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_TAROK_INCREMENT_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_TAROK_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_TAROK_INCREMENT_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_TAROK_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_TAROK_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData)
#endif /* defined (__cplusplus) */

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_MARK_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_MarkStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_MARK_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_MARK_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_MARK_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_MARK_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SCAVENGE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_ScavengeStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_SCAVENGE_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_SCAVENGE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_SCAVENGE_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SCAVENGE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SCAVENGE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_subSpace) \
	do { \
		struct MM_ScavengeEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.subSpace = (arg_subSpace); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_SCAVENGE_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_SCAVENGE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_subSpace) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_SCAVENGE_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SCAVENGE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_subSpace); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_WALK_HEAP_START(hookInterface, arg_omrVM) \
	do { \
		struct MM_WalkHeapStartEvent eventData; \
		eventData.omrVM = (arg_omrVM); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_WALK_HEAP_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_WALK_HEAP_START(hookInterface, arg_omrVM) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_WALK_HEAP_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_WALK_HEAP_START(hookInterface, arg_omrVM); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_WALK_HEAP_END(hookInterface, arg_omrVM) \
	do { \
		struct MM_WalkHeapEndEvent eventData; \
		eventData.omrVM = (arg_omrVM); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_WALK_HEAP_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_WALK_HEAP_END(hookInterface, arg_omrVM) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_WALK_HEAP_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_WALK_HEAP_END(hookInterface, arg_omrVM); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SWEEP_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_SweepStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_SWEEP_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_SWEEP_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_SWEEP_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SWEEP_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SWEEP_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_SweepEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_SWEEP_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_SWEEP_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_SWEEP_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SWEEP_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COMPACT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount) \
	do { \
		struct MM_CompactStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.gcCount = (arg_gcCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_COMPACT_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_COMPACT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_COMPACT_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COMPACT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CLASS_UNLOADING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_ClassUnloadingStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CLASS_UNLOADING_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CLASS_UNLOADING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CLASS_UNLOADING_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CLASS_UNLOADING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_KICKOFF(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_commonData, arg_traceTarget, arg_kickOffThreshold, arg_remainingFree, arg_reason, arg_languageReason) \
	do { \
		struct MM_ConcurrentKickoffEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.commonData = (arg_commonData); \
		eventData.traceTarget = (arg_traceTarget); \
		eventData.kickOffThreshold = (arg_kickOffThreshold); \
		eventData.remainingFree = (arg_remainingFree); \
		eventData.reason = (arg_reason); \
		eventData.languageReason = (arg_languageReason); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_KICKOFF, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_KICKOFF(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_commonData, arg_traceTarget, arg_kickOffThreshold, arg_remainingFree, arg_reason, arg_languageReason) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_KICKOFF)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_KICKOFF(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_commonData, arg_traceTarget, arg_kickOffThreshold, arg_remainingFree, arg_reason, arg_languageReason); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_KICKOFF(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_commonData, arg_traceTarget, arg_kickOffThreshold, arg_remainingFree, arg_reason, arg_languageReason)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_ABORTED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason) \
	do { \
		struct MM_ConcurrentAbortedEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.reason = (arg_reason); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_ABORTED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_ABORTED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_ABORTED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_ABORTED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_ABORTED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_HALTED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_executionMode, arg_traceTarget, arg_tracedTotal, arg_tracedByMutators, arg_tracedByHelpers, arg_cardsCleaned, arg_cardCleaningThreshold, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_isCardCleaningComplete, arg_scanClassesMode, arg_isTracingExhausted) \
	do { \
		struct MM_ConcurrentHaltedEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.executionMode = (arg_executionMode); \
		eventData.traceTarget = (arg_traceTarget); \
		eventData.tracedTotal = (arg_tracedTotal); \
		eventData.tracedByMutators = (arg_tracedByMutators); \
		eventData.tracedByHelpers = (arg_tracedByHelpers); \
		eventData.cardsCleaned = (arg_cardsCleaned); \
		eventData.cardCleaningThreshold = (arg_cardCleaningThreshold); \
		eventData.workStackOverflowOccured = (arg_workStackOverflowOccured); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		eventData.isCardCleaningComplete = (arg_isCardCleaningComplete); \
		eventData.scanClassesMode = (arg_scanClassesMode); \
		eventData.isTracingExhausted = (arg_isTracingExhausted); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_HALTED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_HALTED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_executionMode, arg_traceTarget, arg_tracedTotal, arg_tracedByMutators, arg_tracedByHelpers, arg_cardsCleaned, arg_cardCleaningThreshold, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_isCardCleaningComplete, arg_scanClassesMode, arg_isTracingExhausted) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_HALTED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_HALTED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_executionMode, arg_traceTarget, arg_tracedTotal, arg_tracedByMutators, arg_tracedByHelpers, arg_cardsCleaned, arg_cardCleaningThreshold, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_isCardCleaningComplete, arg_scanClassesMode, arg_isTracingExhausted); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_HALTED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_executionMode, arg_traceTarget, arg_tracedTotal, arg_tracedByMutators, arg_tracedByHelpers, arg_cardsCleaned, arg_cardCleaningThreshold, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_isCardCleaningComplete, arg_scanClassesMode, arg_isTracingExhausted)
#endif /* defined (__cplusplus) */

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount) \
	do { \
		struct MM_ConcurrentCollectionCardCleaningStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount); \
		} \
	} while (0)

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_finalcleanedCardsPhase1, arg_finalcleanedCardsPhase2, arg_finalcleanedCards, arg_bytesTraced, arg_concleanedCardsPhase1, arg_concleanedCardsPhase2, arg_concleanedCardsPhase3, arg_concleanedCards, arg_cardCleaningThreshold, arg_cardCleaningPhase1KickOff, arg_cardCleaningPhase2KickOff, arg_cardCleaningPhase3KickOff, arg_workStackOverflowCount) \
	do { \
		struct MM_ConcurrentCollectionCardCleaningEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.duration = (arg_duration); \
		eventData.finalcleanedCardsPhase1 = (arg_finalcleanedCardsPhase1); \
		eventData.finalcleanedCardsPhase2 = (arg_finalcleanedCardsPhase2); \
		eventData.finalcleanedCards = (arg_finalcleanedCards); \
		eventData.bytesTraced = (arg_bytesTraced); \
		eventData.concleanedCardsPhase1 = (arg_concleanedCardsPhase1); \
		eventData.concleanedCardsPhase2 = (arg_concleanedCardsPhase2); \
		eventData.concleanedCardsPhase3 = (arg_concleanedCardsPhase3); \
		eventData.concleanedCards = (arg_concleanedCards); \
		eventData.cardCleaningThreshold = (arg_cardCleaningThreshold); \
		eventData.cardCleaningPhase1KickOff = (arg_cardCleaningPhase1KickOff); \
		eventData.cardCleaningPhase2KickOff = (arg_cardCleaningPhase2KickOff); \
		eventData.cardCleaningPhase3KickOff = (arg_cardCleaningPhase3KickOff); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_finalcleanedCardsPhase1, arg_finalcleanedCardsPhase2, arg_finalcleanedCards, arg_bytesTraced, arg_concleanedCardsPhase1, arg_concleanedCardsPhase2, arg_concleanedCardsPhase3, arg_concleanedCards, arg_cardCleaningThreshold, arg_cardCleaningPhase1KickOff, arg_cardCleaningPhase2KickOff, arg_cardCleaningPhase3KickOff, arg_workStackOverflowCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_finalcleanedCardsPhase1, arg_finalcleanedCardsPhase2, arg_finalcleanedCards, arg_bytesTraced, arg_concleanedCardsPhase1, arg_concleanedCardsPhase2, arg_concleanedCardsPhase3, arg_concleanedCards, arg_cardCleaningThreshold, arg_cardCleaningPhase1KickOff, arg_cardCleaningPhase2KickOff, arg_cardCleaningPhase3KickOff, arg_workStackOverflowCount); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_finalcleanedCardsPhase1, arg_finalcleanedCardsPhase2, arg_finalcleanedCards, arg_bytesTraced, arg_concleanedCardsPhase1, arg_concleanedCardsPhase2, arg_concleanedCardsPhase3, arg_concleanedCards, arg_cardCleaningThreshold, arg_cardCleaningPhase1KickOff, arg_cardCleaningPhase2KickOff, arg_cardCleaningPhase3KickOff, arg_workStackOverflowCount)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcStartData, arg_traceTarget, arg_tracedTotal, arg_tracedByMutators, arg_tracedByHelpers, arg_cardsCleaned, arg_cardCleaningPhase1Threshold, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_threadsToScanCount, arg_threadsScannedCount, arg_cardCleaningReason) \
	do { \
		struct MM_ConcurrentCollectionStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.gcStartData = (arg_gcStartData); \
		eventData.traceTarget = (arg_traceTarget); \
		eventData.tracedTotal = (arg_tracedTotal); \
		eventData.tracedByMutators = (arg_tracedByMutators); \
		eventData.tracedByHelpers = (arg_tracedByHelpers); \
		eventData.cardsCleaned = (arg_cardsCleaned); \
		eventData.cardCleaningPhase1Threshold = (arg_cardCleaningPhase1Threshold); \
		eventData.workStackOverflowOccured = (arg_workStackOverflowOccured); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		eventData.threadsToScanCount = (arg_threadsToScanCount); \
		eventData.threadsScannedCount = (arg_threadsScannedCount); \
		eventData.cardCleaningReason = (arg_cardCleaningReason); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcStartData, arg_traceTarget, arg_tracedTotal, arg_tracedByMutators, arg_tracedByHelpers, arg_cardsCleaned, arg_cardCleaningPhase1Threshold, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_threadsToScanCount, arg_threadsScannedCount, arg_cardCleaningReason) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcStartData, arg_traceTarget, arg_tracedTotal, arg_tracedByMutators, arg_tracedByHelpers, arg_cardsCleaned, arg_cardCleaningPhase1Threshold, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_threadsToScanCount, arg_threadsScannedCount, arg_cardCleaningReason); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcStartData, arg_traceTarget, arg_tracedTotal, arg_tracedByMutators, arg_tracedByHelpers, arg_cardsCleaned, arg_cardCleaningPhase1Threshold, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_threadsToScanCount, arg_threadsScannedCount, arg_cardCleaningReason)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_exclusiveAccessTime, arg_gcEndData) \
	do { \
		struct MM_ConcurrentCollectionEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.duration = (arg_duration); \
		eventData.exclusiveAccessTime = (arg_exclusiveAccessTime); \
		eventData.gcEndData = (arg_gcEndData); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_exclusiveAccessTime, arg_gcEndData) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_exclusiveAccessTime, arg_gcEndData); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_exclusiveAccessTime, arg_gcEndData)
#endif /* defined (__cplusplus) */

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_ACTIVATED(hookInterface, arg_currentThread) \
	do { \
		struct MM_ConcurrentBackgroundThreadActivatedEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_ACTIVATED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_ACTIVATED(hookInterface, arg_currentThread) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_ACTIVATED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_ACTIVATED(hookInterface, arg_currentThread); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_FINISHED(hookInterface, arg_currentThread, arg_traceTotal) \
	do { \
		struct MM_ConcurrentBackgroundThreadFinishedEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.traceTotal = (arg_traceTotal); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_FINISHED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_FINISHED(hookInterface, arg_currentThread, arg_traceTotal) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_FINISHED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_FINISHED(hookInterface, arg_currentThread, arg_traceTotal); \
		} \
	} while (0)

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount) \
	do { \
		struct MM_ConcurrentCompleteTracingStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_bytesTraced, arg_workStackOverflowCount) \
	do { \
		struct MM_ConcurrentCompleteTracingEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.duration = (arg_duration); \
		eventData.bytesTraced = (arg_bytesTraced); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_bytesTraced, arg_workStackOverflowCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_bytesTraced, arg_workStackOverflowCount); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_bytesTraced, arg_workStackOverflowCount)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount) \
	do { \
		struct MM_ConcurrentRememberedSetScanStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_workStackOverflowCount)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_objectsFound, arg_bytesTraced, arg_workStackOverflowCount) \
	do { \
		struct MM_ConcurrentRememberedSetScanEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.duration = (arg_duration); \
		eventData.objectsFound = (arg_objectsFound); \
		eventData.bytesTraced = (arg_bytesTraced); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_objectsFound, arg_bytesTraced, arg_workStackOverflowCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_objectsFound, arg_bytesTraced, arg_workStackOverflowCount); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_duration, arg_objectsFound, arg_bytesTraced, arg_workStackOverflowCount)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_OBJECT_ENQUEUED_FOR_FINALIZATION(hookInterface, arg_OMR_VM, arg_timestamp, arg_eventid, arg_finalizerJob, arg_job, arg_currentThread) \
	do { \
		struct MM_ObjectEnqueuedForFinalizingEvent eventData; \
		eventData.OMR_VM = (arg_OMR_VM); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.finalizerJob = (arg_finalizerJob); \
		eventData.job = (arg_job); \
		eventData.currentThread = (arg_currentThread); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_OBJECT_ENQUEUED_FOR_FINALIZATION, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_OBJECT_ENQUEUED_FOR_FINALIZATION(hookInterface, arg_OMR_VM, arg_timestamp, arg_eventid, arg_finalizerJob, arg_job, arg_currentThread) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_OBJECT_ENQUEUED_FOR_FINALIZATION)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_OBJECT_ENQUEUED_FOR_FINALIZATION(hookInterface, arg_OMR_VM, arg_timestamp, arg_eventid, arg_finalizerJob, arg_job, arg_currentThread); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_OBJECT_ENQUEUED_FOR_FINALIZATION(hookInterface, arg_OMR_VM, arg_timestamp, arg_eventid, arg_finalizerJob, arg_job, arg_currentThread)
#endif /* defined (__cplusplus) */

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_HEAP_NEW(hookInterface, arg_currentThread, arg_heap) \
	do { \
		struct MM_HeapNewEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.heap = (arg_heap); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_HEAP_NEW, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_HEAP_NEW(hookInterface, arg_currentThread, arg_heap) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_HEAP_NEW)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_HEAP_NEW(hookInterface, arg_currentThread, arg_heap); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_HEAP_DELETE(hookInterface, arg_currentThread, arg_heap) \
	do { \
		struct MM_HeapDeleteEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.heap = (arg_heap); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_HEAP_DELETE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_HEAP_DELETE(hookInterface, arg_currentThread, arg_heap) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_HEAP_DELETE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_HEAP_DELETE(hookInterface, arg_currentThread, arg_heap); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_HEAP_RESIZE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_resizeType, arg_subSpaceType, arg_ratio, arg_amount, arg_newHeapSize, arg_timeTaken, arg_reason) \
	do { \
		struct MM_HeapResizeEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.resizeType = (arg_resizeType); \
		eventData.subSpaceType = (arg_subSpaceType); \
		eventData.ratio = (arg_ratio); \
		eventData.amount = (arg_amount); \
		eventData.newHeapSize = (arg_newHeapSize); \
		eventData.timeTaken = (arg_timeTaken); \
		eventData.reason = (arg_reason); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_HEAP_RESIZE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_HEAP_RESIZE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_resizeType, arg_subSpaceType, arg_ratio, arg_amount, arg_newHeapSize, arg_timeTaken, arg_reason) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_HEAP_RESIZE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_HEAP_RESIZE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_resizeType, arg_subSpaceType, arg_ratio, arg_amount, arg_newHeapSize, arg_timeTaken, arg_reason); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_PERCOLATE_COLLECT(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason) \
	do { \
		struct MM_PercolateCollectEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.reason = (arg_reason); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_PERCOLATE_COLLECT, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_PERCOLATE_COLLECT(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_PERCOLATE_COLLECT)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_PERCOLATE_COLLECT(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason); \
		} \
	} while (0)

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_requestedBytes, arg_gcStartData, arg_subSpaceType) \
	do { \
		struct MM_AllocationFailureCycleStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.requestedBytes = (arg_requestedBytes); \
		eventData.gcStartData = (arg_gcStartData); \
		eventData.subSpaceType = (arg_subSpaceType); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_requestedBytes, arg_gcStartData, arg_subSpaceType) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_requestedBytes, arg_gcStartData, arg_subSpaceType); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_requestedBytes, arg_gcStartData, arg_subSpaceType)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_subSpaceType, arg_gcEndData) \
	do { \
		struct MM_AllocationFailureCycleEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.exclusiveAccessTime = (arg_exclusiveAccessTime); \
		eventData.subSpaceType = (arg_subSpaceType); \
		eventData.gcEndData = (arg_gcEndData); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_subSpaceType, arg_gcEndData) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_subSpaceType, arg_gcEndData); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_subSpaceType, arg_gcEndData)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_requestedBytes, arg_gcStartData, arg_subSpaceType, arg_tenure) \
	do { \
		struct MM_AllocationFailureStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.requestedBytes = (arg_requestedBytes); \
		eventData.gcStartData = (arg_gcStartData); \
		eventData.subSpaceType = (arg_subSpaceType); \
		eventData.tenure = (arg_tenure); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_requestedBytes, arg_gcStartData, arg_subSpaceType, arg_tenure) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_requestedBytes, arg_gcStartData, arg_subSpaceType, arg_tenure); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_requestedBytes, arg_gcStartData, arg_subSpaceType, arg_tenure)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData, arg_allocDescription) \
	do { \
		struct MM_AllocationFailureEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.exclusiveAccessTime = (arg_exclusiveAccessTime); \
		eventData.gcEndData = (arg_gcEndData); \
		eventData.allocDescription = (arg_allocDescription); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData, arg_allocDescription) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData, arg_allocDescription); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData, arg_allocDescription)
#endif /* defined (__cplusplus) */

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SYSTEM_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCode, arg_gcStartData) \
	do { \
		struct MM_SystemGCStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.gcCode = (arg_gcCode); \
		eventData.gcStartData = (arg_gcStartData); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_SYSTEM_GC_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_SYSTEM_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCode, arg_gcStartData) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_SYSTEM_GC_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SYSTEM_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCode, arg_gcStartData); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SYSTEM_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData) \
	do { \
		struct MM_SystemGCEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.exclusiveAccessTime = (arg_exclusiveAccessTime); \
		eventData.gcEndData = (arg_gcEndData); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_SYSTEM_GC_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_SYSTEM_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_SYSTEM_GC_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SYSTEM_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_gcEndData); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_REMEMBEREDSET_OVERFLOW(hookInterface, arg_currentThread) \
	do { \
		struct MM_RememberedSetOverflowEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_REMEMBEREDSET_OVERFLOW, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_REMEMBEREDSET_OVERFLOW(hookInterface, arg_currentThread) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_REMEMBEREDSET_OVERFLOW)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_REMEMBEREDSET_OVERFLOW(hookInterface, arg_currentThread); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SCAVENGER_BACK_OUT(hookInterface, arg_omrVM, arg_value) \
	do { \
		struct MM_ScavengerBackOutEvent eventData; \
		eventData.omrVM = (arg_omrVM); \
		eventData.value = (arg_value); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_SCAVENGER_BACK_OUT, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_SCAVENGER_BACK_OUT(hookInterface, arg_omrVM, arg_value) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_SCAVENGER_BACK_OUT)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_SCAVENGER_BACK_OUT(hookInterface, arg_omrVM, arg_value); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS(hookInterface, arg_currentThread) \
	do { \
		struct MM_ExclusiveAccessEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS(hookInterface, arg_currentThread) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS(hookInterface, arg_currentThread); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_ACQUIRE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_meanIdleTime, arg_lastResponder, arg_haltedThreads) \
	do { \
		struct MM_ExclusiveAccessAcquireEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.exclusiveAccessTime = (arg_exclusiveAccessTime); \
		eventData.meanIdleTime = (arg_meanIdleTime); \
		eventData.lastResponder = (arg_lastResponder); \
		eventData.haltedThreads = (arg_haltedThreads); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_ACQUIRE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_ACQUIRE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_meanIdleTime, arg_lastResponder, arg_haltedThreads) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_ACQUIRE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_ACQUIRE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime, arg_meanIdleTime, arg_lastResponder, arg_haltedThreads); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_RELEASE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_ExclusiveAccessReleaseEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_RELEASE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_RELEASE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_RELEASE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_RELEASE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_INVOKE_GC_CHECK(hookInterface, arg_omrVM, arg_portLibrary, arg_options, arg_invocationNumber) \
	do { \
		struct MM_InvokeGCCheckEvent eventData; \
		eventData.omrVM = (arg_omrVM); \
		eventData.portLibrary = (arg_portLibrary); \
		eventData.options = (arg_options); \
		eventData.invocationNumber = (arg_invocationNumber); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_INVOKE_GC_CHECK, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_INVOKE_GC_CHECK(hookInterface, arg_omrVM, arg_portLibrary, arg_options, arg_invocationNumber) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_INVOKE_GC_CHECK)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_INVOKE_GC_CHECK(hookInterface, arg_omrVM, arg_portLibrary, arg_options, arg_invocationNumber); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENTLY_COMPLETED_SWEEP_PHASE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_timeElapsed, arg_bytesSwept) \
	do { \
		struct MM_ConcurrentlyCompletedSweepPhase eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.timeElapsed = (arg_timeElapsed); \
		eventData.bytesSwept = (arg_bytesSwept); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENTLY_COMPLETED_SWEEP_PHASE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENTLY_COMPLETED_SWEEP_PHASE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_timeElapsed, arg_bytesSwept) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENTLY_COMPLETED_SWEEP_PHASE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENTLY_COMPLETED_SWEEP_PHASE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_timeElapsed, arg_bytesSwept); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COMPLETED_CONCURRENT_SWEEP(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_timeElapsedSweep, arg_bytesSwept, arg_timeElapsedConnect, arg_bytesConnected, arg_reason) \
	do { \
		struct MM_CompletedConcurrentSweep eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.timeElapsedSweep = (arg_timeElapsedSweep); \
		eventData.bytesSwept = (arg_bytesSwept); \
		eventData.timeElapsedConnect = (arg_timeElapsedConnect); \
		eventData.bytesConnected = (arg_bytesConnected); \
		eventData.reason = (arg_reason); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_COMPLETED_CONCURRENT_SWEEP, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_COMPLETED_CONCURRENT_SWEEP(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_timeElapsedSweep, arg_bytesSwept, arg_timeElapsedConnect, arg_bytesConnected, arg_reason) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_COMPLETED_CONCURRENT_SWEEP)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COMPLETED_CONCURRENT_SWEEP(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_timeElapsedSweep, arg_bytesSwept, arg_timeElapsedConnect, arg_bytesConnected, arg_reason); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_GC_ACTIVITY(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount, arg_gcInTime, arg_gcOutTime, arg_newGCPercent, arg_averageGCPercent, arg_excessiveGCPercent) \
	do { \
		struct MM_ExcessiveGCCheckGCActivityEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.gcCount = (arg_gcCount); \
		eventData.gcInTime = (arg_gcInTime); \
		eventData.gcOutTime = (arg_gcOutTime); \
		eventData.newGCPercent = (arg_newGCPercent); \
		eventData.averageGCPercent = (arg_averageGCPercent); \
		eventData.excessiveGCPercent = (arg_excessiveGCPercent); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_GC_ACTIVITY, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_GC_ACTIVITY(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount, arg_gcInTime, arg_gcOutTime, arg_newGCPercent, arg_averageGCPercent, arg_excessiveGCPercent) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_GC_ACTIVITY)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_GC_ACTIVITY(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount, arg_gcInTime, arg_gcOutTime, arg_newGCPercent, arg_averageGCPercent, arg_excessiveGCPercent); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_FREE_SPACE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount, arg_newGCPercent, arg_averageGCPercent, arg_excessiveGCPercent, arg_freeMemoryDelta, arg_reclaimedPercent, arg_activeHeapSize, arg_currentHeapSize, arg_maximumHeapSize) \
	do { \
		struct MM_ExcessiveGCCheckFreeSpaceEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.gcCount = (arg_gcCount); \
		eventData.newGCPercent = (arg_newGCPercent); \
		eventData.averageGCPercent = (arg_averageGCPercent); \
		eventData.excessiveGCPercent = (arg_excessiveGCPercent); \
		eventData.freeMemoryDelta = (arg_freeMemoryDelta); \
		eventData.reclaimedPercent = (arg_reclaimedPercent); \
		eventData.activeHeapSize = (arg_activeHeapSize); \
		eventData.currentHeapSize = (arg_currentHeapSize); \
		eventData.maximumHeapSize = (arg_maximumHeapSize); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_FREE_SPACE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_FREE_SPACE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount, arg_newGCPercent, arg_averageGCPercent, arg_excessiveGCPercent, arg_freeMemoryDelta, arg_reclaimedPercent, arg_activeHeapSize, arg_currentHeapSize, arg_maximumHeapSize) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_FREE_SPACE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_FREE_SPACE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_gcCount, arg_newGCPercent, arg_averageGCPercent, arg_excessiveGCPercent, arg_freeMemoryDelta, arg_reclaimedPercent, arg_activeHeapSize, arg_currentHeapSize, arg_maximumHeapSize); \
		} \
	} while (0)

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CACHE_CLEARED(hookInterface, arg_currentThread, arg_subSpace, arg_cacheBase, arg_cacheAlloc, arg_cacheTop) \
	do { \
		struct MM_CacheClearedEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.subSpace = (arg_subSpace); \
		eventData.cacheBase = (arg_cacheBase); \
		eventData.cacheAlloc = (arg_cacheAlloc); \
		eventData.cacheTop = (arg_cacheTop); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CACHE_CLEARED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CACHE_CLEARED(hookInterface, arg_currentThread, arg_subSpace, arg_cacheBase, arg_cacheAlloc, arg_cacheTop) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CACHE_CLEARED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CACHE_CLEARED(hookInterface, arg_currentThread, arg_subSpace, arg_cacheBase, arg_cacheAlloc, arg_cacheTop); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CACHE_CLEARED(hookInterface, arg_currentThread, arg_subSpace, arg_cacheBase, arg_cacheAlloc, arg_cacheTop)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CACHE_REFRESHED(hookInterface, arg_currentThread, arg_subSpace, arg_cacheBase, arg_cacheTop) \
	do { \
		struct MM_CacheRefreshedEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.subSpace = (arg_subSpace); \
		eventData.cacheBase = (arg_cacheBase); \
		eventData.cacheTop = (arg_cacheTop); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CACHE_REFRESHED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CACHE_REFRESHED(hookInterface, arg_currentThread, arg_subSpace, arg_cacheBase, arg_cacheTop) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CACHE_REFRESHED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CACHE_REFRESHED(hookInterface, arg_currentThread, arg_subSpace, arg_cacheBase, arg_cacheTop); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_CACHE_REFRESHED(hookInterface, arg_currentThread, arg_subSpace, arg_cacheBase, arg_cacheTop)
#endif /* defined (__cplusplus) */

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_NON_TLH_ALLOCATION(hookInterface, arg_currentThread, arg_objectPtr) \
	do { \
		struct MM_NonTLHAllocationEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.objectPtr = (arg_objectPtr); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_NON_TLH_ALLOCATION, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_NON_TLH_ALLOCATION(hookInterface, arg_currentThread, arg_objectPtr) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_NON_TLH_ALLOCATION)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_NON_TLH_ALLOCATION(hookInterface, arg_currentThread, arg_objectPtr); \
		} \
	} while (0)

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_OBJECT_REMOVED_FROM_REMEMBERED_SET(hookInterface, arg_currentThread, arg_objectPtr) \
	do { \
		struct MM_ObjectRemovedFromRememberedSetEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.objectPtr = (arg_objectPtr); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_OBJECT_REMOVED_FROM_REMEMBERED_SET, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_OBJECT_REMOVED_FROM_REMEMBERED_SET(hookInterface, arg_currentThread, arg_objectPtr) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_OBJECT_REMOVED_FROM_REMEMBERED_SET)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_OBJECT_REMOVED_FROM_REMEMBERED_SET(hookInterface, arg_currentThread, arg_objectPtr); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_OBJECT_REMOVED_FROM_REMEMBERED_SET(hookInterface, arg_currentThread, arg_objectPtr)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_REBUILD_FREE_LIST(hookInterface, arg_currentThread, arg_rangeBase, arg_rangeTop) \
	do { \
		struct MM_RebuildFreeListEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.rangeBase = (arg_rangeBase); \
		eventData.rangeTop = (arg_rangeTop); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_REBUILD_FREE_LIST, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_REBUILD_FREE_LIST(hookInterface, arg_currentThread, arg_rangeBase, arg_rangeTop) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_REBUILD_FREE_LIST)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_REBUILD_FREE_LIST(hookInterface, arg_currentThread, arg_rangeBase, arg_rangeTop); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_REBUILD_FREE_LIST(hookInterface, arg_currentThread, arg_rangeBase, arg_rangeTop)
#endif /* defined (__cplusplus) */

#if defined (__cplusplus)
#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_MOVE_OBJECTS(hookInterface, arg_currentThread, arg_sourceBase, arg_destinationBase, arg_size) \
	do { \
		struct MM_MoveObjectsEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.sourceBase = (arg_sourceBase); \
		eventData.destinationBase = (arg_destinationBase); \
		eventData.size = (arg_size); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_MOVE_OBJECTS, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_MOVE_OBJECTS(hookInterface, arg_currentThread, arg_sourceBase, arg_destinationBase, arg_size) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_MOVE_OBJECTS)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_MOVE_OBJECTS(hookInterface, arg_currentThread, arg_sourceBase, arg_destinationBase, arg_size); \
		} \
	} while (0)
#else /* defined (__cplusplus) */
#define TRIGGER_J9HOOK_MM_PRIVATE_MOVE_OBJECTS(hookInterface, arg_currentThread, arg_sourceBase, arg_destinationBase, arg_size)
#endif /* defined (__cplusplus) */

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CARD_CLEANING_PASS_2_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_CardCleanPass2StartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CARD_CLEANING_PASS_2_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CARD_CLEANING_PASS_2_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CARD_CLEANING_PASS_2_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CARD_CLEANING_PASS_2_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime) \
	do { \
		struct MM_MetronomeIncrementStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.exclusiveAccessTime = (arg_exclusiveAccessTime); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_exclusiveAccessTime); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_heapFree, arg_immortalFree, arg_classLoadersUnloaded, arg_classesUnloaded, arg_anonymousClassesUnloaded, arg_nonDeterministicSweepCount, arg_nonDeterministicSweepConsecutive, arg_nonDeterministicSweepDelay, arg_weakReferenceClearCount, arg_softReferenceClearCount, arg_softReferenceThreshold, arg_dynamicSoftReferenceThreshold, arg_phantomReferenceClearCount, arg_finalizableCount, arg_workPacketOverflowCount, arg_objectOverflowCount) \
	do { \
		struct MM_MetronomeIncrementEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.heapFree = (arg_heapFree); \
		eventData.immortalFree = (arg_immortalFree); \
		eventData.classLoadersUnloaded = (arg_classLoadersUnloaded); \
		eventData.classesUnloaded = (arg_classesUnloaded); \
		eventData.anonymousClassesUnloaded = (arg_anonymousClassesUnloaded); \
		eventData.nonDeterministicSweepCount = (arg_nonDeterministicSweepCount); \
		eventData.nonDeterministicSweepConsecutive = (arg_nonDeterministicSweepConsecutive); \
		eventData.nonDeterministicSweepDelay = (arg_nonDeterministicSweepDelay); \
		eventData.weakReferenceClearCount = (arg_weakReferenceClearCount); \
		eventData.softReferenceClearCount = (arg_softReferenceClearCount); \
		eventData.softReferenceThreshold = (arg_softReferenceThreshold); \
		eventData.dynamicSoftReferenceThreshold = (arg_dynamicSoftReferenceThreshold); \
		eventData.phantomReferenceClearCount = (arg_phantomReferenceClearCount); \
		eventData.finalizableCount = (arg_finalizableCount); \
		eventData.workPacketOverflowCount = (arg_workPacketOverflowCount); \
		eventData.objectOverflowCount = (arg_objectOverflowCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_heapFree, arg_immortalFree, arg_classLoadersUnloaded, arg_classesUnloaded, arg_anonymousClassesUnloaded, arg_nonDeterministicSweepCount, arg_nonDeterministicSweepConsecutive, arg_nonDeterministicSweepDelay, arg_weakReferenceClearCount, arg_softReferenceClearCount, arg_softReferenceThreshold, arg_dynamicSoftReferenceThreshold, arg_phantomReferenceClearCount, arg_finalizableCount, arg_workPacketOverflowCount, arg_objectOverflowCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_heapFree, arg_immortalFree, arg_classLoadersUnloaded, arg_classesUnloaded, arg_anonymousClassesUnloaded, arg_nonDeterministicSweepCount, arg_nonDeterministicSweepConsecutive, arg_nonDeterministicSweepDelay, arg_weakReferenceClearCount, arg_softReferenceClearCount, arg_softReferenceThreshold, arg_dynamicSoftReferenceThreshold, arg_phantomReferenceClearCount, arg_finalizableCount, arg_workPacketOverflowCount, arg_objectOverflowCount); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason, arg_reasonParameter, arg_heapFree, arg_immortalFree, arg_classLoadersUnloaded, arg_classesUnloaded, arg_anonymousClassesUnloaded) \
	do { \
		struct MM_MetronomeSynchronousGCStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.reason = (arg_reason); \
		eventData.reasonParameter = (arg_reasonParameter); \
		eventData.heapFree = (arg_heapFree); \
		eventData.immortalFree = (arg_immortalFree); \
		eventData.classLoadersUnloaded = (arg_classLoadersUnloaded); \
		eventData.classesUnloaded = (arg_classesUnloaded); \
		eventData.anonymousClassesUnloaded = (arg_anonymousClassesUnloaded); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason, arg_reasonParameter, arg_heapFree, arg_immortalFree, arg_classLoadersUnloaded, arg_classesUnloaded, arg_anonymousClassesUnloaded) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_reason, arg_reasonParameter, arg_heapFree, arg_immortalFree, arg_classLoadersUnloaded, arg_classesUnloaded, arg_anonymousClassesUnloaded); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_heapFree, arg_immortalFree, arg_classLoadersUnloaded, arg_classesUnloaded, arg_anonymousClassesUnloaded, arg_weakReferenceClearCount, arg_softReferenceClearCount, arg_softReferenceThreshold, arg_dynamicSoftReferenceThreshold, arg_phantomReferenceClearCount, arg_finalizableCount, arg_workPacketOverflowCount, arg_objectOverflowCount) \
	do { \
		struct MM_MetronomeSynchronousGCEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.heapFree = (arg_heapFree); \
		eventData.immortalFree = (arg_immortalFree); \
		eventData.classLoadersUnloaded = (arg_classLoadersUnloaded); \
		eventData.classesUnloaded = (arg_classesUnloaded); \
		eventData.anonymousClassesUnloaded = (arg_anonymousClassesUnloaded); \
		eventData.weakReferenceClearCount = (arg_weakReferenceClearCount); \
		eventData.softReferenceClearCount = (arg_softReferenceClearCount); \
		eventData.softReferenceThreshold = (arg_softReferenceThreshold); \
		eventData.dynamicSoftReferenceThreshold = (arg_dynamicSoftReferenceThreshold); \
		eventData.phantomReferenceClearCount = (arg_phantomReferenceClearCount); \
		eventData.finalizableCount = (arg_finalizableCount); \
		eventData.workPacketOverflowCount = (arg_workPacketOverflowCount); \
		eventData.objectOverflowCount = (arg_objectOverflowCount); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_heapFree, arg_immortalFree, arg_classLoadersUnloaded, arg_classesUnloaded, arg_anonymousClassesUnloaded, arg_weakReferenceClearCount, arg_softReferenceClearCount, arg_softReferenceThreshold, arg_dynamicSoftReferenceThreshold, arg_phantomReferenceClearCount, arg_finalizableCount, arg_workPacketOverflowCount, arg_objectOverflowCount) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_heapFree, arg_immortalFree, arg_classLoadersUnloaded, arg_classesUnloaded, arg_anonymousClassesUnloaded, arg_weakReferenceClearCount, arg_softReferenceClearCount, arg_softReferenceThreshold, arg_dynamicSoftReferenceThreshold, arg_phantomReferenceClearCount, arg_finalizableCount, arg_workPacketOverflowCount, arg_objectOverflowCount); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_MetronomeTriggerStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_MetronomeTriggerEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_OUT_OF_MEMORY(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_memorySpace, arg_memorySpaceString) \
	do { \
		struct MM_OutOfMemoryEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.memorySpace = (arg_memorySpace); \
		eventData.memorySpaceString = (arg_memorySpaceString); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_OUT_OF_MEMORY, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_OUT_OF_MEMORY(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_memorySpace, arg_memorySpaceString) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_OUT_OF_MEMORY)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_OUT_OF_MEMORY(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_memorySpace, arg_memorySpaceString); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_UTILIZATION_TRACKER_OVERFLOW(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_utilizationTrackerAddress, arg_timeSliceDurationArrayAddress, arg_timeSliceCursor) \
	do { \
		struct MM_UtilizationTrackerOverflowEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.utilizationTrackerAddress = (arg_utilizationTrackerAddress); \
		eventData.timeSliceDurationArrayAddress = (arg_timeSliceDurationArrayAddress); \
		eventData.timeSliceCursor = (arg_timeSliceCursor); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_UTILIZATION_TRACKER_OVERFLOW, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_UTILIZATION_TRACKER_OVERFLOW(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_utilizationTrackerAddress, arg_timeSliceDurationArrayAddress, arg_timeSliceCursor) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_UTILIZATION_TRACKER_OVERFLOW)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_UTILIZATION_TRACKER_OVERFLOW(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_utilizationTrackerAddress, arg_timeSliceDurationArrayAddress, arg_timeSliceCursor); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_NON_MONOTONIC_TIME(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_timerDesc) \
	do { \
		struct MM_NonMonotonicTimeEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.timerDesc = (arg_timerDesc); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_NON_MONOTONIC_TIME, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_NON_MONOTONIC_TIME(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_timerDesc) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_NON_MONOTONIC_TIME)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_NON_MONOTONIC_TIME(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_timerDesc); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_REPORT_MEMORY_USAGE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_statistics) \
	do { \
		struct MM_ReportMemoryUsageEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.statistics = (arg_statistics); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_REPORT_MEMORY_USAGE, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_REPORT_MEMORY_USAGE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_statistics) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_REPORT_MEMORY_USAGE)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_REPORT_MEMORY_USAGE(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_statistics); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_VLHGC_GARBAGE_COLLECT_COMPLETED(hookInterface, arg_currentThread, arg_timestamp) \
	do { \
		struct MM_VlhgcGarbageCollectCompletedEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_VLHGC_GARBAGE_COLLECT_COMPLETED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_VLHGC_GARBAGE_COLLECT_COMPLETED(hookInterface, arg_currentThread, arg_timestamp) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_VLHGC_GARBAGE_COLLECT_COMPLETED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_VLHGC_GARBAGE_COLLECT_COMPLETED(hookInterface, arg_currentThread, arg_timestamp); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COPY_FORWARD_ABORT(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_CopyForwardAbortEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_COPY_FORWARD_ABORT, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_COPY_FORWARD_ABORT(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_COPY_FORWARD_ABORT)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COPY_FORWARD_ABORT(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COPY_FORWARD_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_copyForwardStats) \
	do { \
		struct MM_CopyForwardStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.copyForwardStats = (arg_copyForwardStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_COPY_FORWARD_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_COPY_FORWARD_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_copyForwardStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_COPY_FORWARD_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COPY_FORWARD_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_copyForwardStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COPY_FORWARD_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_copyForwardStats, arg_workPacketStats, arg_irrsStats) \
	do { \
		struct MM_CopyForwardEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.copyForwardStats = (arg_copyForwardStats); \
		eventData.workPacketStats = (arg_workPacketStats); \
		eventData.irrsStats = (arg_irrsStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_COPY_FORWARD_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_COPY_FORWARD_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_copyForwardStats, arg_workPacketStats, arg_irrsStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_COPY_FORWARD_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_COPY_FORWARD_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_copyForwardStats, arg_workPacketStats, arg_irrsStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_GMP_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_concurrentGMPStats) \
	do { \
		struct MM_ConcurrentGMPStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.concurrentGMPStats = (arg_concurrentGMPStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_GMP_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_GMP_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_concurrentGMPStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_GMP_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_GMP_START(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_concurrentGMPStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_GMP_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_concurrentGMPStats) \
	do { \
		struct MM_ConcurrentGMPEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.concurrentGMPStats = (arg_concurrentGMPStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_CONCURRENT_GMP_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_GMP_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_concurrentGMPStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_CONCURRENT_GMP_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_CONCURRENT_GMP_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_concurrentGMPStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_MARK_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		struct MM_MarkEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_MARK_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_MARK_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_MARK_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_MARK_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GMP_MARK_START(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		struct MM_GMPMarkStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.markStats = (arg_markStats); \
		eventData.workPacketStats = (arg_workPacketStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_GMP_MARK_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_GMP_MARK_START(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_GMP_MARK_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GMP_MARK_START(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GMP_MARK_END(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		struct MM_GMPMarkEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.markStats = (arg_markStats); \
		eventData.workPacketStats = (arg_workPacketStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_GMP_MARK_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_GMP_MARK_END(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_GMP_MARK_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GMP_MARK_END(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_START(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		struct MM_VLHGCGlobalGCMarkStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.markStats = (arg_markStats); \
		eventData.workPacketStats = (arg_workPacketStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_START(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_START(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_END(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		struct MM_VLHGCGlobalGCMarkEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.markStats = (arg_markStats); \
		eventData.workPacketStats = (arg_workPacketStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_END(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_END(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_PGC_MARK_START(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		struct MM_PGCMarkStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.markStats = (arg_markStats); \
		eventData.workPacketStats = (arg_workPacketStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_PGC_MARK_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_PGC_MARK_START(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_PGC_MARK_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_PGC_MARK_START(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_PGC_MARK_END(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats, arg_irrsStats) \
	do { \
		struct MM_PGCMarkEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.markStats = (arg_markStats); \
		eventData.workPacketStats = (arg_workPacketStats); \
		eventData.irrsStats = (arg_irrsStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_PGC_MARK_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_PGC_MARK_END(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats, arg_irrsStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_PGC_MARK_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_PGC_MARK_END(hookInterface, arg_currentThread, arg_markStats, arg_workPacketStats, arg_irrsStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_START(hookInterface, arg_currentThread, arg_sweepStats) \
	do { \
		struct MM_ReclaimSweepStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.sweepStats = (arg_sweepStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_START(hookInterface, arg_currentThread, arg_sweepStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_START(hookInterface, arg_currentThread, arg_sweepStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_END(hookInterface, arg_currentThread, arg_sweepStats) \
	do { \
		struct MM_ReclaimSweepEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.sweepStats = (arg_sweepStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_END(hookInterface, arg_currentThread, arg_sweepStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_END(hookInterface, arg_currentThread, arg_sweepStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_START(hookInterface, arg_currentThread, arg_compactStats) \
	do { \
		struct MM_ReclaimCompactStartEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.compactStats = (arg_compactStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_START, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_START(hookInterface, arg_currentThread, arg_compactStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_START)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_START(hookInterface, arg_currentThread, arg_compactStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_END(hookInterface, arg_currentThread, arg_compactStats, arg_irrsStats) \
	do { \
		struct MM_ReclaimCompactEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.compactStats = (arg_compactStats); \
		eventData.irrsStats = (arg_irrsStats); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_END(hookInterface, arg_currentThread, arg_compactStats, arg_irrsStats) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_END(hookInterface, arg_currentThread, arg_compactStats, arg_irrsStats); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GC_POST_CYCLE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_commonData, arg_cycleType, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_workpacketCount, arg_fixHeapForWalkReason, arg_fixHeapForWalkTime) \
	do { \
		struct MM_GCPostCycleEndEvent eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.commonData = (arg_commonData); \
		eventData.cycleType = (arg_cycleType); \
		eventData.workStackOverflowOccured = (arg_workStackOverflowOccured); \
		eventData.workStackOverflowCount = (arg_workStackOverflowCount); \
		eventData.workpacketCount = (arg_workpacketCount); \
		eventData.fixHeapForWalkReason = (arg_fixHeapForWalkReason); \
		eventData.fixHeapForWalkTime = (arg_fixHeapForWalkTime); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_GC_POST_CYCLE_END, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_GC_POST_CYCLE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_commonData, arg_cycleType, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_workpacketCount, arg_fixHeapForWalkReason, arg_fixHeapForWalkTime) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_GC_POST_CYCLE_END)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_GC_POST_CYCLE_END(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_commonData, arg_cycleType, arg_workStackOverflowOccured, arg_workStackOverflowCount, arg_workpacketCount, arg_fixHeapForWalkReason, arg_fixHeapForWalkTime); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ACQUIRED_EXCLUSIVE_TO_SATISFY_ALLOCATION(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_bytesRequested, arg_subSpaceTypeFlags) \
	do { \
		struct MM_AcquiredExclusiveToSatisfyAllocation eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.bytesRequested = (arg_bytesRequested); \
		eventData.subSpaceTypeFlags = (arg_subSpaceTypeFlags); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_ACQUIRED_EXCLUSIVE_TO_SATISFY_ALLOCATION, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_ACQUIRED_EXCLUSIVE_TO_SATISFY_ALLOCATION(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_bytesRequested, arg_subSpaceTypeFlags) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_ACQUIRED_EXCLUSIVE_TO_SATISFY_ALLOCATION)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_ACQUIRED_EXCLUSIVE_TO_SATISFY_ALLOCATION(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_bytesRequested, arg_subSpaceTypeFlags); \
		} \
	} while (0)

#define ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_FAILED_ALLOCATION_COMPLETED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_succeeded, arg_bytesRequested) \
	do { \
		struct MM_FailedAllocationCompleted eventData; \
		eventData.currentThread = (arg_currentThread); \
		eventData.timestamp = (arg_timestamp); \
		eventData.eventid = (arg_eventid); \
		eventData.succeeded = (arg_succeeded); \
		eventData.bytesRequested = (arg_bytesRequested); \
		(*J9_HOOK_INTERFACE(hookInterface))->J9HookDispatch(J9_HOOK_INTERFACE(hookInterface), J9HOOK_MM_PRIVATE_FAILED_ALLOCATION_COMPLETED, &eventData); \
	} while (0)

#define TRIGGER_J9HOOK_MM_PRIVATE_FAILED_ALLOCATION_COMPLETED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_succeeded, arg_bytesRequested) \
	do { \
		if (J9_EVENT_IS_HOOKED(hookInterface, J9HOOK_MM_PRIVATE_FAILED_ALLOCATION_COMPLETED)) { \
			ALWAYS_TRIGGER_J9HOOK_MM_PRIVATE_FAILED_ALLOCATION_COMPLETED(hookInterface, arg_currentThread, arg_timestamp, arg_eventid, arg_succeeded, arg_bytesRequested); \
		} \
	} while (0)

typedef struct MM_PrivateHookInterface {
	struct J9CommonHookInterface common;
	U_8 flags[88];
	J9HookRecord* hooks[88];
} MM_PrivateHookInterface;

#endif /* MMPRIVATEHOOK_INTERNAL_H */
