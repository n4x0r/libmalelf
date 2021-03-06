/*
 * The libmalelf is an evil library that could be used for good! It was
 * developed with the intent to assist in the process of infecting
 * binaries and provide a safe way to analyze malwares.
 *
 * Evil using this library is the responsibility of the programmer.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef MALELF_UTIL_H
#define MALELF_UTIL_H

#include <stdio.h>
#include <stdarg.h>
#include "types.h"

MALELF_BEGIN_DECLS

#define MAX_LOG_BUFFER (0x1000)

#define MALELF_LOG malelf_say
#define MALELF_SAY if(!malelf_quiet_mode) malelf_say
#define MALELF_LOG_SUCCESS malelf_success
#define MALELF_LOG_VERBOSE_SUCCESS MALELF_LOG_SUCCESS
#define MALELF_LOG_ERROR malelf_error
#define MALELF_LOG_WARN malelf_warn

#define MALELF_UNUSED(var) (void*)var


/*
 * Log information on a file handler with a prefix.
 * Example:
 * malelf_log(fd, "[+]", "value=%d\n", 1) will print:
 *
 * [+] value=1
 *
 * \param fd Output FILE handler
 * \param prefix String prefix to the log
 * \param format String format
 * \param args List of arguments to format
 * \return Number of bytes written to fd
 */
extern int malelf_log(FILE *fd,
                      const char* prefix,
                      const char* format,
                      va_list args);


/*
 *
 */
extern int malelf_print(FILE *fd, const char* format, ...);


/*
 *
 */
extern int malelf_say(const char* format, ...);


/*
 *
 */
extern int malelf_success(const char* format, ...);


/*
 *
 */
extern int malelf_error(const char* format, ...);


/*
 *
 */
extern int malelf_warn(const char* format, ...);


/*
 *
 */
extern void* malelf_malloc(_u32 size);


/*
 *
 */
extern void* malelf_realloc(void* pointer, _u32 new_size);


/*! Dumps the raw memory in hex
 *
 */
extern _u32 malelf_dump(_u8 *mem, _u32 size);


/*
 *
 */
extern _u32 malelf_write(int fd, _u8 *mem, _u32 size);


/*! Find offset of the first occurrence of magic number magic_addr
 * in data.
 *
 *  \param data Binary buffer
 *  \param size Size of the buffer
 *  \param magic_addr Magic number
 *
 *  \return MALELF_SUCCESS if magic number was found
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_find_magic_number(_u8 *data,
                                     _u32 size,
                                     union malelf_dword magic_addr,
                                     _u32 *offset_magic);


MALELF_END_DECLS

#endif
