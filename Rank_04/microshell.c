/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:11:50 by ksudyn            #+#    #+#             */
/*   Updated: 2025/06/23 19:44:09 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int error(char *str)
{
    while(*str)
        write(2, str++, 1);
    return (1);
}

int cd(char **argv, int i)
{
    if(i != 2)
        return (error("error: cd: bad argument\n"));
    else if (chdir(argv[1]) == -1)
        return (error("error: cd : cannot change directory to "), error(argv[1]), error ("\n"));
    return (0);         
}
//Verifica que tenga exactamente dos argumentos (cd DIR)
//Usa chdir() para cambiar de directorio
//Muestra error si falla

int exec(char **argv, char **envp, int i) 
{
    int fd[2];
    int status;
    int is_pipe = argv[i] && strcmp(argv[i], "|") == 0;

    if (is_pipe && pipe(fd) == -1)
        return error("error: fatal\n");

    int pid = fork();
    if (!pid) 
    {
        argv[i] = 0;
        if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return error("error: fatal\n");
        execve(*argv, argv, envp);
        return error("error: cannot execute "), error(*argv), error("\n");
    }

    waitpid(pid, &status, 0);
    if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return error("error: fatal\n");
    return WIFEXITED(status) && WEXITSTATUS(status);
}

//Ejecuta un comando usando fork() y execve()

//Si hay un "|", crea un pipe

//Usa dup2() para redirigir la entrada/salida cuando es necesario

//Verifica si hay un pipe al final del comando:

//int is_pipe = argv[i] && strcmp(argv[i], "|") == 0;
//Si hay un pipe, crea con pipe(fd)

//Hace un fork() para crear un proceso hijo

//Cierra y redirige los pipes si es necesario

//Llama a execve() para ejecutar el comando

//Si falla, imprime error

//Espera con waitpid()

//Redirige la entrada si hay pipe


int main(int argc, char **argv, char **envp) 
{
    int i = 0;
    int status = 0;

    if (argc > 1) 
    {
        while (argv[i] && argv[++i]) 
        {
            argv += i;
            i = 0;

            // Recorre hasta encontrar un "|" o ";"
            while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
                i++;

            // Si el comando es "cd"
            if (strcmp(*argv, "cd") == 0)
                status = cd(argv, i);
            else if (i)
                status = exec(argv, envp, i);
        }
    }
    return status;
}

//Recorre los argumentos pasados por consola
//Identifica cada comando (separado por | o ;)
//Si es cd, llama a cd()
//Si no, llama a exec()
//Cada uno loo iguala a status para despues retornarlo