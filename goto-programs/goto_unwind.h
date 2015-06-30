/*
 * goto_unwind.h
 *
 *  Created on: Jun 3, 2015
 *      Author: mramalho
 */

#ifndef GOTO_PROGRAMS_GOTO_UNWIND_H_
#define GOTO_PROGRAMS_GOTO_UNWIND_H_

#include <std_types.h>
#include <hash_cont.h>

#include <message_stream.h>

#include "goto_functions.h"
#include "goto_loops.h"

void goto_unwind(
  goto_functionst &goto_functions,
  unsigned unwind,
  message_handlert &message_handler);

class goto_unwindt: public goto_loopst
{
public:
  goto_unwindt(
    goto_functiont &_goto_function,
    unsigned _unwind,
    message_handlert &_message_handler) :
    goto_loopst(
      _goto_function,
      _message_handler),
    unwind(_unwind),
    tmp_goto_program(goto_programt())
  {
    // unwind loops
    if(function_loops.size())
      goto_unwind();
  }

protected:
  unsigned unwind;
  goto_programt tmp_goto_program;

  void goto_unwind();
  void unwind_program(
    goto_programt &goto_program,
    function_loopst::reverse_iterator loop);
};

#endif /* GOTO_PROGRAMS_GOTO_UNWIND_H_ */
