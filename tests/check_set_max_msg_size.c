/*
 * Check: a unit test framework for C
 * Copyright (C) 2001, 2002 Arien Malec
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

/**
 * The purpose of this test is to be used by valgrind to check for
 * memory leaks. Each public API that check exports is used at
 * least once. Tests which use non-public API, or leak intentionally,
 * are not included here.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <check.h>
#include "config.h"
#include "check_check.h"

START_TEST(test_set_max_msg_size)
{
  ck_abort_msg("40 characters of an assertion message...");
}
END_TEST


static Suite *make_set_max_msg_size_suite(void)
{
  Suite *s = suite_create("Check Set Max Msg Size");

  TCase *tc_set_max_msg_size = tcase_create("Test Set Max Msg Size");

  suite_add_tcase (s, tc_set_max_msg_size);

  tcase_add_test (tc_set_max_msg_size, test_set_max_msg_size);

  return s;
}

int main (void)
{
    int n;
    SRunner *sr;

    /*
     * Run the test suite. This is intended to trigger the "Message is too long" error.
     * Actual success/failure is determined by examining the output.
     */
    check_set_max_msg_size(32); // This will have an effect due to no environment variable.
    sr = srunner_create(make_set_max_msg_size_suite());
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
    return EXIT_SUCCESS;
}

