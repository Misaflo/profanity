/*
 * api.h
 *
 * Copyright (C) 2012 - 2014 James Booth <boothj5@gmail.com>
 *
 * This file is part of Profanity.
 *
 * Profanity is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Profanity is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Profanity.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef API_H
#define API_H

#include "plugins/callbacks.h"

void api_cons_alert(void);
void api_cons_show(const char * const message);
void api_notify(const char *message, const char *category, int timeout_ms);
void api_send_line(char *line);
char * api_get_current_recipient(void);

void api_register_command(const char *command_name, int min_args, int max_args,
    const char *usage, const char *short_help, const char *long_help,
    void *callback, void(*callback_func)(PluginCommand *command, gchar **args));
void api_register_timed(void *callback, int interval_seconds,
    void (*callback_func)(PluginTimedFunction *timed_function));

void api_log_debug(const char *message);
void api_log_info(const char *message);
void api_log_warning(const char *message);
void api_log_error(const char *message);

int api_win_exists(const char *tag);
void api_win_create(const char *tag, void *callback,
    void(*callback_func)(PluginWindowCallback *window_callback, char *tag, char *line));
void api_win_focus(const char *tag);
void api_win_process_line(const char *tag, const char * const line);
void api_win_show(const char *tag, const char *line);

#endif
