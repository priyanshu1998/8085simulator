# 8085simulator

Command line based 8085 simulator/debugger (ported from sim8085.com)

###### Language: C


### Motivation:
    Opcodes can be broken down logically (ref: https://www.eeeguide.com/instruction-format-of-8085/) which is sought of mindblowing and acts a 
    factcheck everything that is engineered has a logic behind it.

    So after days of studing and working for long hours on assingnment(this was a 3rd year 1st semester Project assignment)
    We were actually tired and deadline was close.

    We needed to design a simulator that can be used for debugging.
    (Deadline was close and we needed to come up with soln. fast)


### Plan of action:
    A naive solution but a decent solution would have been to map Opcode with action which was actully good 
    considering it also will allow us to create debugger.

    It was too much lines of code (DRY without D : "Reapeat Yourself")
    We found that backend logic of https://www.sim8085.com/ is in C and I just needed to write some code to make it work with command line.

    After a bit of refactoring and debugging(C is very critical with reading memory).
    I managed to do the whole task in just 2 days.
    It was a quite an experience and story to share.

### Notes:
    Refer to log.diff to see the modification and contribution made by me.

    Permalink to sim8085 code which is used.
    https://github.com/debjitbis08/sim8085/blob/6d728504cc6048da372719ab97ef565e7cdf244b/src/core/8085.c

    
    Also note that I split "8085.c" code into a core.h and core.c file.

    core.h : contain only the declations
    core.c : contain only the logic implementation.

    diff is done with between 8085.c and core.c

### Compilation 
    g++ 8085.c core.c

### Execution
    ./a.out <input file>