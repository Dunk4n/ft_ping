/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

const   uint8_t *simple_options[SIMPLE_OPTION_NUMBER] =
    {
    (uint8_t *) "-v",
    (uint8_t *) "-h",
    (uint8_t *) "-f",
    (uint8_t *) "-n",
    (uint8_t *) "-q",
    (uint8_t *) "-4",
    (uint8_t *) "-6",
    (uint8_t *) "-D",
    };

const   uint8_t *argument_options[ARGUMENT_OPTION_NUMBER] =
    {
    (uint8_t *) "-l",
    (uint8_t *) "-I",
    (uint8_t *) "-m",
    (uint8_t *) "-M",
    (uint8_t *) "-w",
    (uint8_t *) "-W",
    (uint8_t *) "-p",
    (uint8_t *) "-Q",
    (uint8_t *) "-S",
    (uint8_t *) "-t",
    (uint8_t *) "-c",
    };

static uint8_t Fu8__copying_string_to_allocated_string(uint8_t *ptr_u8_pssd_source_str, uint8_t **dbl_ptr_u8_pssd_destination_str)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the source string is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_source_str == NULL)
        {
        /**
        * Treat the case when the source string is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the source string is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the source string is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the source string is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the pointer of the destination string is correctly pointing passed as an argument of the function
    */
    if(dbl_ptr_u8_pssd_destination_str == NULL)
        {
        /**
        * Treat the case when the pointer of the destination string is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer of the destination string is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer of the destination string is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer of the destination string is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_length;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt    = 0;
    u64_lcl_length = 0;

    /**
    * Get the length of the source string passed in argument of the function
    */ 
    u64_lcl_length = 0;
    while(ptr_u8_pssd_source_str[u64_lcl_length] != NIL)
        {
        /**
        * Checking for overflow
        */
        if(u64_lcl_length < UINT64_MAX)
            {
            u64_lcl_length++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */ 
            return (RETURN_FAILURE);
            } 
        }

    /**
    * Check if the length of the source string passed in argument of the function is to big to allocate the destination string
    */
    if(u64_lcl_length == UINT64_MAX)
        {
        /**
        * Treat the case when the length of the source string passed in argument of the function is to big to allocate the destination string
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the source string passed in argument of the function is to big to allocate the destination string\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the length of the source string passed in argument of the function is to big to allocate the destination string
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the length of the source string passed in argument of the function is not to big to allocate the destination string
        */
        } 

    /**
    * Check if the destination string is correctly pointing passed as an argument of the function
    */
    if((*dbl_ptr_u8_pssd_destination_str) == NULL)
        {
        /**
        * Treat the case when the destination string is not correctly pointing passed as an argument of the function
        */

        /**
        * Allocating the destination string passed in argument of the function
        */
        (*dbl_ptr_u8_pssd_destination_str) = NULL;
        (*dbl_ptr_u8_pssd_destination_str) = (uint8_t *) malloc(sizeof(uint8_t) * u64_lcl_length + 1);

        /**
        * Check if the allocation of the destination string passed in argument of the function failed
        */
        if((*dbl_ptr_u8_pssd_destination_str) == NULL)
            {
            /**
            * Treat the case when the allocation of the destination string passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the allocation of the destination string passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the destination string passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the destination string passed in argument of the function succeeded
            */

            /**
            * Setting all the character of the destination string passed in argument of the function to nil
            */
            u64_lcl_cnt = 0;
            while(u64_lcl_cnt < u64_lcl_length)
                {
                (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_cnt] = NIL;

                /**
                * Checking for overflow
                */
                if(u64_lcl_cnt < UINT64_MAX)
                    {
                    u64_lcl_cnt++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return a failure to indicate the counter variable overflow
                    */ 
                    return (RETURN_FAILURE);
                    } 
                }

            /**
            * Setting the last character of the destination string passed in argument of the function to nil
            */
            (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_length] = NIL;
            }
        }
    else
        {
        /**
        * Treat the case when the destination string is correctly pointing passed as an argument of the function
        */

        /**
        * Reallocating the destination string passed in argument of the function
        */
        (*dbl_ptr_u8_pssd_destination_str) = (uint8_t *) realloc((*dbl_ptr_u8_pssd_destination_str), sizeof(uint8_t) *  u64_lcl_length + 1);

        /**
        * Check if the reallocation of the destination string passed in argument of the function failed
        */
        if((*dbl_ptr_u8_pssd_destination_str) == NULL)
            {
            /**
            * Treat the case when the reallocation of the destination string passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the reallocation of the destination string passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the destination string passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the destination string passed in argument of the function succeeded
            */

            /**
            * Setting all the character of the destination string passed in argument of the function to nil
            */
            u64_lcl_cnt = 0;
            while(u64_lcl_cnt < u64_lcl_length)
                {
                (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_cnt] = NIL;

                /**
                * Checking for overflow
                */
                if(u64_lcl_cnt < UINT64_MAX)
                    {
                    u64_lcl_cnt++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return a failure to indicate the counter variable overflow
                    */ 
                    return (RETURN_FAILURE);
                    } 
                }

            /**
            * Setting the last character of the destination string passed in argument of the function to nil
            */
            (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_length] = NIL;
            }
        }

    /**
    * Copying the content of the source string passed in argument of the function to the destination string passed in argument of the function
    */
    u64_lcl_cnt = 0;
    while((u64_lcl_cnt < u64_lcl_length) && (ptr_u8_pssd_source_str[u64_lcl_cnt] != NIL))
        {
        (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_cnt] = ptr_u8_pssd_source_str[u64_lcl_cnt];

        /**
        * Checking for overflow
        */
        if(u64_lcl_cnt < UINT64_MAX)
            {
            u64_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */ 
            return (RETURN_FAILURE);
            } 
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__structure_argument_init(argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if( ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure argument passed in argument of the function is already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) != FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is not already initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    uint8_t u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u8_lcl_cnt  = 0;

    /**
    * Setting all the value of the global status of the structure to false
    */
    ptr_sstc_pssd_argument->u8_global_status_ = 0;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FIRST_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SECOND_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_THIRD_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FOURTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FIFTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SIXTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SEVENTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_EIGHTH_BIT;

    /**
    * Reseting all the value of the options in the structure argument passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < SIMPLE_OPTION_NUMBER)
        {
        ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] = FALSE;

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Reseting all the value of the argument options set in the structure argument passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ARGUMENT_OPTION_NUMBER)
        {
        ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] = FALSE;

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            return (RETURN_FAILURE);
            }
        }

    /**
    * Allocating all the argument string of the static array of string to an empty string in the structure argument passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ARGUMENT_OPTION_NUMBER)
        {
        /**
        * Allocating the actual argument string of the static array of string in the structure argument passed in argument of the function to an empty string
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the actual argument string of the static array of string in the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] == NULL)
            {
            /**
            * Treat the case when the allocation of the actual argument string of the static array of string in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the allocation of the actual argument string of the static array of string in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the actual argument string of the static array of string in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the actual argument string of the static array of string in the structure argument passed in argument of the function succeeded
            */

            /**
            * Setting the first character of the actual argument string of the static array of string in the structure argument passed in argument of the function to nil to set it a an empty string
            */
            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt][0] = NIL;
            }

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Allocating the dynamique array of file path in the structure argument passed in argument of the function
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_ = NULL;
    ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_ = (uint8_t **) malloc(sizeof(uint8_t *) *  1);

    /**
    * Check if the allocation of the dynamique array of file path in the structure argument passed in argument of the function failed
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_ == NULL)
        {
        /**
        * Treat the case when the allocation of the dynamique array of file path in the structure argument passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the allocation of the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the allocation of the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the allocation of the dynamique array of file path in the structure argument passed in argument of the function succeeded
        */

        /**
        * Setting the first path of the dynamique array of file path in the structure argument passed in argument of the function to nil
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[0]    = NULL;
        ptr_sstc_pssd_argument->u64_number_of_additional_argument_ = 0;
        }

    /**
    * Setting the structure argument to initialized
    */
    ptr_sstc_pssd_argument->u8_global_status_ |= FIRST_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__structure_argument_close(argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure argument passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;
    u8_lcl_cnt  = 0;

    /**
    * Reseting all the value of the options in the structure argument passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < SIMPLE_OPTION_NUMBER)
        {
        ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] = FALSE;

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Reseting all the value of the argument options set in the structure argument passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ARGUMENT_OPTION_NUMBER)
        {
        ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] = FALSE;

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            return (RETURN_FAILURE);
            }
        }

    /**
    * Freeing and reseting to null all the argument string of the static array of string in the structure argument passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ARGUMENT_OPTION_NUMBER)
        {
        /**
        * Freeing and reseting to null the actual argument string of the static array of string in the structure argument passed in argument of the function
        */
        (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt]);
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = NULL;

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Freeing and setting to null all the file path in the dynamique array in the structure argument passed in argument of the function
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < ptr_sstc_pssd_argument->u64_number_of_additional_argument_ && ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[u64_lcl_cnt] != NULL)
        {
        (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[u64_lcl_cnt]);
        ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[u64_lcl_cnt] = NULL;

        /**
        * Checking for overflow
        */
        if(u64_lcl_cnt < UINT64_MAX)
            {
            u64_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Freeing and setting to null the dynamique array of file path in the structure argument passed in argument of the function
    */
    (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_);
    ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_       = NULL;
    ptr_sstc_pssd_argument->u64_number_of_additional_argument_ = 0;

    /**
    * Setting all the value of the global status of the structure to false
    */
    ptr_sstc_pssd_argument->u8_global_status_ = 0;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FIRST_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SECOND_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_THIRD_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FOURTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FIFTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SIXTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SEVENTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_EIGHTH_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__structure_argument_reset(argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure argument passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;
    u8_lcl_cnt  = 0;

    /**
    * Reseting all the value of the options in the structure argument passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < SIMPLE_OPTION_NUMBER)
        {
        ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] = FALSE;

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Reseting all the value of the argument options set in the structure argument passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ARGUMENT_OPTION_NUMBER)
        {
        ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] = FALSE;

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            return (RETURN_FAILURE);
            }
        }

    /**
    * Freeing and reseting to null all the argument string of the static array of string in the structure argument passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ARGUMENT_OPTION_NUMBER)
        {
        /**
        * Reallocating the actual argument string of the static array of string in the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = (uint8_t *) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt], sizeof(uint8_t) * 1);

        /**
        * Check if the reallocation of the actual argument string of the static array of string in the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] == NULL)
            {
            /**
            * Treat the case when the reallocation of the actual argument string of the static array of string in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;33mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the actual argument string of the static array of string in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;33mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;33mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the actual argument string of the static array of string in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the actual argument string of the static array of string in the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt][0] = '\0';
            }

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Freeing and setting to null all the file path in the dynamique array in the structure argument passed in argument of the function
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < ptr_sstc_pssd_argument->u64_number_of_additional_argument_ && ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[u64_lcl_cnt] != NULL)
        {
        (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[u64_lcl_cnt]);
        ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[u64_lcl_cnt] = NULL;

        /**
        * Checking for overflow
        */
        if(u64_lcl_cnt < UINT64_MAX)
            {
            u64_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Reallocating the dynamique array of file path in the structure argument passed in argument of the function
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_, sizeof(uint8_t *) * 1);

    /**
    * Check if the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_ == NULL)
        {
        /**
        * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;33mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;33mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;33mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function succeeded
        */

        ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[0] = NULL;
        }

    ptr_sstc_pssd_argument->u64_number_of_additional_argument_ = 0;

    /**
    * Setting the structure argument to initialized
    */
    ptr_sstc_pssd_argument->u8_global_status_ |= FIRST_BIT;

    return (RETURN_SUCCESS);
    }

void Fv__structure_argument_display(argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    #ifndef DEVELOPEMENT
    return ;
    #endif

    #ifdef DEMO
    return ;
    #endif

    #ifdef PRODUCTION
    return ;
    #endif

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if( ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return ;
        }
    else
        {
        /**
        * Treat the case when the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure argument passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the structure argument passed in argument of the function is not already initialized
        */
        return ;
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;
    u8_lcl_cnt  = 0;

    ft_printf("    ***********************************************\n");
    ft_printf("    *              STRUCTURE ARGUMENT             *\n");
    ft_printf("    ***********************************************\n\n");

    /**
    * Display all the value of the global status of the structure argument passed in argument of the function
    */
    ft_printf("GLOBAL STATUS:\n");
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) != FALSE)
        {
        ft_printf("    FIRST BIT:     \033[1;93;40mset\033[0m structure initialized\n");
        }
    else
        {
        ft_printf("    FIRST BIT:     structure \033[1;95;40mNOT\033[0m initialized\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        ft_printf("    SECOND BIT:    \033[1;93;40mset error occure\033[0m\n");
        }
    else
        {
        ft_printf("    SECOND BIT:    \033[1;95;40mNOT\033[0m set no error occure\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & THIRD_BIT) != FALSE)
        {
        ft_printf("    THIRD BIT:     \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    THIRD BIT:     \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & FOURTH_BIT) != FALSE)
        {
        ft_printf("    FOURTH BIT:    \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    FOURTH BIT:    \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIFTH_BIT) != FALSE)
        {
        ft_printf("    FIFTH BIT:     \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    FIFTH BIT:     \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & SIXTH_BIT) != FALSE)
        {
        ft_printf("    SIXTH BIT:     \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    SIXTH BIT:     \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & SEVENTH_BIT) != FALSE)
        {
        ft_printf("    SEVENTH BIT:   \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    SEVENTH BIT:   \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & EIGHTH_BIT) != FALSE)
        {
        ft_printf("    EIGHTH BIT:    \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    EIGHTH BIT:    \033[1;95;40mNOT\033[0m set\n");
        }

    ft_printf("\n");

    /**
    * Display all the options set in the structure argument passed in argument of the function
    */
    ft_printf("OPTIONS:\n");
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < SIMPLE_OPTION_NUMBER)
        {
        /**
        * Check if the actual option in the structure argument passed in argument of the function is set
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] != FALSE)
            {
            /**
            * Treat the case when the actual option in the structure argument passed in argument of the function is set
            */

            ft_printf("    The option [%s] is \033[1;93;40mset\033[0m\n", simple_options[u8_lcl_cnt]);
            }
        else
            {
            /**
            * Treat the case when the actual option in the structure argument passed in argument of the function is not set
            */

            ft_printf("    The option [%s] is \033[1;95;40mNOT\033[0m set\n", simple_options[u8_lcl_cnt]);
            }

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            return ;
            }
        }

    ft_printf("\n");

    /**
    * Display all the argument options set in the structure argument passed in argument of the function
    */
    ft_printf("ARGUMENT OPTIONS:\n");
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ARGUMENT_OPTION_NUMBER)
        {
        /**
        * Check if the actual argument option in the structure argument passed in argument of the function is set
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] != FALSE)
            {
            /**
            * Treat the case when the actual argument option in the structure argument passed in argument of the function is set
            */

            ft_printf("    The argument option [%s] is \033[1;93;40mset\033[0m\n", argument_options[u8_lcl_cnt]);
            }
        else
            {
            /**
            * Treat the case when the actual argument option in the structure argument passed in argument of the function is not set
            */

            ft_printf("    The argument option [%s] is \033[1;95;40mNOT\033[0m set\n", argument_options[u8_lcl_cnt]);
            }

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            return ;
            }
        }

    ft_printf("\n");

    /**
    * Display all the argument string of the static array of string in the structure argument passed in argument of the function
    */
    ft_printf("ARGUMENT OPTIONS VALUE:\n");
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ARGUMENT_OPTION_NUMBER)
        {
        /**
        * Display the actual argument string of the static array of string in the structure argument passed in argument of the function
        */

        /**
        * Check if the actual argument string of the static array of string in the structure argument passed in argument of the function is null
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] == NULL)
            {
            /**
            * Treat the case when the actual argument string of the static array of string in the structure argument passed in argument of the function is null
            */

            ft_printf("    [%s] VALUE STR: \033[1;93;40m(nill)\033[0m\n", argument_options[u8_lcl_cnt]);
            }
        else
            {
            /**
            * Treat the case when the actual argument string of the static array of string in the structure argument passed in argument of the function is not null
            */

            ft_printf("    [%s] VALUE STR: \033[1;95;40m[\033[0m%s\033[1;95;40m]\033[0m\n", argument_options[u8_lcl_cnt], ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt]);
            }

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return to indicate the counter variable overflow
            */
            return ;
            }
        }

    ft_printf("\n");

    /**
    * Check if the dynamique array of file path in the structure argument passed in argument of the function is null
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_ == NULL)
        {
        /**
        * Treat the case when the dynamique array of file path in the structure argument passed in argument of the function is null
        */

        ft_printf("FILE PATH ARRAY:     \033[1;95;40mNULL\033[0m\n");
        }
    else
        {
        /**
        * Treat the case when the dynamique array of file path in the structure argument passed in argument of the function is not null
        */

        ft_printf("FILE PATH ARRAY:\n");

        /**
        * Display all the file path of the dynamique array of file path in the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u64_number_of_additional_argument_ && ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[u64_lcl_cnt] != NULL)
            {
            ft_printf("    FILE PATH STR [%lu]: \033[1;95;40m[\033[0m%s\033[1;95;40m]\033[0m\n", u64_lcl_cnt, ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[u64_lcl_cnt]);

            /**
            * Checking for overflow
            */
            if(u64_lcl_cnt < UINT64_MAX)
                {
                u64_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return to indicate the counter variable overflow
                */
                return ;
                }
            }
        }

    ft_printf("\n");

    ft_printf("FILE PATH ARRAY LENGTH: [\033[1;95;40m%lu\033[0m]\n", ptr_sstc_pssd_argument->u64_number_of_additional_argument_);

    ft_printf("\n    ***********************************************\n");
    ft_printf("    *            END STRUCTURE ARGUMENT           *\n");
    ft_printf("    ***********************************************\n");
    }

uint8_t Fu8__load_data_from_argument(argument_t *ptr_sstc_pssd_argument, int32_t s32_pssd_program_argument_number, uint8_t **dbl_ptr_u8_program_arguments)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure argument passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Check if the number of argument of the program is zero
    */
    if(s32_pssd_program_argument_number == 0)
        {
        /**
        * Treat the case when the number of argument of the program is zero
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of argument of the program is zero\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the number of argument of the program is zero
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the number of argument of the program is not zero
        */
        }

    /**
    * Check if the array of argument of the program passed in argument of the function is correctly pointing passed as an argument of the function
    */
    if(dbl_ptr_u8_program_arguments == NULL)
        {
        /**
        * Treat the case when the array of argument of the program passed in argument of the function is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the array of argument of the program passed in argument of the function is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the array of argument of the program passed in argument of the function is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the array of argument of the program passed in argument of the function is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    enum e_argument_option_list e_argument_option_type;
    enum e_simple_option_list   e_option_type;
    int32_t                     s32_lcl_argument_loop_cnt;
    int32_t                     s32_lcl_return_from_comparaison;
    uint8_t                     u8_lcl_cnt;
    uint8_t                     u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    e_argument_option_type          = NO_ARGUMENT_OPTION;
    e_option_type                   = NO_SIMPLE_OPTION;
    s32_lcl_return_from_comparaison = 0;
    u8_lcl_cnt                      = 0;
    u8_lcl_return_from_function     = RETURN_FAILURE;

    s32_lcl_argument_loop_cnt = 1;
    while(s32_lcl_argument_loop_cnt < s32_pssd_program_argument_number)
        {
        e_option_type = NO_SIMPLE_OPTION;
        u8_lcl_cnt    = 0;
        while(u8_lcl_cnt < SIMPLE_OPTION_NUMBER)
            {
            /**
            * Check if the actual simple option is already set
            */
            if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] == FALSE)
                {
                /**
                * Treat the case when the actual simple option is already set
                */

                s32_lcl_return_from_comparaison = 1;
                s32_lcl_return_from_comparaison = ft_strcmp((char *) dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt], (char *) simple_options[u8_lcl_cnt]);

                /**
                * Check if the actual argument of the program is equals to the actual option
                */
                if(s32_lcl_return_from_comparaison == 0)
                    {
                    /**
                    * Treat the case when the actual argument of the program is equals to the actual option
                    */

                    /**
                    * Saving the option type of the actual option and exit the loop
                    */
                    e_option_type = u8_lcl_cnt;
                    break;
                    }
                else
                    {
                    /**
                    * Treat the case when the actual argument of the program is not equals to the actual option
                    */
                    }
                }
            else
                {
                /**
                * Treat the case when  the actual simple option is not already set
                */
                }

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return a failure to indicate the counter variable overflow
                */
                return (RETURN_FAILURE);
                }
            }

        /**
        * Check if the actual argument of the program is an option
        */
        if((e_option_type != NO_SIMPLE_OPTION) && (e_option_type < SIMPLE_OPTION_NUMBER))
            {
            /**
            * Treat the case when the actual argument of the program is an simple option
            */

            /**
            * Setting the found option to the structure argument passed in argument of the function
            */
            ptr_sstc_pssd_argument->ptr_u8_simple_options_[e_option_type] = TRUE;

            /**
            * Checking for overflow
            */
            if(s32_lcl_argument_loop_cnt < INT32_MAX)
                {
                s32_lcl_argument_loop_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return a failure to indicate the counter variable overflow
                */
                return (RETURN_FAILURE);
                }

            continue;
            }
        else
            {
            /**
            * Treat the case when the actual argument of the program is not an simple option
            */
            }

        e_argument_option_type = NO_ARGUMENT_OPTION;
        u8_lcl_cnt             = 0;
        while(u8_lcl_cnt < ARGUMENT_OPTION_NUMBER)
            {
            /**
            * Check if the actual argument option is already set
            */
            if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] == FALSE)
                {
                /**
                * Treat the case when the actual argument option is already set
                */

                s32_lcl_return_from_comparaison = 1;
                s32_lcl_return_from_comparaison = ft_strcmp((char *) dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt], (char *) argument_options[u8_lcl_cnt]);

                /**
                * Check if the actual argument of the program is equals to the actual option
                */
                if(s32_lcl_return_from_comparaison == 0)
                    {
                    /**
                    * Treat the case when the actual argument of the program is equals to the actual option
                    */

                    /**
                    * Saving the option type of the actual option and exit the loop
                    */
                    e_argument_option_type = u8_lcl_cnt;
                    break;
                    }
                else
                    {
                    /**
                    * Treat the case when the actual argument of the program is not equals to the actual option
                    */
                    }
                }
            else
                {
                /**
                * Treat the case when the actual argument option is not already set
                */
                }

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return a failure to indicate the counter variable overflow
                */
                return (RETURN_FAILURE);
                }
            }

        /**
        * Check if the actual argument of the program is an argument option
        */
        if((e_argument_option_type != NO_ARGUMENT_OPTION) && (e_argument_option_type < ARGUMENT_OPTION_NUMBER))
            {
            /**
            * Check if their are an argument to the actual argument option
            */
            if(s32_lcl_argument_loop_cnt + 1 >= s32_pssd_program_argument_number)
                {
                /**
                * Treat the case when their are an argument to the actual argument option
                */

                /**
                * Display option error and command option help
                */
                ft_fprintf(STDERR_FILENO, "ft_ping: Error: '%s' missing argument.\n\n", dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt]);

                ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

                (void) Fv__help();

                return (RETURN_SUCCESS);
                }
            else
                {
                /**
                * Treat the case when their is not an argument to the actual argument option
                */
                }

            /**
            * Setting the found option to the structure argument passed in argument of the function
            */
            ptr_sstc_pssd_argument->ptr_u8_argument_options_[e_argument_option_type] = TRUE;

            /**
            * Checking for overflow
            */
            if(s32_lcl_argument_loop_cnt < INT32_MAX)
                {
                s32_lcl_argument_loop_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return a failure to indicate the counter variable overflow
                */
                return (RETURN_FAILURE);
                }

            /**
            * Copying the actual option argument to the actual argument option string in the structure argument passed in argument of the function
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__copying_string_to_allocated_string(dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt], &(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[e_argument_option_type]));

            /**
            * Check if function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function suucceeded
                */
                }

            /**
            * Checking for overflow
            */
            if(s32_lcl_argument_loop_cnt < INT32_MAX)
                {
                s32_lcl_argument_loop_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return a failure to indicate the counter variable overflow
                */
                return (RETURN_FAILURE);
                }

            continue;
            }
        else
            {
            /**
            * Display option error and command option help
            */
            }

        /**
        * Check if the number of file in argument is at the maximum value
        */
        if(ptr_sstc_pssd_argument->u64_number_of_additional_argument_ == UINT64_MAX)
            {
            /**
            * Treat the case when the number of file in argument is at the maximum value
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of file in argument is at the maximum value\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the number of file in argument is at the maximum value
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the number of file in argument is not at the maximum value
            */
            }

        /**
        * Reallocate the dynamique array of file path in the structure argument passed in argument of the function to add a new file path
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_, sizeof(uint8_t *) * (ptr_sstc_pssd_argument->u64_number_of_additional_argument_ + 1));

        /**
        * Check if the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[ptr_sstc_pssd_argument->u64_number_of_additional_argument_] = NULL;
            }

        /**
        * Copying the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__copying_string_to_allocated_string(dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt], &(ptr_sstc_pssd_argument->dbl_ptr_u8_additional_argument_str_[ptr_sstc_pssd_argument->u64_number_of_additional_argument_]));

        /**
        * Check if function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function suucceeded
            */
            }

        /**
        * Checking for overflow
        */
        if(ptr_sstc_pssd_argument->u64_number_of_additional_argument_ < UINT64_MAX)
            {
            ptr_sstc_pssd_argument->u64_number_of_additional_argument_++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }

        /**
        * Checking for overflow
        */
        if(s32_lcl_argument_loop_cnt < INT32_MAX)
            {
            s32_lcl_argument_loop_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    return (RETURN_SUCCESS);
    }
