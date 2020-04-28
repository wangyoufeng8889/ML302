/**
 * @file shell_cmd_list.c
 * @author Letter (NevermindZZT@gmail.com)
 * @brief shell cmd list
 * @version 3.0.0
 * @date 2020-01-17
 * 
 * @copyright (c) 2020 Unicook
 * 
 */

#include "shell.h"

#if SHELL_USING_CMD_EXPORT != 1

extern int shellSetVar(char *name, int value);
extern void shellUp(Shell *shell);
extern void shellDown(Shell *shell);
extern void shellRight(Shell *shell);
extern void shellLeft(Shell *shell);
extern void shellTab(Shell *shell);
extern void shellBackspace(Shell *shell);
extern void shellDelete(Shell *shell);
extern void shellEnter(Shell *shell);
extern void shellHelp(int argc, char *argv[]);
extern void shellUsers(void);
extern void shellCmds(void);
extern void shellVars(void);
extern void shellKeys(void);
extern void shellClear(void);
extern void onemo_test_send_at(int argc, char *agrv[]);
extern void onemo_test_dump_at(int argc, char *agrv[]);

/**
 * @brief shell命令表
 * 
 */
const ShellCommand shellCommandList[] =
    {
        {.attr.value = SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_USER),
         .data.user.name = SHELL_DEFAULT_USER,
         .data.user.password = SHELL_DEFAULT_USER_PASSWORD,
         .data.user.desc = "defalut user"},
        SHELL_CMD_ITEM(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC),
                       setVar, shellSetVar, set var),
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0), 0x1B5B4100, shellUp, up),
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0), 0x1B5B4200, shellDown, down),
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0) | SHELL_CMD_ENABLE_UNCHECKED,
                       0x1B5B4300, shellRight, right),
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0) | SHELL_CMD_ENABLE_UNCHECKED,
                       0x1B5B4400, shellLeft, left),
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0), 0x09000000, shellTab, tab),
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0) | SHELL_CMD_ENABLE_UNCHECKED,
                       0x08000000, shellBackspace, backspace),
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0) | SHELL_CMD_ENABLE_UNCHECKED,
                       0x7F000000, shellDelete, delete),
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0) | SHELL_CMD_ENABLE_UNCHECKED,
                       0x1B5B337E, shellDelete, delete),
#if SHELL_ENTER_LF == 1
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0) | SHELL_CMD_ENABLE_UNCHECKED,
                       0x0A000000, shellEnter, enter),
#endif
#if SHELL_ENTER_CR == 1
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0) | SHELL_CMD_ENABLE_UNCHECKED,
                       0x0D000000, shellEnter, enter),
#endif
#if SHELL_ENTER_CRLF == 1
        SHELL_KEY_ITEM(SHELL_CMD_PERMISSION(0) | SHELL_CMD_ENABLE_UNCHECKED,
                       0x0D0A0000, shellEnter, enter),
#endif
        SHELL_CMD_ITEM(
            SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN) | SHELL_CMD_DISABLE_RETURN,
            help, shellHelp, show command info\r\nhelp[cmd]),
        SHELL_CMD_ITEM(
            SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN,
            users, shellUsers, list all user),
        SHELL_CMD_ITEM(
            SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN,
            cmds, shellCmds, list all cmd),
        SHELL_CMD_ITEM(
            SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN,
            vars, shellVars, list all var),
        SHELL_CMD_ITEM(
            SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN,
            keys, shellKeys, list all key),
        SHELL_CMD_ITEM(
            SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN,
            cls, shellClear, clear console),
        SHELL_CMD_ITEM(
            SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN) | SHELL_CMD_DISABLE_RETURN,
            send_at, onemo_test_send_at, vir at send),
        SHELL_CMD_ITEM(
            SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN) | SHELL_CMD_DISABLE_RETURN,
            dump_at, onemo_test_dump_at, at dump),
};

/**
 * @brief shell命令表大小
 * 
 */
const unsigned short shellCommandCount = sizeof(shellCommandList) / sizeof(ShellCommand);

#endif
