/*
** EPITECH PROJECT, 2019
** cd.c
** File description:
** Change directory
*/

#include "mysh.h"

static int go_here(char *str)
{
    struct stat sb;

    if (stat(str, &sb) == -1)
        return (error_ret(84, str, ENOENT));
    if (!S_ISDIR(sb.st_mode))
        return (error_ret(84, str, ENOTDIR));
    return (chdir(str));
}

static int go_back(char **envp)
{
    char *oldpwd = find_env_data(envp, "OLDPWD");

    if (my_strcmp(oldpwd, "mysh") == 0)
        return (arrfree_ret(error_ret(84, NULL, ENOENT), oldpwd));
    return (arrfree_ret(chdir(oldpwd), oldpwd));
}

static int exec_home(shell_vars_t *vars, int rk, int len)
{
    struct stat sb;
    char *str = NULL;

    if (len == 1 || my_strlen(vars->commands[rk][1]) == 1) {
        str = find_env_data(vars->envp, "HOME");
        if (my_strcmp(str, "mysh") == 0)
            return (arrfree_ret(84, str));
        if (stat(str, &sb) == -1 || !S_ISDIR(sb.st_mode))
            return (arrfree_ret(84, str));
        return (arrfree_ret(chdir(str), str));
    }
    vars->commands[rk][1][0] = '/';
    if (vars->commands[rk][1][1] == '/') {
        str = find_env_data(vars->envp, "HOME");
        if (my_strcmp(str, "mysh") == 0)
            return (arrfree_ret(84, str));
        str = concat_words(1, str, vars->commands[rk][1], NULL);
    } else
        str = concat_words(0, str, "/home", vars->commands[rk][1], NULL);
    return (arrfree_ret(go_here(str), str));
}

static int update_env(shell_vars_t *vars, char *oldpwd)
{
    char *pwd = NULL;

    pwd = getcwd(pwd, 0);
    update_var_env(&vars->envp, "OLDPWD", oldpwd);
    update_var_env(&vars->envp, "PWD", pwd);
    free(pwd);
    return (0);
}

int exec_cd(shell_vars_t *vars, int rk)
{
    int len = arr2len(vars->commands[rk]);
    int code = 0;
    char *save = NULL;

    if (len > 2)
        return (m_ret_e(84, "cd", "Too many arguments"));
    save = getcwd(save, 0);
    if (len == 1 || vars->commands[rk][1][0] == '~')
        code = exec_home(vars, rk, len);
    else if (my_strcmp(vars->commands[rk][1], "-") == 0)
        code = go_back(vars->envp);
    else
        code = go_here(vars->commands[rk][1]);
    if (code != 84 && code != -1)
        update_env(vars, save);
    free(save);
    return (code);
}
