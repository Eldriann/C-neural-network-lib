/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the puts functions YOU NEED TO TUEN MACROS ON WHEN UNIT TESTING
*/

/* File created the 10/04/2018 at 13:40:00 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "nn.h"

void redirect_all(void)
{
	cr_redirect_stderr();
	cr_redirect_stdout();
}

Test(puts_debug, Valid_message, .timeout=1, .init=redirect_all)
{
	if (NN_DISPLAY_DEBUG_MESSAGES == false) {
		cr_skip("Warning NN_DISPLAY_DEBUG_MESSAGES is set to false: test will be skipped");
	}
	cr_expect_eq(puts_debug("Valid str\n"), 19);
	cr_expect_stderr_eq_str("[DEBUG]: Valid str\n");
}

Test(puts_debug, NULL_message, .timeout=1, .init=redirect_all)
{
	if (NN_DISPLAY_DEBUG_MESSAGES == false) {
		cr_skip("Warning NN_DISPLAY_DEBUG_MESSAGES is set to false: test will be skipped");
	}
	cr_expect_eq(puts_debug(NULL), 32);
	cr_expect_stderr_eq_str("[ERROR]: Debug message is NULL!\n");
}

Test(puts_debug, Empty_message, .timeout=1, .init=redirect_all)
{
	if (NN_DISPLAY_DEBUG_MESSAGES == false) {
		cr_skip("Warning NN_DISPLAY_DEBUG_MESSAGES is set to false: test will be skipped");
	}
	cr_expect_eq(puts_debug(""), 9);
	cr_expect_stderr_eq_str("[DEBUG]: ");
}

Test(puts_error, Valid_message, .timeout=1, .init=redirect_all)
{
	if (NN_DISPLAY_ERROR_MESSAGES == false) {
		cr_skip("Warning NN_DISPLAY_ERROR_MESSAGES is set to false: test will be skipped");
	}
	cr_expect_eq(puts_error("Valid str\n"), 19);
	cr_expect_stderr_eq_str("[ERROR]: Valid str\n");
}

Test(puts_error, NULL_message, .timeout=1, .init=redirect_all)
{
	if (NN_DISPLAY_ERROR_MESSAGES == false) {
		cr_skip("Warning NN_DISPLAY_ERROR_MESSAGES is set to false: test will be skipped");
	}
	cr_expect_eq(puts_error(NULL), 32);
	cr_expect_stderr_eq_str("[ERROR]: Error message is NULL!\n");
}

Test(puts_error, Empty_message, .timeout=1, .init=redirect_all)
{
	if (NN_DISPLAY_ERROR_MESSAGES == false) {
		cr_skip("Warning NN_DISPLAY_ERROR_MESSAGES is set to false: test will be skipped");
	}
	cr_expect_eq(puts_error(""), 9);
	cr_expect_stderr_eq_str("[ERROR]: ");
}