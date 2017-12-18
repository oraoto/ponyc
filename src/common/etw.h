#ifndef ETW_H
#define ETW_H

#include "../libponyrt/actor/actor.h"

#include <TraceLoggingProvider.h>
TRACELOGGING_DECLARE_PROVIDER(etw_provider);

#define TraceLoggingScheduler(ptr)                   \
    TraceLoggingUIntPtr(ptr, "Scheduler")
#define TraceLoggingSchedulerIdx(idx)                \
    TraceLoggingInt32(idx, "SchedulerIdx")
#define TraceLoggingThread(ptr, n)                   \
    TraceLoggingUIntPtr(ptr, n)
#define TraceLoggingMessage(id)                      \
    TraceLoggingUInt32(id, "Message")
#define TraceLoggingActor(ptr, n)                    \
    TraceLoggingStruct(2, n),                        \
    TraceLoggingUInt32(((pony_actor_t *)ptr)->type->id, "type"), \
    TraceLoggingUIntPtr(ptr, "ptr")

#define PONY_ACTOR_ALLOC(name, a0, a1)               \
    do { TraceLoggingWrite(etw_provider, #name,      \
    TraceLoggingScheduler(a0),                       \
    TraceLoggingActor(a1, "Actor")                   \
    );} while (0)

#define PONY_ACTOR_MSG_SEND(name, a0, a1, a2, a3)    \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingScheduler(a0),                   \
        TraceLoggingMessage(a1),                     \
        TraceLoggingActor(a2, "FromActor"),          \
        TraceLoggingActor(a3, "ToActor")             \
    );} while (0)

#define PONY_ACTOR_MSG_RUN(name, a0, a1, a2)         \
    do { TraceLoggingWrite(etw_provider, #name,      \
         TraceLoggingScheduler(a0),                  \
         TraceLoggingActor(a1, "Actor"),             \
         TraceLoggingMessage(a2)                     \
    );} while (0)

#define PONY_ACTOR_MSG_PUSH(name, a0, a1, a2, a3)    \
    do { TraceLoggingWrite(etw_provider, #name,      \
         TraceLoggingSchedulerIdx(a0),               \
         TraceLoggingMessage(a1),                    \
         TraceLoggingActor(a2, "FromActor"),         \
         TraceLoggingActor(a3, "ToActor")            \
    );} while (0)

#define PONY_ACTOR_MSG_POP(name, a0, a1, a2)         \
    do { TraceLoggingWrite(etw_provider, #name,      \
         TraceLoggingSchedulerIdx(a0),               \
         TraceLoggingMessage(a1),                    \
         TraceLoggingActor(a2, "Actor")              \
    );} while (0)

#define PONY_THREAD_MSG_PUSH(name, a0, a1, a2)       \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingMessage(a0),                     \
        TraceLoggingThread(a0, "FromThread"),        \
        TraceLoggingThread(a1, "ToThread")           \
    );} while (0)

#define PONY_THREAD_MSG_POP(name, a0, a1)            \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingMessage(a0),                     \
        TraceLoggingThread(a1, "Thread")             \
    );} while (0)

#define PONY_ACTOR_SCHEDULED(name, a0, a1)           \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingScheduler(a0),                   \
        TraceLoggingActor(a1, "Actor")               \
    );} while (0)

#define PONY_ACTOR_DESCHEDULED(name, a0, a1)         \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingScheduler(a0),                   \
        TraceLoggingActor(a1, "Actor")               \
    );} while (0)

#define PONY_ACTOR_OVERLOADED(name, a0)              \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingActor(a0, "Actor")               \
    ); } while (0)

#define PONY_ACTOR_OVERLOADED_CLEARED(name, a0)      \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingActor(a0, "Actor")               \
    );} while (0)

#define PONY_ACTOR_UNDER_PRESSURE(name, a0)          \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingActor(a0, "Actor")               \
    );} while (0)

#define PONY_ACTOR_PRESSURE_RELEASED(name, a0)       \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingActor(a0, "Actor")               \
    );} while (0)

#define PONY_GC_END(name, a0)                        \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingScheduler(a0)                    \
    );} while (0)

#define PONY_GC_SEND_END(name, a0)                   \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingScheduler(a0)                    \
    );} while (0)

#define PONY_GC_SEND_START(name, a0)                 \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingScheduler(a0)                    \
    );} while (0)

#define PONY_GC_RECV_END(name, a0)                   \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingScheduler(a0)                    \
    );} while (0)

#define PONY_GC_RECV_START(name, a0)                 \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingScheduler(a0)                    \
    );} while (0)

#define PONY_GC_START(name, a0)                      \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingScheduler(a0)                    \
    );} while (0)

#define PONY_GC_THRESHOLD(name, a0)                  \
    do { TraceLoggingWrite(etw_provider, #name,      \
        TraceLoggingFloat64(a0));                    \
    } while (0)

#define PONY_HEAP_ALLOC(name, a0, a1)                \
    do { TraceLoggingWrite(etw_provider, #name,      \
         TraceLoggingScheduler(a0),                  \
         TraceLoggingUInt64(a1, "Size"));            \
    } while (0)

#define PONY_RT_INIT(name)                           \
    do { TraceLoggingWrite(etw_provider, #name); } while (0)

#define PONY_RT_START(name)                          \
    do { TraceLoggingWrite(etw_provider, #name); } while (0)

#define PONY_RT_END(name)                            \
    do { TraceLoggingWrite(etw_provider, #name); } while (0)

#define PONY_WORK_STEAL_SUCCESSFUL(name, a0, a1, a2) \
    do { TraceLoggingWrite(etw_provider, #name,      \
         TraceLoggingScheduler(a0),                  \
         TraceLoggingActor(a1, "Victim"),            \
         TraceLoggingActor(a2, "Actor")              \
    );} while (0)

#define PONY_WORK_STEAL_FAILURE(name, a0, a1)        \
    do { TraceLoggingWrite(etw_provider, #name,      \
          TraceLoggingScheduler(a0),                 \
         TraceLoggingActor(a1, "Victim")             \
    );} while (0)

#endif
