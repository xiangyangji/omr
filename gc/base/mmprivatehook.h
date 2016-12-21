/* Auto-generated public header file */
#ifndef MMPRIVATEHOOK_H
#define MMPRIVATEHOOK_H

#include "omrhookable.h"


/* Begin declarations block */


/*
 * @ddr_namespace: default
 */

#include "../include/mmhook_common.h"

	
/* End declarations block */

/* J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_START

			Triggered when an increment of a global GC is about to start.  Note that this hook is always triggered between the start and end events of the corresponding cycle.  This hook is only used on collectors which are incremental.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_GlobalGCIncrementStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_START 1
typedef struct MM_GlobalGCIncrementStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t globalGCCount;
	uintptr_t localGCCount;
	uintptr_t bytesRequested;
} MM_GlobalGCIncrementStartEvent;

/* J9HOOK_MM_PRIVATE_GC_INCREMENT_START

			Triggered when an increment of a GC is about to start.  Note that this hook is always triggered between the start and end events of the corresponding cycle.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_GC_INCREMENT_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_GCIncrementStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_GC_INCREMENT_START 2
typedef struct MM_GCIncrementStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	void * stats;
} MM_GCIncrementStartEvent;

/* J9HOOK_MM_PRIVATE_GLOBAL_GC_COLLECT_COMPLETE

			Triggered on completion of Mark ,Sweep and Compact phases of collect.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_GLOBAL_GC_COLLECT_COMPLETE, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_GlobalGCCollectCompleteEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_GLOBAL_GC_COLLECT_COMPLETE 3
typedef struct MM_GlobalGCCollectCompleteEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_GlobalGCCollectCompleteEvent;

/* J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_END

			Triggered when an increment of a global GC has completed.  Note that this hook is always triggered between the start and end events of the corresponding cycle.  This hook is only used on collectors which are incremental.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_GlobalGCIncrementEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_GLOBAL_GC_INCREMENT_END 4
typedef struct MM_GlobalGCIncrementEndEvent {
	struct OMR_VMThread* omrVMThread;
	uint64_t timestamp;
	uintptr_t eventid;
	struct MM_CommonGCData* commonData;
} MM_GlobalGCIncrementEndEvent;

/* J9HOOK_MM_PRIVATE_GC_INCREMENT_END

			Triggered when an increment of a GC has completed.  Note that this hook is always triggered between the start and end events of the corresponding cycle.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_GC_INCREMENT_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_GCIncrementEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_GC_INCREMENT_END 5
typedef struct MM_GCIncrementEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	void * stats;
} MM_GCIncrementEndEvent;

/* J9HOOK_MM_PRIVATE_TAROK_INCREMENT_START

			Triggered when a Tarok increment starts.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_TAROK_INCREMENT_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_TarokIncrementStartEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_TAROK_INCREMENT_START 6
typedef struct MM_TarokIncrementStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t incrementid;
	struct MM_CommonGCStartData* gcStartData;
	uintptr_t taxationThreshold;
} MM_TarokIncrementStartEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_TAROK_INCREMENT_END

			Triggered when a Tarok increment ends.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_TAROK_INCREMENT_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_TarokIncrementEndEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_TAROK_INCREMENT_END 7
typedef struct MM_TarokIncrementEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t exclusiveAccessTime;
	struct MM_CommonGCEndData* gcEndData;
} MM_TarokIncrementEndEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_MARK_START

			Triggered when a mark phase is about to start.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_MARK_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_MarkStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_MARK_START 8
typedef struct MM_MarkStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_MarkStartEvent;

/* J9HOOK_MM_PRIVATE_SCAVENGE_START

			Triggered when a scavenge is about to start.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_SCAVENGE_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ScavengeStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_SCAVENGE_START 9
typedef struct MM_ScavengeStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_ScavengeStartEvent;

/* J9HOOK_MM_PRIVATE_SCAVENGE_END

			Triggered when a scavenge is completed.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_SCAVENGE_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ScavengeEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_SCAVENGE_END 10
typedef struct MM_ScavengeEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	void* subSpace;
} MM_ScavengeEndEvent;

/* J9HOOK_MM_PRIVATE_WALK_HEAP_START

			Report the beginning of a heap walk event.
			Report the fact that a heap walk is about to occur, so that any necessary
			actions can be performed to put the heap in a walkable state.
			The act of putting the heap into a walkable state is performed by
			code which has hooked the J9HOOK_MM_WALK_HEAP_START hook, such as
			GC_VMInterface::initializeExtensions.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_WALK_HEAP_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_WalkHeapStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_WALK_HEAP_START 11
typedef struct MM_WalkHeapStartEvent {
	struct OMR_VM* omrVM;
} MM_WalkHeapStartEvent;

/* J9HOOK_MM_PRIVATE_WALK_HEAP_END

			Report the end of a heap walk event.
			Report the fact that a heap walk has completed, so that any necessary
			actions can be performed to restore the heap to a "normal" state.
			These actions are actually performed by code which has hooked the
			J9HOOK_MM_WALK_HEAP_END hook, such as GC_VMInterface::initializeExtensions.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_WALK_HEAP_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_WalkHeapEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_WALK_HEAP_END 12
typedef struct MM_WalkHeapEndEvent {
	struct OMR_VM* omrVM;
} MM_WalkHeapEndEvent;

/* J9HOOK_MM_PRIVATE_SWEEP_START

			Triggered when a sweep phase is about to start.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_SWEEP_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_SweepStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_SWEEP_START 13
typedef struct MM_SweepStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_SweepStartEvent;

/* J9HOOK_MM_PRIVATE_SWEEP_END

			Triggered when a sweep phase is completed.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_SWEEP_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_SweepEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_SWEEP_END 14
typedef struct MM_SweepEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_SweepEndEvent;

/* J9HOOK_MM_PRIVATE_COMPACT_START

			Triggered when a compact phase is about to start.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_COMPACT_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_CompactStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_COMPACT_START 15
typedef struct MM_CompactStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t gcCount;
} MM_CompactStartEvent;

/* J9HOOK_MM_PRIVATE_CLASS_UNLOADING_START

			Triggered when a class unloading phase is about to start.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CLASS_UNLOADING_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ClassUnloadingStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_CLASS_UNLOADING_START 16
typedef struct MM_ClassUnloadingStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_ClassUnloadingStartEvent;

/* J9HOOK_MM_PRIVATE_CONCURRENT_KICKOFF


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_KICKOFF, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentKickoffEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_KICKOFF 17
typedef struct MM_ConcurrentKickoffEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	struct MM_CommonGCData* commonData;
	uintptr_t traceTarget;
	uintptr_t kickOffThreshold;
	uintptr_t remainingFree;
	uintptr_t reason;
	uintptr_t languageReason;
} MM_ConcurrentKickoffEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CONCURRENT_ABORTED


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_ABORTED, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentAbortedEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_ABORTED 18
typedef struct MM_ConcurrentAbortedEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t reason;
} MM_ConcurrentAbortedEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CONCURRENT_HALTED


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_HALTED, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentHaltedEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_HALTED 19
typedef struct MM_ConcurrentHaltedEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t executionMode;
	uintptr_t traceTarget;
	uintptr_t tracedTotal;
	uintptr_t tracedByMutators;
	uintptr_t tracedByHelpers;
	uintptr_t cardsCleaned;
	uintptr_t cardCleaningThreshold;
	uintptr_t workStackOverflowOccured;
	uintptr_t workStackOverflowCount;
	uintptr_t isCardCleaningComplete;
	uintptr_t scanClassesMode;
	uintptr_t isTracingExhausted;
} MM_ConcurrentHaltedEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_START


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentCollectionCardCleaningStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_START 20
typedef struct MM_ConcurrentCollectionCardCleaningStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t workStackOverflowCount;
} MM_ConcurrentCollectionCardCleaningStartEvent;

/* J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_END


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentCollectionCardCleaningEndEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_CARD_CLEANING_END 21
typedef struct MM_ConcurrentCollectionCardCleaningEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t duration;
	uintptr_t finalcleanedCardsPhase1;
	uintptr_t finalcleanedCardsPhase2;
	uintptr_t finalcleanedCards;
	uintptr_t bytesTraced;
	uintptr_t concleanedCardsPhase1;
	uintptr_t concleanedCardsPhase2;
	uintptr_t concleanedCardsPhase3;
	uintptr_t concleanedCards;
	uintptr_t cardCleaningThreshold;
	uintptr_t cardCleaningPhase1KickOff;
	uintptr_t cardCleaningPhase2KickOff;
	uintptr_t cardCleaningPhase3KickOff;
	uintptr_t workStackOverflowCount;
} MM_ConcurrentCollectionCardCleaningEndEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_START


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentCollectionStartEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_START 22
typedef struct MM_ConcurrentCollectionStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	struct MM_CommonGCStartData* gcStartData;
	uintptr_t traceTarget;
	uintptr_t tracedTotal;
	uintptr_t tracedByMutators;
	uintptr_t tracedByHelpers;
	uintptr_t cardsCleaned;
	uintptr_t cardCleaningPhase1Threshold;
	uintptr_t workStackOverflowOccured;
	uintptr_t workStackOverflowCount;
	uintptr_t threadsToScanCount;
	uintptr_t threadsScannedCount;
	uintptr_t cardCleaningReason;
} MM_ConcurrentCollectionStartEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_END


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentCollectionEndEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_COLLECTION_END 23
typedef struct MM_ConcurrentCollectionEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t duration;
	uint64_t exclusiveAccessTime;
	struct MM_CommonGCEndData* gcEndData;
} MM_ConcurrentCollectionEndEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_ACTIVATED


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_ACTIVATED, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentBackgroundThreadActivatedEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_ACTIVATED 24
typedef struct MM_ConcurrentBackgroundThreadActivatedEvent {
	struct OMR_VMThread* currentThread;
} MM_ConcurrentBackgroundThreadActivatedEvent;

/* J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_FINISHED


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_FINISHED, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentBackgroundThreadFinishedEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_CONCURRENT_BACKGROUND_THREAD_FINISHED 25
typedef struct MM_ConcurrentBackgroundThreadFinishedEvent {
	struct OMR_VMThread* currentThread;
	uintptr_t traceTotal;
} MM_ConcurrentBackgroundThreadFinishedEvent;

/* J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_START


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentCompleteTracingStartEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_START 26
typedef struct MM_ConcurrentCompleteTracingStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t workStackOverflowCount;
} MM_ConcurrentCompleteTracingStartEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_END


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentCompleteTracingEndEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_COMPLETE_TRACING_END 27
typedef struct MM_ConcurrentCompleteTracingEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t duration;
	uintptr_t bytesTraced;
	uintptr_t workStackOverflowCount;
} MM_ConcurrentCompleteTracingEndEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_START


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentRememberedSetScanStartEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_START 28
typedef struct MM_ConcurrentRememberedSetScanStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t workStackOverflowCount;
} MM_ConcurrentRememberedSetScanStartEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_END


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentRememberedSetScanEndEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CONCURRENT_REMEMBERED_SET_SCAN_END 29
typedef struct MM_ConcurrentRememberedSetScanEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t duration;
	uintptr_t objectsFound;
	uintptr_t bytesTraced;
	uintptr_t workStackOverflowCount;
} MM_ConcurrentRememberedSetScanEndEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_OBJECT_ENQUEUED_FOR_FINALIZATION
Reports that a job has been enqueued for finalization.

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_OBJECT_ENQUEUED_FOR_FINALIZATION, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ObjectEnqueuedForFinalizingEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_OBJECT_ENQUEUED_FOR_FINALIZATION 30
typedef struct MM_ObjectEnqueuedForFinalizingEvent {
	struct OMR_VM* OMR_VM;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t finalizerJob;
	class GC_FinalizerJob* job;
	struct OMR_VMThread* currentThread;
} MM_ObjectEnqueuedForFinalizingEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_HEAP_NEW
Report the creation of a new heap

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_HEAP_NEW, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_HeapNewEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_HEAP_NEW 31
typedef struct MM_HeapNewEvent {
	struct OMR_VMThread* currentThread;
	void* heap;
} MM_HeapNewEvent;

/* J9HOOK_MM_PRIVATE_HEAP_DELETE
Report the deletion of a heap

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_HEAP_DELETE, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_HeapDeleteEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_HEAP_DELETE 32
typedef struct MM_HeapDeleteEvent {
	struct OMR_VMThread* currentThread;
	void* heap;
} MM_HeapDeleteEvent;

/* J9HOOK_MM_PRIVATE_HEAP_RESIZE
Report the start of a heap expansion event through hooks.

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_HEAP_RESIZE, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_HeapResizeEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_HEAP_RESIZE 33
typedef struct MM_HeapResizeEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t resizeType;
	uintptr_t subSpaceType;
	uint32_t ratio;
	uintptr_t amount;
	uintptr_t newHeapSize;
	uint64_t timeTaken;
	uintptr_t reason;
} MM_HeapResizeEvent;

/* J9HOOK_MM_PRIVATE_PERCOLATE_COLLECT


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_PERCOLATE_COLLECT, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_PercolateCollectEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_PERCOLATE_COLLECT 34
typedef struct MM_PercolateCollectEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t reason;
} MM_PercolateCollectEvent;

/* J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_START


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_AllocationFailureCycleStartEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_START 35
typedef struct MM_AllocationFailureCycleStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t requestedBytes;
	struct MM_CommonGCStartData* gcStartData;
	uintptr_t subSpaceType;
} MM_AllocationFailureCycleStartEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_END


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_AllocationFailureCycleEndEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_CYCLE_END 36
typedef struct MM_AllocationFailureCycleEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t exclusiveAccessTime;
	uintptr_t subSpaceType;
	struct MM_CommonGCEndData* gcEndData;
} MM_AllocationFailureCycleEndEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_START


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_AllocationFailureStartEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_START 37
typedef struct MM_AllocationFailureStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t requestedBytes;
	struct MM_CommonGCStartData* gcStartData;
	uintptr_t subSpaceType;
	bool tenure;
} MM_AllocationFailureStartEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_END


Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_AllocationFailureEndEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_ALLOCATION_FAILURE_END 38
typedef struct MM_AllocationFailureEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t exclusiveAccessTime;
	struct MM_CommonGCEndData* gcEndData;
	class MM_AllocateDescription * allocDescription;
} MM_AllocationFailureEndEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_SYSTEM_GC_START

			Triggered when a system GC is about to start.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_SYSTEM_GC_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_SystemGCStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_SYSTEM_GC_START 39
typedef struct MM_SystemGCStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint32_t gcCode;
	struct MM_CommonGCStartData* gcStartData;
} MM_SystemGCStartEvent;

/* J9HOOK_MM_PRIVATE_SYSTEM_GC_END

			Triggered when a system GC is completed.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_SYSTEM_GC_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_SystemGCEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_SYSTEM_GC_END 40
typedef struct MM_SystemGCEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t exclusiveAccessTime;
	struct MM_CommonGCEndData* gcEndData;
} MM_SystemGCEndEvent;

/* J9HOOK_MM_PRIVATE_REMEMBEREDSET_OVERFLOW

			Inform consumers of RememberedSet overflow.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_REMEMBEREDSET_OVERFLOW, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_RememberedSetOverflowEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_REMEMBEREDSET_OVERFLOW 41
typedef struct MM_RememberedSetOverflowEvent {
	struct OMR_VMThread* currentThread;
} MM_RememberedSetOverflowEvent;

/* J9HOOK_MM_PRIVATE_SCAVENGER_BACK_OUT

			Triggered when the scavenger backout flag value changes.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_SCAVENGER_BACK_OUT, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ScavengerBackOutEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_SCAVENGER_BACK_OUT 42
typedef struct MM_ScavengerBackOutEvent {
	struct OMR_VM* omrVM;
	BOOLEAN value;
} MM_ScavengerBackOutEvent;

/* J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS

			DEPRECATED: use J9HOOK_MM_EXCLUSIVE_ACCESS_ACQUIRE
			Triggered when a garbage collector thread acquires exclusive VM access.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ExclusiveAccessEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS 43
typedef struct MM_ExclusiveAccessEvent {
	struct OMR_VMThread* currentThread;
} MM_ExclusiveAccessEvent;

/* J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_ACQUIRE

			Triggered when a garbage collector thread acquires exclusive VM access.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_ACQUIRE, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ExclusiveAccessAcquireEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_ACQUIRE 44
typedef struct MM_ExclusiveAccessAcquireEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t exclusiveAccessTime;
	uint64_t meanIdleTime;
	OMR_VMThread* lastResponder;
	uintptr_t haltedThreads;
} MM_ExclusiveAccessAcquireEvent;

/* J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_RELEASE

			Triggered when a garbage collector thread releases exclusive VM access.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_RELEASE, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ExclusiveAccessReleaseEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_EXCLUSIVE_ACCESS_RELEASE 45
typedef struct MM_ExclusiveAccessReleaseEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_ExclusiveAccessReleaseEvent;

/* J9HOOK_MM_PRIVATE_INVOKE_GC_CHECK

			Manually initiate a GCCheck run (as opposed to having one triggered by a GC).
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_INVOKE_GC_CHECK, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_InvokeGCCheckEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_INVOKE_GC_CHECK 46
typedef struct MM_InvokeGCCheckEvent {
	struct OMR_VM* omrVM;
	struct OMRPortLibrary* portLibrary;
	char* options;
	uintptr_t invocationNumber;
} MM_InvokeGCCheckEvent;

/* J9HOOK_MM_PRIVATE_CONCURRENTLY_COMPLETED_SWEEP_PHASE

			Triggered when the sweep phase has been complete concurrently (not counting connection).
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENTLY_COMPLETED_SWEEP_PHASE, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentlyCompletedSweepPhase* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_CONCURRENTLY_COMPLETED_SWEEP_PHASE 47
typedef struct MM_ConcurrentlyCompletedSweepPhase {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t timeElapsed;
	uintptr_t bytesSwept;
} MM_ConcurrentlyCompletedSweepPhase;

/* J9HOOK_MM_PRIVATE_COMPLETED_CONCURRENT_SWEEP

			Triggered when the concurrent sweep and connect is completed for an STW garbage collection.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_COMPLETED_CONCURRENT_SWEEP, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_CompletedConcurrentSweep* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_COMPLETED_CONCURRENT_SWEEP 48
typedef struct MM_CompletedConcurrentSweep {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t timeElapsedSweep;
	uintptr_t bytesSwept;
	uint64_t timeElapsedConnect;
	uintptr_t bytesConnected;
	uintptr_t reason;
} MM_CompletedConcurrentSweep;

/* J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_GC_ACTIVITY

			Triggered when we check to see how much time we are spending in GC.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_GC_ACTIVITY, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ExcessiveGCCheckGCActivityEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_GC_ACTIVITY 49
typedef struct MM_ExcessiveGCCheckGCActivityEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t gcCount;
	uint64_t gcInTime;
	uint64_t gcOutTime;
	float newGCPercent;
	float averageGCPercent;
	float excessiveGCPercent;
} MM_ExcessiveGCCheckGCActivityEvent;

/* J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_FREE_SPACE

			Triggered when we check how much free space is being reclaimed when GC activity has reached excessive level. 
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_FREE_SPACE, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ExcessiveGCCheckFreeSpaceEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_EXCESSIVEGC_CHECK_FREE_SPACE 50
typedef struct MM_ExcessiveGCCheckFreeSpaceEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t gcCount;
	float newGCPercent;
	float averageGCPercent;
	float excessiveGCPercent;
	uintptr_t freeMemoryDelta;
	float reclaimedPercent;
	uintptr_t activeHeapSize;
	uintptr_t currentHeapSize;
	uintptr_t maximumHeapSize;
} MM_ExcessiveGCCheckFreeSpaceEvent;

/* J9HOOK_MM_PRIVATE_CACHE_CLEARED
Triggered when an allocation cache is full.

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CACHE_CLEARED, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_CacheClearedEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CACHE_CLEARED 51
typedef struct MM_CacheClearedEvent {
	struct OMR_VMThread* currentThread;
	void * subSpace;
	void * cacheBase;
	void * cacheAlloc;
	void * cacheTop;
} MM_CacheClearedEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CACHE_REFRESHED
Triggered when a new allocation cache is allocated

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CACHE_REFRESHED, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_CacheRefreshedEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_CACHE_REFRESHED 52
typedef struct MM_CacheRefreshedEvent {
	struct OMR_VMThread* currentThread;
	void * subSpace;
	void * cacheBase;
	void * cacheTop;
} MM_CacheRefreshedEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_NON_TLH_ALLOCATION
Triggered when an allocation is made which is too big for an allocation cache.

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_NON_TLH_ALLOCATION, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_NonTLHAllocationEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_NON_TLH_ALLOCATION 53
typedef struct MM_NonTLHAllocationEvent {
	struct OMR_VMThread* currentThread;
	void * objectPtr;
} MM_NonTLHAllocationEvent;

/* J9HOOK_MM_PRIVATE_OBJECT_REMOVED_FROM_REMEMBERED_SET
Triggered when an object reference is removed from the remembered set

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_OBJECT_REMOVED_FROM_REMEMBERED_SET, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ObjectRemovedFromRememberedSetEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_OBJECT_REMOVED_FROM_REMEMBERED_SET 54
typedef struct MM_ObjectRemovedFromRememberedSetEvent {
	struct OMR_VMThread* currentThread;
	void * objectPtr;
} MM_ObjectRemovedFromRememberedSetEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_REBUILD_FREE_LIST
Triggered when a range of memory subspace is emptied out and added to free list

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_REBUILD_FREE_LIST, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_RebuildFreeListEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_REBUILD_FREE_LIST 55
typedef struct MM_RebuildFreeListEvent {
	struct OMR_VMThread* currentThread;
	void *  rangeBase;
	void *  rangeTop;
} MM_RebuildFreeListEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_MOVE_OBJECTS
Triggered when a range of objects is moved fromone heap location to another

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_MOVE_OBJECTS, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_MoveObjectsEvent* eventData = voidData;
		. . .
	}
 */
