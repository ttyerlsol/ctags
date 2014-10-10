/*
*   $Id: elixir.c 2014-10-10 16:40:00Z tteoh $
*
*
*   This source code is released for free distribution under the terms of the
*   GNU General Public License.
*
*   This module contains functions for generating tags for Erlang language
*   files.  Some of the parsing constructs are based on the Emacs 'etags'
*   program by Francesco Potori <pot@gnu.org>
*/
/*
*   INCLUDE FILES
*/
#include "general.h"  /* must always come first */
#include "parse.h"      /* always include */

/* FUNCTION DEFINITIONS */

static void installElixirRegex (const langType language)
{
    addTagRegex (language, "^defmodule[ \t]*([a-zA-Z0-9_]+)", "\\1", "M,module", "i");
    addTagRegex (language, "[ \t]*defmacro[ \t]+([a-zA-Z0-9_]+)", "\\1", "m,macro", "i");
    addTagRegex (language, "[ \t]*defp[ \t]+([a-zA-Z0-9_]+)", "\\1", "p,function,functions", "i");
    addTagRegex (language, "[ \t]*def[ \t]+([a-zA-Z0-9_]+)", "\\1", "f,function,functions", "i");
}

/* Create parser definition stucture */
extern parserDefinition* ElixirParser (void)
{
    static const char *const extensions [] = { "ex", "exs", NULL };
    parserDefinition* const def = parserNew ("Elixir");
    def->extensions = extensions;
    def->initialize = installElixirRegex; 
    def->regex      = TRUE;
    return def;
}

/* vi:set tabstop=4 shiftwidth=4: */
