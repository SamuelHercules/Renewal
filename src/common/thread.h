/**
 * This file is part of RagEmu.
 * http://ragemu.org - https://github.com/RagEmu/Renewal
 *
 * Copyright (C) 2016  RagEmu Dev Team
 * Copyright (C) 2012-2015  Hercules Dev Team
 * Copyright (C)  rAthena Project
 *
 * RagEmu is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef COMMON_THREAD_H
#define COMMON_THREAD_H

#include "common/cbasetypes.h"

typedef struct rAthread rAthread;
typedef void* (*rAthreadProc)(void*);

typedef enum RATHREAD_PRIO {
	RAT_PRIO_LOW = 0,
	RAT_PRIO_NORMAL,
	RAT_PRIO_HIGH
} RATHREAD_PRIO;


#ifdef RAGEMU_CORE
/**
 * Creates a new Thread
 *
 * @param entyPoint  - entryProc,
 * @param param - general purpose parameter, would be given as parameter to the thread's entry point.
 *
 * @return not NULL if success
 */
rAthread *rathread_create(rAthreadProc entryPoint, void *param);


/**
 * Creates a new Thread (with more creation options)
 *
 * @param entyPoint  - entryProc,
 * @param param - general purpose parameter, would be given as parameter to the thread's entry point
 * @param szStack - stack Size in bytes
 * @param prio - Priority of the Thread @ OS Scheduler..
 *
 * @return not NULL if success
 */
rAthread *rathread_createEx(rAthreadProc entryPoint, void *param, size_t szStack, RATHREAD_PRIO prio);


/**
 * Destroys the given Thread immediately
 *
 * @note The Handle gets invalid after call! don't use it afterwards.
 *
 * @param handle - thread to destroy.
 */
void rathread_destroy(rAthread *handle);


/**
 * Returns the thread handle of the thread calling this function
 *
 * @note this wont work @ programs main thread
 * @note the underlying implementation might not perform very well, cache the value received!
 *
 * @return not NULL if success
 */
rAthread *rathread_self(void);


/**
 * Returns own thread id (TID)
 *
 * @note this is an unique identifier for the calling thread, and
 *        depends on platform/ compiler, and may not be the systems Thread ID!
 *
 * @return -1 when fails, otherwise >= 0
 */
int rathread_get_tid(void);


/**
 * Waits for the given thread to terminate
 *
 * @param handle - thread to wait (join) for
 * @param out_Exitcode - [OPTIONAL] - if given => Exitcode (value) of the given thread - if it's terminated
 *
 * @return true - if the given thread has been terminated.
 */
bool rathread_wait(rAthread *handle, void **out_exitCode);


/**
 * Sets the given PRIORITY @ OS Task Scheduler
 *
 * @param handle - thread to set prio for
 * @param rio - the priority (RAT_PRIO_LOW ... )
 */
void rathread_prio_set(rAthread *handle, RATHREAD_PRIO prio);


/**
 * Gets the current Prio of the given thread
 *
 * @param handle - the thread to get the prio for.
 */
RATHREAD_PRIO rathread_prio_get(rAthread *handle);


/**
 * Tells the OS scheduler to yield the execution of the calling thread
 *
 * @note: this will not "pause" the thread,
 *        it just allows the OS to spend the remaining time
 *        of the slice to another thread.
 */
void rathread_yield(void);

void rathread_init(void);
void rathread_final(void);
#endif // RAGEMU_CORE

#endif /* COMMON_THREAD_H */