#if defined (__cplusplus)
#define J9HOOK_MM_PRIVATE_MOVE_OBJECTS 56
typedef struct MM_MoveObjectsEvent {
	struct OMR_VMThread* currentThread;
	void *  sourceBase;
	void *  destinationBase;
	uintptr_t size;
} MM_MoveObjectsEvent;
#endif /* defined (__cplusplus)*/

/* J9HOOK_MM_PRIVATE_CARD_CLEANING_PASS_2_START

			Triggered at the start of any second card cleaning pass.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CARD_CLEANING_PASS_2_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_CardCleanPass2StartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_CARD_CLEANING_PASS_2_START 57
typedef struct MM_CardCleanPass2StartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_CardCleanPass2StartEvent;

/* J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_START

			Triggered when a metronome GC increment begins.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_MetronomeIncrementStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_START 58
typedef struct MM_MetronomeIncrementStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uint64_t exclusiveAccessTime;
} MM_MetronomeIncrementStartEvent;

/* J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_END

			Triggered when a metronome GC increment ends.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_MetronomeIncrementEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_METRONOME_INCREMENT_END 59
typedef struct MM_MetronomeIncrementEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t heapFree;
	uintptr_t immortalFree;
	uintptr_t classLoadersUnloaded;
	uintptr_t classesUnloaded;
	uintptr_t anonymousClassesUnloaded;
	uintptr_t nonDeterministicSweepCount;
	uintptr_t nonDeterministicSweepConsecutive;
	uint64_t nonDeterministicSweepDelay;
	uintptr_t weakReferenceClearCount;
	uintptr_t softReferenceClearCount;
	uintptr_t softReferenceThreshold;
	uintptr_t dynamicSoftReferenceThreshold;
	uintptr_t phantomReferenceClearCount;
	uintptr_t finalizableCount;
	uintptr_t workPacketOverflowCount;
	uintptr_t objectOverflowCount;
} MM_MetronomeIncrementEndEvent;

/* J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_START

			Triggered when metronome decides to complete a GC synchronously.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_MetronomeSynchronousGCStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_START 60
typedef struct MM_MetronomeSynchronousGCStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t reason;
	uintptr_t reasonParameter;
	uintptr_t heapFree;
	uintptr_t immortalFree;
	uintptr_t classLoadersUnloaded;
	uintptr_t classesUnloaded;
	uintptr_t anonymousClassesUnloaded;
} MM_MetronomeSynchronousGCStartEvent;

/* J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_END

			Triggered when synchronous GC is completed.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_MetronomeSynchronousGCEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_METRONOME_SYNCHRONOUS_GC_END 61
typedef struct MM_MetronomeSynchronousGCEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t heapFree;
	uintptr_t immortalFree;
	uintptr_t classLoadersUnloaded;
	uintptr_t classesUnloaded;
	uintptr_t anonymousClassesUnloaded;
	uintptr_t weakReferenceClearCount;
	uintptr_t softReferenceClearCount;
	uintptr_t softReferenceThreshold;
	uintptr_t dynamicSoftReferenceThreshold;
	uintptr_t phantomReferenceClearCount;
	uintptr_t finalizableCount;
	uintptr_t workPacketOverflowCount;
	uintptr_t objectOverflowCount;
} MM_MetronomeSynchronousGCEndEvent;

/* J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_START

			Triggered when metronome decides to start a continuous GC due to low free memory (below trigger point).
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_MetronomeTriggerStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_START 62
typedef struct MM_MetronomeTriggerStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_MetronomeTriggerStartEvent;

/* J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_END

			Triggered when metronome freed enough memory (above trigger point) after a just finished GC cycle.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_MetronomeTriggerEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_METRONOME_TRIGGER_END 63
typedef struct MM_MetronomeTriggerEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_MetronomeTriggerEndEvent;

/* J9HOOK_MM_PRIVATE_OUT_OF_MEMORY

			Triggered when we are about to return NULL from J9AllocateObject() or J9AllocateIndexableObject().
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_OUT_OF_MEMORY, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_OutOfMemoryEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_OUT_OF_MEMORY 64
typedef struct MM_OutOfMemoryEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	void* memorySpace;
	const char* memorySpaceString;
} MM_OutOfMemoryEvent;

/* J9HOOK_MM_PRIVATE_UTILIZATION_TRACKER_OVERFLOW

			Triggered when the utilization tracker has overflowed its _timeSliceDuration array
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_UTILIZATION_TRACKER_OVERFLOW, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_UtilizationTrackerOverflowEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_UTILIZATION_TRACKER_OVERFLOW 65
typedef struct MM_UtilizationTrackerOverflowEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	void* utilizationTrackerAddress;
	void* timeSliceDurationArrayAddress;
	uintptr_t timeSliceCursor;
} MM_UtilizationTrackerOverflowEvent;

/* J9HOOK_MM_PRIVATE_NON_MONOTONIC_TIME

			Triggered when the GC detects time going backwards 
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_NON_MONOTONIC_TIME, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_NonMonotonicTimeEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_NON_MONOTONIC_TIME 66
typedef struct MM_NonMonotonicTimeEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	const char* timerDesc;
} MM_NonMonotonicTimeEvent;

/* J9HOOK_MM_PRIVATE_REPORT_MEMORY_USAGE

			Triggered just before the end of a global GC
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_REPORT_MEMORY_USAGE, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ReportMemoryUsageEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_REPORT_MEMORY_USAGE 67
typedef struct MM_ReportMemoryUsageEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	struct MM_MemoryStatistics* statistics;
} MM_ReportMemoryUsageEvent;

/* J9HOOK_MM_PRIVATE_VLHGC_GARBAGE_COLLECT_COMPLETED

			Triggered at the end of a GC but before the final cleanup and increment end reporting
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_VLHGC_GARBAGE_COLLECT_COMPLETED, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_VlhgcGarbageCollectCompletedEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_VLHGC_GARBAGE_COLLECT_COMPLETED 68
typedef struct MM_VlhgcGarbageCollectCompletedEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
} MM_VlhgcGarbageCollectCompletedEvent;

/* J9HOOK_MM_PRIVATE_COPY_FORWARD_ABORT

			Triggered when the copy forward scheme raises the abort flag.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_COPY_FORWARD_ABORT, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_CopyForwardAbortEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_COPY_FORWARD_ABORT 69
typedef struct MM_CopyForwardAbortEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_CopyForwardAbortEvent;

/* J9HOOK_MM_PRIVATE_COPY_FORWARD_START

			Triggered when the copy forward operation is about to start.
			NOTE: For internal GC use only.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_COPY_FORWARD_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_CopyForwardStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_COPY_FORWARD_START 70
typedef struct MM_CopyForwardStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	void * copyForwardStats;
} MM_CopyForwardStartEvent;

/* J9HOOK_MM_PRIVATE_COPY_FORWARD_END

			Triggered when the copy forward cycle operations end.
			NOTE: For internal GC use only.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_COPY_FORWARD_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_CopyForwardEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_COPY_FORWARD_END 71
typedef struct MM_CopyForwardEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	void * copyForwardStats;
	void * workPacketStats;
	void * irrsStats;
} MM_CopyForwardEndEvent;

/* J9HOOK_MM_PRIVATE_CONCURRENT_GMP_START

			Triggered when concurrent GMP work begins.
			NOTE:  Only expected to be used by verbose GC output.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_GMP_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentGMPStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_CONCURRENT_GMP_START 72
typedef struct MM_ConcurrentGMPStartEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	void * concurrentGMPStats;
} MM_ConcurrentGMPStartEvent;

/* J9HOOK_MM_PRIVATE_CONCURRENT_GMP_END

			Triggered when concurrent GMP work ends.
			NOTE:  Only expected to be used by verbose GC output.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_CONCURRENT_GMP_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ConcurrentGMPEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_CONCURRENT_GMP_END 73
typedef struct MM_ConcurrentGMPEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	void * concurrentGMPStats;
} MM_ConcurrentGMPEndEvent;

/* J9HOOK_MM_PRIVATE_MARK_END

			Triggered when a mark phase is completed.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_MARK_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_MarkEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_MARK_END 74
typedef struct MM_MarkEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
} MM_MarkEndEvent;

/* J9HOOK_MM_PRIVATE_GMP_MARK_START

			Triggered when a GMP mark phase increment is started.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_GMP_MARK_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_GMPMarkStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_GMP_MARK_START 75
typedef struct MM_GMPMarkStartEvent {
	struct OMR_VMThread* currentThread;
	void * markStats;
	void * workPacketStats;
} MM_GMPMarkStartEvent;

/* J9HOOK_MM_PRIVATE_GMP_MARK_END

			Triggered when a GMP mark phase increment ends.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_GMP_MARK_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_GMPMarkEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_GMP_MARK_END 76
typedef struct MM_GMPMarkEndEvent {
	struct OMR_VMThread* currentThread;
	void * markStats;
	void * workPacketStats;
} MM_GMPMarkEndEvent;

/* J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_START

			Triggered when a vlhgc global gc mark phase is started.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_VLHGCGlobalGCMarkStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_START 77
typedef struct MM_VLHGCGlobalGCMarkStartEvent {
	struct OMR_VMThread* currentThread;
	void * markStats;
	void * workPacketStats;
} MM_VLHGCGlobalGCMarkStartEvent;

/* J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_END

			Triggered when a vlhgc global gc mark phase ends.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_VLHGCGlobalGCMarkEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_VLHGC_GLOBAL_GC_MARK_END 78
typedef struct MM_VLHGCGlobalGCMarkEndEvent {
	struct OMR_VMThread* currentThread;
	void * markStats;
	void * workPacketStats;
} MM_VLHGCGlobalGCMarkEndEvent;

/* J9HOOK_MM_PRIVATE_PGC_MARK_START

			Triggered when a PGC mark phase increment is started.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_PGC_MARK_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_PGCMarkStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_PGC_MARK_START 79
typedef struct MM_PGCMarkStartEvent {
	struct OMR_VMThread* currentThread;
	void * markStats;
	void * workPacketStats;
} MM_PGCMarkStartEvent;

/* J9HOOK_MM_PRIVATE_PGC_MARK_END

			Triggered when a PGC mark phase increment ends.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_PGC_MARK_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_PGCMarkEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_PGC_MARK_END 80
typedef struct MM_PGCMarkEndEvent {
	struct OMR_VMThread* currentThread;
	void * markStats;
	void * workPacketStats;
	void * irrsStats;
} MM_PGCMarkEndEvent;

/* J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_START

			Triggered when a reclaim sweep event starts.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ReclaimSweepStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_START 81
typedef struct MM_ReclaimSweepStartEvent {
	struct OMR_VMThread* currentThread;
	void * sweepStats;
} MM_ReclaimSweepStartEvent;

/* J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_END

			Triggered when a reclaim sweep event ends.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ReclaimSweepEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_RECLAIM_SWEEP_END 82
typedef struct MM_ReclaimSweepEndEvent {
	struct OMR_VMThread* currentThread;
	void * sweepStats;
} MM_ReclaimSweepEndEvent;

/* J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_START

			Triggered when a reclaim compact event starts.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_START, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ReclaimCompactStartEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_START 83
typedef struct MM_ReclaimCompactStartEvent {
	struct OMR_VMThread* currentThread;
	void * compactStats;
} MM_ReclaimCompactStartEvent;

/* J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_END

			Triggered when a reclaim compact event ends.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_ReclaimCompactEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_RECLAIM_COMPACT_END 84
typedef struct MM_ReclaimCompactEndEvent {
	struct OMR_VMThread* currentThread;
	void * compactStats;
	void * irrsStats;
} MM_ReclaimCompactEndEvent;

/* J9HOOK_MM_PRIVATE_GC_POST_CYCLE_END

			Private hook triggered after the public CYCLE_END event. Used by verbose GC to track time spent in other components that hooks the public CYCLE_END event.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_GC_POST_CYCLE_END, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_GCPostCycleEndEvent* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_GC_POST_CYCLE_END 85
typedef struct MM_GCPostCycleEndEvent {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	struct MM_CommonGCData* commonData;
	uintptr_t cycleType;
	uintptr_t workStackOverflowOccured;
	uintptr_t workStackOverflowCount;
	uintptr_t workpacketCount;
	uintptr_t fixHeapForWalkReason;
	uint64_t fixHeapForWalkTime;
} MM_GCPostCycleEndEvent;

/* J9HOOK_MM_PRIVATE_ACQUIRED_EXCLUSIVE_TO_SATISFY_ALLOCATION

			Private hook triggered if exclusive access was acquired for an allocation, but the allocation was then satisfied without having to GC.
			This typically represents a thrashing / spinning avoidance decision - had to acquire exclusive in order to ensure the thread made forward
			progress.
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_ACQUIRED_EXCLUSIVE_TO_SATISFY_ALLOCATION, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_AcquiredExclusiveToSatisfyAllocation* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_ACQUIRED_EXCLUSIVE_TO_SATISFY_ALLOCATION 86
typedef struct MM_AcquiredExclusiveToSatisfyAllocation {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t bytesRequested;
	uintptr_t subSpaceTypeFlags;
} MM_AcquiredExclusiveToSatisfyAllocation;

/* J9HOOK_MM_PRIVATE_FAILED_ALLOCATION_COMPLETED

			Private hook triggered when an allocation which caused an AF is completed
		

Example usage:
	(*hookable)->J9HookRegister(hookable, J9HOOK_MM_PRIVATE_FAILED_ALLOCATION_COMPLETED, eventOccurred, NULL);

	static void
	eventOccurred(J9HookInterface** hookInterface, UDATA eventNum, void* voidData, void* userData)
	{
		MM_FailedAllocationCompleted* eventData = voidData;
		. . .
	}
 */
#define J9HOOK_MM_PRIVATE_FAILED_ALLOCATION_COMPLETED 87
typedef struct MM_FailedAllocationCompleted {
	struct OMR_VMThread* currentThread;
	uint64_t timestamp;
	uintptr_t eventid;
	uintptr_t succeeded;
	uintptr_t bytesRequested;
} MM_FailedAllocationCompleted;

#endif /* MMPRIVATEHOOK_H */
